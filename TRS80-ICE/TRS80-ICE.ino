/*
      Zilog Z80 emulator for HT-1080Z/Videogenie TRS-80 clones
      Code is based on:
        - MCLZ80, for deatils and copyrights please check MCLZ8.copyright
        - calphool TRS80MSX, for details and copyrights please check fd1771.h
      
      Main functionalities:
        - Z80 pin compatible replacement
        - Multiple turbo modes using internal RAM to shadow ROM/RAM reads/writes
        - Boot menu to load diag ROM // GPL v2 license Credits and source: https://github.com/misterblack1/trs80-diagnosticrom
        - CMD command can be invoked for menu based CAS loader form SD card.

      HT1080-Z author             :   frescho
      Creation                    :   03/02/2023
      Link                        :   https://frescho.hu
*/

#include <stdint.h>
#include "mcl_Z80.h"
#include "ht1080z_hw.h"
#include "ht1080z_sw.h"

extern uint16_t register_pc;    // PC register, needed to be able to rewrite for CAS loader, it is used by mcl_z80

// Setup Teensy 4.1 IO's
void setup() {
  setupTeensyPins();
  bootMenu ();
  // Handle power on as a reset
  initAfterReset();
}

void loop() {
  // Call MCL_Z80 to execute instruction in an infinite loop
  executeInstruction();
}
