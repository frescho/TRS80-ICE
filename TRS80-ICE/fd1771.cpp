#include <SD.h>
#include "fd1771.h"
#include "ht1080z_hw.h"
#include "ht1080z_sw.h"

uint8_t currentDrive;
uint8_t currentDriveRegister;
int interruptStatus;
int oldInterruptStatus;

typedef struct  {
  uint8_t trackNum = 0;
  uint8_t sectorNum = 0;
  uint8_t sectorPerTrack = 10;  
  uint8_t dataRegister = 0;
  uint8_t commandRegister;
  uint8_t statusRegister;
  int byteCtr = 0;
  int afterSectorBusyCtr = 0;
  int busyCtr = 0;
  int DRQCtr = 0;

  int iIndexHole = 1;
  int iTrackDirection = IN;
  int motorRunningCtr;

  int sectorsProcessed = 0;
  int statusRegisterChecks = 0;
  uint8_t currentCommand;
  File diskFile;
  String sDiskFileName;
}
drivesettings;

drivesettings Drives[4];

char buffer[255];

int openDiskFileByName(String sFileName, int iDriveNum)
{

  if (!initSD()) return -1;
  Drives[iDriveNum].diskFile.close();
  Drives[iDriveNum].diskFile = SD.open(sFileName.c_str(), FILE_WRITE);
  if (!Drives[iDriveNum].diskFile)
  {
    Drives[iDriveNum].diskFile.close();
    return -1;
  }
  else {
    Drives[iDriveNum].sDiskFileName = sFileName;
    Drives[currentDrive].sectorPerTrack = 10;
    if (Drives[iDriveNum].diskFile.size() > (10*255*256))
    {
      Drives[currentDrive].sectorPerTrack = 255;
    }
    return 1;
  }
}


void init1771Emulation() {
  Drives[0].statusRegister = NOTREADY | TRACKZERO;
  Drives[1].statusRegister = NOTREADY | TRACKZERO;
  Drives[2].statusRegister = NOTREADY | TRACKZERO;
  Drives[3].statusRegister = NOTREADY | TRACKZERO;
}


inline void cmdRestore() {
  Drives[currentDrive].trackNum = 0;
  Drives[currentDrive].diskFile.seek(0);
  Drives[currentDrive].statusRegister = HEADENGAGED | TRACKZERO;
  Drives[currentDrive].currentCommand = CMD_RESTORE;
  interruptStatus |= (0x40);
}

inline void cmdSeek() {
  Drives[currentDrive].trackNum = Drives[currentDrive].dataRegister;
  Drives[currentDrive].diskFile.seek(Drives[currentDrive].trackNum * Drives[currentDrive].sectorPerTrack * 256 + Drives[currentDrive].sectorNum * 256);
  Drives[currentDrive].statusRegister = HEADENGAGED | BUSY;
  if (Drives[currentDrive].trackNum == 0)
    Drives[currentDrive].statusRegister |= TRACKZERO;
//  Drives[currentDrive].busyCtr = 79;
  Drives[currentDrive].busyCtr = 9;
  Drives[currentDrive].currentCommand = CMD_SEEK;
}

inline void cmdStep() {
  if ((Drives[currentDrive].commandRegister & 0x10) == 0x10) {           // only do this stuff if the update flag is set on the track register, otherwise just generate an interupt like we complied
    if (Drives[currentDrive].iTrackDirection == OUT) {
      if (Drives[currentDrive].trackNum > 0)
        Drives[currentDrive].trackNum--;
    }
    else {
      Drives[currentDrive].trackNum++;
    }
  }
  Drives[currentDrive].diskFile.seek(Drives[currentDrive].trackNum * Drives[currentDrive].sectorPerTrack * 256 + Drives[currentDrive].sectorNum * 256);
  Drives[currentDrive].statusRegister = INDEXHOLE;
  Drives[currentDrive].currentCommand = CMD_STEP;
}


inline void cmdStepIn() {
  if ((Drives[currentDrive].commandRegister & 0x10) == 0x10) {          // only do this stuff if the update flag is set on the track register, otherwise just generate an interupt like we complied
    Drives[currentDrive].trackNum++;
  }
  Drives[currentDrive].iTrackDirection = IN; // IN is away from 0
  Drives[currentDrive].diskFile.seek(Drives[currentDrive].trackNum * Drives[currentDrive].sectorPerTrack * 256 + Drives[currentDrive].sectorNum * 256);
  Drives[currentDrive].statusRegister = INDEXHOLE;
  Drives[currentDrive].currentCommand = CMD_STEPIN;
}


