#include <stdint.h>
#include <SD.h>
#include "ht1080z_hw.h"
#include "ht1080z_sw.h"
#include "mcl_Z80.h"
#include "fd1771.h"

int looper=0;

// RAM_END can be redefined as there were 16k and 48k variants of TRS-80, so we may redefine it
uint16_t RAM_END = 0xFFFF;
uint8_t internalMemory[MEMORY_SIZE];
uint8_t accelerationModeMap[0xffff];

// Acceleration mode
//  0x0 - All external memory accesses Machine works as a not expanded HT-1080Z. Acceleration can't be turned on
//  0x1 - (DEFAULT) Reads and writes are cycle accurate using internal memory and writes passing through to machine's RAM
//  0x2 - Reads accelerated using internal memory, but writes are cycle accurate and pass through to motherboard
//  0x3 - All read and write accesses use accelerated internal memory wherever it is possible
//  0x4 - For HW testing ROM shadowed by internal RAM otherwise equal to 0x0

uint8_t  accelerationMode = 0x01;

// Heavily machine dependent, we need to check if memory access can be accelerated
// Example: On TRS-80/HT-1080Z keyboard is memory mapped, so in any case we need to read the registers, not the simulated memory array
// Acceleration modes and what is accelerated:
// accelerationMode=0x4 => Special mode, only the ROM shadowed, but it is cycle accurate. Used for DiagROM
// accelerationMode=0x3 => Full (RW) acceleration: Shadowed ROM and mapped RAM. Yes, I know ROM is not writable, but in special case you can rewrite code...
// accelerationMode=0x2 => Read acceleration: Video RAM, writes must reach mobo RAM, for screen output
// accelerationMode=0x1 => No acceleration, but write back to shadow RAM for all the rest, like memory mapped IO
// ROM_END         0x37DD
// VIDEO_RAM_START 0x3C00
// VIDEO_RAM_END   0x3FFF
// RAM_START       0x4000

uint8_t internalAddressCheck(uint16_t localAddress) {

  //  ROM is shadowed and can be read accelerated, so up to 0x02
  if (accelerationMode == 0x00) return 0x0;
  if ( (localAddress&0xfffc) == FDC_BASE_ADDRESS || localAddress == DRIVE_SELECT_REGISTER ) return 0x2;
  
  if (localAddress <= ROM_END) {    
    switch (accelerationMode) {
      case 0x01:
        return 0x01;
      case 0x02:
        return 0x02;
      case 0x03:
        return 0x03;
      case 0x04:
        return 0x01;
    }
  }

  // RAM Embedded IO are, no acceleration at all
  if (localAddress < VIDEO_RAM_START) return 0x00;

  // Video RAM is shadowed and can be read accelerated, so up to 0x02
  if (localAddress < RAM_START) {
    switch (accelerationMode) {
      case 0x01:
        return 0x01;
      case 0x02:
        return 0x02;
      case 0x03:
        return 0x02;
      case 0x04:
        return 0x00;
    }
  }

  // All in, RAM can be accelerated up to 0x03, but for test ROM I turn it off
  if ( (localAddress >= RAM_START) && (localAddress <= RAM_END) ) {
    switch (accelerationMode) {
      case 0x01:
        return 0x01;
      case 0x02:
        return 0x02;
      case 0x03:
        return 0x03;
      case 0x04:
        return 0x00;
    }
  }

  // If we are here fall back to no acceleration mode
  return 0x0; 
}

void buildAccelerationModeMap () {
  uint16_t i=0;
  while (true) {
    accelerationModeMap[i]=internalAddressCheck(i);
    if (i==0xffff) break;
    i++;
    }
}

// Read from the array stored in arduino RAM
// In case of Floppy access we call the fd1771 routine
uint8_t internalMemoryRead(uint16_t localAddress) {
  if (((localAddress&0xfffc) == FDC_BASE_ADDRESS || localAddress == DRIVE_SELECT_REGISTER) && floppyDiskEnabled) return floppyDiskControllerRead (localAddress);
  return internalMemory[localAddress];
}

// internal PORT shadow It can be used for extra emulations or something else
uint8_t   internalPort[PORT_SIZE];


