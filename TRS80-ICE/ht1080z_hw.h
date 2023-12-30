// Machine specific variables and functions
//
// HT-1080Z is a TRS-80 clone. Hardware description is very similar to TRS-80 Hardware description
//
// Address (hex)  Description
// 0000-2FFF Level II ROM                         -> read cachable
// 3000-37DF Unused in case of TRS-80
//    3000-37FF HT-1080Z: expansion ROM           -> read cachable
// 37E0-37FF Memory Mapped I/O (37E8H - printer port, 37E0H to 37EFH FDD controller)
// 3800-38FF Keyboard map
// 3900-3BFF (Keyboard 'shadow'ed here)
// 3C00-3FFF 1kb Video RAM                        -> read cachable
// 4000-41FF RAM used by the ROM routines         -> rw cachable
//    40A4-40A5 Ptr to start of BASIC program
//    40B1-40B2 Ptr to top of BASIC memory
//    40D6-40D7 Memory size stored here
//    40DF-40ED Ptr to entry address for SYSTEM programs
//    http://ht.homeserver.hu/doc/listak/vegyes/informacios_lapok.pdf
// 4200-7FFF Usable RAM in a 16K machine          -> rw cachable
// 8000-BFFF Additional RAM in a 32K machine      -> rw cachable
// C000-FFFF Still more in a 48K machine          -> rw cachable

#define MEMORY_SIZE     65536
#define PORT_SIZE       256
#define ROM_START       0x0000
// Original TRS-80 Model 0x2fff, HT-1080Z has been expanded to (docs: 0x35ff) 0x374f based on ROM dump
// It is set based on: https://www.trs-80.com/wordpress/ram-addresses-and-routines/ 3000H-37DDH 12288-143011 Reserved. Unused in Model I.
#define ROM_END         0x37DD
#define VIDEO_RAM_START 0x3C00
#define VIDEO_RAM_END   0x3FFF
#define RAM_START       0x4000

#define DRIVE_SELECT_REGISTER 0x37E1
#define FDC_BASE_ADDRESS 0x37EC
#define HT_ROM_SIZE 14336
#define DIAG_ROM_SIZE 1317

// Keyboard special cahracters
#define ENTER 0x0A
#define CLEAR 0x08
#define BREAK 0x1B
#define LEFT 0x11
#define RIGHT 0x12
#define DOWN 0x13
#define UP 0x14
#define SHIFT 0x15

// RAM_END can be redefined as there were 16k and 48k variants of TRS-80
extern uint16_t RAM_END;      



// MCL Z80 emulator and Menu is managed through writing this register

#define MCL_MENU_REGISTER 0x00


// CMD 0x4713   ->  Basic implementation is done, supports CAS files
// LOAD 0x4188  ->  Basic implementation is done, supports CAS files
// SAVE 0x41A0  ->  Implement if requested
// Source:
// http://ht.homeserver.hu/doc/listak/mikro_magazin/lemez_utasitas_86szept.jpg
#define BASIC_CMD 0x4173
#define BASIC_LOAD 0x4188

// ROMs and BASIC expansions has been downloaded from page dedicated to HT
// Size: 12k+2k
// Link: http://ht.homeserver.hu/html/hardverrom.html
// Latest version is used as default 

extern uint8_t internalMemory[];
extern uint8_t accelerationModeMap[];

// Acceleration mode See deatils in ht1080z.cpp
extern uint8_t accelerationMode;

//  Machine specific functions resides here. The following ones are required for MCL_Z80 and the main ino file

//  Checking PC. If it equals to not used basic commands it invokes subroutine
//  Two commands are implemented to load CAS files from SD card
//  CMD starts a menu to select file, while LOAD awaits the file path
void checkBasicEntryPoint ();

//  Checking if the given address can be accelerated or not
//
// Heavily machine dependent, we need to check if memory access can be accelerated
// Example: On TRS-80/HT-1080Z keyboard is memory mapped, so in any case we need to read the registers, not the simulated memory array
// Acceleration modes and what is accelerated:
// accelerationMode=0x4 => Special mode, only the ROM shadowed, but it is cycle accurate. Used for DiagROM
// accelerationMode=0x3 => Full (RW) acceleration: Shadowed ROM and mapped RAM. Yes, I know ROM is not writable, but in special case you can rewrite code...
// accelerationMode=0x2 => Read acceleration: Video RAM, writes must reach mobo RAM, for screen output
// accelerationMode=0x1 => No acceleration, but write back to shadow RAM for all the rest, like memory mapped IO
// uint8_t internalAddressCheck(uint16_t localAddress);

// Pre calculate a map for each address based on actual acceleration mode.
// Call it whenever you change the AccelerationMode to build the new map.
// Use the array AccelerationModeMap[uint16_t memoryAddress] to get acceleration mode for a given memory address.
// It was introduced to speed up the BIU part as it was not fast enough
void buildAccelerationModeMap (void);

//  Reading a single byte from Arduino Memory instead of the RAM of machine
//  It is much faster as it is running on 600MHz
//  For a paged system the function handles page selection and mapping intead of MCL_Z80
uint8_t internalMemoryRead(uint16_t);

//  Writes a single byte to Arduino Memory. It is called if acceleration mode is at least 1
//  It is a must to be able to be able to change mode
//  Similar to internalMemoryRead paging must be handled here if any
uint8_t internalMemoryWrite(uint8_t, uint16_t, uint8_t);

//  Writes a byte to an array
//  It can't be cached, but can be used for further features like paging
//  Port 0x00 write is controlling acceleration mode between mode 0 and 3
void internalPortWrite(uint16_t, uint8_t);

// Read ROM file from SD card to RAM. Called from boot menu
bool copyRomFileToRAM(String);

// Simply just fill with space the screen
void clearScreen(); 

// Display string on screen, beware it is not very sophisticated
void displayStringXY (String, uint8_t, uint8_t);  

// Read cas file to RAM and start if it is a binary or return to BASIC
// Can handle binary and basic programs in CAS file format.
// CAS file reference (hungarian): http://ht.homeserver.hu/html/konvertformatum.html
uint16_t copyCasToMemory(String);

// Checking keyboard and returns if any of them is pressed. It does not wait, so requires an external loop
char keyboardRead(int);    