inline void cmdStepOut() {
  if ((Drives[currentDrive].commandRegister & 0x10) == 0x10) {          // only do this stuff if the update flag is set on the track register, otherwise just generate an interupt like we complied
    if (Drives[currentDrive].trackNum > 0)
      Drives[currentDrive].trackNum--;
  }
  Drives[currentDrive].iTrackDirection = OUT;                         // OUT is toward 0
  Drives[currentDrive].diskFile.seek(Drives[currentDrive].trackNum * Drives[currentDrive].sectorPerTrack * 256 + Drives[currentDrive].sectorNum * 256);
  Drives[currentDrive].statusRegister = INDEXHOLE;
  Drives[currentDrive].currentCommand = CMD_STEPOUT;
}

inline void cmdReadSector() {
  Drives[currentDrive].byteCtr = 256;
  Drives[currentDrive].busyCtr = 256;
  Drives[currentDrive].afterSectorBusyCtr = 5;
  Drives[currentDrive].statusRegister = BUSY;
  Drives[currentDrive].currentCommand = CMD_READ;
  Drives[currentDrive].DRQCtr = 0;
  if (Drives[currentDrive].sectorsProcessed == 0)
    Drives[currentDrive].DRQCtr = 4;
  else
    Drives[currentDrive].statusRegister |= DRQ;

  Drives[currentDrive].sectorsProcessed++;
}

inline void cmdForceInterrupt(int interruptType) {
  Drives[currentDrive].statusRegister = HEADENGAGED;
  if (Drives[currentDrive].trackNum == 0)
    Drives[currentDrive].statusRegister |= TRACKZERO;

  if (interruptType != 0x00) { }

  Drives[currentDrive].currentCommand = CMD_FORCE_INTERRUPT;
}


inline void cmdWriteSector() {
  Drives[currentDrive].currentCommand = CMD_WRITE;

  Drives[currentDrive].byteCtr = 256;
  Drives[currentDrive].busyCtr = 256;
  Drives[currentDrive].afterSectorBusyCtr = 5;
  Drives[currentDrive].statusRegister = BUSY;
  Drives[currentDrive].DRQCtr = 0;
  if (Drives[currentDrive].sectorsProcessed == 0)
    Drives[currentDrive].DRQCtr = 4;
  else
    Drives[currentDrive].statusRegister |= DRQ;

  Drives[currentDrive].statusRegister &= ~(WRITEFAULT);

  Drives[currentDrive].sectorsProcessed++;
}

inline void cmdReadAddr() {
  Drives[currentDrive].currentCommand = CMD_READ_ADDR;
}

inline void cmdReadTrk() {
  Drives[currentDrive].currentCommand = CMD_READ_TRK ;
}

inline void cmdWriteTrk() {
  Drives[currentDrive].currentCommand = CMD_WRITE_TRK;
}


void invokeCommand(uint8_t dataBus) {
  Drives[currentDrive].commandRegister = dataBus;

  //
  // Command   Type    76543210
  //
  // RESTORE      1     0000XXXX
  // SEEK         1     0001XXXX
  // STEP         1     001uXXXX    u = update track register
  // STEP IN      1     010uXXXX
  // STEP OUT     1     011uXXXX
  // READ SECTOR  2     100mbXXX    m = muliple record, b = 128-1024 block length (0) or 16-4096 block length(1)
  // WRITE SECTOR 2     101mbXXX
  // READ ADDR    3     11000100
  // READ TRK     3     1110010X
  // WRITE TRK    3     11110100
  // FORCE INTRP  4     1101XXXX

  if ((Drives[currentDrive].commandRegister & CMD_READ_MASK) == CMD_READ) {       // read command
    cmdReadSector();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_FORCE_INTERRUPT_MASK) == CMD_FORCE_INTERRUPT) {       // force interrupt command
    cmdForceInterrupt(Drives[currentDrive].commandRegister & 0x0f);
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_SEEK_MASK) == CMD_SEEK) {        // seek command
    cmdSeek();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_RESTORE_MASK) == CMD_RESTORE) {             // restore command
    cmdRestore();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_STEP_MASK) == CMD_STEP) {        // step command
    cmdStep();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_STEPIN_MASK) == CMD_STEPIN) {       // step in command
    cmdStepIn();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_STEPOUT_MASK) == CMD_STEPOUT) {       // step out command
    cmdStepOut();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_WRITE_MASK) == CMD_WRITE) {       // write command
    cmdWriteSector();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_READ_ADDR_MASK) == CMD_READ_ADDR) {              // read address command
    cmdReadAddr();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_READ_TRK_MASK) == CMD_READ_TRK) {       // read track command
    cmdReadTrk();
    return;
  }
  if ((Drives[currentDrive].commandRegister & CMD_WRITE_TRK_MASK) == CMD_WRITE_TRK) {              // write track command
    cmdWriteTrk();
    return;
  }

  Drives[currentDrive].currentCommand = 0;
  //digitalWriteFast(INTERUPT_TO_TRS80, LOW);
}


