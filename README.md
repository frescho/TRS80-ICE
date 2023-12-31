# TRS80-ICE

## What is TRS80-ICE?

TRS80-ICE is an in circuit hardware emulator for TRS-80 Model 1 and its clones. It is based on Teensy 4.1 microcotroller board and all the functionalities are based on software. It has been started as a fork of [Micro Core Labs MCLZ8](https://github.com/MicroCoreLabs/Projects/tree/master/MCLZ8) and hardware wise it is still the same, but the software part was expanded heavily. Main functionalities:

- Z80 pin compatible in-circuit hardware emulator
- Z80 emulation is correct in speed aspect, but not 100% machine cycle accurate.
- It is possible to load different ROM versions from SD card
- RAM expansion based on Teensy internal memory
- Floppy emulation: JV1 floppy images can be stored on SD card. FDC1771 code is based on [calphool TRS80MXS](https://github.com/calphool/TRS80MXS)
- CAS file load from SD card if FDC is not active
- Turbo mode, RAM and ROM cached in Teensy RAM
- Interactive menu to select ROM, RAM, images etc...
- MTP file access of SD card over USB cable


## License

This program is free software: you can redistribute, partially or fully use and/or modify it. You are also encouraged to modify the code to fit your needs.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
The copyright notice above must be included in all copies or substantial portions of the Software.
Original copyright notice for parts based on MCL (Z80 emulation) or calphtool (FDC part) must be included:

 - MCLZ80: for deatils and copyrights please check MCLZ8.copyright
 - calphool TRS80MXS: for details and copyrights please check fd1771.h


## How to build the hardware?

- Order or source any other way the PCB
- Solder level shifters
  ![MCL board with level shifters](https://github.com/frescho/TRS80-ICE/blob/main/pictures/TRS80_ICE_board.jpg)
- Solder Teensy 4.1
- Solder pins and solder it directly to TRS-80 model 1. Clones may have enough room to plug in the emulator directly to CPU socket.
   ![MCL board ready to use](https://github.com/frescho/TRS80-ICE/blob/main/pictures/TRS80_ICE.jpg)


## How to install firmware?

In order to compile in Arduino IDE you need the following steps:

1. Add Teensy to **Settings / Additional boards manager URLs** URL may change, please on Teensy official page if the following is not working:  (https://www.pjrc.com/teensy/package_teensy_index.json)
   ![Additional board](https://github.com/frescho/TRS80-ICE/blob/main/pictures/arduino_IDE_additional_board.jpg)
2. Install Teensy under **Tools / Board / Boards Manager** Search for Teensy and install it, right now the actual version is 1.58.1
   ![Additional board](https://github.com/frescho/TRS80-ICE/blob/main/pictures/arduino_IDE_board_manager.jpg)
4. Install MTP library for Arduino IDE (e.g.: /Users/frescho/Library/Arduino15/libraries/) Please refer to Arduino IDE documentation for exact location. [Working fork](https://github.com/frescho/MTP_t4/tree/master) of MTP library.
5. Connect to the USB cable. Make sure that you do not turn on the HT1080Z at the same time.
6. Set the board in the IDE under **Tools**, don't forget to select Port
   ![Teensy settings](https://github.com/frescho/TRS80-ICE/blob/main/pictures/arduino_IDE_Teensy_settings.jpg)
8. Upload the firmware to the ontroller. If it is already connected to the Z80 socket it may boot after install even if it is powered only from USB cable. It is not recommended as it may damage 4016 RAM chips.

## SD card content

Please rename the file in SD folder and try it with 7zip or any other program...

## How to install?

If firmware is ready and you have the SD card just replace the original Z80 with it. TRS-80 has lack of space, you need to seat the Teensy as low as possible, but it is best if you solder it directly to the motherboard. Videogenie/HT-1080Z is not so nice as the voltage regulator is blocking the USB port, so MTP won't work. 

## How to use it?

Please find [this youtube video](https://youtu.be/LCopyd4x9qo) about it. Also the code contains more details about TRS-80 hardware as well as other things. 

### Acceleration mode
 
   0x0 - All external memory accesses Machine works as a not expanded TRS-80 Model 1. Acceleration can't be turned on from basic

   0x1 - (DEFAULT) Reads and writes are cycle accurate using Teensy internal memory and writes passing through to machine's RAM

   0x2 - Reads accelerated using Teensy internal memory, but writes are cycle accurate and pass through to motherboard

   0x3 - All read and write accesses use accelerated Teensy internal memory wherever it is possible

   0x4 - For HW testing ROM shadowed by Teensy internal RAM otherwise equal to 0x0
