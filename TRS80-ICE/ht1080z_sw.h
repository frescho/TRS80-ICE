#ifndef _HT1080Z_h
#define _HT1080Z_h

// Used for MTP file transfer
#define SD_MOSI 11
#define SD_MISO 12
#define SD_SCK  13
#define SPI_SPEED SD_SCK_MHZ(33)  // adjust to sd card 

// Used to enable/disable FDC
#define FLOPPY_IMAGE_CONFIG "/config/images.cfg"
#define DEFAULT_ROM "/config/rom.cfg"
#define DEFAULT_RAM "/config/ram.cfg"
extern bool floppyDiskEnabled;

//  A menu implemented during startup. Can be invoked by pressing space
//  Also set basic parameters if not called, such as FDC support etc.
void bootMenu();

// Display a menu where you can load CAS files and mount disk images
uint16_t BasicCmdCommand (void);

// Called from BASIC to load CAS files
uint16_t BasicLoadCommand (void);

// Init the SD card
bool initSD(void);

#endif
