/*
    Zilog Z80 emulator running on a Teensy 4.1. The board fits into Z80 socket
    The aim is to speed up and expand old computers.
    Based on    :  MCLZ8.c, please find Author and Copyright information in MCLZ8.copyright

    Original author of MCLZ80   :   Ted Fried, MicroCore Labs
    Creation                    :   20/04/2022
    Links                       :   https://github.com/MicroCoreLabs/Projects/tree/master/MCLZ8
                                    https://microcorelabs.wordpress.com/author/microcorelabs/
                                      
    ==================================
      Revision 1
      Author        : Ted Fried, MicroCore Labs
      Creation      : 4/20/2022

      Revision 2
      Author        : frescho, frescho.hu
      Modification  : 20/4/2022
      Description   : Reorganised and split code to make easier implementation of new machines
*/


#ifndef _MCL_Z80_h
#define _MCL_Z80_h

// Z80 PC register, It is defined here as it must be reached from everywhere
extern uint16_t register_pc;

//  Use it to setup Teensy board pins after reset or power up to base state
void setupTeensyPins(void);

//  Call it to set registers and CPU emulation to defults after reset or power on.
void initAfterReset(void);
//  Call it to check reset PIN status. It is calling initAfterReset if required
//inline void checkReset(void)  __attribute__((always_inline));
//  Call it to check if there is an interrupt. The function checks if interrupts are enabled and execute accordingly
//inline void checkInterrupts(void)  __attribute__((always_inline));
//  Call the function to execute next command. If it is a multi byte command it is fetching the next part after prefix and acts accordingly
void executeInstruction(void);

//  Use this to write a byte to a given port
//  E.g.: You can use it to set 32 or 64 char on port 0xff
void ioWriteByte(uint8_t, uint8_t );
//  Use the function to read a port addressed by 8 bit
uint8_t ioReadByte(uint8_t);

//  Read/Write a byte from memory
//  It is also used for Memory embedded IO
uint8_t readByte(uint16_t);
uint8_t readByteM1(uint16_t); // This one reads a byte and also invokes a DRAM refresh
void writeByte(uint16_t, uint8_t);

//  It can be used to get HL register value. This register is used by BASIC to point to a string
//  Example: I use it to get the parameter of LOAD basic command in loadCommand function
uint16_t getHLregister (void);

#endif
