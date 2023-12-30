#include <stdint.h>
#include <SD.h>
#include <SPI.h>
#include <MTP.h>
#include "ht1080z_sw.h"
#include "ht1080z_hw.h"
#include "mcl_Z80.h"
#include "fd1771.h"

// FDC is enabled by default
bool floppyDiskEnabled = true;
bool selectROMFile = false;

bool initSD() {
  if (!SD.begin(BUILTIN_SDCARD)) {  // couldn't establish SD card connection
    return false;
  }
  return true;
}

// MTP file transfer related settings
const char *sd_str[]={"sdio","sd1"}; // edit to reflect your configuration
const int cs[] = {BUILTIN_SDCARD,10}; // edit to reflect your configuration
const int nsd = sizeof(sd_str)/sizeof(const char *);
SDClass sdx[nsd];

MTPStorage_SD storage;
MTPD mtpd(&storage);

void mtpSetup()
{ 
  SPI.setMOSI(SD_MOSI);
  SPI.setMISO(SD_MISO);
  SPI.setSCK(SD_SCK);

  for(int i=0; i<nsd; i++)
  { 
    sdx[i].sdfs.begin(SdioConfig(FIFO_SDIO));
    storage.addFilesystem(sdx[i], sd_str[i]);
  }
}

// Read or write the first line of file. It is used to read/store configs
String readStringFromFile (String fileName) {
  File configFile;
  String fileContent="";
  configFile = SD.open(fileName.c_str(), FILE_READ);
  if (configFile) {
      fileContent = configFile.readStringUntil('\n');
  }    
  configFile.close();
  return fileContent;
}

void writeStringToFile (String fileName, String fileContent) {
  File configFile;
  configFile = SD.open(fileName.c_str(), FILE_WRITE);
  if (!configFile) {
    configFile.close();
    return;
  }

  configFile.seek(0);
  configFile.truncate();
  configFile.write( fileContent.c_str(), strlen(fileContent.c_str()) );
  configFile.write("\n");
  configFile.close();
}

// Convert values to text for menus
String accelerationModeToString (uint8_t status) {
  if (status==0x00) return "OFF, SAFE MODE    ";
  if (status==0x01) return "ON, CYCLE ACCURATE";
  if (status==0x02) return "ON, READS CACHED  ";
  if (status==0x03) return "ON, FULL SPEED    ";
  return "ONLY ROM SHADOW   ";
}

String boolToString (bool status) {
  if (status==true) return " ON ";
  return " OFF";
}

// OK, not nice, but efficient conversion and in case there is something sily I still can set a proper value
// To be honest you may set only 16k or 48k RAM, that is simple :)
uint16_t RAMSizetoInt(String RAMSizeString) {
  if (RAMSizeString=="16k") return 0x7fff;
  return 0xffff;
}