inline void driveSelect(uint8_t dataBus) {
    currentDriveRegister = dataBus;
  if (dataBus == 0x01)
    currentDrive = 0;
  else if (dataBus == 0x02)
    currentDrive = 1;
  else if (dataBus == 0x04)
    currentDrive = 2;
  else if (dataBus == 0x08)
    currentDrive = 3;
  else {
    currentDrive = 0;
  }
  Drives[currentDrive].statusRegister |= HEADENGAGED;
  if (Drives[currentDrive].trackNum == 0) {
    Drives[currentDrive].statusRegister |= TRACKZERO;
  }
  Drives[currentDrive].motorRunningCtr = 80;

  if (Drives[currentDrive].currentCommand == CMD_SEEK && Drives[currentDrive].busyCtr > 8) { // hack to make seeks late in the cycle match
    Drives[currentDrive].busyCtr = 8;
  }
}

inline void setTrkReg(uint8_t dataBus) {
  Drives[currentDrive].trackNum = dataBus;  // track
  Drives[currentDrive].diskFile.seek(Drives[currentDrive].trackNum * Drives[currentDrive].sectorPerTrack * 256 + Drives[currentDrive].sectorNum * 256);
  //statusRegister = INDEXHOLE;
  return;
}

inline void setSectorReg(uint8_t dataBus) {
  Drives[currentDrive].sectorNum = dataBus; // sector
  Drives[currentDrive].diskFile.seek(Drives[currentDrive].trackNum * Drives[currentDrive].sectorPerTrack * 256 + Drives[currentDrive].sectorNum * 256);
  //statusRegister = INDEXHOLE;
  return;
}

inline void setDataReg(uint8_t dataBus) {
  Drives[currentDrive].dataRegister = dataBus;  // data byte

  if ( Drives[currentDrive].currentCommand == CMD_WRITE) {
    if (Drives[currentDrive].byteCtr > 0) {
      Drives[currentDrive].byteCtr--;

      Drives[currentDrive].diskFile.write(Drives[currentDrive].dataRegister);

      if (Drives[currentDrive].byteCtr == 0) {
        Drives[currentDrive].busyCtr = 3;
        Drives[currentDrive].diskFile.flush(); //Even if it is not 100% safe, but worth to spare SD card wearing and speed to flush it when a 
      }
    }
  }
  //statusRegister = INDEXHOLE;
  return;
}

//
//   FDC registers and drive select latch written by Z80
//
void floppyDiskControllerWrite(uint16_t localAddress, uint8_t dataBus) {

  if (localAddress == DRIVE_SELECT_REGISTER) { // drive select register
    return driveSelect(dataBus);
  }
  if (localAddress == FDC_BASE_ADDRESS) { // command invokation request
    return invokeCommand(dataBus);
  }
  if (localAddress == FDC_BASE_ADDRESS+1) { // set track register
    return setTrkReg(dataBus);
  }
  if (localAddress == FDC_BASE_ADDRESS+2) { // set sector register
    return setSectorReg(dataBus);
  }
  if (localAddress == FDC_BASE_ADDRESS+3) { // set data register
    return setDataReg(dataBus);
  }
}