// Always write data to internal RAM
// It is required to be able to change acceleration mode on the fly
// Return EE if write is accelerated: mode=3 and accelerated RAM range
// Accelerated range for write: RAM_START «-» RAM_END
uint8_t internalMemoryWrite(uint8_t localMode, uint16_t localAddress , uint8_t localData) {
  if ((localAddress >= VIDEO_RAM_START) && (localAddress <= RAM_END)) {
    internalMemory[localAddress] = localData;
    if (localMode > 2) return 0xee;
    return 0x00;
  }
  if (((localAddress&0xfffc) == FDC_BASE_ADDRESS || localAddress == DRIVE_SELECT_REGISTER ) && floppyDiskEnabled) { floppyDiskControllerWrite (localAddress, localData); return 0xee; }
  return 0x00;
}

// Write IO port data to internal RAM array
//
// Port 0x00 is selected to controll acceleration mode, so can be changed on the fly between mode 1-3
//
// TRS prefers RAM embedded I/O, but there are few more on HT/Videogenie:
// 0x1E-0x1F - HT-1080Z Sound generator
// 0E8H to 0EBH Serial (Modem) port
// 0xF8 - Videogenie/HT-1080Z RS232 port (data in/status out)
// 0xF9 - Videogenie/HT-1080Z RS232 port (data out/status in)
// 0xFE - Videogenie/HT-1080Z Int/ext cassette lath (bit4)
// 0xFF - Casette
// Sources:
// http://cpmarchives.classiccmp.org/trs80/mirrors/kjsl/www.kjsl.com/trs80/mod1intern.html
// https://www.classic-computers.org.nz/system-80/manuals_tm3_page37.jpg
// Maybe I'll use it later to simulate something or debugging for purposes
// Right now from BASIC you can change speed to 2: out 0,2
void internalPortWrite(uint16_t localAddress , uint8_t localData) {
  internalPort[localAddress] = localData;
  if (accelerationMode != 0  && localAddress == MCL_MENU_REGISTER && localData <= 0x3) {
    accelerationMode = localData;
    buildAccelerationModeMap();
  }
  if (accelerationMode != 0  && localAddress == MCL_MENU_REGISTER && localData == 0xff) BasicCmdCommand();
}

// Screen handling routines - Computer specific, but still can be reused
// TRS-80 and clones have a simple 64x16 char screen
// Use only capitals to keep compatibility over all ROM version
// HT-1080Z is a nice one as can handle small letter and depending on version few Hungarian specific chars

void clearScreen() {
  // set 64x16 char and clear screen
  ioWriteByte(0xff, ioReadByte(0xff) & 0xf7 );
  for (uint16_t localCounter = VIDEO_RAM_START; localCounter <= VIDEO_RAM_END; localCounter++ ) writeByte( localCounter, 0x20 );
}

void displayStringXY (String message, uint8_t x, uint8_t y) {
  if (x >= 64) {
    x = 0;  // Rewind to beginning of next row if x is out of screen
    y++;
  }
  if (y >= 16) {
    x = 0;  // Rewind to top if y is out of screen
    y = 0;
  }
  uint16_t localCounter = VIDEO_RAM_START + x + 64 * y;
  for ( uint8_t i = 0; i < message.length(); i++ ) {
    writeByte( localCounter, message[i] );
    localCounter++;
  }
}

