/*
    FD1771 Floppy controller emulator code running on Arduino.
    Please find below original Author and Copyright information
    Based on    :  calphool TRS80MSX (https://github.com/calphool/TRS80MXS)
    
    Revision 1
    Author        : frescho, frescho.hu
    Modification  : 20/4/2022
    Description   : Reorganised, reworked and expanded to run on the same Teensy board as MCL_Z8
  
    Copyright (c) 2019 JMR, 
    
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#define IN 0
#define OUT 1

// type 1 status bits
#define BUSY 0x01
#define INDEXHOLE 0x02
#define TRACKZERO 0x04
#define CRCERR 0x08
#define SEEKERR 0x10
#define HEADENGAGED 0x20
#define WRITEPROT 0x40
#define NOTREADY 0x80

// read status bits
#define DRQ 0x02
#define LOSTDATA 0x04
#define NOTFND 0x10
#define FA 0x20
#define F9 0x40
#define F8 0x60
#define FB 0x00

// write status bits
#define WRITEFAULT 0x20


#define CMD_RESTORE 0x00
#define CMD_SEEK    0x10
#define CMD_STEP    0x20
#define CMD_STEPIN  0x40
#define CMD_STEPOUT 0x60

#define CMD_READ    0x80
#define CMD_WRITE   0xA0

#define CMD_READ_ADDR 0xC4
#define CMD_READ_TRK  0xE4
#define CMD_WRITE_TRK 0xF4

#define CMD_FORCE_INTERRUPT 0xD0

#define CMD_RESTORE_MASK 0xF0
#define CMD_SEEK_MASK 0xF0
#define CMD_STEP_MASK 0xE0
#define CMD_STEPIN_MASK 0xE0
#define CMD_STEPOUT_MASK 0xE0
#define CMD_READ_MASK 0xE0
#define CMD_WRITE_MASK 0xE0
#define CMD_READ_ADDR_MASK 0xFF
#define CMD_READ_TRK_MASK 0xFE
#define CMD_WRITE_TRK_MASK 0xF0
#define CMD_FORCE_INTERRUPT_MASK 0xF0

extern bool floppyDiskEnabled;

// Initialise the fd1771. /config/images.cfg file on SD card contains image list for drive 0-3
void fd1771Setup();
// Use it to mount new image to one of the drives
int openDiskFileByName(String, int);
// Save currently mounted images to the config file
void fd1771SaveConfig();

// Read and write the FDC registers
uint8_t floppyDiskControllerRead(uint16_t);
void floppyDiskControllerWrite(uint16_t, uint8_t);