uint8_t getStatusRegister() {
  Drives[currentDrive].statusRegisterChecks++;
  if (Drives[currentDrive].DRQCtr > 0) {
    Drives[currentDrive].DRQCtr--;
  }
  if (Drives[currentDrive].busyCtr > 0) {
    Drives[currentDrive].busyCtr--;
  }

  if ((Drives[currentDrive].currentCommand == CMD_READ) || (Drives[currentDrive].currentCommand == CMD_WRITE)) {
    if (Drives[currentDrive].DRQCtr == 0)
      Drives[currentDrive].statusRegister |= DRQ;

    if (Drives[currentDrive].byteCtr == 0) {
      Drives[currentDrive].statusRegister &= ~(DRQ);
      interruptStatus |= (0x40);
    }
  }

  if (Drives[currentDrive].currentCommand == CMD_SEEK) {
    if (Drives[currentDrive].busyCtr <= 0) {
      interruptStatus |= (0x40);
      //digitalWriteFast(INTERUPT_TO_TRS80, LOW);
    }
  }

  if (Drives[currentDrive].busyCtr == 0) {
    Drives[currentDrive].afterSectorBusyCtr--;
    if (Drives[currentDrive].afterSectorBusyCtr <= 0) {
      Drives[currentDrive].statusRegister &= ~(BUSY);
    }
  }

  if (Drives[currentDrive].motorRunningCtr == 0)
    Drives[currentDrive].statusRegister |= NOTREADY;
  else
    Drives[currentDrive].statusRegister &= ~(NOTREADY);

  if (Drives[currentDrive].sectorsProcessed == 0) {
    if (Drives[currentDrive].trackNum == 0) {
      Drives[currentDrive].statusRegister |= TRACKZERO; // force track number to zero on the first status check
    }
  }

  if (Drives[currentDrive].trackNum == 17 && Drives[currentDrive].currentCommand != CMD_WRITE) {
    Drives[currentDrive].statusRegister |= 0x20;   // goofy thing that's required because NEWDOS expects to see "FA" status bits on track 17... is this what was keeping me from booting?
  }

  if (Drives[currentDrive].statusRegisterChecks % 1200 == 0) {
    if ((Drives[currentDrive].statusRegister & INDEXHOLE) == INDEXHOLE)
      Drives[currentDrive].statusRegister &= ~(INDEXHOLE);
    else
      Drives[currentDrive].statusRegister |= INDEXHOLE;
  }

  return Drives[currentDrive].statusRegister;
}

uint8_t getDataRegister() {
  if (Drives[currentDrive].byteCtr > 0) {
    Drives[currentDrive].byteCtr--;
    if (Drives[currentDrive].byteCtr == 0) {
      Drives[currentDrive].busyCtr = 3;
    }
    Drives[currentDrive].dataRegister = Drives[currentDrive].diskFile.read();
  }

  return Drives[currentDrive].dataRegister;
}


//
//   FDC registers and drive select read by Z80
//
uint8_t floppyDiskControllerRead(uint16_t localAddress) {

  if (localAddress == DRIVE_SELECT_REGISTER) {            // read disk select register
//    interruptStatus &= ~(0x40);
//    return getStatusRegister();
      return currentDriveRegister;
  }

  if (localAddress == FDC_BASE_ADDRESS) {            // read status register
    interruptStatus &= ~(0x40);
    return getStatusRegister();
  }
  
  if (localAddress == FDC_BASE_ADDRESS+1) {             // read track register
    return Drives[currentDrive].trackNum;
  }

  if (localAddress == FDC_BASE_ADDRESS+2) {             // read sector register
    return Drives[currentDrive].sectorNum;
  }

  if (localAddress == FDC_BASE_ADDRESS+3) {            // read data register
    return getDataRegister();
  }

  return 0xfe;
}

/* initialize everything */
void fd1771Setup() {
  if ( floppyDiskEnabled == false ) return; // Just exit if FDC is disabled
  if (!SD.begin(BUILTIN_SDCARD)) {  // couldn't establish SD card connection
    return;
  }
  File configFile;
  configFile=SD.open(FLOPPY_IMAGE_CONFIG);
  
  if (!configFile) {
    configFile.close();
    return;
  }
  
  for (int i=0;i<4;i++) {
    String imageFilename = configFile.readStringUntil('\n');
    openDiskFileByName(imageFilename, i);
  }
  init1771Emulation();
}

void fd1771SaveConfig() {
    if (!SD.begin(BUILTIN_SDCARD)) {  // couldn't establish SD card connection
    return;
  }
  File configFile;
  SD.remove(FLOPPY_IMAGE_CONFIG);
  configFile=SD.open(FLOPPY_IMAGE_CONFIG,FILE_WRITE);

  if (!configFile) {
    configFile.close();
    return;
  }

  configFile.seek(0);
  for (int i=0;i<4;i++) {
    configFile.write(Drives[i].sDiskFileName.c_str(),strlen(Drives[i].sDiskFileName.c_str()));
    configFile.write("\n");
  }
  configFile.close();
}