// Display boot menu where user can modify settings
void bootMenu() {

  char keyboardBuffer;

  // Init SD card, if it fails go to safe mode
  if (!initSD()) {
    accelerationMode = 0x00;
    buildAccelerationModeMap();
    return;
  }
  
  // Default settings, read configs from file and FDC init
  accelerationMode = 0x01;
  buildAccelerationModeMap();
  floppyDiskEnabled=true;
  String defaultROMFile = readStringFromFile(DEFAULT_ROM);
  String defaultRAMSize = readStringFromFile(DEFAULT_RAM);
  RAM_END = RAMSizetoInt(defaultRAMSize);
  fd1771Setup();

  clearScreen();
  
  // Wait and display message to invoke boot menu
  // Read key from keyboard and break out in case of SPACE
  for (uint8_t a = 0; a < 15; a++) {
    keyboardBuffer=keyboardRead(200);
    if ( keyboardBuffer == ' ' )
      break;
    displayStringXY ("PRESS SPACE TO ENTER MENU", 17+a, a);
  }

  // If menu was not invoked, just start with default settings
  if ( keyboardBuffer !=' ' ) {
    String defaultROMFile = readStringFromFile(DEFAULT_ROM);
    copyRomFileToRAM(defaultROMFile);
    return;
  }

  while (true) {
    //Display menu and current status
    clearScreen();

    String bootMenu[9] = { "USE KEYS TO SELECT MENU (1-5)", " ", "0. START", "1. CPU ACC. MODE", "2. ROM FILE", "3. RAM SIZE", "4. SELECT FLOPPY IMG", "5. FLOPPY IS", "6. MTP FILE TRANSFER" };
    for (uint8_t i = 0; i < 9; i++) displayStringXY (bootMenu[i], 0, i);
    displayStringXY (accelerationModeToString(accelerationMode), 22, 3);
    displayStringXY (defaultROMFile, 22, 4);
    displayStringXY (defaultRAMSize, 22, 5);
    displayStringXY ( boolToString(floppyDiskEnabled) , 22, 7);

    keyboardBuffer=0x00;
    while ( keyboardBuffer==0x00 ) { 
      keyboardBuffer=keyboardRead(150);
    }

    // Start with existing settings
    if (keyboardBuffer=='0') {
      copyRomFileToRAM(defaultROMFile);
      return;
    }
    // Acceleration mode
    if (keyboardBuffer=='1') {
      accelerationMode++;
      if (accelerationMode==0x05) accelerationMode=0;
      buildAccelerationModeMap();
    }
    // Invoke ROM image selector
    if (keyboardBuffer=='2') {
      selectROMFile=true;
          BasicCmdCommand();
          selectROMFile=false;
          defaultROMFile = readStringFromFile(DEFAULT_ROM);
    }
    // Change RAM size between 16 and 48k
    if (keyboardBuffer=='3') {
        if (defaultRAMSize=="16k") defaultRAMSize="48k";
        else defaultRAMSize="16k";
        writeStringToFile (DEFAULT_RAM, defaultRAMSize);
        RAM_END = RAMSizetoInt(defaultRAMSize);
    }
    // Invoke floppy image selector, but it works only if FDC is enabled
    if (keyboardBuffer=='4' && floppyDiskEnabled) {
        BasicCmdCommand();
    }
    // Invert FDC status I don't save it, by default FDC is enabled, except mode 0
    if (keyboardBuffer=='5') floppyDiskEnabled=!floppyDiskEnabled;

    // MTP file transfer from computer to SD card
    if (keyboardBuffer=='6') {
      clearScreen();
      displayStringXY ("MTP TRANSFER, PRESS ANY KEY TO EXIT", 10, 7);
      delay(200); // It is neccessary to have enough time to release '6' so not jumping out imidiately
      mtpSetup();
      keyboardBuffer=0x00;
      while ( keyboardBuffer==0x00 ) {
        mtpd.loop();
        keyboardBuffer=keyboardRead(0);
      }
    }
  }
}


uint16_t BasicLoadCommand () {
  char buffer[64];
  uint16_t i;
  uint16_t parameterPointer = getHLregister();

  // HL should point on a " if not return and display error
  if (readByte(parameterPointer) != 0x22) return register_pc;
  // HL points to the parameter, so fetch it
  for  (i = 0; i < 0xff; i++) {
    buffer[i] = readByte(parameterPointer + i + 1);
    if (buffer[i] == 0x22) {
      buffer[i] = 0x00;
      break;
    }
  }

  i = copyCasToMemory(buffer);

  // Cleanup and return from call
  if (i == 0x01) writeByte(register_pc, 0xc9);
  if (i > VIDEO_RAM_END) return i;
  return register_pc;
}