uint16_t copyCasToMemory(String casFileName) {
  uint16_t i = 0;
  uint8_t buffer;
  uint16_t localAddress;
  File casFile;

  // Open and load
  if (!SD.begin(BUILTIN_SDCARD)) return register_pc;
  casFile = SD.open(casFileName.c_str(),FILE_READ);
  if (!casFile) return register_pc;
  if (casFile.isDirectory()) return register_pc;
  
  casFile.seek(0);

  // 0-254 Lead - 255 * 0
  for (i = 0; i < 255; i++) if (casFile.read() != 0x00) return 0x00;

  // 255 Sync - 0xa5
  if (casFile.read() != 0xa5) return 0x00;
  buffer = casFile.read();

  // 0x55 - Machine language program
  if (buffer == 0x55) {
    // Jump over filename I can fileseek, but make it stupid simple;
    for (i = 0x00; i < 6 ; i++) casFile.read();

    // Read blocks into RAM until EOF (0x78)
    while (true) {
      buffer = casFile.read();
      if (buffer == 0x78) break; // EOF, No more blocks, proceed forward
      if (buffer != 0x3c) return 0x0; // If not EOF, must be 0x3c = header of block
      i = casFile.read(); // Bytes in the block, 0x00=256
      if (i == 0) i = 256; // in case of 0 it is turned to 256
      localAddress = (casFile.read() | casFile.read() << 8); // Read RAM address LSB + MSB

      // Read the block into RAM 
      for (int j = 0; j <= i; j++) {
        buffer = casFile.read();
        writeByte( localAddress, buffer );
        localAddress++;
      }
    }

    // Read program entry address and return it so we can start the binary code
    localAddress = (casFile.read() | casFile.read() << 8); // Read LSB + MSB
    casFile.close();
    return localAddress;
  }

  // 0xd3 - BASIC
  if (buffer == 0xd3) {
    // BASIC means 3x 0xd3 + 1 Character as Name, so just read and check them
    if (casFile.read() != 0xd3) return 0x00;
    if (casFile.read() != 0xd3) return 0x00;
    casFile.read();

    // Read pointer where to load BASIC program
    localAddress = (readByte(0x40a5) << 8); // Address high 0x40a5
    localAddress = localAddress | readByte(0x40a4); // Address low 0x40a4

    // Load the program until EOF,
    do {
      writeByte(localAddress, casFile.read() );
      localAddress++;
    } while (casFile.available());

    // Close the file
    casFile.close();
    
    // Update BASIC pointer to the end of program
    localAddress--;
    buffer = localAddress & 0xff;
    writeByte(0x40f9, buffer );
    buffer = localAddress >> 8;
    writeByte(0x40fa, buffer );
    return 0x01; // It is a BASIC program
  }
  return 0x00; // If we are here something went wrong
}


// Checking keyboard and returns if any of them is pressed. It delays, so doesn't requires an external loop
// I've define values for the for special non ASCII keys, please find in .h file
char keyboardRead(int msDelay) {
  uint8_t buffer;
  
  // Keyboard matrix definition
  // TRS-80 as well as HT-1080Z is using memory embedded IO for the keyboard.
  typedef struct  {
    uint16_t keyboardRowAddress;
    char character [8];
  } keyboardRow;
  
  keyboardRow keyboardMatrix[] = {
    {0x3801, '@','A','B','C','D','E','F','G' },
    {0x3802, 'H','I','J','K','L','M','N','O' },
    {0x3804, 'P','Q','R','S','T','U','V','W' },
    {0x3808, 'X','Y','Z',false,false,false,false,false },
    {0x3810, '0','1','2','3','4','5','6','7' },
    {0x3820, '8','9',':',';',',','-','.','/' },
    {0x3840, ENTER,CLEAR,BREAK,UP,DOWN,LEFT,RIGHT,' ' },
    {0x3880, SHIFT,false,false,false,false,false,false,false },
  };

  uint startMilis=millis();
  while ( millis()<startMilis+msDelay) {
    readByteM1(0x3801);   // It is not so nice, but I use M1 cycle in the delay loop, but that way I can enforce DRAM refresh
  }

  // Iterate over the keyboard matrix and keys
  for (uint8_t i=0; i<8;i++) {
    buffer=readByteM1(keyboardMatrix[i].keyboardRowAddress);  
    for (int bitShift=0; bitShift<8;bitShift++) {
      if ( buffer & ( 0x01 << bitShift ))
        return keyboardMatrix[i].character[bitShift];
    }
  }
  return 0x00;
}

// Open a ROM file and read it into simulated ROM space
bool copyRomFileToRAM(String ROMFile) {
  File file=SD.open(ROMFile.c_str(),FILE_READ);
    if ( !file || file.isDirectory() ) {
    file.close();
    return false;
  }

  for (uint16_t localCounter = ROM_START; localCounter <= ROM_END; localCounter++) {  // I may start from 0 as ROM_START is static for this machine, but that way I can controll it in the header file
    internalMemory[localCounter] =  file.read();
    if ( !file.available() ) break; // It is neccessary for short ROMs (e.g. DIAG ROM) to break the for cycle earlier
  }
  
  file.close();
  return true;
}

// SD card loader code is hooked on unused BASIC commands 
// Active if mode >= 0x1 and floppy disk emulation is off
// Also I need to check if register_pc == entry point
// To speed up things the checks were splitted so arduino spares few more clock cycles 

void checkBasicEntryPoint () {
  if ( register_pc == BASIC_CMD )
    if ( accelerationMode != 0 && floppyDiskEnabled == false) register_pc = BasicCmdCommand();
  if ( register_pc == BASIC_LOAD )
    if ( accelerationMode != 0 && floppyDiskEnabled == false) register_pc = BasicLoadCommand();
}