// A menu where you can select files. Used for:
// In case FDC not enabled load CAS file
// In case FDC enabled select floppy images
// In case ROM variable set select ROM file
uint16_t BasicCmdCommand (void) {

// Allocate struct to store directory content
  struct fileStore {
    String elementType;
    String elementName;
  };
  fileStore fileStoreBuffer [1024]; // Use this struct to store file names for sort
  
  uint16_t selectedElement = 0;
  String actualDirectory = "/";
  String actualElement = " ";
  uint16_t i;
  char keyboardBuffer;
  uint16_t elementCounter;
  uint8_t itIsANewDir = 1;

  File workingDirectory = SD.open (actualDirectory.c_str());

  // We are iterating from here to walk over directories and files
  while (true) {

    if (itIsANewDir == 1) {
      itIsANewDir = 0;
      workingDirectory.rewindDirectory();
      for (i = 0; i < 1024; i++) {
        fileStoreBuffer[i].elementType = "";  // Make sure the array is empty
        fileStoreBuffer[i].elementName = "";
      }
      i = 0;

      // Dump file type + names to array
      while (true) {
        File element = workingDirectory.openNextFile();
        if (!element) break;
        if (element.isDirectory()) fileStoreBuffer[i].elementType = "DIR "; else fileStoreBuffer[i].elementType = "FILE"; //Type
        fileStoreBuffer[i].elementName = element.name();
        i++;
        if (i == 1023) break;
      }
      elementCounter = i - 1;

      // Bubble sort the array
      while (true) {
        int swapHappened = 0;
        for (uint16_t j = 0; j < i - 1; j++) {
          if ( (fileStoreBuffer[j].elementType + fileStoreBuffer[j].elementName) > (fileStoreBuffer[j + 1].elementType + fileStoreBuffer[j + 1].elementName) ) {
            String storeType = fileStoreBuffer[j].elementType;
            String storeName = fileStoreBuffer[j].elementName;
            fileStoreBuffer[j].elementType = fileStoreBuffer[j + 1].elementType;
            fileStoreBuffer[j].elementName = fileStoreBuffer[j + 1].elementName;
            fileStoreBuffer[j + 1].elementType = storeType;
            fileStoreBuffer[j + 1].elementName = storeName;
            swapHappened = 1;
          }
        }
        if (swapHappened == 0) break;
      }
    }

    // Force 64 char mode, clear screen and display header
    clearScreen ();
    displayStringXY ("Navigate: UP/DOWN, load: ENTER, upper dir: CLEAR, exit: BREAK  ", 0, 0);
    displayStringXY ("== Type = Name == DIR:                                      ===", 0, 1);
    displayStringXY (actualDirectory, 23, 1);
    displayStringXY ("=>                                                             ", 0, 2);
    //                1234567890123456789012345678901234567890123456789012345678901234
    // Display type and Names
    for (i = selectedElement; i <= selectedElement + 12; i++) {
      displayStringXY (fileStoreBuffer[i].elementType, 3, i - selectedElement + 2);
      displayStringXY (fileStoreBuffer[i].elementName.toUpperCase(), 10, i - selectedElement + 2);
      if (i == elementCounter) break;
    }

    keyboardBuffer=0x00;
    while ( keyboardBuffer==0x00 ) { 
      keyboardBuffer=keyboardRead(150);
    }

    // ENTER CHDIR or load the file
    if (keyboardBuffer == ENTER) {
      String filename = actualDirectory + fileStoreBuffer[selectedElement].elementName;

      if (fileStoreBuffer[selectedElement].elementType == "DIR ") {    // If directory set new actual dir
        workingDirectory.close();
        workingDirectory = SD.open(filename.c_str());
        actualDirectory = filename + "/";
        itIsANewDir = 1;                                        // Force re-read of directory
        selectedElement = 0;                                    // Reset to the first element in directory
      } 
      
      else {                                                  // Not directory -> Load the file (cas loader takes care if the format is fine)
        int fileNameLenght = strlen(filename.c_str());
        String imageFilename=filename.toUpperCase();
        if (imageFilename.substring (fileNameLenght - 4) == ".CAS" && floppyDiskEnabled== false) {    // CAS file handling
          i = copyCasToMemory(imageFilename);
          if (i == 0x01) return 0x01c9;
          if (i > VIDEO_RAM_END) return i;
        }
        
        // Disk image mounting
        if (imageFilename.substring (fileNameLenght - 4) == ".DSK" && floppyDiskEnabled== true) {
          displayStringXY ("++++++++++++++++++++", 10, 7);
          displayStringXY ("+ Select drive 0-3 +", 10, 8);
          displayStringXY ("+    Exit with 4   +", 10, 9);
          displayStringXY ("++++++++++++++++++++", 10, 10);

          keyboardBuffer=0x00;
          while ( !(keyboardBuffer>='0' && keyboardBuffer <='4') )
            keyboardBuffer=keyboardRead(150);

          if (keyboardBuffer<'4') { // Mount and save config
            if ( openDiskFileByName( imageFilename, keyboardBuffer-'0' ) )
              fd1771SaveConfig();
            return 0;
          }        
          itIsANewDir = 1;
        }
        
        if (imageFilename.substring (fileNameLenght - 4) == ".ROM" && selectROMFile == true) {
          writeStringToFile (DEFAULT_ROM, imageFilename);
          return 0;
        }
      }
    }

    // CLEAR = cd back to upper directory
    if (keyboardBuffer  == CLEAR && actualDirectory != "/") {
      actualDirectory = actualDirectory.substring(0, actualDirectory.lastIndexOf("/"));
      actualDirectory = actualDirectory.substring(0, actualDirectory.lastIndexOf("/")) + "/";
      workingDirectory.close();
      workingDirectory = SD.open(actualDirectory.c_str());
      itIsANewDir = 1;                                          // Force re-read of directory
      selectedElement = 0;                                      // Reset to the first element in directory
    }

    // BREAK -> Exit from the loader menu
    if (keyboardBuffer == BREAK) {
      if ( floppyDiskEnabled ) {
        clearScreen ();
        delay(100);
        return 0;
      }
      return 0x01c9;
    }
    
    // Up -> Step one element up if possible
    if (keyboardBuffer == UP ) {
      if (selectedElement > 0) selectedElement--;
    }
    
    //DOWN -> Step one element down if possible
    if (keyboardBuffer == DOWN ) {
      if (selectedElement < elementCounter) selectedElement++;
    }
  }
}
