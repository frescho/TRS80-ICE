#include <Arduino.h>
#include "z80_teensy_pins.h"
#include "z80_registers.h"
#include "ht1080z_hw.h"
#include "mcl_Z80.h"


inline void opcode_0xDD()  __attribute__((always_inline));
inline void opcode_0xFD()  __attribute__((always_inline));
inline void opcode_0x00()  __attribute__((always_inline));
inline void opcode_0xC5()  __attribute__((always_inline));
inline void opcode_0xD5()  __attribute__((always_inline));
inline void opcode_0xE5()  __attribute__((always_inline));
inline void opcode_0xF5()  __attribute__((always_inline));
inline void opcode_0xF1()  __attribute__((always_inline));
inline void opcode_0xC1()  __attribute__((always_inline));
inline void opcode_0xD1()  __attribute__((always_inline));
inline void opcode_0xE1()  __attribute__((always_inline));
inline void opcode_0x3F()  __attribute__((always_inline));
inline void opcode_0x2F()  __attribute__((always_inline));
inline void opcode_0x37()  __attribute__((always_inline));
inline void opcode_0xED46()  __attribute__((always_inline));
inline void opcode_0xED56()  __attribute__((always_inline));
inline void opcode_0xED5E()  __attribute__((always_inline));
inline void opcode_0xFB()  __attribute__((always_inline));
inline void opcode_0xF3()  __attribute__((always_inline));
inline void opcode_0x08()  __attribute__((always_inline));
inline void opcode_0xEB()  __attribute__((always_inline));
inline void opcode_0xD9()  __attribute__((always_inline));
inline void opcode_0xE3()  __attribute__((always_inline));
inline void Jump_Not_Taken8()  __attribute__((always_inline));
inline void Jump_Not_Taken16()  __attribute__((always_inline));
inline void Jump_Taken8()  __attribute__((always_inline));
inline void Jump_Taken16()  __attribute__((always_inline));
inline void opcode_0x18()  __attribute__((always_inline)); // jr *    - Disp8
inline void opcode_0x20()  __attribute__((always_inline));
inline void opcode_0x28()  __attribute__((always_inline));
inline void opcode_0x30()  __attribute__((always_inline));
inline void opcode_0x38()  __attribute__((always_inline));
inline void opcode_0x10()  __attribute__((always_inline));
inline void opcode_0xC2()  __attribute__((always_inline));
inline void opcode_0xCA()  __attribute__((always_inline));
inline void opcode_0xD2()  __attribute__((always_inline));
inline void opcode_0xDA()  __attribute__((always_inline));
inline void opcode_0xE2()  __attribute__((always_inline));
inline void opcode_0xEA()  __attribute__((always_inline));
inline void opcode_0xF2()  __attribute__((always_inline));
inline void opcode_0xFA()  __attribute__((always_inline));
inline void opcode_0xC3()  __attribute__((always_inline));
inline void opcode_0xE9()  __attribute__((always_inline));
inline void opcode_0xC4()  __attribute__((always_inline));
inline void opcode_0xCC()  __attribute__((always_inline));
inline void opcode_0xD4()  __attribute__((always_inline));
inline void opcode_0xDC()  __attribute__((always_inline));
inline void opcode_0xE4()  __attribute__((always_inline));
inline void opcode_0xEC()  __attribute__((always_inline));
inline void opcode_0xF4()  __attribute__((always_inline));
inline void opcode_0xFC()  __attribute__((always_inline));
inline void opcode_0xCD()  __attribute__((always_inline));
inline void opcode_0xC9()  __attribute__((always_inline));
inline void opcode_0xC0()  __attribute__((always_inline));
inline void opcode_0xC8()  __attribute__((always_inline));
inline void opcode_0xD0()  __attribute__((always_inline));
inline void opcode_0xD8()  __attribute__((always_inline));
inline void opcode_0xE0()  __attribute__((always_inline));
inline void opcode_0xE8()  __attribute__((always_inline));
inline void opcode_0xF0()  __attribute__((always_inline));
inline void opcode_0xF8()  __attribute__((always_inline));
inline void opcode_0xED45()  __attribute__((always_inline));
inline void opcode_0xED4D()  __attribute__((always_inline));
inline void opcode_0xC7()  __attribute__((always_inline));
inline void opcode_0xD7()  __attribute__((always_inline));
inline void opcode_0xE7()  __attribute__((always_inline));
inline void opcode_0xF7()  __attribute__((always_inline));
inline void opcode_0xCF()  __attribute__((always_inline));
inline void opcode_0xDF()  __attribute__((always_inline));
inline void opcode_0xEF()  __attribute__((always_inline));
inline void opcode_0xFF()  __attribute__((always_inline));
inline void opcode_0x01()  __attribute__((always_inline));
inline void opcode_0x11()  __attribute__((always_inline));
inline void opcode_0x0A()  __attribute__((always_inline));
inline void opcode_0x0E()  __attribute__((always_inline));
inline void opcode_0x1E()  __attribute__((always_inline));
inline void opcode_0x1A()  __attribute__((always_inline));
inline void opcode_0x21()  __attribute__((always_inline));
inline void opcode_0x22()  __attribute__((always_inline));
inline void opcode_0x2A()  __attribute__((always_inline));
inline void opcode_0x06()  __attribute__((always_inline));
inline void opcode_0x16()  __attribute__((always_inline));
inline void opcode_0x26()  __attribute__((always_inline));
inline void opcode_0x2E()  __attribute__((always_inline));
inline void opcode_0x31()  __attribute__((always_inline));
inline void opcode_0x32()  __attribute__((always_inline));
inline void opcode_0x36()  __attribute__((always_inline));
inline void opcode_0x3A()  __attribute__((always_inline));
inline void opcode_0x3E()  __attribute__((always_inline));
inline void opcode_0x40()  __attribute__((always_inline));
inline void opcode_0x41()  __attribute__((always_inline));
inline void opcode_0x42()  __attribute__((always_inline));
inline void opcode_0x43()  __attribute__((always_inline));
inline void opcode_0x44()  __attribute__((always_inline));
inline void opcode_0x45()  __attribute__((always_inline));
inline void opcode_0x46()  __attribute__((always_inline));
inline void opcode_0x47()  __attribute__((always_inline));
inline void opcode_0x48()  __attribute__((always_inline));
inline void opcode_0x49()  __attribute__((always_inline));
inline void opcode_0x4A()  __attribute__((always_inline));
inline void opcode_0x4B()  __attribute__((always_inline));
inline void opcode_0x4C()  __attribute__((always_inline));
inline void opcode_0x4D()  __attribute__((always_inline));
inline void opcode_0x4E()  __attribute__((always_inline));
inline void opcode_0x4F()  __attribute__((always_inline));
inline void opcode_0x50()  __attribute__((always_inline));
inline void opcode_0x51()  __attribute__((always_inline));
inline void opcode_0x52()  __attribute__((always_inline));
inline void opcode_0x53()  __attribute__((always_inline));
inline void opcode_0x54()  __attribute__((always_inline));
inline void opcode_0x55()  __attribute__((always_inline));
inline void opcode_0x56()  __attribute__((always_inline));
inline void opcode_0x57()  __attribute__((always_inline));
inline void opcode_0x58()  __attribute__((always_inline));
inline void opcode_0x59()  __attribute__((always_inline));
inline void opcode_0x5A()  __attribute__((always_inline));
inline void opcode_0x5B()  __attribute__((always_inline));
inline void opcode_0x5C()  __attribute__((always_inline));
inline void opcode_0x5D()  __attribute__((always_inline));
inline void opcode_0x5E()  __attribute__((always_inline));
inline void opcode_0x5F()  __attribute__((always_inline));
inline void opcode_0x60()  __attribute__((always_inline));
inline void opcode_0x61()  __attribute__((always_inline));
inline void opcode_0x62()  __attribute__((always_inline));
inline void opcode_0x63()  __attribute__((always_inline));
inline void opcode_0x64()  __attribute__((always_inline));
inline void opcode_0x65()  __attribute__((always_inline));
inline void opcode_0x66()  __attribute__((always_inline));
inline void opcode_0x67()  __attribute__((always_inline));
inline void opcode_0x68()  __attribute__((always_inline));
inline void opcode_0x69()  __attribute__((always_inline));
inline void opcode_0x6A()  __attribute__((always_inline));
inline void opcode_0x6B()  __attribute__((always_inline));
inline void opcode_0x6C()  __attribute__((always_inline));
inline void opcode_0x6D()  __attribute__((always_inline));
inline void opcode_0x6E()  __attribute__((always_inline));
inline void opcode_0x6F()  __attribute__((always_inline));
inline void opcode_0x02()  __attribute__((always_inline));
inline void opcode_0x12()  __attribute__((always_inline));
inline void opcode_0x70()  __attribute__((always_inline));
inline void opcode_0x71()  __attribute__((always_inline));
inline void opcode_0x72()  __attribute__((always_inline));
inline void opcode_0x73()  __attribute__((always_inline));
inline void opcode_0x74()  __attribute__((always_inline));
inline void opcode_0x75()  __attribute__((always_inline));
inline void opcode_0x77()  __attribute__((always_inline));
inline void opcode_0x78()  __attribute__((always_inline));
inline void opcode_0x79()  __attribute__((always_inline));
inline void opcode_0x7A()  __attribute__((always_inline));
inline void opcode_0x7B()  __attribute__((always_inline));
inline void opcode_0x7C()  __attribute__((always_inline));
inline void opcode_0x7D()  __attribute__((always_inline));
inline void opcode_0x7E()  __attribute__((always_inline));
inline void opcode_0x7F()  __attribute__((always_inline));
inline void opcode_0xF9()  __attribute__((always_inline));
inline void opcode_0xED43()  __attribute__((always_inline));
inline void opcode_0xED53()  __attribute__((always_inline));
inline void opcode_0xED63()  __attribute__((always_inline));
inline void opcode_0xED73()  __attribute__((always_inline));
inline void opcode_0xED4B()  __attribute__((always_inline));
inline void opcode_0xED5B()  __attribute__((always_inline));
inline void opcode_0xED6B()  __attribute__((always_inline));
inline void opcode_0xED7B()  __attribute__((always_inline));
inline void opcode_0xED47()  __attribute__((always_inline));
inline void opcode_0xED57()  __attribute__((always_inline));
inline void opcode_0xED4F()  __attribute__((always_inline));
inline void opcode_0xED5F()  __attribute__((always_inline));
inline void Flags_Boolean()  __attribute__((always_inline));
inline void opcode_0xA0()  __attribute__((always_inline));
inline void opcode_0xA1()  __attribute__((always_inline));
inline void opcode_0xA2()  __attribute__((always_inline));
inline void opcode_0xA3()  __attribute__((always_inline));
inline void opcode_0xA4()  __attribute__((always_inline));
inline void opcode_0xA5()  __attribute__((always_inline));
inline void opcode_0xA6()  __attribute__((always_inline));
inline void opcode_0xA7()  __attribute__((always_inline));
inline void opcode_0xE6()  __attribute__((always_inline));
inline void opcode_0xA8()  __attribute__((always_inline));
inline void opcode_0xA9()  __attribute__((always_inline));
inline void opcode_0xAA()  __attribute__((always_inline));
inline void opcode_0xAB()  __attribute__((always_inline));
inline void opcode_0xAC()  __attribute__((always_inline));
inline void opcode_0xAD()  __attribute__((always_inline));
inline void opcode_0xAE()  __attribute__((always_inline));
inline void opcode_0xAF()  __attribute__((always_inline));
inline void opcode_0xEE()  __attribute__((always_inline));
inline void opcode_0xB0()  __attribute__((always_inline));
inline void opcode_0xB1()  __attribute__((always_inline));
inline void opcode_0xB2()  __attribute__((always_inline));
inline void opcode_0xB3()  __attribute__((always_inline));
inline void opcode_0xB4()  __attribute__((always_inline));
inline void opcode_0xB5()  __attribute__((always_inline));
inline void opcode_0xB6()  __attribute__((always_inline));
inline void opcode_0xB7()  __attribute__((always_inline));
inline void opcode_0xF6()  __attribute__((always_inline));
inline void opcode_0x09()  __attribute__((always_inline));
inline void opcode_0x19()  __attribute__((always_inline));
inline void opcode_0x29()  __attribute__((always_inline));
inline void opcode_0x39()  __attribute__((always_inline));
inline void opcode_0xC6()  __attribute__((always_inline));
inline void opcode_0x87()  __attribute__((always_inline));
inline void opcode_0x80()  __attribute__((always_inline));
inline void opcode_0x81()  __attribute__((always_inline));
inline void opcode_0x82()  __attribute__((always_inline));
inline void opcode_0x83()  __attribute__((always_inline));
inline void opcode_0x84()  __attribute__((always_inline));
inline void opcode_0x85()  __attribute__((always_inline));
inline void opcode_0x86()  __attribute__((always_inline));
inline void opcode_0xED4A()  __attribute__((always_inline));
inline void opcode_0xED5A()  __attribute__((always_inline));
inline void opcode_0xED6A()  __attribute__((always_inline));
inline void opcode_0xED7A()  __attribute__((always_inline));
inline void opcode_0xCE()  __attribute__((always_inline));
inline void opcode_0x8F()  __attribute__((always_inline));
inline void opcode_0x88()  __attribute__((always_inline));
inline void opcode_0x89()  __attribute__((always_inline));
inline void opcode_0x8A()  __attribute__((always_inline));
inline void opcode_0x8B()  __attribute__((always_inline));
inline void opcode_0x8C()  __attribute__((always_inline));
inline void opcode_0x8D()  __attribute__((always_inline));
inline void opcode_0x8E()  __attribute__((always_inline));
inline void opcode_0xED44()  __attribute__((always_inline));
inline void opcode_0xD6()  __attribute__((always_inline));
inline void opcode_0x97()  __attribute__((always_inline));
inline void opcode_0x90()  __attribute__((always_inline));
inline void opcode_0x91()  __attribute__((always_inline));
inline void opcode_0x92()  __attribute__((always_inline));
inline void opcode_0x93()  __attribute__((always_inline));
inline void opcode_0x94()  __attribute__((always_inline));
inline void opcode_0x95()  __attribute__((always_inline));
inline void opcode_0x96()  __attribute__((always_inline));
inline void opcode_0xED42()  __attribute__((always_inline));
inline void opcode_0xED52()  __attribute__((always_inline));
inline void opcode_0xED62()  __attribute__((always_inline));
inline void opcode_0xED72()  __attribute__((always_inline));
inline void opcode_0xDE()  __attribute__((always_inline));
inline void opcode_0x9F()  __attribute__((always_inline));
inline void opcode_0x98()  __attribute__((always_inline));
inline void opcode_0x99()  __attribute__((always_inline));
inline void opcode_0x9A()  __attribute__((always_inline));
inline void opcode_0x9B()  __attribute__((always_inline));
inline void opcode_0x9C()  __attribute__((always_inline));
inline void opcode_0x9D()  __attribute__((always_inline));
inline void opcode_0x9E()  __attribute__((always_inline));
inline void opcode_0xFE()  __attribute__((always_inline));
inline void opcode_0xBF()  __attribute__((always_inline));
inline void opcode_0xB8()  __attribute__((always_inline));
inline void opcode_0xB9()  __attribute__((always_inline));
inline void opcode_0xBA()  __attribute__((always_inline));
inline void opcode_0xBB()  __attribute__((always_inline));
inline void opcode_0xBC()  __attribute__((always_inline));
inline void opcode_0xBD()  __attribute__((always_inline));
inline void opcode_0xBE()  __attribute__((always_inline));
inline void opcode_0x33()  __attribute__((always_inline));
inline void opcode_0x03()  __attribute__((always_inline));
inline void opcode_0x13()  __attribute__((always_inline));
inline void opcode_0x23()  __attribute__((always_inline));
inline void opcode_0x3C()  __attribute__((always_inline));
inline void opcode_0x04()  __attribute__((always_inline));
inline void opcode_0x0C()  __attribute__((always_inline));
inline void opcode_0x14()  __attribute__((always_inline));
inline void opcode_0x1C()  __attribute__((always_inline));
inline void opcode_0x24()  __attribute__((always_inline));
inline void opcode_0x2C()  __attribute__((always_inline));
inline void opcode_0x34()  __attribute__((always_inline));
inline void opcode_0x3B()  __attribute__((always_inline));
inline void opcode_0x0B()  __attribute__((always_inline));
inline void opcode_0x1B()  __attribute__((always_inline));
inline void opcode_0x2B()  __attribute__((always_inline));
inline void opcode_0x3D()  __attribute__((always_inline));
inline void opcode_0x05()  __attribute__((always_inline));
inline void opcode_0x0D()  __attribute__((always_inline));
inline void opcode_0x15()  __attribute__((always_inline));
inline void opcode_0x1D()  __attribute__((always_inline));
inline void opcode_0x25()  __attribute__((always_inline));
inline void opcode_0x2D()  __attribute__((always_inline));
inline void opcode_0x35()  __attribute__((always_inline));
inline void opcode_0xDB()  __attribute__((always_inline));
inline void opcode_0xED78()  __attribute__((always_inline));
inline void opcode_0xED40()  __attribute__((always_inline));
inline void opcode_0xED48()  __attribute__((always_inline));
inline void opcode_0xED50()  __attribute__((always_inline));
inline void opcode_0xED58()  __attribute__((always_inline));
inline void opcode_0xED60()  __attribute__((always_inline));
inline void opcode_0xED68()  __attribute__((always_inline));
inline void opcode_0xED70()  __attribute__((always_inline));
inline void opcode_0xD3()  __attribute__((always_inline));
inline void opcode_0xED79()  __attribute__((always_inline));
inline void opcode_0xED41()  __attribute__((always_inline));
inline void opcode_0xED49()  __attribute__((always_inline));
inline void opcode_0xED51()  __attribute__((always_inline));
inline void opcode_0xED59()  __attribute__((always_inline));
inline void opcode_0xED61()  __attribute__((always_inline));
inline void opcode_0xED69()  __attribute__((always_inline));
inline void opcode_0xED71()  __attribute__((always_inline));
inline void opcode_0x07()  __attribute__((always_inline));
inline void opcode_0xCB00()  __attribute__((always_inline));
inline void opcode_0xCB01()  __attribute__((always_inline));
inline void opcode_0xCB02()  __attribute__((always_inline));
inline void opcode_0xCB03()  __attribute__((always_inline));
inline void opcode_0xCB04()  __attribute__((always_inline));
inline void opcode_0xCB05()  __attribute__((always_inline));
inline void opcode_0xCB07()  __attribute__((always_inline));
inline void opcode_0xCB06()  __attribute__((always_inline));
inline void opcode_0x0F()  __attribute__((always_inline));
inline void opcode_0xCB08()  __attribute__((always_inline));
inline void opcode_0xCB09()  __attribute__((always_inline));
inline void opcode_0xCB0A()  __attribute__((always_inline));
inline void opcode_0xCB0B()  __attribute__((always_inline));
inline void opcode_0xCB0C()  __attribute__((always_inline));
inline void opcode_0xCB0D()  __attribute__((always_inline));
inline void opcode_0xCB0F()  __attribute__((always_inline));
inline void opcode_0xCB0E()  __attribute__((always_inline));
inline void opcode_0x17()  __attribute__((always_inline));
inline void opcode_0xCB10()  __attribute__((always_inline));
inline void opcode_0xCB11()  __attribute__((always_inline));
inline void opcode_0xCB12()  __attribute__((always_inline));
inline void opcode_0xCB13()  __attribute__((always_inline));
inline void opcode_0xCB14()  __attribute__((always_inline));
inline void opcode_0xCB15()  __attribute__((always_inline));
inline void opcode_0xCB17()  __attribute__((always_inline));
inline void opcode_0xCB16()  __attribute__((always_inline));
inline void opcode_0x1F()  __attribute__((always_inline));
inline void opcode_0xCB18()  __attribute__((always_inline));
inline void opcode_0xCB19()  __attribute__((always_inline));
inline void opcode_0xCB1A()  __attribute__((always_inline));
inline void opcode_0xCB1B()  __attribute__((always_inline));
inline void opcode_0xCB1C()  __attribute__((always_inline));
inline void opcode_0xCB1D()  __attribute__((always_inline));
inline void opcode_0xCB1F()  __attribute__((always_inline));
inline void opcode_0xCB1E()  __attribute__((always_inline));
inline void opcode_0xCB20()  __attribute__((always_inline));
inline void opcode_0xCB21()  __attribute__((always_inline));
inline void opcode_0xCB22()  __attribute__((always_inline));
inline void opcode_0xCB23()  __attribute__((always_inline));
inline void opcode_0xCB24()  __attribute__((always_inline));
inline void opcode_0xCB25()  __attribute__((always_inline));
inline void opcode_0xCB27()  __attribute__((always_inline));
inline void opcode_0xCB26()  __attribute__((always_inline));
inline void opcode_0xCB28()  __attribute__((always_inline));
inline void opcode_0xCB29()  __attribute__((always_inline));
inline void opcode_0xCB2A()  __attribute__((always_inline));
inline void opcode_0xCB2B()  __attribute__((always_inline));
inline void opcode_0xCB2C()  __attribute__((always_inline));
inline void opcode_0xCB2D()  __attribute__((always_inline));
inline void opcode_0xCB2F()  __attribute__((always_inline));
inline void opcode_0xCB2E()  __attribute__((always_inline));
inline void opcode_0xCB30()  __attribute__((always_inline));
inline void opcode_0xCB31()  __attribute__((always_inline));
inline void opcode_0xCB32()  __attribute__((always_inline));
inline void opcode_0xCB33()  __attribute__((always_inline));
inline void opcode_0xCB34()  __attribute__((always_inline));
inline void opcode_0xCB35()  __attribute__((always_inline));
inline void opcode_0xCB37()  __attribute__((always_inline));
inline void opcode_0xCB36()  __attribute__((always_inline));
inline void opcode_0xCB38()  __attribute__((always_inline));
inline void opcode_0xCB39()  __attribute__((always_inline));
inline void opcode_0xCB3A()  __attribute__((always_inline));
inline void opcode_0xCB3B()  __attribute__((always_inline));
inline void opcode_0xCB3C()  __attribute__((always_inline));
inline void opcode_0xCB3D()  __attribute__((always_inline));
inline void opcode_0xCB3F()  __attribute__((always_inline));
inline void opcode_0xCB3E()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_b()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_c()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_d()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_e()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_h()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_l()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_a()  __attribute__((always_inline));
inline void opcode_0xCB_Bit_hl()  __attribute__((always_inline));
inline void opcode_0xCB_Res_b()  __attribute__((always_inline));
inline void opcode_0xCB_Res_c()  __attribute__((always_inline));
inline void opcode_0xCB_Res_d()  __attribute__((always_inline));
inline void opcode_0xCB_Res_e()  __attribute__((always_inline));
inline void opcode_0xCB_Res_h()  __attribute__((always_inline));
inline void opcode_0xCB_Res_l()  __attribute__((always_inline));
inline void opcode_0xCB_Res_a()  __attribute__((always_inline));
inline void opcode_0xCB_Res_hl()  __attribute__((always_inline));
inline void opcode_0xCB_Set_b()  __attribute__((always_inline));
inline void opcode_0xCB_Set_c()  __attribute__((always_inline));
inline void opcode_0xCB_Set_d()  __attribute__((always_inline));
inline void opcode_0xCB_Set_e()  __attribute__((always_inline));
inline void opcode_0xCB_Set_h()  __attribute__((always_inline));
inline void opcode_0xCB_Set_l()  __attribute__((always_inline));
inline void opcode_0xCB_Set_a()  __attribute__((always_inline));
inline void opcode_0xCB_Set_hl()  __attribute__((always_inline));
inline void opcode_0x76()  __attribute__((always_inline));
inline void opcode_0x27()  __attribute__((always_inline));
inline void opcode_0xEDA2()  __attribute__((always_inline));
inline void opcode_0xEDA3()  __attribute__((always_inline));
inline void opcode_0xEDA0()  __attribute__((always_inline));
inline void opcode_0xEDA8()  __attribute__((always_inline));
inline void opcode_0xEDA1()  __attribute__((always_inline));
inline void opcode_0xEDA9()  __attribute__((always_inline));
inline void opcode_0xEDAA()  __attribute__((always_inline));
inline void opcode_0xEDAB()  __attribute__((always_inline));
inline void opcode_0xED67()  __attribute__((always_inline));
inline void opcode_0xED6F()  __attribute__((always_inline));
inline void NMI_Handler()  __attribute__((always_inline));
inline void INTR_Handler()  __attribute__((always_inline));
inline void decode_table_0xCB()  __attribute__((always_inline));
inline void decode_table_0xED()  __attribute__((always_inline));
inline void checkReset()  __attribute__((always_inline));
inline void checkInterrupts()  __attribute__((always_inline));


// --------------------------------------------------------------------------------------------------
// Z80 Base functions
// You may find below bus cycles, READ/WRITE functions and setting CPU to 0 after reset
// --------------------------------------------------------------------------------------------------

// force Teensy to start over from 0
void(* resetTeensy) (void) = 0; //declare reset function @ address 0

// --------------------------------------------------------------------------------------------------
// Pin setup
// --------------------------------------------------------------------------------------------------

void setupTeensyPins()
{
  pinMode(PIN_RESET, INPUT);
  pinMode(PIN_CLK, INPUT);
  pinMode(PIN_NMI, INPUT);
  pinMode(PIN_INTR, INPUT);
  pinMode(PIN_WAIT, INPUT);

  pinMode(PIN_M1, OUTPUT);
  pinMode(PIN_HALT, OUTPUT);
  pinMode(PIN_RD, OUTPUT);
  pinMode(PIN_WR, OUTPUT);
  pinMode(PIN_MREQ, OUTPUT);
  pinMode(PIN_IOREQ, OUTPUT);
  pinMode(PIN_RFSH, OUTPUT);

  pinMode(PIN_ADDR15, OUTPUT);
  pinMode(PIN_ADDR14, OUTPUT);
  pinMode(PIN_ADDR13, OUTPUT);
  pinMode(PIN_ADDR12, OUTPUT);
  pinMode(PIN_ADDR11, OUTPUT);
  pinMode(PIN_ADDR10, OUTPUT);
  pinMode(PIN_ADDR9, OUTPUT);
  pinMode(PIN_ADDR8, OUTPUT);

  pinMode(PIN_AD7_OUT, OUTPUT);
  pinMode(PIN_AD6_OUT, OUTPUT);
  pinMode(PIN_AD5_OUT, OUTPUT);
  pinMode(PIN_AD4_OUT, OUTPUT);
  pinMode(PIN_AD3_OUT, OUTPUT);
  pinMode(PIN_AD2_OUT, OUTPUT);
  pinMode(PIN_AD1_OUT, OUTPUT);
  pinMode(PIN_AD0_OUT, OUTPUT);
  pinMode(PIN_DATA_OE_n, OUTPUT);
  pinMode(PIN_ADDR_LATCH_n, OUTPUT);

  pinMode(PIN_AD7_IN, INPUT);
  pinMode(PIN_AD6_IN, INPUT);
  pinMode(PIN_AD5_IN, INPUT);
  pinMode(PIN_AD4_IN, INPUT);
  pinMode(PIN_AD3_IN, INPUT);
  pinMode(PIN_AD2_IN, INPUT);
  pinMode(PIN_AD1_IN, INPUT);
  pinMode(PIN_AD0_IN, INPUT);

  digitalWriteFast(PIN_M1, 0x1);
  digitalWriteFast(PIN_HALT, 0x1);
  digitalWriteFast(PIN_RD, 0x1);
  digitalWriteFast(PIN_WR, 0x1);
  digitalWriteFast(PIN_MREQ, 0x1);
  digitalWriteFast(PIN_IOREQ, 0x1);
  digitalWriteFast(PIN_RFSH, 0x1);
  digitalWriteFast(PIN_ADDR_LATCH_n, 0x1);
}

// -------------------------------------------------
// Wait for the CLK rising edge
// -------------------------------------------------
inline void waitForClockRisingEdge()  __attribute__((always_inline));
inline void waitForClockRisingEdge()
{

  while ((GPIO6_DR & 0x08000000) != 0)
  {
  } // First ensure clock is at a low level
  do
  {
    GPIO6_raw_data = GPIO6_DR;
  } while ((GPIO6_raw_data & 0x08000000) == 0); // Then poll for the first instance where clock is not low

  if (debounce_refresh == 1)
  {
    digitalWriteFast(PIN_RFSH, 0x1);
    debounce_refresh = 0;
  }

if (clock_counter == 1) {
  direct_nmi = (GPIO6_raw_data & 0x00010000);
  direct_intr = (GPIO6_raw_data & 0x04000000);
  if (direct_nmi_d != 0 && direct_nmi == 0)
    nmi_latched = 1; // Latch NMI on both CLK edges
  direct_nmi_d = direct_nmi;
}

  return;
}

// -------------------------------------------------
// Wait for the CLK falling edge
// -------------------------------------------------
inline void waitForclockFallingEdge() __attribute__((always_inline));
inline void waitForclockFallingEdge()
{

  if (clock_counter > 0)
    clock_counter--; // Count down clock_counter here at end of each instruction

  while ((GPIO6_DR & 0x08000000) == 0)
  {
  } // First ensure clock is at a high level
  do
  {
  } while ((GPIO6_DR & 0x08000000) != 0); // Then poll for the first instance where clock is not high

  GPIO6_raw_data = GPIO6_DR; // Store slightly-delayed version of GPIO6 in a global register
  direct_wait = (GPIO6_raw_data & 0x01000000);
  direct_reset = (GPIO6_raw_data & 0x02000000);

  return;
}

// -------------------------------------------------
// Z80 BUS Interface Unit simulation
// -------------------------------------------------

uint8_t BIUBusCycle(register uint8_t biu_operation, register uint16_t local_address, register uint8_t local_data)
{
  register uint8_t read_cycle;
  register uint8_t read_data;
  register uint32_t read_data_raw;
  register uint32_t writeback_data7;
  register uint32_t writeback_data8;
  register uint32_t writeback_data9;

  register uint32_t gpio7_out;
  register uint32_t gpio8_out;
  register uint32_t gpio9_out;
  register uint8_t local_address_high;
  register uint8_t local_address_low;
  register uint8_t m1_cycle;
  uint8_t local_mode;

//  noInterrupts();                          // Disable Teensy interupts so the Z80 bus cycle can complete without interruption
  
  if ( biu_operation == OPCODE_READ_M1 ) {
    local_mode=accelerationModeMap[local_address];
    if (local_mode > 1) return internalMemoryRead(local_address);
    m1_cycle = 0;
  } else if ( biu_operation == MEM_WRITE_BYTE ) {
    local_mode=accelerationModeMap[local_address];
    if (local_mode > 1) {
      if (internalMemoryWrite(local_mode, local_address, local_data))  // Need to check 0xEE to make sure video RAM not write cached
        return 0xee;
      }
    m1_cycle = 2;
  } else if ( biu_operation == MEM_READ_BYTE ) {   
    local_mode=accelerationModeMap[local_address];
    if (local_mode > 1) return internalMemoryRead(local_address);
    m1_cycle = 2;
  } else if ( biu_operation == IO_WRITE_BYTE ) {
    local_mode = 0;
    m1_cycle = 2;
    internalPortWrite(local_address, local_data);
  } else if ( biu_operation ==  IO_READ_BYTE ) {
    local_mode = 0;
    m1_cycle = 2;
  } else if ( biu_operation ==   INTERRUPT_ACK ) {
    local_mode=accelerationModeMap[local_address];
    m1_cycle = 0;
  }

  digitalWriteFast(PIN_ADDR_LATCH_n, 0x1); // Allow address to propagate through '373 latch

  // Address phase is common for all bus cycle types - Lower byte of address is multiplexed with data so needs to be externally latched
  // -----------------------------------------------------------------------------------------------------------------------------------------
  waitForClockRisingEdge(); // T1 Rising

  // Pre-calculations before the clock edge was moved after edge to gain speed. 
  // Based on my estimation it will cause timing issue cca. at 10MHz, but that is so far...

  //Calculating and writing GPIO 
  local_address_high = (local_address) >> 8;
  local_address_low = (0x00FF & local_address);

  GPIO7_DR = (0xCFF0E3FC & GPIO7_DR) | m1_cycle | gpio7_high_array[local_address_high] | gpio7_low_array[local_address_low]; 
  GPIO9_DR = (0xFFFFFE1F & GPIO9_DR)| gpio9_high_array[local_address_high] | gpio9_low_array[local_address_low] | 0x80000010;
  GPIO8_DR = (0xFF3FFFFF & GPIO8_DR)| gpio8_high_array[local_address_high];

  if ((biu_operation == OPCODE_READ_M1) || (biu_operation == INTERRUPT_ACK))
      digitalWriteFast(PIN_M1, 0x0);

  read_cycle = (biu_operation & 0x1);

  // Opcode fetch - M1 type - 4 cycles
  // -----------------------------------------------------------------------------
  if (biu_operation == OPCODE_READ_M1)
  {
    waitForclockFallingEdge(); // T1 Falling
    digitalWriteFast(PIN_MREQ, 0x0);
    digitalWriteFast(PIN_RD, 0x0);
    // digitalWriteFast(PIN_ADDR_LATCH_n,0x0);

    waitForclockFallingEdge(); // T2 falling
    while (direct_wait == 0)
    {
      // WAIT STATE MODIFY
      clock_counter++; // Compensate wait state clock counter
      waitForclockFallingEdge(); // T2 Falling wait state, repeated in case of Wait State
    }

    // Pre-calculate before the next clock edge to gain speed
    //
    local_address_high = register_i;
    local_address_low = register_r;
    gpio7_out = gpio7_high_array[local_address_high] | gpio7_low_array[local_address_low];
    gpio8_out = gpio8_high_array[local_address_high];
    gpio9_out = gpio9_high_array[local_address_high] | gpio9_low_array[local_address_low];

    writeback_data7 = (0xCFF0E3FC & GPIO7_DR) | 0x2; // drive M1 high again
    writeback_data8 = (0xFF3FFFFF & GPIO8_DR);
    writeback_data9 = (0xFFFFFE1F & GPIO9_DR);

    waitForClockRisingEdge();
    read_data_raw = GPIO6_raw_data; // T3 Rising   -- Read data sampled on this edge

    // Drive Refresh address
    //
    GPIO9_DR = writeback_data9 | gpio9_out;
    GPIO8_DR = writeback_data8 | gpio8_out;
    GPIO7_DR = writeback_data7 | gpio7_out;

    digitalWriteFast(PIN_MREQ, 0x1);
    digitalWriteFast(PIN_RFSH, 0x0);
    digitalWriteFast(PIN_RD, 0x1);
    digitalWriteFast(PIN_M1, 0x1);

    waitForclockFallingEdge();                          // T3 Falling
    digitalWriteFast(PIN_MREQ, 0x0);                    //
    read_data = read_data_array[(read_data_raw >> 16)]; // Process the Z80 bus data read during T3 Rising, re-arranging bits through read_data_array

    // If reset button is pressed for more than 1s and less than 5s initiate hard reset
    // On HT-1080Z Reset button is connected to Non maskable Interrupt and has an active 0 level
    if ( (GPIO6_raw_data & 0x00010000) != 0x00010000) {
      uint32_t timestamp = millis();
      if ( (timestamp-resetButtonPressed)<5000 && (timestamp-resetButtonPressed)>1000 )
      {
        clearScreen ();
        displayStringXY ("REBOOTING", 30, 10);
        delay (100);
        resetTeensy();
      } else resetButtonPressed=timestamp;
    }

    waitForClockRisingEdge();                           // T4 Rising for interrupt handling
    
    debounce_refresh = 1;                               // Next Rising edge will debounce it
    if (local_mode > 0)                                 // Mode 1 Reads to shadow ROM/RAM
      read_data = internalMemory[local_address];    
      
    waitForclockFallingEdge();  // T4 Falling
    digitalWriteFast(PIN_MREQ, 0x1);
//    interrupts();
    return read_data;
  }

  // Memory Read/Write - 3 cycles
  // -----------------------------------------------------------------------------
  else if ((biu_operation == MEM_READ_BYTE) || (biu_operation == MEM_WRITE_BYTE))
  {
    if (local_mode > 0 && biu_operation == MEM_WRITE_BYTE) internalMemory[local_address] = local_data;
    waitForclockFallingEdge(); // T1 Falling
    digitalWriteFast(PIN_ADDR_LATCH_n, 0x0); 
    digitalWriteFast(PIN_MREQ, 0x0);
    digitalWriteFast(PIN_RD, !read_cycle);

    digitalWriteFast(PIN_AD7_OUT, (local_data & 0x80));
    digitalWriteFast(PIN_AD6_OUT, (local_data & 0x40));
    digitalWriteFast(PIN_AD5_OUT, (local_data & 0x20));
    digitalWriteFast(PIN_AD4_OUT, (local_data & 0x10));
    digitalWriteFast(PIN_AD3_OUT, (local_data & 0x08));
    digitalWriteFast(PIN_AD2_OUT, (local_data & 0x04));
    digitalWriteFast(PIN_AD1_OUT, (local_data & 0x02));
    digitalWriteFast(PIN_AD0_OUT, (local_data & 0x01));
    digitalWriteFast(PIN_DATA_OE_n, read_cycle);

    waitForclockFallingEdge();  // T2 Falling
    digitalWriteFast(PIN_WR, read_cycle); 
    while (direct_wait == 0)  // WAIT STATE MODIFY
    {
    clock_counter++; // Compensate wait state clock counter
    waitForclockFallingEdge();
    }
    
    waitForClockRisingEdge();    // T3 Rising for interrupt handling
    
    waitForclockFallingEdge();    // T3 Falling   -- Read data sampled on this edge
    digitalWriteFast(PIN_MREQ, 0x1); 
    digitalWriteFast(PIN_RD, 0x1);
    digitalWriteFast(PIN_WR, 0x1);
//    interrupts();
    // Mode 1 Reads
    if (local_mode > 0)                                   
      return internalMemory[local_address];

    // Mode 0 read result
    return read_data_array[(GPIO6_raw_data >> 16)]; // Read the Z80 bus data, re-arranging bits through read_data_array
  }

  // IO Read/Write - 3 cycles with one additional wait state
  // -----------------------------------------------------------------------------
  else if ((biu_operation == IO_READ_BYTE) || (biu_operation == IO_WRITE_BYTE))
  {

    waitForclockFallingEdge(); // T1 Falling
    digitalWriteFast(PIN_ADDR_LATCH_n, 0x0); 
    digitalWriteFast(PIN_AD7_OUT, (local_data & 0x80));
    digitalWriteFast(PIN_AD6_OUT, (local_data & 0x40));
    digitalWriteFast(PIN_AD5_OUT, (local_data & 0x20));
    digitalWriteFast(PIN_AD4_OUT, (local_data & 0x10));
    digitalWriteFast(PIN_AD3_OUT, (local_data & 0x08));
    digitalWriteFast(PIN_AD2_OUT, (local_data & 0x04));
    digitalWriteFast(PIN_AD1_OUT, (local_data & 0x02));
    digitalWriteFast(PIN_AD0_OUT, (local_data & 0x01));
    digitalWriteFast(PIN_DATA_OE_n, read_cycle);

    waitForClockRisingEdge(); // T2 Rising
    digitalWriteFast(PIN_IOREQ, 0x0);
    digitalWriteFast(PIN_RD, !read_cycle);
    digitalWriteFast(PIN_WR, read_cycle);

    waitForClockRisingEdge(); // Tw Rising
    waitForclockFallingEdge(); //Tw Falling
    while (direct_wait == 0)
    {
// WAIT STATE MODIFY
clock_counter++; // Compensate wait state clock counter
      waitForclockFallingEdge(); // Tw Falling
    }
    waitForClockRisingEdge();  // T3 Rising for interrupt handling
    waitForclockFallingEdge(); //T3 Falling -- Read data sampled on this edge

    digitalWriteFast(PIN_IOREQ, 0x1);
    digitalWriteFast(PIN_RD, 0x1);
    digitalWriteFast(PIN_WR, 0x1);
    read_data = read_data_array[(GPIO6_raw_data >> 16)]; // Read the Z80 bus data, re-arranging bits through read_data_array
//    interrupts();
    return read_data;
  }

  // Interrupt Acknowledge - 4 cycle M1 type but with two additional wait states
  // -----------------------------------------------------------------------------
  else if (biu_operation == INTERRUPT_ACK)
  {
    waitForclockFallingEdge(); // T1 Falling
    waitForClockRisingEdge(); // T2 Rising
    waitForClockRisingEdge(); // Tw1 Rising
    waitForclockFallingEdge(); // Tw1 Falling
    digitalWriteFast(PIN_IOREQ, 0x0); 

    waitForclockFallingEdge(); // Tw2 Falling
    while (direct_wait == 0)
    {
// WAIT STATE MODIFY
clock_counter++; // Compensate wait state clock counter
      waitForclockFallingEdge(); // Tw2 Falling
    }

    // Pre-calculate before the next clock edge to gain speed
    //
    local_address_high = register_i;
    local_address_low = register_r;
    gpio7_out = gpio7_high_array[local_address_high] | gpio7_low_array[local_address_low];
    gpio8_out = gpio8_high_array[local_address_high] | 0x00040000; // Also set IOREQ_n high
    gpio9_out = gpio9_high_array[local_address_high] | gpio9_low_array[local_address_low];

    writeback_data7 = (0xCFF0E3FC & GPIO7_DR) | 0x2; // drive M1 high again
    writeback_data9 = (0xFFFFFE1F & GPIO9_DR);       // Read in current GPIOx register value and clear the bits we intend to update
    writeback_data8 = (0xFF3FFFFF & GPIO8_DR);       // Read in current GPIOx register value and clear the bits we intend to update

    waitForClockRisingEdge();
    read_data_raw = GPIO6_raw_data; // T3 Rising   -- Read data sampled on this edge

    // Drive Refresh address
    //
    GPIO9_DR = writeback_data9 | gpio9_out;
    GPIO8_DR = writeback_data8 | gpio8_out;
    GPIO7_DR = writeback_data7 | gpio7_out;

    digitalWriteFast(PIN_M1, 0x1);
    digitalWriteFast(PIN_RFSH, 0x0);
    digitalWriteFast(PIN_IOREQ, 0x1);

    waitForclockFallingEdge();
    digitalWriteFast(PIN_MREQ, 0x0);                    // T3 Falling
    read_data = read_data_array[(read_data_raw >> 16)]; // Read the Z80 bus data, re-arranging bits through read_data_array
    debounce_refresh = 1;
    
    waitForclockFallingEdge();
    digitalWriteFast(PIN_MREQ, 0x1); // T4 Falling   
//    interrupts();
    return read_data;
  }

  return 0xEE;
}

// ------------------------------------------------------
// Z80 Reset routine
// ------------------------------------------------------

void resetSequence()
{

  while (direct_reset == 0)
  {
    waitForclockFallingEdge(); // Stay here until RESET is de-aserted
  }

  clock_counter = 0; // Debounce prefix, cycle counter, and nmi
  last_instruction_set_a_prefix = 0;
  prefix_dd = 0;
  prefix_fd = 0;
  prefix_cb = 0;
  pause_interrupts = 0;
  halt_in_progress = 0;
  nmi_latched = 0;
  direct_nmi_d = 0;

  register_iff1 = 0; // Reset registers
  register_iff2 = 0;
  register_i = 0;
  register_r = 0;
  register_im = 0;
  register_pc = 0;
  register_sp = 0xFFFF;
  register_a = 0x00;
  register_f = 0xFF;

  waitForClockRisingEdge();
}

// ------------------------------------------------------
// Fetch an opcode byte - M1 cycle
// ------------------------------------------------------
void Fetch_opcode(void) __attribute__((always_inline));
void inline Fetch_opcode(void)
{
  if (assert_iack_type0 == 1)
    fetched_byte = BIUBusCycle(INTERRUPT_ACK, 0x0000, 0x00);
  else {
    clock_counter=4;  // M1 = 4 clock cycles
    fetched_byte = BIUBusCycle(OPCODE_READ_M1, register_pc, 0x00);
  }

  assert_iack_type0 = 0;
  register_pc++;
  register_r = (register_r & 0x80) | (0x7F & (register_r + 1));
}

// ------------------------------------------------------
// Fetch a subsequent byte
// ------------------------------------------------------
uint8_t Fetch_byte()
{
    fetched_byte = BIUBusCycle(MEM_READ_BYTE, register_pc, 0x00);
    register_pc++;
    return fetched_byte;
}

// ------------------------------------------------------
// Read and Write data from BIU
// ------------------------------------------------------

uint8_t readByte(uint16_t local_address)
{
  return BIUBusCycle(MEM_READ_BYTE, local_address, 0x00);
}

uint8_t readByteM1(uint16_t local_address)
{
  return BIUBusCycle(OPCODE_READ_M1, local_address, 0x00);
}

uint16_t readWord(uint16_t local_address)
{
  uint8_t local_byte1;
  uint8_t local_byte2;
  local_byte1 = BIUBusCycle(MEM_READ_BYTE, local_address, 0x00);
  local_byte2 = BIUBusCycle(MEM_READ_BYTE, local_address + 1, 0x00);
  return (local_byte1 | (local_byte2 << 8));
}

void writeByte(uint16_t local_address, uint8_t local_data)
{
  BIUBusCycle(MEM_WRITE_BYTE, local_address, local_data);
  return;
}

void writeWord(uint16_t local_address, uint16_t local_data)
{
  BIUBusCycle(MEM_WRITE_BYTE, local_address, local_data);
  BIUBusCycle(MEM_WRITE_BYTE, local_address + 1, local_data >> 8);
  return;
}

void Writeback_Reg16(uint8_t local_reg, uint16_t local_data)
{
  switch (local_reg)
  {
  case REG_BC:
    register_b = (local_data >> 8);
    register_c = (0xFF & local_data);
    break;
  case REG_DE:
    register_d = (local_data >> 8);
    register_e = (0xFF & local_data);
    break;
  case REG_HL:
    register_h = (local_data >> 8);
    register_l = (0xFF & local_data);
    break;
  case REG_AF:
    register_a = (local_data >> 8);
    register_f = (0xFF & local_data);
    break;
  case REG_IX:
    register_ixh = (local_data >> 8);
    register_ixl = (0xFF & local_data);
    break;
  case REG_IY:
    register_iyh = (local_data >> 8);
    register_iyl = (0xFF & local_data);
    break;
  }
  return;
}

void ioWriteByte(uint8_t local_address, uint8_t local_data)
{
  BIUBusCycle(IO_WRITE_BYTE, local_address, local_data);
  return;
}

uint8_t ioReadByte(uint8_t local_address)
{
  uint8_t local_byte;
  local_byte = BIUBusCycle(IO_READ_BYTE, local_address, 0x00);
  return local_byte;
}

// --------------------------------------------------------------------------------------------------
// Z80 Opcodes
// --------------------------------------------------------------------------------------------------

// ------------------------------------------------------
// Prefix Opcodes
// ------------------------------------------------------
void opcode_0xDD()
{
  prefix_dd = 1;
  last_instruction_set_a_prefix = 1;
  clock_counter = clock_counter + Opcode_Timing_DDFD[opcode_byte];
  return;
}

void opcode_0xFD()
{
  prefix_fd = 1;
  last_instruction_set_a_prefix = 1;
  clock_counter = clock_counter + Opcode_Timing_DDFD[opcode_byte];
  return;
}

void opcode_0x00()
{
  return; // NOP
}

// ------------------------------------------------------
// Stack handling PUSH/POP
// ------------------------------------------------------
void Push(uint16_t local_data)
{
  register_sp--;
  BIUBusCycle(MEM_WRITE_BYTE, register_sp, local_data >> 8); // High Byte
  register_sp--;
  BIUBusCycle(MEM_WRITE_BYTE, register_sp, local_data); // Low Byte
  return;
}

uint16_t Pop()
{
  uint8_t local_data_low;
  uint8_t local_data_high;

  local_data_low = BIUBusCycle(MEM_READ_BYTE, register_sp, 0x00); // Low Byte
  register_sp++;
  local_data_high = BIUBusCycle(MEM_READ_BYTE, register_sp, 0x00); // High Byte
  register_sp++;
  return ((local_data_high << 8) | local_data_low);
}
void opcode_0xC5()
{
  Push(REGISTER_BC); // push bc
  return;
}
void opcode_0xD5()
{
  Push(REGISTER_DE); // push de
  return;
}
void opcode_0xE5()
{
  if (prefix_dd == 1)
    Push(REGISTER_IX); // push hl
  else if (prefix_fd == 1)
    Push(REGISTER_IY);
  else
    Push(REGISTER_HL);
  return;
}
void opcode_0xF5()
{
  Push(REGISTER_AF); // push af
  return;
}

void opcode_0xF1()
{
  uint16_t local_data = Pop(); // pop af
  register_a = (local_data >> 8);
  register_f = (local_data & 0xFF);
  return;
}
void opcode_0xC1()
{
  uint16_t local_data = Pop(); // pop bc
  register_b = (local_data >> 8);
  register_c = (local_data & 0xFF);
  return;
}
void opcode_0xD1()
{
  uint16_t local_data = Pop(); // pop de
  register_d = (local_data >> 8);
  register_e = (local_data & 0xFF);
  return;
}
void opcode_0xE1()
{
  uint16_t local_data = Pop();
  if (prefix_dd == 1)
  {
    register_ixh = (local_data >> 8); // pop ix
    register_ixl = (local_data & 0xFF);
  }
  else if (prefix_fd == 1)
  {
    register_iyh = (local_data >> 8); // pop iy
    register_iyl = (local_data & 0xFF);
  }
  else
  {
    register_h = (local_data >> 8); // pop hl
    register_l = (local_data & 0xFF);
  }
  return;
}

// ------------------------------------------------------
// Flags/Complements
// ------------------------------------------------------

void opcode_0x3F()
{
  temp8 = register_f & 0x01;      // Store old C Flag
  register_f = register_f & 0xC4; // Clear H, C, N, 5,3
  if (temp8 == 1)
    register_f = register_f | 0x10; // Set H
  if (temp8 == 0)
    register_f = register_f | 0x01; // Compliment C Flag
  register_f = register_f | (register_a & 0x28);
  return;
} // ccf

void opcode_0x2F()
{
  register_a = 0xFF ^ register_a; // Compliment register a
  register_f = register_f | 0x12; // Set N and H Flags
  register_f = register_f & 0xD7; // Clear Flags 5,3
  register_f = register_f | (register_a & 0x28);
  return;
} // cpl

void opcode_0x37()
{
  register_f = register_f | 0x01; // Set C
  register_f = register_f & 0xC5; // Clear Flags H, N, 5,3
  register_f = register_f | (register_a & 0x28);
  return;
} // scf

// ------------------------------------------------------
// Interrupt enables and modes
// ------------------------------------------------------
void opcode_0xED46()
{
  register_im = 0; // IM0
  return;
}
void opcode_0xED56()
{
  register_im = 1; // IM1
  return;
}
void opcode_0xED5E()
{
  register_im = 2; // IM2
  return;
}
void opcode_0xFB()
{
  register_iff1 = 1; // ei
  register_iff2 = 1;
  last_instruction_set_a_prefix = 0;
  return;
}
void opcode_0xF3()
{
  register_iff1 = 0; // di
  register_iff2 = 0;
  return;
}

// ------------------------------------------------------
// Exchanges
// ------------------------------------------------------
void opcode_0x08()
{
  temp8 = register_a; // ex af,af'
  register_a = register_a2;
  register_a2 = temp8;
  temp8 = register_f;
  register_f = register_f2;
  register_f2 = temp8;
  return;
}
void opcode_0xEB()
{
  temp8 = register_d; // ex de hl
  register_d = register_h;
  register_h = temp8;
  temp8 = register_e;
  register_e = register_l;
  register_l = temp8;
  return;
}

void opcode_0xD9()
{
  temp8 = register_b;
  register_b = register_b2;
  register_b2 = temp8;
  temp8 = register_c;
  register_c = register_c2;
  register_c2 = temp8; // exx  bc  bc'
  temp8 = register_d;
  register_d = register_d2;
  register_d2 = temp8;
  temp8 = register_e;
  register_e = register_e2;
  register_e2 = temp8; //      de  de'
  temp8 = register_h;
  register_h = register_h2;
  register_h2 = temp8;
  temp8 = register_l;
  register_l = register_l2;
  register_l2 = temp8;
  return;
} //      hl  hl'

void opcode_0xE3()
{
  if (prefix_dd == 1)
  {
    temp8 = readByte(register_sp);
    writeByte(register_sp, register_ixl);
    register_ixl = temp8; // ex (sp),ix
    temp8 = readByte(register_sp + 1);
    writeByte(register_sp + 1, register_ixh);
    register_ixh = temp8;
  }
  else if (prefix_fd == 1)
  {
    temp8 = readByte(register_sp);
    writeByte(register_sp, register_iyl);
    register_iyl = temp8; // ex (sp),iy
    temp8 = readByte(register_sp + 1);
    writeByte(register_sp + 1, register_iyh);
    register_iyh = temp8;
  }
  else

  {
    temp8 = readByte(register_sp);
    writeByte(register_sp, register_l);
    register_l = temp8; // ex (sp),hl
    temp8 = readByte(register_sp + 1);
    writeByte(register_sp + 1, register_h);
    register_h = temp8;
  }
  return;
}

// ------------------------------------------------------
// Jumps, Calls, Returns
// ------------------------------------------------------

uint16_t Sign_Extend(uint8_t local_data)
{
  if ((0x0080 & local_data) != 0)
    return (0xFF00 | local_data);
  else
    return (0x00FF & local_data);
}

void Jump_Not_Taken8()
{
  Fetch_byte();
  return;
}
void Jump_Not_Taken16()
{
  Fetch_byte();
  Fetch_byte();
  return;
}
void Jump_Taken8()
{
  uint16_t local_displacement;

  local_displacement = Sign_Extend(Fetch_byte());
  register_pc = (register_pc) + local_displacement;
  return;
}
void Jump_Taken16()
{
  uint16_t local_displacement;

  local_displacement = Fetch_byte();
  register_pc = (Fetch_byte() << 8) | local_displacement;
  return;
}
void opcode_0x18() // jr *    - Disp8
{
  clock_counter = clock_counter + 5; 
  Jump_Taken8();
  return;
}
void opcode_0x20()
{
  if (flag_z == 0)
  {
    clock_counter = clock_counter + 5; // jr nz,* - Disp8
    Jump_Taken8();
  }
  else
    Jump_Not_Taken8();
  return;
}
void opcode_0x28()
{
  if (flag_z == 1)
  {
    clock_counter = clock_counter + 5; // jr z,*  - Disp8
    Jump_Taken8();
  }
  else
    Jump_Not_Taken8();
  return;
}
void opcode_0x30()
{
  if (flag_c == 0)
  {
    clock_counter = clock_counter + 5; // jr nc,* - Disp8
    Jump_Taken8();
  }
  else
    Jump_Not_Taken8();
  return;
}
void opcode_0x38()
{
  if (flag_c == 1)
  {
    clock_counter = clock_counter + 5; // jr c,*  - Disp8
    Jump_Taken8();
  }
  else
    Jump_Not_Taken8();
  return;
}
void opcode_0x10()
{
  register_b--; // djnz *  - Disp8
  if (register_b != 0)
  {
    clock_counter = clock_counter + 5;
    Jump_Taken8();
  }
  else
    Jump_Not_Taken8();
  return;
}

void opcode_0xC2()
{
  if (flag_z == 0)
    Jump_Taken16(); // jp nz,**
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xCA()
{
  if (flag_z == 1)
    Jump_Taken16(); // jp z,**
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xD2()
{
  if (flag_c == 0)
    Jump_Taken16(); // jp nc,**
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xDA()
{
  if (flag_c == 1)
    Jump_Taken16(); // jp c,**
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xE2()
{
  if (flag_p == 0)
    Jump_Taken16(); // jp po,**
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xEA()
{
  if (flag_p == 1)
    Jump_Taken16(); // jp pe,**
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xF2()
{
  if (flag_s == 0)
    Jump_Taken16(); // jp p,**
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xFA()
{
  if (flag_s == 1)
    Jump_Taken16(); // jp m,**
  else
    Jump_Not_Taken16();
  return;
}

void opcode_0xC3()
{
  Jump_Taken16(); // jp **
  return;
}
void opcode_0xE9()
{
  if (prefix_dd == 1)
    register_pc = (REGISTER_IX); // jp ix or iy, or (hl)
  else if (prefix_fd == 1)
    register_pc = (REGISTER_IY);
  else
    register_pc = (REGISTER_HL);
  return;
}

void opcode_0xC4()
{
  if (flag_z == 0)
  {
    clock_counter = clock_counter + 7; // call nz,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xCC()
{
  if (flag_z == 1)
  {
    clock_counter = clock_counter + 7; // call z,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xD4()
{
  if (flag_c == 0)
  {
    clock_counter = clock_counter + 7; // call nc,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xDC()
{
  if (flag_c == 1)
  {
    clock_counter = clock_counter + 7; // call c,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xE4()
{
  if (flag_p == 0)
  {
    clock_counter = clock_counter + 7; // call po,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xEC()
{
  if (flag_p == 1)
  {
    clock_counter = clock_counter + 7; // call pe,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xF4()
{
  if (flag_s == 0)
  {
    clock_counter = clock_counter + 7; // call p,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xFC()
{
  if (flag_s == 1)
  {
    clock_counter = clock_counter + 7; // call m,**
    Push(register_pc + 2);
    Jump_Taken16();
  }
  else
    Jump_Not_Taken16();
  return;
}
void opcode_0xCD()
{
  clock_counter = clock_counter + 7; // call **
  Push(register_pc + 2);
  Jump_Taken16();
  return;
}

// ret
void opcode_0xC9()
{
  clock_counter = clock_counter + 6;
  register_pc = Pop();
  return;
}
// ret nz
void opcode_0xC0()
{
  if (flag_z == 0)
  {
    clock_counter = clock_counter + 6;
    register_pc = Pop();
  }
  return;
}
void opcode_0xC8()
// ret z
{
  if (flag_z == 1)
  {
    clock_counter = clock_counter + 6; 
    register_pc = Pop();
  }
  return;
}
// ret nc
void opcode_0xD0()
{
  if (flag_c == 0)
  {
    clock_counter = clock_counter + 6;
    register_pc = Pop();
  }
  return;
}
// ret c
void opcode_0xD8()
{
  if (flag_c == 1)
  {
    clock_counter = clock_counter + 6; 
    register_pc = Pop();
  }
  return;
}
// ret po
void opcode_0xE0()
{
  if (flag_p == 0)
  {
    clock_counter = clock_counter + 6;
    register_pc = Pop();
  }
  return;
}
// ret pe
void opcode_0xE8()
{
  if (flag_p == 1)
  {
    clock_counter = clock_counter + 6; 
    register_pc = Pop();
  }
  return;
}
// ret p
void opcode_0xF0()
{
  if (flag_s == 0)
  {
    clock_counter = clock_counter + 6; 
    register_pc = Pop();
  }
  return;
}
// ret m
void opcode_0xF8()
{
  if (flag_s == 1)
  {
    clock_counter = clock_counter + 6; 
    register_pc = Pop();
  }
  return;
}
// retn
void opcode_0xED45()
{
  register_iff1 = register_iff2;
  register_pc = Pop();
  return;
}
// reti
void opcode_0xED4D()
{
  register_pc = Pop();
  return;
}

void opcode_0xC7()
{
  Push(register_pc); // rst 00h
  register_pc = 0x00;
  return;
}
void opcode_0xD7()
{
  Push(register_pc); // rst 10h
  register_pc = 0x10;
  return;
}
void opcode_0xE7()
{
  Push(register_pc); // rst 20h
  register_pc = 0x20;
  return;
}
void opcode_0xF7()
{
  Push(register_pc); // rst 30h
  register_pc = 0x30;
  return;
}
void opcode_0xCF()
{
  Push(register_pc); // rst 08h
  register_pc = 0x08;
  return;
}
void opcode_0xDF()
{
  Push(register_pc); // rst 18h
  register_pc = 0x18;
  return;
}
void opcode_0xEF()
{
  Push(register_pc); // rst 28h
  register_pc = 0x28;
  return;
}
void opcode_0xFF()
{
  Push(register_pc); // rst 38h
  register_pc = 0x38;
  return;
}

// ------------------------------------------------------
// Loads
// ------------------------------------------------------
void opcode_0x01()
{
  register_c = Fetch_byte();
  register_b = Fetch_byte();
  return;
}
void opcode_0x11()
{
  register_e = Fetch_byte();
  register_d = Fetch_byte();
  return;
}
void opcode_0x0A()
{
  register_a = readByte(REGISTER_BC);
  return;
}
void opcode_0x0E()
{
  register_c = Fetch_byte();
  return;
}
void opcode_0x1E()
{
  register_e = Fetch_byte();
  return;
}
void opcode_0x1A()
{
  register_a = readByte(REGISTER_DE);
  return;
}

void opcode_0x21()
{
  if (prefix_dd == 1)
  {
    register_ixl = Fetch_byte();
    register_ixh = Fetch_byte();
  }
  else if (prefix_fd == 1)
  {
    register_iyl = Fetch_byte();
    register_iyh = Fetch_byte();
  }
  else
  {
    register_l = Fetch_byte();
    register_h = Fetch_byte();
  }
  return;
}

void opcode_0x22()
{
  uint16_t local_address;

  local_address = Fetch_byte();
  local_address = (Fetch_byte() << 8) | local_address;

  if (prefix_dd == 1)
  {
    writeByte(local_address, register_ixl);
    writeByte(local_address + 1, register_ixh);
  }
  else if (prefix_fd == 1)
  {
    writeByte(local_address, register_iyl);
    writeByte(local_address + 1, register_iyh);
  }
  else
  {
    writeByte(local_address, register_l);
    writeByte(local_address + 1, register_h);
  }
  return;
}

void opcode_0x2A()
{
  uint16_t local_address;

  local_address = Fetch_byte();
  local_address = (Fetch_byte() << 8) | local_address;

  if (prefix_dd == 1)
  {
    register_ixl = readByte(local_address);
    register_ixh = readByte(local_address + 1);
  }
  else if (prefix_fd == 1)
  {
    register_iyl = readByte(local_address);
    register_iyh = readByte(local_address + 1);
  }
  else
  {
    register_l = readByte(local_address);
    register_h = readByte(local_address + 1);
  }
  return;
}

void opcode_0x06()
{
  register_b = Fetch_byte();
  return;
}
void opcode_0x16()
{
  register_d = Fetch_byte();
  return;
}
void opcode_0x26()
{
  if (prefix_dd == 1)
  {
    register_ixh = Fetch_byte();
  }
  else if (prefix_fd == 1)
  {
    register_iyh = Fetch_byte();
  }
  else
    register_h = Fetch_byte();
  return;
}
void opcode_0x2E()
{
  if (prefix_dd == 1)
  {
    register_ixl = Fetch_byte();
  }
  else if (prefix_fd == 1)
  {
    register_iyl = Fetch_byte();
  }
  else
    register_l = Fetch_byte();
  return;
}

void opcode_0x31()
{
  uint16_t local_address;
  local_address = Fetch_byte();
  local_address = (Fetch_byte() << 8) | local_address;

  register_sp = local_address;
  return;
}

void opcode_0x32()
{
  uint16_t local_address;

  local_address = Fetch_byte();
  local_address = (Fetch_byte() << 8) | local_address;

  writeByte(local_address, register_a);
  return;
}

void opcode_0x36()
{
  if (prefix_dd == 1)
    writeByte(REGISTER_IX + Sign_Extend(Fetch_byte()), Fetch_byte());
  else if (prefix_fd == 1)
    writeByte(REGISTER_IY + Sign_Extend(Fetch_byte()), Fetch_byte());
  else
    writeByte(REGISTER_HL, Fetch_byte());
  return;
}

void opcode_0x3A()
{
  register_a = readByte((Fetch_byte() | (Fetch_byte() << 8)));
  return;
}
void opcode_0x3E()
{
  register_a = Fetch_byte();
  return;
}

void opcode_0x40()
{
  register_b = register_b;
  return;
}
void opcode_0x41()
{
  register_b = register_c;
  return;
}
void opcode_0x42()
{
  register_b = register_d;
  return;
}
void opcode_0x43()
{
  register_b = register_e;
  return;
}
void opcode_0x44()
{
  if (prefix_dd == 1)
    register_b = register_ixh;
  else if (prefix_fd == 1)
    register_b = register_iyh;
  else
    register_b = register_h;
  return;
}
void opcode_0x45()
{
  if (prefix_dd == 1)
    register_b = register_ixl;
  else if (prefix_fd == 1)
    register_b = register_iyl;
  else
    register_b = register_l;
  return;
}
void opcode_0x46()
{
  if (prefix_dd == 1)
    register_b = readByte(REGISTER_IX + Sign_Extend(Fetch_byte()));
  else if (prefix_fd == 1)
    register_b = readByte(REGISTER_IY + Sign_Extend(Fetch_byte()));
  else
    register_b = readByte(REGISTER_HL);
  return;
}
void opcode_0x47()
{
  register_b = register_a;
  return;
}
void opcode_0x48()
{
  register_c = register_b;
  return;
}
void opcode_0x49()
{
  register_c = register_c;
  return;
}
void opcode_0x4A()
{
  register_c = register_d;
  return;
}
void opcode_0x4B()
{
  register_c = register_e;
  return;
}
void opcode_0x4C()
{
  if (prefix_dd == 1)
    register_c = register_ixh;
  else if (prefix_fd == 1)
    register_c = register_iyh;
  else
    register_c = register_h;
  return;
}
void opcode_0x4D()
{
  if (prefix_dd == 1)
    register_c = register_ixl;
  else if (prefix_fd == 1)
    register_c = register_iyl;
  else
    register_c = register_l;
  return;
}
void opcode_0x4E()
{
  if (prefix_dd == 1)
    register_c = readByte(REGISTER_IX + Sign_Extend(Fetch_byte()));
  else if (prefix_fd == 1)
    register_c = readByte(REGISTER_IY + Sign_Extend(Fetch_byte()));
  else
    register_c = readByte(REGISTER_HL);
  return;
}
void opcode_0x4F()
{
  register_c = register_a;
  return;
}

// ----------------------------------------

void opcode_0x50()
{
  register_d = register_b;
  return;
}
void opcode_0x51()
{
  register_d = register_c;
  return;
}
void opcode_0x52()
{
  register_d = register_d;
  return;
}
void opcode_0x53()
{
  register_d = register_e;
  return;
}
void opcode_0x54()
{
  if (prefix_dd == 1)
    register_d = register_ixh;
  else if (prefix_fd == 1)
    register_d = register_iyh;
  else
    register_d = register_h;
  return;
}
void opcode_0x55()
{
  if (prefix_dd == 1)
    register_d = register_ixl;
  else if (prefix_fd == 1)
    register_d = register_iyl;
  else
    register_d = register_l;
  return;
}
void opcode_0x56()
{
  if (prefix_dd == 1)
    register_d = readByte(REGISTER_IX + Sign_Extend(Fetch_byte()));
  else if (prefix_fd == 1)
    register_d = readByte(REGISTER_IY + Sign_Extend(Fetch_byte()));
  else
    register_d = readByte(REGISTER_HL);
  return;
}
void opcode_0x57()
{
  register_d = register_a;
  return;
}
void opcode_0x58()
{
  register_e = register_b;
  return;
}
void opcode_0x59()
{
  register_e = register_c;
  return;
}
void opcode_0x5A()
{
  register_e = register_d;
  return;
}
void opcode_0x5B()
{
  register_e = register_e;
  return;
}
void opcode_0x5C()
{
  if (prefix_dd == 1)
    register_e = register_ixh;
  else if (prefix_fd == 1)
    register_e = register_iyh;
  else
    register_e = register_h;
  return;
}
void opcode_0x5D()
{
  if (prefix_dd == 1)
    register_e = register_ixl;
  else if (prefix_fd == 1)
    register_e = register_iyl;
  else
    register_e = register_l;
  return;
}
void opcode_0x5E()
{
  if (prefix_dd == 1)
    register_e = readByte(REGISTER_IX + Sign_Extend(Fetch_byte()));
  else if (prefix_fd == 1)
    register_e = readByte(REGISTER_IY + Sign_Extend(Fetch_byte()));
  else
    register_e = readByte(REGISTER_HL);
  return;
}
void opcode_0x5F()
{
  register_e = register_a;
  return;
}

// ----------------------------------------

void opcode_0x60()
{
  if (prefix_dd == 1)
    register_ixh = register_b;
  else if (prefix_fd == 1)
    register_iyh = register_b;
  else
    register_h = register_b;
  return;
}
void opcode_0x61()
{
  if (prefix_dd == 1)
    register_ixh = register_c;
  else if (prefix_fd == 1)
    register_iyh = register_c;
  else
    register_h = register_c;
  return;
}
void opcode_0x62()
{
  if (prefix_dd == 1)
    register_ixh = register_d;
  else if (prefix_fd == 1)
    register_iyh = register_d;
  else
    register_h = register_d;
  return;
}
void opcode_0x63()
{
  if (prefix_dd == 1)
    register_ixh = register_e;
  else if (prefix_fd == 1)
    register_iyh = register_e;
  else
    register_h = register_e;
  return;
}
void opcode_0x64()
{
  if (prefix_dd == 1)
    register_ixh = register_ixh;
  else if (prefix_fd == 1)
    register_iyh = register_iyh;
  else
    register_h = register_h;
  return;
}
void opcode_0x65()
{
  if (prefix_dd == 1)
    register_ixh = register_ixl;
  else if (prefix_fd == 1)
    register_iyh = register_iyl;
  else
    register_h = register_l;
  return;
}
void opcode_0x66()
{
  if (prefix_dd == 1)
    register_h = readByte(REGISTER_IX + Sign_Extend(Fetch_byte()));
  else if (prefix_fd == 1)
    register_h = readByte(REGISTER_IY + Sign_Extend(Fetch_byte()));
  else
    register_h = readByte(REGISTER_HL);
  return;
}
void opcode_0x67()
{
  if (prefix_dd == 1)
    register_ixh = register_a;
  else if (prefix_fd == 1)
    register_iyh = register_a;
  else
    register_h = register_a;
  return;
}
void opcode_0x68()
{
  if (prefix_dd == 1)
    register_ixl = register_b;
  else if (prefix_fd == 1)
    register_iyl = register_b;
  else
    register_l = register_b;
  return;
}
void opcode_0x69()
{
  if (prefix_dd == 1)
    register_ixl = register_c;
  else if (prefix_fd == 1)
    register_iyl = register_c;
  else
    register_l = register_c;
  return;
}
void opcode_0x6A()
{
  if (prefix_dd == 1)
    register_ixl = register_d;
  else if (prefix_fd == 1)
    register_iyl = register_d;
  else
    register_l = register_d;
  return;
}
void opcode_0x6B()
{
  if (prefix_dd == 1)
    register_ixl = register_e;
  else if (prefix_fd == 1)
    register_iyl = register_e;
  else
    register_l = register_e;
  return;
}
void opcode_0x6C()
{
  if (prefix_dd == 1)
    register_ixl = register_ixh;
  else if (prefix_fd == 1)
    register_iyl = register_iyh;
  else
    register_l = register_h;
  return;
}
void opcode_0x6D()
{
  if (prefix_dd == 1)
    register_ixl = register_ixl;
  else if (prefix_fd == 1)
    register_iyl = register_iyl;
  else
    register_l = register_l;
  return;
}
void opcode_0x6E()
{
  if (prefix_dd == 1)
    register_l = readByte(REGISTER_IX + Sign_Extend(Fetch_byte()));
  else if (prefix_fd == 1)
    register_l = readByte(REGISTER_IY + Sign_Extend(Fetch_byte()));
  else
    register_l = readByte(REGISTER_HL);
  return;
}
void opcode_0x6F()
{
  if (prefix_dd == 1)
    register_ixl = register_a;
  else if (prefix_fd == 1)
    register_iyl = register_a;
  else
    register_l = register_a;
  return;
}

// ----------------------------------------

void opcode_0x02()
{
  writeByte(REGISTER_BC, register_a); // ld (bc),a
  return;
}
void opcode_0x12()
{
  writeByte(REGISTER_DE, register_a); // ld (de),a
  return;
}

void opcode_0x70()
{
  if (prefix_dd == 1)
    writeByte((REGISTER_IX + Sign_Extend(Fetch_byte())), register_b);
  else if (prefix_fd == 1)
    writeByte((REGISTER_IY + Sign_Extend(Fetch_byte())), register_b);
  else
    writeByte(REGISTER_HL, register_b);
  return;
}

void opcode_0x71()
{
  if (prefix_dd == 1)
    writeByte((REGISTER_IX + Sign_Extend(Fetch_byte())), register_c);
  else if (prefix_fd == 1)
    writeByte((REGISTER_IY + Sign_Extend(Fetch_byte())), register_c);
  else
    writeByte(REGISTER_HL, register_c);
  return;
}

void opcode_0x72()
{
  if (prefix_dd == 1)
    writeByte((REGISTER_IX + Sign_Extend(Fetch_byte())), register_d);
  else if (prefix_fd == 1)
    writeByte((REGISTER_IY + Sign_Extend(Fetch_byte())), register_d);
  else
    writeByte(REGISTER_HL, register_d);
  return;
}

void opcode_0x73()
{
  if (prefix_dd == 1)
    writeByte((REGISTER_IX + Sign_Extend(Fetch_byte())), register_e);
  else if (prefix_fd == 1)
    writeByte((REGISTER_IY + Sign_Extend(Fetch_byte())), register_e);
  else
    writeByte(REGISTER_HL, register_e);
  return;
}

void opcode_0x74()
{
  if (prefix_dd == 1)
    writeByte((REGISTER_IX + Sign_Extend(Fetch_byte())), register_h);
  else if (prefix_fd == 1)
    writeByte((REGISTER_IY + Sign_Extend(Fetch_byte())), register_h);
  else
    writeByte(REGISTER_HL, register_h);
  return;
}

void opcode_0x75()
{
  if (prefix_dd == 1)
    writeByte((REGISTER_IX + Sign_Extend(Fetch_byte())), register_l);
  else if (prefix_fd == 1)
    writeByte((REGISTER_IY + Sign_Extend(Fetch_byte())), register_l);
  else
    writeByte(REGISTER_HL, register_l);
  return;
}

void opcode_0x77()
{
  if (prefix_dd == 1)
    writeByte((REGISTER_IX + Sign_Extend(Fetch_byte())), register_a);
  else if (prefix_fd == 1)
    writeByte((REGISTER_IY + Sign_Extend(Fetch_byte())), register_a);
  else
    writeByte(REGISTER_HL, register_a);
  return;
}
void opcode_0x78()
{
  register_a = register_b;
  return;
}
void opcode_0x79()
{
  register_a = register_c;
  return;
}
void opcode_0x7A()
{
  register_a = register_d;
  return;
}
void opcode_0x7B()
{
  register_a = register_e;
  return;
}
void opcode_0x7C()
{
  if (prefix_dd == 1)
    register_a = register_ixh;
  else if (prefix_fd == 1)
    register_a = register_iyh;
  else
    register_a = register_h;
  return;
}
void opcode_0x7D()
{
  if (prefix_dd == 1)
    register_a = register_ixl;
  else if (prefix_fd == 1)
    register_a = register_iyl;
  else
    register_a = register_l;
  return;
}
void opcode_0x7E()
{
  if (prefix_dd == 1)
    register_a = readByte(REGISTER_IX + Sign_Extend(Fetch_byte()));
  else if (prefix_fd == 1)
    register_a = readByte(REGISTER_IY + Sign_Extend(Fetch_byte()));
  else
    register_a = readByte(REGISTER_HL);
  return;
}
void opcode_0x7F()
{
  register_a = register_a;
  return;
}

// ----------------------------------------

void opcode_0xF9()
{
  if (prefix_dd == 1)
    register_sp = ((register_ixh << 8) | register_ixl);
  else if (prefix_fd == 1)
    register_sp = ((register_iyh << 8) | register_iyl);
  else
    register_sp = ((register_h << 8) | register_l);
  return;
}

void opcode_0xED43()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  writeByte(local_address, register_c);
  writeByte(local_address + 1, register_b);
  return;
}

void opcode_0xED53()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  writeByte(local_address, register_e);
  writeByte(local_address + 1, register_d);
  return;
}

void opcode_0xED63()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  writeByte(local_address, register_l);
  writeByte(local_address + 1, register_h);
  return;
}

void opcode_0xED73()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  writeWord(local_address, register_sp);
  return;
}

void opcode_0xED4B()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  register_c = readByte(local_address);
  register_b = readByte(local_address + 1);

  return;
}

void opcode_0xED5B()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  register_e = readByte(local_address);
  register_d = readByte(local_address + 1);

  return;
}

void opcode_0xED6B()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  register_l = readByte(local_address);
  register_h = readByte(local_address + 1);

  return;
}

void opcode_0xED7B()
{
  uint16_t local_address;

  local_address = (Fetch_byte() | (Fetch_byte() << 8));

  register_sp = readWord(local_address);

  return;
}

void opcode_0xED47()
{
  register_i = register_a; // ld i, a
  return;
}

void opcode_0xED57()
{
  register_a = register_i;        // ld a, i
  register_f = register_f & 0x29; // Clear S, Z, H, P, N flags
  if (register_iff2)
    register_f = register_f | 0x04;              // Set P flag
  register_f = register_f | (register_a & 0x80); // Set S flag
  if (register_a == 0)
    register_f = register_f | 0x40; // Set Z flag
  return;
}

void opcode_0xED4F()
{
  register_r = register_a;
  return;
}

void opcode_0xED5F()
{
  register_a = register_r;
  register_f = register_f & 0x29; // Clear S, Z, H, P, N flags
  if (register_iff2)
    register_f = register_f | 0x04;              // Set P flag
  register_f = register_f | (register_a & 0x80); // Set S flag
  if (register_a == 0)
    register_f = register_f | 0x40; // Set Z flag
  return;
}

// ------------------------------------------------------
// Boolean
// ------------------------------------------------------

void Flags_Boolean()
{
  register_f = register_f & 0x00; // Clear S, Z, H, P, N, C flags
  if (and_opcode == 1)
    register_f = register_f | 0x10;                   // Set H flag
  register_f = register_f | Parity_Array[register_a]; // Set P flag
  register_f = register_f | (register_a & 0x80);      // Set S flag
  if (register_a == 0)
    register_f = register_f | 0x40;              // Set Z flag
  register_f = register_f | (register_a & 0x28); // Set flag bits 5,3 to ALU results
  and_opcode = 0;
  return;
}

void opcode_0xA0()
{
  register_a = (register_a & register_b); // and b
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xA1()
{
  register_a = (register_a & register_c); // and c
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xA2()
{
  register_a = (register_a & register_d); // and d
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xA3()
{
  register_a = (register_a & register_e); // and e
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xA4()
{
  if (prefix_dd == 1)
    register_a = (register_a & register_ixh);
  else // and h , ixh, iyh
    if (prefix_fd == 1)
      register_a = (register_a & register_iyh);
    else
      register_a = (register_a & register_h);
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xA5()
{
  if (prefix_dd == 1)
    register_a = (register_a & register_ixl);
  else // and l , ixl, iyl
    if (prefix_fd == 1)
      register_a = (register_a & register_iyl);
    else
      register_a = (register_a & register_l);
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xA6()
{
  if (prefix_dd == 1)
    register_a = (register_a & readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  else // and (hl) , ix+*, iy+*
    if (prefix_fd == 1)
      register_a = (register_a & readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    else
      register_a = (register_a & readByte(REGISTER_HL));
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xA7()
{
  register_a = (register_a & register_a); // and a
  and_opcode = 1;
  Flags_Boolean();
  return;
}
void opcode_0xE6()
{
  register_a = (register_a & Fetch_byte()); // and *
  and_opcode = 1;
  Flags_Boolean();
  return;
}

// ----

void opcode_0xA8()
{
  register_a = (register_a ^ register_b); // xor b
  Flags_Boolean();
  return;
}
void opcode_0xA9()
{
  register_a = (register_a ^ register_c); // xor c
  Flags_Boolean();
  return;
}
void opcode_0xAA()
{
  register_a = (register_a ^ register_d); // xor d
  Flags_Boolean();
  return;
}
void opcode_0xAB()
{
  register_a = (register_a ^ register_e); // xor e
  Flags_Boolean();
  return;
}
void opcode_0xAC()
{
  if (prefix_dd == 1)
    register_a = (register_a ^ register_ixh);
  else // xor h , ixh, iyh
    if (prefix_fd == 1)
      register_a = (register_a ^ register_iyh);
    else
      register_a = (register_a ^ register_h);
  Flags_Boolean();
  return;
}
void opcode_0xAD()
{
  if (prefix_dd == 1)
    register_a = (register_a ^ register_ixl);
  else // xor l , ixl, iyl
    if (prefix_fd == 1)
      register_a = (register_a ^ register_iyl);
    else
      register_a = (register_a ^ register_l);
  Flags_Boolean();
  return;
}
void opcode_0xAE()
{
  if (prefix_dd == 1)
    register_a = (register_a ^ readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  else // xor (hl) , ix+*, iy+*
    if (prefix_fd == 1)
      register_a = (register_a ^ readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    else
      register_a = (register_a ^ readByte(REGISTER_HL));
  Flags_Boolean();
  return;
}
void opcode_0xAF()
{
  register_a = (register_a ^ register_a); // xor a
  Flags_Boolean();
  return;
}
void opcode_0xEE()
{
  register_a = (register_a ^ Fetch_byte()); // xor *
  Flags_Boolean();
  return;
}

// ----

void opcode_0xB0()
{
  register_a = (register_a | register_b); // or b
  Flags_Boolean();
  return;
}
void opcode_0xB1()
{
  register_a = (register_a | register_c); // or c
  Flags_Boolean();
  return;
}
void opcode_0xB2()
{
  register_a = (register_a | register_d); // or d
  Flags_Boolean();
  return;
}
void opcode_0xB3()
{
  register_a = (register_a | register_e); // or e
  Flags_Boolean();
  return;
}
void opcode_0xB4()
{
  if (prefix_dd == 1)
    register_a = (register_a | register_ixh);
  else // or h , ixh, iyh
    if (prefix_fd == 1)
      register_a = (register_a | register_iyh);
    else
      register_a = (register_a | register_h);
  Flags_Boolean();
  return;
}
void opcode_0xB5()
{
  if (prefix_dd == 1)
    register_a = (register_a | register_ixl);
  else // or l , ixl, iyl
    if (prefix_fd == 1)
      register_a = (register_a | register_iyl);
    else
      register_a = (register_a | register_l);
  Flags_Boolean();
  return;
}
void opcode_0xB6()
{
  if (prefix_dd == 1)
    register_a = (register_a | readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  else // or (hl) , ix+*, iy+*
    if (prefix_fd == 1)
      register_a = (register_a | readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    else
      register_a = (register_a | readByte(REGISTER_HL));
  Flags_Boolean();
  return;
}
void opcode_0xB7()
{
  register_a = (register_a | register_a); // or a
  Flags_Boolean();
  return;
}
void opcode_0xF6()
{
  register_a = (register_a | Fetch_byte()); // or *
  Flags_Boolean();
  return;
}

// ------------------------------------------------------
// Addition for bytes
// ------------------------------------------------------
uint8_t ADD_Bytes(uint8_t local_data1, uint8_t local_data2)
{
  uint8_t local_nibble_results;
  uint16_t local_byte_results;
  uint16_t operand0 = 0;
  uint16_t operand1 = 0;
  uint16_t result = 0;
  uint8_t local_cf = 0;

  local_cf = (flag_c);

  register_f = register_f & 0x01; // Clear S, Z, H, V, N flags

  if (with_carry == 1)
  {
    local_nibble_results = (0x0F & local_data1) + (0x0F & local_data2) + local_cf; // Perform the nibble math
    local_byte_results = local_data1 + local_data2 + local_cf;                     // Perform the byte math
  }
  else
  {
    local_nibble_results = (0x0F & local_data1) + (0x0F & local_data2); // Perform the nibble math
    local_byte_results = local_data1 + local_data2;                     // Perform the byte math
  }

  if (local_nibble_results > 0x0F)
    register_f = (register_f | 0x10); // Set H Flag
  if (inc_dec == 0)
  {
    if (local_byte_results > 0xFF)
      register_f = (register_f | 0x01); // Set C Flag if not INC or DEC opcodes
    else
      register_f = (register_f & 0xFE);
  }
  inc_dec = 0; // Debounce inc_dec

  operand0 = (local_data1 & 0x0080);
  operand1 = (local_data2 & 0x0080);
  result = (local_byte_results & 0x0080);
  if (operand0 == 0 && operand1 == 0 && result != 0)
    register_f = (register_f | 0x04); // Set V Flag
  else if (operand0 != 0 && operand1 != 0 && result == 0)
    register_f = (register_f | 0x04);

  register_f = register_f | (local_byte_results & 0x80); // Set S flag
  if ((0xFF & local_byte_results) == 0)
    register_f = register_f | 0x40;                      // Set Z flag
  register_f = register_f | (local_byte_results & 0x28); // Set flag bits 5,3 to ALU results
  with_carry = 0;

  return local_byte_results;
}

// ------------------------------------------------------
// Addition for words
// ------------------------------------------------------
uint16_t ADD_Words(uint16_t local_data1, uint16_t local_data2)
{
  uint16_t local_nibble_results;
  uint32_t local_word_results;
  uint8_t local_cf = 0;

  local_cf = (flag_c);

  register_f = register_f & 0xC5; // Clear H, N flags

  if (with_carry == 1)
  {
    local_nibble_results = (0x0FFF & local_data1) + (0x0FFF & local_data2) + local_cf; // Perform the nibble math
    local_word_results = local_data1 + local_data2 + local_cf;                         // Perform the word math
  }
  else
  {
    local_nibble_results = (0x0FFF & local_data1) + (0x0FFF & local_data2); // Perform the nibble math
    local_word_results = local_data1 + local_data2;                         // Perform the word math
  }

  if (local_nibble_results > 0x0FFF)
    register_f = (register_f | 0x10); // Set H Flag
  if (inc_dec == 0)
  {
    if (local_word_results > 0xFFFF)
      register_f = (register_f | 0x01); // Set C Flag if not INC or DEC opcodes
    else
      register_f = (register_f & 0xFE);
  }
  register_f = register_f | ((local_word_results >> 8) & 0x28); // Set flag bits 5,3 to ALU results
  inc_dec = 0;                                                  // Debounce inc_dec
  with_carry = 0;

  return local_word_results;
}

// ------------------------------------------------------
// Addition for words2 - Sets all flags
// ------------------------------------------------------
uint16_t ADD_Words2(uint16_t local_data1, uint16_t local_data2)
{
  uint16_t local_nibble_results;
  uint32_t local_word_results;
  uint16_t operand0 = 0;
  uint16_t operand1 = 0;
  uint16_t result = 0;
  uint8_t local_cf = 0;

  local_cf = (flag_c);

  register_f = register_f & 0x01; // Clear S, Z, H, V, N flags

  if (with_carry == 1)
  {
    local_nibble_results = (0x0FFF & local_data1) + (0x0FFF & local_data2) + local_cf; // Perform the nibble math
    local_word_results = local_data1 + local_data2 + local_cf;                         // Perform the word math
  }
  else
  {
    local_nibble_results = (0x0FFF & local_data1) + (0x0FFF & local_data2); // Perform the nibble math
    local_word_results = local_data1 + local_data2;                         // Perform the word math
  }

  if (local_nibble_results > 0x0FFF)
    register_f = (register_f | 0x10); // Set H Flag
  if (inc_dec == 0)
  {
    if (local_word_results > 0xFFFF)
      register_f = (register_f | 0x01); // Set C Flag if not INC or DEC opcodes
    else
      register_f = (register_f & 0xFE);
  }
  inc_dec = 0; // Debounce inc_dec

  operand0 = (local_data1 & 0x8000);
  operand1 = (local_data2 & 0x8000);
  result = (local_word_results & 0x8000);
  if (operand0 == 0 && operand1 == 0 && result != 0)
    register_f = (register_f | 0x04); // Set V Flag
  else if (operand0 != 0 && operand1 != 0 && result == 0)
    register_f = (register_f | 0x04);

  if (local_word_results & 0x8000)
    register_f = register_f | 0x80; // Set S flag
  if (local_word_results == 0)
    register_f = register_f | 0x40;                             // Set Z flag
  register_f = register_f | ((local_word_results >> 8) & 0x28); // Set flag bits 5,3 to ALU results
  with_carry = 0;

  return local_word_results;
}

// ------------------------------------------------------
// Subtraction for bytes
// ------------------------------------------------------
uint8_t SUB_Bytes(uint8_t local_data1, uint8_t local_data2)
{
  uint8_t local_nibble_results;
  uint16_t local_byte_results;
  uint16_t operand0 = 0;
  uint16_t operand1 = 0;
  uint16_t result = 0;
  uint8_t local_cf = 0;

  local_cf = (flag_c);

  register_f = register_f & 0x01; // Clear S, Z, H, V, N flags

  if (with_carry == 1)
  {
    local_nibble_results = (0x0F & local_data1) - (0x0F & local_data2) - local_cf; // Perform the nibble math
    local_byte_results = local_data1 - local_data2 - local_cf;                     // Perform the byte math
  }
  else
  {
    local_nibble_results = (0x0F & local_data1) - (0x0F & local_data2); // Perform the nibble math
    local_byte_results = local_data1 - local_data2;                     // Perform the byte math
  }

  if (local_nibble_results > 0x0F)
    register_f = (register_f | 0x10); // Set H Flag
  if (inc_dec == 0)
  {
    if (local_byte_results > 0xFF)
      register_f = (register_f | 0x01); // Set C Flag if not INC or DEC opcodes
    else
      register_f = (register_f & 0xFE);
  }
  inc_dec = 0; // Debounce inc_dec

  operand0 = (local_data1 & 0x0080);
  operand1 = (local_data2 & 0x0080);
  result = (local_byte_results & 0x0080);
  if (operand0 == 0 && operand1 != 0 && result != 0)
    register_f = (register_f | 0x04); // Set V Flag
  else if (operand0 != 0 && operand1 == 0 && result == 0)
    register_f = (register_f | 0x04);

  register_f = register_f | (local_byte_results & 0x80); // Set S flag
  if ((0xFF & local_byte_results) == 0)
    register_f = register_f | 0x40; // Set Z flag
  register_f = register_f | 0x02;   // Set N flag always for subtraction
  if (cp_opcode == 0)
    register_f = register_f | (local_byte_results & 0x28);
  else                                              // Set flag bits 5,3 to ALU results
    register_f = register_f | (local_data2 & 0x28); // Set flag bits 5,3 to ALU results
  with_carry = 0;
  cp_opcode = 0;

  return local_byte_results;
}
// ------------------------------------------------------
// Subtraction for words
// ------------------------------------------------------
uint16_t SUB_Words(uint16_t local_data1, uint16_t local_data2)
{
  uint16_t local_nibble_results;
  uint32_t local_word_results;
  uint16_t operand0 = 0;
  uint16_t operand1 = 0;
  uint16_t result = 0;
  uint8_t local_cf = 0;

  local_cf = (flag_c);

  register_f = register_f & 0x01; // Clear S, Z, H, V, N flags

  if (with_carry == 1)
  {
    local_nibble_results = (0x0FFF & local_data1) - (0x0FFF & local_data2) - local_cf; // Perform the nibble math
    local_word_results = local_data1 - local_data2 - local_cf;                         // Perform the word math
  }
  else
  {
    local_nibble_results = (0x0FFF & local_data1) - (0x0FFF & local_data2); // Perform the nibble math
    local_word_results = local_data1 - local_data2;                         // Perform the word math
  }

  if (local_nibble_results > 0x0FFF)
    register_f = (register_f | 0x10); // Set H Flag
  if (inc_dec == 0)
  {
    if (local_word_results > 0xFFFF)
      register_f = (register_f | 0x01); // Set C Flag if not INC or DEC opcodes
    else
      register_f = (register_f & 0xFE);
  }
  inc_dec = 0; // Debounce inc_dec

  operand0 = (local_data1 & 0x8000);
  operand1 = (local_data2 & 0x8000);
  result = (local_word_results & 0x8000);
  if (operand0 == 0 && operand1 != 0 && result != 0)
    register_f = (register_f | 0x04); // Set V Flag
  else if (operand0 != 0 && operand1 == 0 && result == 0)
    register_f = (register_f | 0x04);

  if (local_word_results & 0x8000)
    register_f = register_f | 0x80; // Set S flag
  if (local_word_results == 0)
    register_f = register_f | 0x40;                             // Set Z flag
  register_f = register_f | 0x02;                               // Set N flag always for subtraction
  register_f = register_f | ((local_word_results >> 8) & 0x28); // Set flag bits 5,3 to ALU results
  with_carry = 0;

  return local_word_results;
}
void opcode_0x09()
{
  if (prefix_dd == 1)
    Writeback_Reg16(REG_IX, ADD_Words(REGISTER_IX, REGISTER_BC));
  else // add ix,bc
    if (prefix_fd == 1)
      Writeback_Reg16(REG_IY, ADD_Words(REGISTER_IY, REGISTER_BC));
    else // add iy,bc
      Writeback_Reg16(REG_HL, ADD_Words(REGISTER_HL, REGISTER_BC));
  return;
} // add hl,bc

void opcode_0x19()
{
  if (prefix_dd == 1)
    Writeback_Reg16(REG_IX, ADD_Words(REGISTER_IX, REGISTER_DE));
  else // add ix,de
    if (prefix_fd == 1)
      Writeback_Reg16(REG_IY, ADD_Words(REGISTER_IY, REGISTER_DE));
    else // add iy,de
      Writeback_Reg16(REG_HL, ADD_Words(REGISTER_HL, REGISTER_DE));
  return;
} // add hl,de

void opcode_0x29()
{
  if (prefix_dd == 1)
    Writeback_Reg16(REG_IX, ADD_Words(REGISTER_IX, REGISTER_IX));
  else // add ix,ix
    if (prefix_fd == 1)
      Writeback_Reg16(REG_IY, ADD_Words(REGISTER_IY, REGISTER_IY));
    else // add iy,iy
      Writeback_Reg16(REG_HL, ADD_Words(REGISTER_HL, REGISTER_HL));
  return;
} // add hl,hl

void opcode_0x39()
{
  if (prefix_dd == 1)
    Writeback_Reg16(REG_IX, ADD_Words(REGISTER_IX, register_sp));
  else // add ix,sp
    if (prefix_fd == 1)
      Writeback_Reg16(REG_IY, ADD_Words(REGISTER_IY, register_sp));
    else // add iy,sp
      Writeback_Reg16(REG_HL, ADD_Words(REGISTER_HL, register_sp));
  return;
} // add hl,sp

void opcode_0xC6()
{
  register_a = ADD_Bytes(register_a, Fetch_byte()); // add a,*
  return;
}
void opcode_0x87()
{
  register_a = ADD_Bytes(register_a, register_a); // add a,a
  return;
}
void opcode_0x80()
{
  register_a = ADD_Bytes(register_a, register_b); // add a,b
  return;
}
void opcode_0x81()
{
  register_a = ADD_Bytes(register_a, register_c); // add a,c
  return;
}
void opcode_0x82()
{
  register_a = ADD_Bytes(register_a, register_d); // add a,d
  return;
}
void opcode_0x83()
{
  register_a = ADD_Bytes(register_a, register_e); // add a,e
  return;
}

void opcode_0x84()
{
  if (prefix_dd == 1)
  {
    register_a = ADD_Bytes(register_a, register_ixh);
  }
  else // add a, h/ixh/iyh
    if (prefix_fd == 1)
    {
      register_a = ADD_Bytes(register_a, register_iyh);
    }
    else
    {
      register_a = ADD_Bytes(register_a, register_h);
    }
  return;
}

void opcode_0x85()
{
  if (prefix_dd == 1)
  {
    register_a = ADD_Bytes(register_a, register_ixl);
  }
  else // add a, l/ixl/iyl
    if (prefix_fd == 1)
    {
      register_a = ADD_Bytes(register_a, register_iyl);
    }
    else
    {
      register_a = ADD_Bytes(register_a, register_l);
    }
  return;
}

void opcode_0x86()
{
  if (prefix_dd == 1)
  {
    register_a = ADD_Bytes(register_a, readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else // add a, (hl)/(ix+*)/(iy+*)
    if (prefix_fd == 1)
    {
      register_a = ADD_Bytes(register_a, readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    }
    else
    {
      register_a = ADD_Bytes(register_a, readByte(REGISTER_HL));
    }
  return;
}

void opcode_0xED4A()
{
  with_carry = 1; // adc hl,bc
  Writeback_Reg16(REG_HL, ADD_Words2(REGISTER_HL, REGISTER_BC));
  return;
}
void opcode_0xED5A()
{
  with_carry = 1; // adc hl,de
  Writeback_Reg16(REG_HL, ADD_Words2(REGISTER_HL, REGISTER_DE));
  return;
}
void opcode_0xED6A()
{
  with_carry = 1; // adc hl,hl
  Writeback_Reg16(REG_HL, ADD_Words2(REGISTER_HL, REGISTER_HL));
  return;
}
void opcode_0xED7A()
{
  with_carry = 1; // adc hl,sp
  Writeback_Reg16(REG_HL, ADD_Words2(REGISTER_HL, register_sp));
  return;
}

void opcode_0xCE()
{
  with_carry = 1; // adc *
  register_a = ADD_Bytes(register_a, Fetch_byte());
  return;
}
void opcode_0x8F()
{
  with_carry = 1; // adc a,a
  register_a = ADD_Bytes(register_a, register_a);
  return;
}
void opcode_0x88()
{
  with_carry = 1; // adc a,b
  register_a = ADD_Bytes(register_a, register_b);
  return;
}
void opcode_0x89()
{
  with_carry = 1; // adc a,c
  register_a = ADD_Bytes(register_a, register_c);
  return;
}
void opcode_0x8A()
{
  with_carry = 1; // adc a,d
  register_a = ADD_Bytes(register_a, register_d);
  return;
}
void opcode_0x8B()
{
  with_carry = 1; // adc a,e
  register_a = ADD_Bytes(register_a, register_e);
  return;
}

void opcode_0x8C()
{
  if (prefix_dd == 1)
  {
    with_carry = 1;
    register_a = ADD_Bytes(register_a, register_ixh);
  }
  else // adc a, h/ixh/iyh
    if (prefix_fd == 1)
    {
      with_carry = 1;
      register_a = ADD_Bytes(register_a, register_iyh);
    }
    else
    {
      with_carry = 1;
      register_a = ADD_Bytes(register_a, register_h);
    }
  return;
}

void opcode_0x8D()
{
  if (prefix_dd == 1)
  {
    with_carry = 1;
    register_a = ADD_Bytes(register_a, register_ixl);
  }
  else // adc a, l/ixl/iyl
    if (prefix_fd == 1)
    {
      with_carry = 1;
      register_a = ADD_Bytes(register_a, register_iyl);
    }
    else
    {
      with_carry = 1;
      register_a = ADD_Bytes(register_a, register_l);
    }
  return;
}

void opcode_0x8E()
{
  if (prefix_dd == 1)
  {
    with_carry = 1;
    register_a = ADD_Bytes(register_a, readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else // adc a, (hl)/(ix+*)/(iy+*)
    if (prefix_fd == 1)
    {
      with_carry = 1;
      register_a = ADD_Bytes(register_a, readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    }
    else
    {
      with_carry = 1;
      register_a = ADD_Bytes(register_a, readByte(REGISTER_HL));
    }
  return;
}

void opcode_0xED44()
{
  register_a = SUB_Bytes(0, register_a); // neg a
  return;
}
void opcode_0xD6()
{
  register_a = SUB_Bytes(register_a, Fetch_byte()); // sub a,*
  return;
}
void opcode_0x97()
{
  register_a = SUB_Bytes(register_a, register_a); // sub a,a
  return;
}
void opcode_0x90()
{
  register_a = SUB_Bytes(register_a, register_b); // sub a,b
  return;
}
void opcode_0x91()
{
  register_a = SUB_Bytes(register_a, register_c); // sub a,c
  return;
}
void opcode_0x92()
{
  register_a = SUB_Bytes(register_a, register_d); // sub a,d
  return;
}
void opcode_0x93()
{
  register_a = SUB_Bytes(register_a, register_e); // sub a,e
  return;
}

void opcode_0x94()
{
  if (prefix_dd == 1)
  {
    register_a = SUB_Bytes(register_a, register_ixh);
  }
  else // sub a, h/ixh/iyh
    if (prefix_fd == 1)
    {
      register_a = SUB_Bytes(register_a, register_iyh);
    }
    else
    {
      register_a = SUB_Bytes(register_a, register_h);
    }
  return;
}

void opcode_0x95()
{
  if (prefix_dd == 1)
  {
    register_a = SUB_Bytes(register_a, register_ixl);
  }
  else // sub a, l/ixl/iyl
    if (prefix_fd == 1)
    {
      register_a = SUB_Bytes(register_a, register_iyl);
    }
    else
    {
      register_a = SUB_Bytes(register_a, register_l);
    }
  return;
}

void opcode_0x96()
{
  if (prefix_dd == 1)
  {
    register_a = SUB_Bytes(register_a, readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else // sub a, (hl)/(ix+*)/(iy+*)
    if (prefix_fd == 1)
    {
      register_a = SUB_Bytes(register_a, readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    }
    else
    {
      register_a = SUB_Bytes(register_a, readByte(REGISTER_HL));
    }
  return;
}

void opcode_0xED42()
{
  with_carry = 1; // sbc hl,bc
  Writeback_Reg16(REG_HL, SUB_Words(REGISTER_HL, REGISTER_BC));
  return;
}
void opcode_0xED52()
{
  with_carry = 1; // sbc hl,de
  Writeback_Reg16(REG_HL, SUB_Words(REGISTER_HL, REGISTER_DE));
  return;
}
void opcode_0xED62()
{
  with_carry = 1; // sbc hl,hl
  Writeback_Reg16(REG_HL, SUB_Words(REGISTER_HL, REGISTER_HL));
  return;
}
void opcode_0xED72()
{
  with_carry = 1; // sbc hl,sp
  Writeback_Reg16(REG_HL, SUB_Words(REGISTER_HL, register_sp));
  return;
}

void opcode_0xDE()
{
  with_carry = 1; // sbc a,*
  register_a = SUB_Bytes(register_a, Fetch_byte());
  return;
}
void opcode_0x9F()
{
  with_carry = 1; // sbc a,a
  register_a = SUB_Bytes(register_a, register_a);
  return;
}
void opcode_0x98()
{
  with_carry = 1; // sbc a,b
  register_a = SUB_Bytes(register_a, register_b);
  return;
}
void opcode_0x99()
{
  with_carry = 1; // sbc a,c
  register_a = SUB_Bytes(register_a, register_c);
  return;
}
void opcode_0x9A()
{
  with_carry = 1; // sbc a,d
  register_a = SUB_Bytes(register_a, register_d);
  return;
}
void opcode_0x9B()
{
  with_carry = 1; // sbc a,e
  register_a = SUB_Bytes(register_a, register_e);
  return;
}

void opcode_0x9C()
{
  if (prefix_dd == 1)
  {
    with_carry = 1;
    register_a = SUB_Bytes(register_a, register_ixh);
  }
  else // sbc a, h/ixh/iyh
    if (prefix_fd == 1)
    {
      with_carry = 1;
      register_a = SUB_Bytes(register_a, register_iyh);
    }
    else
    {
      with_carry = 1;
      register_a = SUB_Bytes(register_a, register_h);
    }
  return;
}

void opcode_0x9D()
{
  if (prefix_dd == 1)
  {
    with_carry = 1;
    register_a = SUB_Bytes(register_a, register_ixl);
  }
  else // sbc a, l/ixl/iyl
    if (prefix_fd == 1)
    {
      with_carry = 1;
      register_a = SUB_Bytes(register_a, register_iyl);
    }
    else
    {
      with_carry = 1;
      register_a = SUB_Bytes(register_a, register_l);
    }
  return;
}

void opcode_0x9E()
{
  if (prefix_dd == 1)
  {
    with_carry = 1;
    register_a = SUB_Bytes(register_a, readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else // sbc a, (hl)/(ix+*)/(iy+*)
    if (prefix_fd == 1)
    {
      with_carry = 1;
      register_a = SUB_Bytes(register_a, readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    }
    else
    {
      with_carry = 1;
      register_a = SUB_Bytes(register_a, readByte(REGISTER_HL));
    }
  return;
}

void opcode_0xFE()
{
  cp_opcode = 1; // cp *
  SUB_Bytes(register_a, Fetch_byte());
  return;
}
void opcode_0xBF()
{
  cp_opcode = 1; // cp a,a
  SUB_Bytes(register_a, register_a);
  return;
}
void opcode_0xB8()
{
  cp_opcode = 1; // cp a,b
  SUB_Bytes(register_a, register_b);
  return;
}
void opcode_0xB9()
{
  cp_opcode = 1; // cp a,c
  SUB_Bytes(register_a, register_c);
  return;
}
void opcode_0xBA()
{
  cp_opcode = 1; // cp a,d
  SUB_Bytes(register_a, register_d);
  return;
}
void opcode_0xBB()
{
  cp_opcode = 1; // cp a,e
  SUB_Bytes(register_a, register_e);
  return;
}

void opcode_0xBC()
{
  if (prefix_dd == 1)
  {
    cp_opcode = 1;
    SUB_Bytes(register_a, register_ixh);
  }
  else // cp a, h/ixh/iyh
    if (prefix_fd == 1)
    {
      cp_opcode = 1;
      SUB_Bytes(register_a, register_iyh);
    }
    else
    {
      cp_opcode = 1;
      SUB_Bytes(register_a, register_h);
    }
  return;
}

void opcode_0xBD()
{
  if (prefix_dd == 1)
  {
    cp_opcode = 1;
    SUB_Bytes(register_a, register_ixl);
  }
  else // cp a, l/ixl/iyl
    if (prefix_fd == 1)
    {
      cp_opcode = 1;
      SUB_Bytes(register_a, register_iyl);
    }
    else
    {
      cp_opcode = 1;
      SUB_Bytes(register_a, register_l);
    }
  return;
}

void opcode_0xBE()
{
  if (prefix_dd == 1)
  {
    cp_opcode = 1;
    SUB_Bytes(register_a, readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else // cp a, (hl)/(ix+*)/(iy+*)
    if (prefix_fd == 1)
    {
      cp_opcode = 1;
      SUB_Bytes(register_a, readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
    }
    else
    {
      cp_opcode = 1;
      SUB_Bytes(register_a, readByte(REGISTER_HL));
    }
  return;
}

void opcode_0x33()
{
  register_sp++; // inc sp
  return;
}
void opcode_0x03()
{
  Writeback_Reg16(REG_BC, (REGISTER_BC) + 1); // inc bc
  return;
}
void opcode_0x13()
{
  Writeback_Reg16(REG_DE, (REGISTER_DE) + 1); // inc de
  return;
}
void opcode_0x23()
{
  if (prefix_dd == 1)
  {
    Writeback_Reg16(REG_IX, (REGISTER_IX) + 1);
  }
  else // inc hl
    if (prefix_fd == 1)
    {
      Writeback_Reg16(REG_IY, (REGISTER_IY) + 1);
    }
    else
    {
      Writeback_Reg16(REG_HL, (REGISTER_HL) + 1);
    }
  return;
}

void opcode_0x3C()
{
  inc_dec = 1; // inc a
  register_a = ADD_Bytes(register_a, 0x1);
  return;
}
void opcode_0x04()
{
  inc_dec = 1; // inc b
  register_b = ADD_Bytes(register_b, 0x1);
  return;
}
void opcode_0x0C()
{
  inc_dec = 1; // inc c
  register_c = ADD_Bytes(register_c, 0x1);
  return;
}
void opcode_0x14()
{
  inc_dec = 1; // inc d
  register_d = ADD_Bytes(register_d, 0x1);
  return;
}
void opcode_0x1C()
{
  inc_dec = 1; // inc e
  register_e = ADD_Bytes(register_e, 0x1);
  return;
}

void opcode_0x24()
{
  inc_dec = 1;
  if (prefix_dd == 1)
  {
    register_ixh = ADD_Bytes(register_ixh, 0x1);
  }
  else // inc ixh, iyh, h
    if (prefix_fd == 1)
    {
      register_iyh = ADD_Bytes(register_iyh, 0x1);
    }
    else
    {
      register_h = ADD_Bytes(register_h, 0x1);
    }
  return;
}

void opcode_0x2C()
{
  inc_dec = 1;
  if (prefix_dd == 1)
  {
    register_ixl = ADD_Bytes(register_ixl, 0x1);
  }
  else // inc ixl, iyl, l
    if (prefix_fd == 1)
    {
      register_iyl = ADD_Bytes(register_iyl, 0x1);
    }
    else
    {
      register_l = ADD_Bytes(register_l, 0x1);
    }
  return;
}

void opcode_0x34()
{
  inc_dec = 1;
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(Fetch_byte());
    writeByte(temp16, ADD_Bytes(readByte(temp16), 0x1));
  }
  else // inc ix+*, iy+*, (hl)
    if (prefix_fd == 1)
    {
      temp16 = REGISTER_IY + Sign_Extend(Fetch_byte());
      writeByte(temp16, ADD_Bytes(readByte(temp16), 0x1));
    }
    else
    {
      writeByte(REGISTER_HL, ADD_Bytes(readByte(REGISTER_HL), 0x1));
    }
  return;
}

// -----------
void opcode_0x3B()
{
  register_sp--; // dec sp
  return;
}
void opcode_0x0B()
{
  Writeback_Reg16(REG_BC, (REGISTER_BC)-1); // dec bc
  return;
}
void opcode_0x1B()
{
  Writeback_Reg16(REG_DE, (REGISTER_DE)-1); // dec de
  return;
}
void opcode_0x2B()
{
  if (prefix_dd == 1)
  {
    Writeback_Reg16(REG_IX, (REGISTER_IX)-1);
  }
  else // dec hl
    if (prefix_fd == 1)
    {
      Writeback_Reg16(REG_IY, (REGISTER_IY)-1);
    }
    else
    {
      Writeback_Reg16(REG_HL, (REGISTER_HL)-1);
    }
  return;
}
// -----------
void opcode_0x3D()
{
  inc_dec = 1; // dec a
  register_a = SUB_Bytes(register_a, 0x1);
  return;
}
void opcode_0x05()
{
  inc_dec = 1; // dec b
  register_b = SUB_Bytes(register_b, 0x1);
  return;
}
void opcode_0x0D()
{
  inc_dec = 1; // dec c
  register_c = SUB_Bytes(register_c, 0x1);
  return;
}
void opcode_0x15()
{
  inc_dec = 1; // dec d
  register_d = SUB_Bytes(register_d, 0x1);
  return;
}
void opcode_0x1D()
{
  inc_dec = 1; // dec e
  register_e = SUB_Bytes(register_e, 0x1);
  return;
}

void opcode_0x25()
{
  inc_dec = 1;
  if (prefix_dd == 1)
  {
    register_ixh = SUB_Bytes(register_ixh, 0x1);
  }
  else // dec ixh, iyh, h
    if (prefix_fd == 1)
    {
      register_iyh = SUB_Bytes(register_iyh, 0x1);
    }
    else
    {
      register_h = SUB_Bytes(register_h, 0x1);
    }
  return;
}

void opcode_0x2D()
{
  inc_dec = 1;
  if (prefix_dd == 1)
  {
    register_ixl = SUB_Bytes(register_ixl, 0x1);
  }
  else // dec ixl, iyl, l
    if (prefix_fd == 1)
    {
      register_iyl = SUB_Bytes(register_iyl, 0x1);
    }
    else
    {
      register_l = SUB_Bytes(register_l, 0x1);
    }
  return;
}

void opcode_0x35()
{
  inc_dec = 1;
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(Fetch_byte());
    writeByte(temp16, SUB_Bytes(readByte(temp16), 0x1));
  }
  else // dec ix+*, iy+*, (hl)
    if (prefix_fd == 1)
    {
      temp16 = REGISTER_IY + Sign_Extend(Fetch_byte());
      writeByte(temp16, SUB_Bytes(readByte(temp16), 0x1));
    }
    else
    {
      writeByte(REGISTER_HL, SUB_Bytes(readByte(REGISTER_HL), 0x1));
    }
  return;
}

// ------------------------------------------------------
// Input and Output
// ------------------------------------------------------
void Flags_IO(uint8_t local_data)
{

  register_f = register_f & 0x29;                     // Clear S, Z, H, P, N flags
  register_f = register_f | Parity_Array[local_data]; // Set P flag
  register_f = register_f | (local_data & 0x80);      // Set S flag
  if (local_data == 0)
    register_f = register_f | 0x40; // Set Z flag
  return;
}
void opcode_0xDB()
{
  register_a = BIUBusCycle(IO_READ_BYTE, Fetch_byte(), 0x00); // in a,(*)
  return;
}
void opcode_0xED78()
{
  register_a = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in a,(c)
  Flags_IO(register_a);
  return;
}
void opcode_0xED40()
{
  register_b = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in b,(c)
  Flags_IO(register_b);
  return;
}
void opcode_0xED48()
{
  register_c = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in c,(c)
  Flags_IO(register_c);
  return;
}
void opcode_0xED50()
{
  register_d = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in d,(c)
  Flags_IO(register_d);
  return;
}
void opcode_0xED58()
{
  register_e = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in e,(c)
  Flags_IO(register_e);
  return;
}
void opcode_0xED60()
{
  register_h = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in h,(c)
  Flags_IO(register_h);
  return;
}
void opcode_0xED68()
{
  register_l = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in l,(c)
  Flags_IO(register_l);
  return;
}
void opcode_0xED70()
{
  temp8 = BIUBusCycle(IO_READ_BYTE, register_c, 0x00); // in(c)
  Flags_IO(temp8);
  return;
}

void opcode_0xD3()
{
  BIUBusCycle(IO_WRITE_BYTE, Fetch_byte(), register_a); // out (*),a
  return;
}
void opcode_0xED79()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, register_a); // out (c),a
  return;
}
void opcode_0xED41()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, register_b); // out (c),b
  return;
}
void opcode_0xED49()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, register_c); // out (c),c
  return;
}
void opcode_0xED51()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, register_d); // out (c),d
  return;
}
void opcode_0xED59()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, register_e); // out (c),e
  return;
}
void opcode_0xED61()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, register_h); // out (c),h
  return;
}
void opcode_0xED69()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, register_l); // out (c),l
  return;
}
void opcode_0xED71()
{
  BIUBusCycle(IO_WRITE_BYTE, register_c, 0x0); // out (c),0x0
  return;
}

// ------------------------------------------------------
// Shifts and Rotates
// ------------------------------------------------------

void Flags_Shifts(uint8_t local_data)
{
  if (prefix_cb == 0)
  {
    register_f = register_f & 0xC5;                // Clear H, N, 5, 3 flags
    register_f = register_f | (local_data & 0x28); // Set flag bits 5,3 to ALU results
  }
  else
  {
    register_f = register_f & 0x01;                     // Clear H, N, P, S, Z, 5, 3  flags
    register_f = register_f | Parity_Array[local_data]; // Set P flag
    register_f = register_f | (local_data & 0x80);      // Set S flag
    if (local_data == 0)
      register_f = register_f | 0x40;              // Set Z flag
    register_f = register_f | (local_data & 0x28); // Set flag bits 5,3 to ALU results
  }
  return;
}

uint8_t RLC(uint8_t local_data)
{
  register_f = register_f & 0xFE;                // Clear C flag
  register_f = register_f | (local_data >> 7);   // C Flag = bit[7]
  local_data = (local_data << 1);                // Shift register_a left 1 bit
  local_data = local_data | (register_f & 0x01); // register_a bit[0] = bit shifted out of bit[7]
  Flags_Shifts(local_data);
  return local_data;
} // rlca

uint8_t RRC(uint8_t local_data)
{
  register_f = register_f & 0xFE;                       // Clear C flag
  register_f = register_f | (local_data & 0x01);        // C Flag = bit[0]
  local_data = (local_data >> 1);                       // Shift register_a left 1 bit
  local_data = local_data | ((register_f & 0x01) << 7); // register_a bit[7] = bit shifted out of bit[0]
  Flags_Shifts(local_data);
  return local_data;
} // rrca

uint8_t RL(uint8_t local_data)
{
  temp8 = register_f & 0x01;                   // Store old C flag
  register_f = register_f & 0xFE;              // Clear C flag
  register_f = register_f | (local_data >> 7); // C Flag = bit[7]
  local_data = (local_data << 1);              // Shift register_a left 1 bit
  local_data = local_data | temp8;             // register_a bit[0] = old C Flag
  Flags_Shifts(local_data);
  return local_data;
} // rla

uint8_t RR(uint8_t local_data)
{
  temp8 = register_f & 0x01;                     // Store old C flag
  register_f = register_f & 0xFE;                // Clear C flag
  register_f = register_f | (local_data & 0x01); // C Flag = bit[0]
  local_data = (local_data >> 1);                // Shift register_a left 1 bit
  local_data = local_data | (temp8 << 7);        // register_a bit[7] = old C Flag
  Flags_Shifts(local_data);
  return local_data;
} // rra

uint8_t SLA(uint8_t local_data)
{
  register_f = register_f & 0xFE;              // Clear C flag
  register_f = register_f | (local_data >> 7); // C Flag = bit[7]
  local_data = (local_data << 1);              // Shift register_a left 1 bit
  Flags_Shifts(local_data);
  return local_data;
} // sla

uint8_t SRA(uint8_t local_data)
{
  register_f = register_f & 0xFE;                // Clear C flag
  register_f = register_f | (local_data & 0x01); // C Flag = bit[0]
  local_data = (local_data >> 1);                // Shift register_a right 1 bit
  if (local_data & 0x40)
    local_data = local_data | 0x80; // Keep bit[7] the same as before the shift
  Flags_Shifts(local_data);
  return local_data;
} // sra

uint8_t SLL(uint8_t local_data)
{
  register_f = register_f & 0xFE;              // Clear C flag
  register_f = register_f | (local_data >> 7); // C Flag = bit[7]
  local_data = (local_data << 1);              // Shift register_a left 1 bit
  local_data = local_data | 0x1;               // Set bit[0] to 1
  Flags_Shifts(local_data);
  return local_data;
} // sll

uint8_t SRL(uint8_t local_data)
{
  register_f = register_f & 0xFE;                // Clear C flag
  register_f = register_f | (local_data & 0x01); // C Flag = bit[0]
  local_data = (local_data >> 1);                // Shift register_a left 1 bit
  Flags_Shifts(local_data);
  return local_data;
} // rra

void opcode_0x07()
{
  register_a = RLC(register_a); // rlc
  return;
}
void opcode_0xCB00()
{
  if (prefix_dd == 1)
  {
    register_b = RLC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = RLC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = RLC(register_b);
  }
  return;
}
void opcode_0xCB01()
{
  if (prefix_dd == 1)
  {
    register_c = RLC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = RLC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = RLC(register_c);
  }
  return;
}
void opcode_0xCB02()
{
  if (prefix_dd == 1)
  {
    register_d = RLC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = RLC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = RLC(register_d);
  }
  return;
}
void opcode_0xCB03()
{
  if (prefix_dd == 1)
  {
    register_e = RLC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = RLC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = RLC(register_e);
  }
  return;
}
void opcode_0xCB04()
{
  if (prefix_dd == 1)
  {
    register_h = RLC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = RLC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = RLC(register_h);
  }
  return;
}
void opcode_0xCB05()
{
  if (prefix_dd == 1)
  {
    register_l = RLC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = RLC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = RLC(register_l);
  }
  return;
}
void opcode_0xCB07()
{
  if (prefix_dd == 1)
  {
    register_a = RLC(readByte(REGISTER_IX + Sign_Extend(cb_prefix_offset)));
  }
  else if (prefix_fd == 1)
  {
    register_a = RLC(readByte(REGISTER_IY + Sign_Extend(cb_prefix_offset)));
  }
  else
  {
    register_a = RLC(register_a);
  }
  return;
}
void opcode_0xCB06()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RLC(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RLC(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), RLC(readByte(REGISTER_HL)));
  return;
}

void opcode_0x0F()
{
  register_a = RRC(register_a); // rrc
  return;
}
void opcode_0xCB08()
{
  if (prefix_dd == 1)
  {
    register_b = RRC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = RRC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = RRC(register_b);
  }
  return;
}
void opcode_0xCB09()
{
  if (prefix_dd == 1)
  {
    register_c = RRC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = RRC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = RRC(register_c);
  }
  return;
}
void opcode_0xCB0A()
{
  if (prefix_dd == 1)
  {
    register_d = RRC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = RRC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = RRC(register_d);
  }
  return;
}
void opcode_0xCB0B()
{
  if (prefix_dd == 1)
  {
    register_e = RRC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = RRC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = RRC(register_e);
  }
  return;
}
void opcode_0xCB0C()
{
  if (prefix_dd == 1)
  {
    register_h = RRC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = RRC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = RRC(register_h);
  }
  return;
}
void opcode_0xCB0D()
{
  if (prefix_dd == 1)
  {
    register_l = RRC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = RRC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = RRC(register_l);
  }
  return;
}
void opcode_0xCB0F()
{
  if (prefix_dd == 1)
  {
    register_a = RRC(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_a = RRC(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = RRC(register_a);
  }
  return;
}
void opcode_0xCB0E()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RRC(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RRC(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), RRC(readByte(REGISTER_HL)));
  return;
}

void opcode_0x17()
{
  register_a = RL(register_a); // rl
  return;
}
void opcode_0xCB10()
{
  if (prefix_dd == 1)
  {
    register_b = RL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = RL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = RL(register_b);
  }
  return;
}
void opcode_0xCB11()
{
  if (prefix_dd == 1)
  {
    register_c = RL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = RL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = RL(register_c);
  }
  return;
}
void opcode_0xCB12()
{
  if (prefix_dd == 1)
  {
    register_d = RL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = RL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = RL(register_d);
  }
  return;
}
void opcode_0xCB13()
{
  if (prefix_dd == 1)
  {
    register_e = RL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = RL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = RL(register_e);
  }
  return;
}
void opcode_0xCB14()
{
  if (prefix_dd == 1)
  {
    register_h = RL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = RL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = RL(register_h);
  }
  return;
}
void opcode_0xCB15()
{
  if (prefix_dd == 1)
  {
    register_l = RL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = RL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = RL(register_l);
  }
  return;
}
void opcode_0xCB17()
{
  if (prefix_dd == 1)
  {
    register_a = RL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_a = RL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = RL(register_a);
  }
  return;
}
void opcode_0xCB16()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RL(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RL(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), RL(readByte(REGISTER_HL)));
  return;
}

void opcode_0x1F()
{
  register_a = RR(register_a); // rr
  return;
}
void opcode_0xCB18()
{
  if (prefix_dd == 1)
  {
    register_b = RR(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = RR(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = RR(register_b);
  }
  return;
}
void opcode_0xCB19()
{
  if (prefix_dd == 1)
  {
    register_c = RR(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = RR(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = RR(register_c);
  }
  return;
}
void opcode_0xCB1A()
{
  if (prefix_dd == 1)
  {
    register_d = RR(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = RR(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = RR(register_d);
  }
  return;
}
void opcode_0xCB1B()
{
  if (prefix_dd == 1)
  {
    register_e = RR(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = RR(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = RR(register_e);
  }
  return;
}
void opcode_0xCB1C()
{
  if (prefix_dd == 1)
  {
    register_h = RR(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = RR(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = RR(register_h);
  }
  return;
}
void opcode_0xCB1D()
{
  if (prefix_dd == 1)
  {
    register_l = RR(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = RR(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = RR(register_l);
  }
  return;
}
void opcode_0xCB1F()
{
  if (prefix_dd == 1)
  {
    register_a = RR(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_a = RR(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = RR(register_a);
  }
  return;
}
void opcode_0xCB1E()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RR(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RR(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), RR(readByte(REGISTER_HL)));
  return;
}

// ----

void opcode_0xCB20()
{
  if (prefix_dd == 1)
  {
    register_b = SLA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = SLA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = SLA(register_b);
  }
  return;
}
void opcode_0xCB21()
{
  if (prefix_dd == 1)
  {
    register_c = SLA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = SLA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = SLA(register_c);
  }
  return;
}
void opcode_0xCB22()
{
  if (prefix_dd == 1)
  {
    register_d = SLA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = SLA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = SLA(register_d);
  }
  return;
}
void opcode_0xCB23()
{
  if (prefix_dd == 1)
  {
    register_e = SLA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = SLA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = SLA(register_e);
  }
  return;
}
void opcode_0xCB24()
{
  if (prefix_dd == 1)
  {
    register_h = SLA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = SLA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = SLA(register_h);
  }
  return;
}
void opcode_0xCB25()
{
  if (prefix_dd == 1)
  {
    register_l = SLA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = SLA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = SLA(register_l);
  }
  return;
}
void opcode_0xCB27()
{
  if (prefix_dd == 1)
  {
    register_a = SLA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_a = SLA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = SLA(register_a);
  }
  return;
}
void opcode_0xCB26()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SLA(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SLA(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), SLA(readByte(REGISTER_HL)));
  return;
}

void opcode_0xCB28()
{
  if (prefix_dd == 1)
  {
    register_b = SRA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = SRA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = SRA(register_b);
  }
  return;
}
void opcode_0xCB29()
{
  if (prefix_dd == 1)
  {
    register_c = SRA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = SRA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = SRA(register_c);
  }
  return;
}
void opcode_0xCB2A()
{
  if (prefix_dd == 1)
  {
    register_d = SRA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = SRA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = SRA(register_d);
  }
  return;
}
void opcode_0xCB2B()
{
  if (prefix_dd == 1)
  {
    register_e = SRA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = SRA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = SRA(register_e);
  }
  return;
}
void opcode_0xCB2C()
{
  if (prefix_dd == 1)
  {
    register_h = SRA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = SRA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = SRA(register_h);
  }
  return;
}
void opcode_0xCB2D()
{
  if (prefix_dd == 1)
  {
    register_l = SRA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = SRA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = SRA(register_l);
  }
  return;
}
void opcode_0xCB2F()
{
  if (prefix_dd == 1)
  {
    register_a = SRA(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_a = SRA(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = SRA(register_a);
  }
  return;
}
void opcode_0xCB2E()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SRA(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SRA(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), SRA(readByte(REGISTER_HL)));
  return;
}

void opcode_0xCB30()
{
  if (prefix_dd == 1)
  {
    register_b = SLL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = SLL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = SLL(register_b);
  }
  return;
}
void opcode_0xCB31()
{
  if (prefix_dd == 1)
  {
    register_c = SLL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = SLL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = SLL(register_c);
  }
  return;
}
void opcode_0xCB32()
{
  if (prefix_dd == 1)
  {
    register_d = SLL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = SLL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = SLL(register_d);
  }
  return;
}
void opcode_0xCB33()
{
  if (prefix_dd == 1)
  {
    register_e = SLL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = SLL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = SLL(register_e);
  }
  return;
}
void opcode_0xCB34()
{
  if (prefix_dd == 1)
  {
    register_h = SLL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = SLL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = SLL(register_h);
  }
  return;
}
void opcode_0xCB35()
{
  if (prefix_dd == 1)
  {
    register_l = SLL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = SLL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = SLL(register_l);
  }
  return;
}
void opcode_0xCB37()
{
  if (prefix_dd == 1)
  {
    register_a = SLL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_a = SLL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = SLL(register_a);
  }
  return;
}
void opcode_0xCB36()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SLL(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SLL(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), SLL(readByte(REGISTER_HL)));
  return;
}

void opcode_0xCB38()
{
  if (prefix_dd == 1)
  {
    register_b = SRL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_b = SRL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = SRL(register_b);
  }
  return;
}
void opcode_0xCB39()
{
  if (prefix_dd == 1)
  {
    register_c = SRL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_c = SRL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = SRL(register_c);
  }
  return;
}
void opcode_0xCB3A()
{
  if (prefix_dd == 1)
  {
    register_d = SRL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_d = SRL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = SRL(register_d);
  }
  return;
}
void opcode_0xCB3B()
{
  if (prefix_dd == 1)
  {
    register_e = SRL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_e = SRL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = SRL(register_e);
  }
  return;
}
void opcode_0xCB3C()
{
  if (prefix_dd == 1)
  {
    register_h = SRL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_h = SRL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = SRL(register_h);
  }
  return;
}
void opcode_0xCB3D()
{
  if (prefix_dd == 1)
  {
    register_l = SRL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_l = SRL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = SRL(register_l);
  }
  return;
}
void opcode_0xCB3F()
{
  if (prefix_dd == 1)
  {
    register_a = SRL(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    register_a = SRL(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = SRL(register_a);
  }
  return;
}
void opcode_0xCB3E()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SRL(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SRL(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), SRL(readByte(REGISTER_HL)));
  return;
}

void BIT(uint8_t local_data)
{
  uint8_t local_bitnum;
  register_f = register_f & 0x01; // Clear all flags except C
  local_bitnum = (CB_opcode >> 3) & 0x07;
  switch (local_bitnum)
  {
  case 0x00:
    temp8 = (local_data & 0x01);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break; // Set Z flag
  case 0x01:
    temp8 = (local_data & 0x02);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break;
  case 0x02:
    temp8 = (local_data & 0x04);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break;
  case 0x03:
    temp8 = (local_data & 0x08);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break;
  case 0x04:
    temp8 = (local_data & 0x10);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break;
  case 0x05:
    temp8 = (local_data & 0x20);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break;
  case 0x06:
    temp8 = (local_data & 0x40);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break;
  case 0x07:
    temp8 = (local_data & 0x80);
    if (temp8 == 0)
    {
      register_f = register_f | 0x40;
    }
    break;
  }

  register_f = register_f | 0x10;           // Set H flag
  register_f = register_f | (temp8 & 0x80); // Set S flag
  if (temp8 == 0)
    register_f = register_f | 0x04; // Set P flag

  if (special == 1)
  { // Special handlinig for (hl)
    clock_counter = clock_counter + 0x4;
    register_f = register_f | ((register_pc >> 8) & 0x28); // Set flag bits 5,3 to ALU results
  }
  else if (special == 2)
  {                                                   // Special handlinig for IX+*
    register_f = register_f | ((temp16 >> 8) & 0x28); // Set flag bits 5,3 to ALU results
  }

  else
  {                                                // Other opcodes
    register_f = register_f | (local_data & 0x28); // Set flag bits 5,3 to ALU results
  }

  special = 0;
  return;
} // bit

void opcode_0xCB_Bit_b()
{
  if (prefix_dd == 1)
  {
    BIT(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    BIT(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    BIT(register_b);
  }
  return;
}
void opcode_0xCB_Bit_c()
{
  if (prefix_dd == 1)
  {
    BIT(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    BIT(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    BIT(register_c);
  }
  return;
}
void opcode_0xCB_Bit_d()
{
  if (prefix_dd == 1)
  {
    BIT(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    BIT(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    BIT(register_d);
  }
  return;
}
void opcode_0xCB_Bit_e()
{
  if (prefix_dd == 1)
  {
    BIT(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    BIT(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    BIT(register_e);
  }
  return;
}
void opcode_0xCB_Bit_h()
{
  if (prefix_dd == 1)
  {
    BIT(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    BIT(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    BIT(register_h);
  }
  return;
}
void opcode_0xCB_Bit_l()
{
  if (prefix_dd == 1)
  {
    BIT(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    BIT(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    BIT(register_l);
  }
  return;
}
void opcode_0xCB_Bit_a()
{
  if (prefix_dd == 1)
  {
    BIT(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    BIT(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    BIT(register_a);
  }
  return;
}
void opcode_0xCB_Bit_hl()
{
  if (prefix_dd == 1)
  {
    special = 2;
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    BIT(readByte(temp16));
  }
  else if (prefix_fd == 1)
  {
    special = 2;
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    BIT(readByte(temp16));
  }
  else
  {
    special = 1;
    BIT(readByte(REGISTER_HL));
  }
  return;
}

uint8_t RES(uint8_t local_data)
{
  uint8_t local_bitnum;

  local_bitnum = (CB_opcode >> 3) & 0x07;
  switch (local_bitnum)
  {
  case 0x00:
    local_data = (local_data & (~(0x01)));
    break;
  case 0x01:
    local_data = (local_data & (~(0x02)));
    break;
  case 0x02:
    local_data = (local_data & (~(0x04)));
    break;
  case 0x03:
    local_data = (local_data & (~(0x08)));
    break;
  case 0x04:
    local_data = (local_data & (~(0x10)));
    break;
  case 0x05:
    local_data = (local_data & (~(0x20)));
    break;
  case 0x06:
    local_data = (local_data & (~(0x40)));
    break;
  case 0x07:
    local_data = (local_data & (~(0x80)));
    break;
  }
  return local_data;
} // res

void opcode_0xCB_Res_b()
{
  if (prefix_dd == 1)
  {
    RES(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    RES(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = RES(register_b);
  }
  return;
}
void opcode_0xCB_Res_c()
{
  if (prefix_dd == 1)
  {
    RES(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    RES(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = RES(register_c);
  }
  return;
}
void opcode_0xCB_Res_d()
{
  if (prefix_dd == 1)
  {
    RES(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    RES(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = RES(register_d);
  }
  return;
}
void opcode_0xCB_Res_e()
{
  if (prefix_dd == 1)
  {
    RES(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    RES(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = RES(register_e);
  }
  return;
}
void opcode_0xCB_Res_h()
{
  if (prefix_dd == 1)
  {
    RES(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    RES(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = RES(register_h);
  }
  return;
}
void opcode_0xCB_Res_l()
{
  if (prefix_dd == 1)
  {
    RES(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    RES(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = RES(register_l);
  }
  return;
}
void opcode_0xCB_Res_a()
{
  if (prefix_dd == 1)
  {
    RES(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    RES(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = RES(register_a);
  }
  return;
}
void opcode_0xCB_Res_hl()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RES(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, RES(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), RES(readByte(REGISTER_HL)));
  return;
}

uint8_t SET(uint8_t local_data)
{
  uint8_t local_bitnum;

  clock_counter = clock_counter + 0x3;
  local_bitnum = (CB_opcode >> 3) & 0x07;
  switch (local_bitnum)
  {
  case 0x00:
    local_data = (local_data | 0x01);
    break;
  case 0x01:
    local_data = (local_data | 0x02);
    break;
  case 0x02:
    local_data = (local_data | 0x04);
    break;
  case 0x03:
    local_data = (local_data | 0x08);
    break;
  case 0x04:
    local_data = (local_data | 0x10);
    break;
  case 0x05:
    local_data = (local_data | 0x20);
    break;
  case 0x06:
    local_data = (local_data | 0x40);
    break;
  case 0x07:
    local_data = (local_data | 0x80);
    break;
  }
  return local_data;
} // set

void opcode_0xCB_Set_b()
{
  if (prefix_dd == 1)
  {
    SET(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    SET(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_b = SET(register_b);
  }
  return;
}
void opcode_0xCB_Set_c()
{
  if (prefix_dd == 1)
  {
    SET(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    SET(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_c = SET(register_c);
  }
  return;
}
void opcode_0xCB_Set_d()
{
  if (prefix_dd == 1)
  {
    SET(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    SET(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_d = SET(register_d);
  }
  return;
}
void opcode_0xCB_Set_e()
{
  if (prefix_dd == 1)
  {
    SET(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    SET(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_e = SET(register_e);
  }
  return;
}
void opcode_0xCB_Set_h()
{
  if (prefix_dd == 1)
  {
    SET(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    SET(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_h = SET(register_h);
  }
  return;
}
void opcode_0xCB_Set_l()
{
  if (prefix_dd == 1)
  {
    SET(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    SET(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_l = SET(register_l);
  }
  return;
}
void opcode_0xCB_Set_a()
{
  if (prefix_dd == 1)
  {
    SET(readByte(REGISTER_IX + Sign_Extend(Fetch_byte())));
  }
  else if (prefix_fd == 1)
  {
    SET(readByte(REGISTER_IY + Sign_Extend(Fetch_byte())));
  }
  else
  {
    register_a = SET(register_a);
  }
  return;
}
void opcode_0xCB_Set_hl()
{
  if (prefix_dd == 1)
  {
    temp16 = REGISTER_IX + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SET(readByte(temp16)));
  }
  else if (prefix_fd == 1)
  {
    temp16 = REGISTER_IY + Sign_Extend(cb_prefix_offset);
    writeByte(temp16, SET(readByte(temp16)));
  }
  else
    writeByte((REGISTER_HL), SET(readByte(REGISTER_HL)));
  return;
}

void opcode_0x76()
{ // Halt

  digitalWriteFast(PIN_HALT, 0x0);
  halt_in_progress = 1;
  register_pc--;
  return;
}

void opcode_0x27()
{                                 // daa
  register_f = register_f & 0x13; // Clear S, Z, P Flags
  temp8 = 0;
  if (((0x0f & register_a) > 0x09) || (flag_h == 1))
  {
    temp8 = temp8 + 0x06;
  }
  if (((register_a) > 0x99) || (flag_c == 1))
  {
    temp8 = temp8 + 0x60; // Set C Flag
    register_f = register_f | 0x01;
  }

  if (flag_n == 1)
  {
    if (((0x0F & register_a) < 0x06) && (flag_h == 1))
      register_f = register_f | 0x10;
    else
      register_f = register_f & 0xEF; // Set H Flag
    register_a = register_a - temp8;
  }
  else
  {
    if ((0x0F & register_a) > 0x09)
      register_f = register_f | 0x10;
    else
      register_f = register_f & 0xEF; // Set H Flag
    register_a = register_a + temp8;
  }

  if (register_a & 0x80)
    register_f = register_f | 0x80; // Set S Flag
  if (register_a == 0)
    register_f = register_f | 0x40;                   // Set Z Flag
  register_f = register_f | Parity_Array[register_a]; // Set P flag
  register_f = register_f | (register_a & 0x28);      // Set flag bits 5,3 to ALU results
  return;
}

void opcode_0xEDA2()
{                                 // ini
  register_f = register_f & 0xBF; // Clear Z flag
  writeByte(REGISTER_HL, BIUBusCycle(IO_READ_BYTE, register_c, 0x00));
  Writeback_Reg16(REG_HL, (REGISTER_HL + 1));
  register_b--;
  if (register_b == 0)
    register_f = register_f | 0x40; // Set Z flag
  register_f = register_f | 0x02;   // Set N flag
  if ((opcode_byte > 0xAF) && (register_b != 0))
  {
    clock_counter = clock_counter + 0x5; // Allow for repeat of this instruction
    register_pc = register_pc - 2;
  }
  return;
}

void opcode_0xEDA3()
{                                 // outi
  register_f = register_f & 0xBF; // Clear Z flag
  BIUBusCycle(IO_WRITE_BYTE, register_c, (readByte(REGISTER_HL)));
  Writeback_Reg16(REG_HL, (REGISTER_HL + 1));
  register_b--;
  if (register_b == 0)
    register_f = register_f | 0x40; // Set Z flag
  register_f = register_f | 0x02;   // Set N flag
  if ((opcode_byte > 0xAF) && (register_b != 0))
  {
    clock_counter = clock_counter + 0x5; // Allow for repeat of this instruction
    register_pc = register_pc - 2;
  }
  return;
}

void opcode_0xEDA0()
{                                 // ldi
  register_f = register_f & 0xC1; // Clear N, H, P, 5,3 flags
  temp8 = readByte(REGISTER_HL);
  writeByte(REGISTER_DE, temp8);
  Writeback_Reg16(REG_HL, (REGISTER_HL + 1));
  Writeback_Reg16(REG_DE, (REGISTER_DE + 1));
  Writeback_Reg16(REG_BC, (REGISTER_BC - 1));
  if ((opcode_byte > 0xAF) && (REGISTER_BC != 0))
  {
    clock_counter = clock_counter + 0x5; // Allow for repeat of this instruction
    register_pc = register_pc - 2;
  }
  temp8 = temp8 + register_a;
  if (temp8 & 0x08)
    register_f = register_f | 0x08;
  if (temp8 & 0x02)
    register_f = register_f | 0x20;
  if (REGISTER_BC != 0)
    register_f = register_f | 0x04; // Set P flag
  return;
}

void opcode_0xEDA8()
{                                 // ldd
  register_f = register_f & 0xC1; // Clear N, H, P, 5,3 flags
  temp8 = readByte(REGISTER_HL);
  writeByte(REGISTER_DE, temp8);
  Writeback_Reg16(REG_HL, (REGISTER_HL - 1));
  Writeback_Reg16(REG_DE, (REGISTER_DE - 1));
  Writeback_Reg16(REG_BC, (REGISTER_BC - 1));
  if ((opcode_byte > 0xAF) && (REGISTER_BC != 0))
  {
    clock_counter = clock_counter + 0x5; // Allow for repeat of this instruction
    register_pc = register_pc - 2;
  }
  temp8 = temp8 + register_a;
  if (temp8 & 0x08)
    register_f = register_f | 0x08;
  if (temp8 & 0x02)
    register_f = register_f | 0x20;
  if (REGISTER_BC != 0)
    register_f = register_f | 0x04; // Set P flag
  return;
}

void opcode_0xEDA1()
{ // cpi
  uint8_t old_C = flag_c;
  temp8 = SUB_Bytes(register_a, readByte(REGISTER_HL));
  Writeback_Reg16(REG_HL, (REGISTER_HL + 1));
  Writeback_Reg16(REG_BC, (REGISTER_BC - 1));
  if ((opcode_byte > 0xAF) && (REGISTER_BC != 0) && (flag_z != 1))
  {
    clock_counter = clock_counter + 0x5; // Allow for repeat of this instruction
    register_pc = register_pc - 2;
  }

  register_f = register_f & 0xD2; // Clear C, P, 3,5 flags
  if ((temp8 - flag_h) & 0x08)
    register_f = register_f | 0x08; // 3
  if ((temp8 - flag_h) & 0x02)
    register_f = register_f | 0x20; // 5
  if (old_C == 1)
    register_f = register_f | 0x01; // C
  if (REGISTER_BC != 0)
    register_f = register_f | 0x04; // p
  return;
}

void opcode_0xEDA9()
{ // cpd
  uint8_t old_C = flag_c;
  temp8 = SUB_Bytes(register_a, readByte(REGISTER_HL));
  Writeback_Reg16(REG_HL, (REGISTER_HL - 1));
  Writeback_Reg16(REG_BC, (REGISTER_BC - 1));
  if ((opcode_byte > 0xAF) && (REGISTER_BC != 0) && (flag_z != 1))
  {
    clock_counter = clock_counter + 0x5; // Allow for repeat of this instruction
    register_pc = register_pc - 2;
  }

  register_f = register_f & 0xD2; // Clear C, P, 3,5 flags
  if ((temp8 - flag_h) & 0x08)
    register_f = register_f | 0x08; // 3
  if ((temp8 - flag_h) & 0x02)
    register_f = register_f | 0x20; // 5
  if (old_C == 1)
    register_f = register_f | 0x01; // C
  if (REGISTER_BC != 0)
    register_f = register_f | 0x04; // p
  return;
}

void opcode_0xEDAA()
{                                 // ind
  register_f = register_f & 0xBF; // Clear Z flag
  writeByte(REGISTER_HL, BIUBusCycle(IO_READ_BYTE, register_c, 0x00));
  Writeback_Reg16(REG_HL, (REGISTER_HL + 1));
  register_b--;
  if (register_b == 0)
    register_f = register_f | 0x40; // Set Z flag
  register_f = register_f | 0x02;   // Set N flag
  if ((opcode_byte > 0xAF) && (register_b != 0))
  {
    clock_counter = clock_counter + 0x5; // Allow for repeat of this instruction
    register_pc = register_pc - 2;
  }
  return;
}

void opcode_0xEDAB()
{                                 // outd
  register_f = register_f & 0xBF; // Clear Z flag
  BIUBusCycle(IO_WRITE_BYTE, register_c, (readByte(REGISTER_HL)));
  Writeback_Reg16(REG_HL, (REGISTER_HL - 1));
  register_b--;
  if (register_b == 0)
    register_f = register_f | 0x40; // Set Z flag
  register_f = register_f | 0x02;   // Set N flag
  if ((opcode_byte > 0xAF) && (register_b != 0))
    register_pc = register_pc - 2; // Allow for repeat of this instruction
  return;
}

void opcode_0xED67()
{                                 // rrd
  register_f = register_f & 0x01; // Clear S, Z, H, P, N flags
  temp8 = readByte(REGISTER_HL);
  temp16 = (register_a << 8) | temp8;
  temp16 = temp16 >> 4;
  temp16 = (temp16 & 0xF0FF) | ((temp8 & 0x0F) << 8);

  register_a = (register_a & 0xF0) | (0x0F & (temp16 >> 8));
  writeByte(REGISTER_HL, (temp16 & 0x00FF));

  register_f = register_f | Parity_Array[register_a]; // Set P flag
  register_f = register_f | (register_a & 0x80);      // Set S flag
  if (register_a == 0)
    register_f = register_f | 0x40;              // Set Z flag
  register_f = register_f | (register_a & 0x28); // Set flag bits 5,3 to ALU results
  return;
}

void opcode_0xED6F()
{                                 // rld
  register_f = register_f & 0x01; // Clear S, Z, H, P, N flags

  temp16 = (register_a << 8) | readByte(REGISTER_HL);
  temp16 = temp16 << 4;
  temp16 = (temp16 >> 12) | (temp16 & 0xFFF0);

  writeByte(REGISTER_HL, (temp16 & 0x00FF));
  register_a = (register_a & 0xF0) | (0x0F & (temp16 >> 8));

  register_f = register_f | Parity_Array[register_a]; // Set P flag
  register_f = register_f | (register_a & 0x80);      // Set S flag
  if (register_a == 0)
    register_f = register_f | 0x40;              // Set Z flag
  register_f = register_f | (register_a & 0x28); // Set flag bits 5,3 to ALU results
  return;
}

// -------------------------------------------------
// NMI Handler
// -------------------------------------------------
void NMI_Handler()
{

  BIUBusCycle(OPCODE_READ_M1, 0xABCD, 0x00);
  waitForclockFallingEdge();

  if (halt_in_progress == 1)
    Push(register_pc + 1);
  else
    Push(register_pc);
  halt_in_progress = 0;
  digitalWriteFast(PIN_HALT, 0x1);
  register_iff2 = register_iff1;
  register_iff1 = 0;
  register_pc = 0x0066;
  nmi_latched = 0;
  return;
}

// -------------------------------------------------
// INTR Handler
// -------------------------------------------------
void INTR_Handler()
{
  uint8_t local_intr_vector;

  register_iff1 = 0;
  register_iff2 = 0;

  if (register_im == 0)
  {
    assert_iack_type0 = 1; // BIU performs IACK during the next opcode fetch
    return;
  }
  else if (register_im == 1)
  {
    local_intr_vector = BIUBusCycle(INTERRUPT_ACK, 0x0000, 0x00);
    BIUBusCycle(OPCODE_READ_M1, 0xABCD, 0x00);
    waitForclockFallingEdge();

    if (halt_in_progress == 1)
      Push(register_pc + 1);
    else
      Push(register_pc);
    halt_in_progress = 0;
    digitalWriteFast(PIN_HALT, 0x1);
    register_pc = 0x0038;
    return;
  }
  else if (register_im == 2)
  {
    local_intr_vector = BIUBusCycle(INTERRUPT_ACK, 0x0000, 0x00);
    waitForclockFallingEdge();
    if (halt_in_progress == 1)
      Push(register_pc + 1);
    else
      Push(register_pc);
    halt_in_progress = 0;
    digitalWriteFast(PIN_HALT, 0x1);
    temp16 = (register_i << 8) | local_intr_vector;
    register_pc = readWord(temp16);
    return;
  }

  return;
}

// -------------------------------------------------------------------------------------
// Decode tables for multi byte OPcodes
// -------------------------------------------------------------------------------------

void decode_table_0xCB()
{

  if (nmi_latched == 1)
  { // NMI allowed between CB and ED opcodes.  Back-off PC and handle the NMI
    register_pc--;
    return;
  }

  prefix_cb = 1;

  if ((prefix_dd == 1) || (prefix_fd == 1))
  {
    Fetch_opcode();
    cb_prefix_offset = fetched_byte;
    Fetch_opcode();
    opcode_byte = fetched_byte;
    CB_opcode = opcode_byte;
  }
  else
  {
    Fetch_opcode();
    opcode_byte = fetched_byte;
    CB_opcode = opcode_byte;
  }

  switch (opcode_byte)
  {

  case 0x00:
    opcode_0xCB00();
    break;
  case 0x01:
    opcode_0xCB01();
    break;
  case 0x02:
    opcode_0xCB02();
    break;
  case 0x03:
    opcode_0xCB03();
    break;
  case 0x04:
    opcode_0xCB04();
    break;
  case 0x05:
    opcode_0xCB05();
    break;
  case 0x06:
    opcode_0xCB06();
    break;
  case 0x07:
    opcode_0xCB07();
    break;
  case 0x08:
    opcode_0xCB08();
    break;
  case 0x09:
    opcode_0xCB09();
    break;
  case 0x0A:
    opcode_0xCB0A();
    break;
  case 0x0B:
    opcode_0xCB0B();
    break;
  case 0x0C:
    opcode_0xCB0C();
    break;
  case 0x0D:
    opcode_0xCB0D();
    break;
  case 0x0E:
    opcode_0xCB0E();
    break;
  case 0x0F:
    opcode_0xCB0F();
    break;
  case 0x10:
    opcode_0xCB10();
    break;
  case 0x11:
    opcode_0xCB11();
    break;
  case 0x12:
    opcode_0xCB12();
    break;
  case 0x13:
    opcode_0xCB13();
    break;
  case 0x14:
    opcode_0xCB14();
    break;
  case 0x15:
    opcode_0xCB15();
    break;
  case 0x16:
    opcode_0xCB16();
    break;
  case 0x17:
    opcode_0xCB17();
    break;
  case 0x18:
    opcode_0xCB18();
    break;
  case 0x19:
    opcode_0xCB19();
    break;
  case 0x1A:
    opcode_0xCB1A();
    break;
  case 0x1B:
    opcode_0xCB1B();
    break;
  case 0x1C:
    opcode_0xCB1C();
    break;
  case 0x1D:
    opcode_0xCB1D();
    break;
  case 0x1E:
    opcode_0xCB1E();
    break;
  case 0x1F:
    opcode_0xCB1F();
    break;
  case 0x20:
    opcode_0xCB20();
    break;
  case 0x21:
    opcode_0xCB21();
    break;
  case 0x22:
    opcode_0xCB22();
    break;
  case 0x23:
    opcode_0xCB23();
    break;
  case 0x24:
    opcode_0xCB24();
    break;
  case 0x25:
    opcode_0xCB25();
    break;
  case 0x26:
    opcode_0xCB26();
    break;
  case 0x27:
    opcode_0xCB27();
    break;
  case 0x28:
    opcode_0xCB28();
    break;
  case 0x29:
    opcode_0xCB29();
    break;
  case 0x2A:
    opcode_0xCB2A();
    break;
  case 0x2B:
    opcode_0xCB2B();
    break;
  case 0x2C:
    opcode_0xCB2C();
    break;
  case 0x2D:
    opcode_0xCB2D();
    break;
  case 0x2E:
    opcode_0xCB2E();
    break;
  case 0x2F:
    opcode_0xCB2F();
    break;
  case 0x30:
    opcode_0xCB30();
    break;
  case 0x31:
    opcode_0xCB31();
    break;
  case 0x32:
    opcode_0xCB32();
    break;
  case 0x33:
    opcode_0xCB33();
    break;
  case 0x34:
    opcode_0xCB34();
    break;
  case 0x35:
    opcode_0xCB35();
    break;
  case 0x36:
    opcode_0xCB36();
    break;
  case 0x37:
    opcode_0xCB37();
    break;
  case 0x38:
    opcode_0xCB38();
    break;
  case 0x39:
    opcode_0xCB39();
    break;
  case 0x3A:
    opcode_0xCB3A();
    break;
  case 0x3B:
    opcode_0xCB3B();
    break;
  case 0x3C:
    opcode_0xCB3C();
    break;
  case 0x3D:
    opcode_0xCB3D();
    break;
  case 0x3E:
    opcode_0xCB3E();
    break;
  case 0x3F:
    opcode_0xCB3F();
    break;
  case 0x40:
    opcode_0xCB_Bit_b();
    break;
  case 0x41:
    opcode_0xCB_Bit_c();
    break;
  case 0x42:
    opcode_0xCB_Bit_d();
    break;
  case 0x43:
    opcode_0xCB_Bit_e();
    break;
  case 0x44:
    opcode_0xCB_Bit_h();
    break;
  case 0x45:
    opcode_0xCB_Bit_l();
    break;
  case 0x46:
    opcode_0xCB_Bit_hl();
    break;
  case 0x47:
    opcode_0xCB_Bit_a();
    break;
  case 0x48:
    opcode_0xCB_Bit_b();
    break;
  case 0x49:
    opcode_0xCB_Bit_c();
    break;
  case 0x4A:
    opcode_0xCB_Bit_d();
    break;
  case 0x4B:
    opcode_0xCB_Bit_e();
    break;
  case 0x4C:
    opcode_0xCB_Bit_h();
    break;
  case 0x4D:
    opcode_0xCB_Bit_l();
    break;
  case 0x4E:
    opcode_0xCB_Bit_hl();
    break;
  case 0x4F:
    opcode_0xCB_Bit_a();
    break;
  case 0x50:
    opcode_0xCB_Bit_b();
    break;
  case 0x51:
    opcode_0xCB_Bit_c();
    break;
  case 0x52:
    opcode_0xCB_Bit_d();
    break;
  case 0x53:
    opcode_0xCB_Bit_e();
    break;
  case 0x54:
    opcode_0xCB_Bit_h();
    break;
  case 0x55:
    opcode_0xCB_Bit_l();
    break;
  case 0x56:
    opcode_0xCB_Bit_hl();
    break;
  case 0x57:
    opcode_0xCB_Bit_a();
    break;
  case 0x58:
    opcode_0xCB_Bit_b();
    break;
  case 0x59:
    opcode_0xCB_Bit_c();
    break;
  case 0x5A:
    opcode_0xCB_Bit_d();
    break;
  case 0x5B:
    opcode_0xCB_Bit_e();
    break;
  case 0x5C:
    opcode_0xCB_Bit_h();
    break;
  case 0x5D:
    opcode_0xCB_Bit_l();
    break;
  case 0x5E:
    opcode_0xCB_Bit_hl();
    break;
  case 0x5F:
    opcode_0xCB_Bit_a();
    break;
  case 0x60:
    opcode_0xCB_Bit_b();
    break;
  case 0x61:
    opcode_0xCB_Bit_c();
    break;
  case 0x62:
    opcode_0xCB_Bit_d();
    break;
  case 0x63:
    opcode_0xCB_Bit_e();
    break;
  case 0x64:
    opcode_0xCB_Bit_h();
    break;
  case 0x65:
    opcode_0xCB_Bit_l();
    break;
  case 0x66:
    opcode_0xCB_Bit_hl();
    break;
  case 0x67:
    opcode_0xCB_Bit_a();
    break;
  case 0x68:
    opcode_0xCB_Bit_b();
    break;
  case 0x69:
    opcode_0xCB_Bit_c();
    break;
  case 0x6A:
    opcode_0xCB_Bit_d();
    break;
  case 0x6B:
    opcode_0xCB_Bit_e();
    break;
  case 0x6C:
    opcode_0xCB_Bit_h();
    break;
  case 0x6D:
    opcode_0xCB_Bit_l();
    break;
  case 0x6E:
    opcode_0xCB_Bit_hl();
    break;
  case 0x6F:
    opcode_0xCB_Bit_a();
    break;
  case 0x70:
    opcode_0xCB_Bit_b();
    break;
  case 0x71:
    opcode_0xCB_Bit_c();
    break;
  case 0x72:
    opcode_0xCB_Bit_d();
    break;
  case 0x73:
    opcode_0xCB_Bit_e();
    break;
  case 0x74:
    opcode_0xCB_Bit_h();
    break;
  case 0x75:
    opcode_0xCB_Bit_l();
    break;
  case 0x76:
    opcode_0xCB_Bit_hl();
    break;
  case 0x77:
    opcode_0xCB_Bit_a();
    break;
  case 0x78:
    opcode_0xCB_Bit_b();
    break;
  case 0x79:
    opcode_0xCB_Bit_c();
    break;
  case 0x7A:
    opcode_0xCB_Bit_d();
    break;
  case 0x7B:
    opcode_0xCB_Bit_e();
    break;
  case 0x7C:
    opcode_0xCB_Bit_h();
    break;
  case 0x7D:
    opcode_0xCB_Bit_l();
    break;
  case 0x7E:
    opcode_0xCB_Bit_hl();
    break;
  case 0x7F:
    opcode_0xCB_Bit_a();
    break;
  case 0x80:
    opcode_0xCB_Res_b();
    break;
  case 0x81:
    opcode_0xCB_Res_c();
    break;
  case 0x82:
    opcode_0xCB_Res_d();
    break;
  case 0x83:
    opcode_0xCB_Res_e();
    break;
  case 0x84:
    opcode_0xCB_Res_h();
    break;
  case 0x85:
    opcode_0xCB_Res_l();
    break;
  case 0x86:
    opcode_0xCB_Res_hl();
    break;
  case 0x87:
    opcode_0xCB_Res_a();
    break;
  case 0x88:
    opcode_0xCB_Res_b();
    break;
  case 0x89:
    opcode_0xCB_Res_c();
    break;
  case 0x8A:
    opcode_0xCB_Res_d();
    break;
  case 0x8B:
    opcode_0xCB_Res_e();
    break;
  case 0x8C:
    opcode_0xCB_Res_h();
    break;
  case 0x8D:
    opcode_0xCB_Res_l();
    break;
  case 0x8E:
    opcode_0xCB_Res_hl();
    break;
  case 0x8F:
    opcode_0xCB_Res_a();
    break;
  case 0x90:
    opcode_0xCB_Res_b();
    break;
  case 0x91:
    opcode_0xCB_Res_c();
    break;
  case 0x92:
    opcode_0xCB_Res_d();
    break;
  case 0x93:
    opcode_0xCB_Res_e();
    break;
  case 0x94:
    opcode_0xCB_Res_h();
    break;
  case 0x95:
    opcode_0xCB_Res_l();
    break;
  case 0x96:
    opcode_0xCB_Res_hl();
    break;
  case 0x97:
    opcode_0xCB_Res_a();
    break;
  case 0x98:
    opcode_0xCB_Res_b();
    break;
  case 0x99:
    opcode_0xCB_Res_c();
    break;
  case 0x9A:
    opcode_0xCB_Res_d();
    break;
  case 0x9B:
    opcode_0xCB_Res_e();
    break;
  case 0x9C:
    opcode_0xCB_Res_h();
    break;
  case 0x9D:
    opcode_0xCB_Res_l();
    break;
  case 0x9E:
    opcode_0xCB_Res_hl();
    break;
  case 0x9F:
    opcode_0xCB_Res_a();
    break;
  case 0xA0:
    opcode_0xCB_Res_b();
    break;
  case 0xA1:
    opcode_0xCB_Res_c();
    break;
  case 0xA2:
    opcode_0xCB_Res_d();
    break;
  case 0xA3:
    opcode_0xCB_Res_e();
    break;
  case 0xA4:
    opcode_0xCB_Res_h();
    break;
  case 0xA5:
    opcode_0xCB_Res_l();
    break;
  case 0xA6:
    opcode_0xCB_Res_hl();
    break;
  case 0xA7:
    opcode_0xCB_Res_a();
    break;
  case 0xA8:
    opcode_0xCB_Res_b();
    break;
  case 0xA9:
    opcode_0xCB_Res_c();
    break;
  case 0xAA:
    opcode_0xCB_Res_d();
    break;
  case 0xAB:
    opcode_0xCB_Res_e();
    break;
  case 0xAC:
    opcode_0xCB_Res_h();
    break;
  case 0xAD:
    opcode_0xCB_Res_l();
    break;
  case 0xAE:
    opcode_0xCB_Res_hl();
    break;
  case 0xAF:
    opcode_0xCB_Res_a();
    break;
  case 0xB0:
    opcode_0xCB_Res_b();
    break;
  case 0xB1:
    opcode_0xCB_Res_c();
    break;
  case 0xB2:
    opcode_0xCB_Res_d();
    break;
  case 0xB3:
    opcode_0xCB_Res_e();
    break;
  case 0xB4:
    opcode_0xCB_Res_h();
    break;
  case 0xB5:
    opcode_0xCB_Res_l();
    break;
  case 0xB6:
    opcode_0xCB_Res_hl();
    break;
  case 0xB7:
    opcode_0xCB_Res_a();
    break;
  case 0xB8:
    opcode_0xCB_Res_b();
    break;
  case 0xB9:
    opcode_0xCB_Res_c();
    break;
  case 0xBA:
    opcode_0xCB_Res_d();
    break;
  case 0xBB:
    opcode_0xCB_Res_e();
    break;
  case 0xBC:
    opcode_0xCB_Res_h();
    break;
  case 0xBD:
    opcode_0xCB_Res_l();
    break;
  case 0xBE:
    opcode_0xCB_Res_hl();
    break;
  case 0xBF:
    opcode_0xCB_Res_a();
    break;
  case 0xC0:
    opcode_0xCB_Set_b();
    break;
  case 0xC1:
    opcode_0xCB_Set_c();
    break;
  case 0xC2:
    opcode_0xCB_Set_d();
    break;
  case 0xC3:
    opcode_0xCB_Set_e();
    break;
  case 0xC4:
    opcode_0xCB_Set_h();
    break;
  case 0xC5:
    opcode_0xCB_Set_l();
    break;
  case 0xC6:
    opcode_0xCB_Set_hl();
    break;
  case 0xC7:
    opcode_0xCB_Set_a();
    break;
  case 0xC8:
    opcode_0xCB_Set_b();
    break;
  case 0xC9:
    opcode_0xCB_Set_c();
    break;
  case 0xCA:
    opcode_0xCB_Set_d();
    break;
  case 0xCB:
    opcode_0xCB_Set_e();
    break;
  case 0xCC:
    opcode_0xCB_Set_h();
    break;
  case 0xCD:
    opcode_0xCB_Set_l();
    break;
  case 0xCE:
    opcode_0xCB_Set_hl();
    break;
  case 0xCF:
    opcode_0xCB_Set_a();
    break;
  case 0xD0:
    opcode_0xCB_Set_b();
    break;
  case 0xD1:
    opcode_0xCB_Set_c();
    break;
  case 0xD2:
    opcode_0xCB_Set_d();
    break;
  case 0xD3:
    opcode_0xCB_Set_e();
    break;
  case 0xD4:
    opcode_0xCB_Set_h();
    break;
  case 0xD5:
    opcode_0xCB_Set_l();
    break;
  case 0xD6:
    opcode_0xCB_Set_hl();
    break;
  case 0xD7:
    opcode_0xCB_Set_a();
    break;
  case 0xD8:
    opcode_0xCB_Set_b();
    break;
  case 0xD9:
    opcode_0xCB_Set_c();
    break;
  case 0xDA:
    opcode_0xCB_Set_d();
    break;
  case 0xDB:
    opcode_0xCB_Set_e();
    break;
  case 0xDC:
    opcode_0xCB_Set_h();
    break;
  case 0xDD:
    opcode_0xCB_Set_l();
    break;
  case 0xDE:
    opcode_0xCB_Set_hl();
    break;
  case 0xDF:
    opcode_0xCB_Set_a();
    break;
  case 0xE0:
    opcode_0xCB_Set_b();
    break;
  case 0xE1:
    opcode_0xCB_Set_c();
    break;
  case 0xE2:
    opcode_0xCB_Set_d();
    break;
  case 0xE3:
    opcode_0xCB_Set_e();
    break;
  case 0xE4:
    opcode_0xCB_Set_h();
    break;
  case 0xE5:
    opcode_0xCB_Set_l();
    break;
  case 0xE6:
    opcode_0xCB_Set_hl();
    break;
  case 0xE7:
    opcode_0xCB_Set_a();
    break;
  case 0xE8:
    opcode_0xCB_Set_b();
    break;
  case 0xE9:
    opcode_0xCB_Set_c();
    break;
  case 0xEA:
    opcode_0xCB_Set_d();
    break;
  case 0xEB:
    opcode_0xCB_Set_e();
    break;
  case 0xEC:
    opcode_0xCB_Set_h();
    break;
  case 0xED:
    opcode_0xCB_Set_l();
    break;
  case 0xEE:
    opcode_0xCB_Set_hl();
    break;
  case 0xEF:
    opcode_0xCB_Set_a();
    break;
  case 0xF0:
    opcode_0xCB_Set_b();
    break;
  case 0xF1:
    opcode_0xCB_Set_c();
    break;
  case 0xF2:
    opcode_0xCB_Set_d();
    break;
  case 0xF3:
    opcode_0xCB_Set_e();
    break;
  case 0xF4:
    opcode_0xCB_Set_h();
    break;
  case 0xF5:
    opcode_0xCB_Set_l();
    break;
  case 0xF6:
    opcode_0xCB_Set_hl();
    break;
  case 0xF7:
    opcode_0xCB_Set_a();
    break;
  case 0xF8:
    opcode_0xCB_Set_b();
    break;
  case 0xF9:
    opcode_0xCB_Set_c();
    break;
  case 0xFA:
    opcode_0xCB_Set_d();
    break;
  case 0xFB:
    opcode_0xCB_Set_e();
    break;
  case 0xFC:
    opcode_0xCB_Set_h();
    break;
  case 0xFD:
    opcode_0xCB_Set_l();
    break;
  case 0xFE:
    opcode_0xCB_Set_hl();
    break;
  case 0xFF:
    opcode_0xCB_Set_a();
    break;
  }

  return;
}

void decode_table_0xED()
{

  if (nmi_latched == 1)
  { // NMI allowed between CB and ED opcodes.  Back-off PC and handle the NMI
    register_pc--;
    return;
  }
  
  Fetch_opcode();
  opcode_byte = fetched_byte;

  clock_counter = clock_counter + Opcode_Timing_ED[opcode_byte];

  switch (opcode_byte)
  {

  case 0x00:
    opcode_0x00();
    break;
  case 0x01:
    opcode_0x00();
    break;
  case 0x02:
    opcode_0x00();
    break;
  case 0x03:
    opcode_0x00();
    break;
  case 0x04:
    opcode_0x00();
    break;
  case 0x05:
    opcode_0x00();
    break;
  case 0x06:
    opcode_0x00();
    break;
  case 0x07:
    opcode_0x00();
    break;
  case 0x08:
    opcode_0x00();
    break;
  case 0x09:
    opcode_0x00();
    break;
  case 0x0A:
    opcode_0x00();
    break;
  case 0x0B:
    opcode_0x00();
    break;
  case 0x0C:
    opcode_0x00();
    break;
  case 0x0D:
    opcode_0x00();
    break;
  case 0x0E:
    opcode_0x00();
    break;
  case 0x0F:
    opcode_0x00();
    break;
  case 0x10:
    opcode_0x00();
    break;
  case 0x11:
    opcode_0x00();
    break;
  case 0x12:
    opcode_0x00();
    break;
  case 0x13:
    opcode_0x00();
    break;
  case 0x14:
    opcode_0x00();
    break;
  case 0x15:
    opcode_0x00();
    break;
  case 0x16:
    opcode_0x00();
    break;
  case 0x17:
    opcode_0x00();
    break;
  case 0x18:
    opcode_0x00();
    break;
  case 0x19:
    opcode_0x00();
    break;
  case 0x1A:
    opcode_0x00();
    break;
  case 0x1B:
    opcode_0x00();
    break;
  case 0x1C:
    opcode_0x00();
    break;
  case 0x1D:
    opcode_0x00();
    break;
  case 0x1E:
    opcode_0x00();
    break;
  case 0x1F:
    opcode_0x00();
    break;
  case 0x20:
    opcode_0x00();
    break;
  case 0x21:
    opcode_0x00();
    break;
  case 0x22:
    opcode_0x00();
    break;
  case 0x23:
    opcode_0x00();
    break;
  case 0x24:
    opcode_0x00();
    break;
  case 0x25:
    opcode_0x00();
    break;
  case 0x26:
    opcode_0x00();
    break;
  case 0x27:
    opcode_0x00();
    break;
  case 0x28:
    opcode_0x00();
    break;
  case 0x29:
    opcode_0x00();
    break;
  case 0x2A:
    opcode_0x00();
    break;
  case 0x2B:
    opcode_0x00();
    break;
  case 0x2C:
    opcode_0x00();
    break;
  case 0x2D:
    opcode_0x00();
    break;
  case 0x2E:
    opcode_0x00();
    break;
  case 0x2F:
    opcode_0x00();
    break;
  case 0x30:
    opcode_0x00();
    break;
  case 0x31:
    opcode_0x00();
    break;
  case 0x32:
    opcode_0x00();
    break;
  case 0x33:
    opcode_0x00();
    break;
  case 0x34:
    opcode_0x00();
    break;
  case 0x35:
    opcode_0x00();
    break;
  case 0x36:
    opcode_0x00();
    break;
  case 0x37:
    opcode_0x00();
    break;
  case 0x38:
    opcode_0x00();
    break;
  case 0x39:
    opcode_0x00();
    break;
  case 0x3A:
    opcode_0x00();
    break;
  case 0x3B:
    opcode_0x00();
    break;
  case 0x3C:
    opcode_0x00();
    break;
  case 0x3D:
    opcode_0x00();
    break;
  case 0x3E:
    opcode_0x00();
    break;
  case 0x3F:
    opcode_0x00();
    break;
  case 0x40:
    opcode_0xED40();
    break;
  case 0x41:
    opcode_0xED41();
    break;
  case 0x42:
    opcode_0xED42();
    break;
  case 0x43:
    opcode_0xED43();
    break;
  case 0x44:
    opcode_0xED44();
    break;
  case 0x45:
    opcode_0xED45();
    break;
  case 0x46:
    opcode_0xED46();
    break;
  case 0x47:
    opcode_0xED47();
    break;
  case 0x48:
    opcode_0xED48();
    break;
  case 0x49:
    opcode_0xED49();
    break;
  case 0x4A:
    opcode_0xED4A();
    break;
  case 0x4B:
    opcode_0xED4B();
    break;
  case 0x4C:
    opcode_0xED44();
    break;
  case 0x4D:
    opcode_0xED4D();
    break;
  case 0x4E:
    opcode_0x00();
    break;
  case 0x4F:
    opcode_0xED4F();
    break;
  case 0x50:
    opcode_0xED50();
    break;
  case 0x51:
    opcode_0xED51();
    break;
  case 0x52:
    opcode_0xED52();
    break;
  case 0x53:
    opcode_0xED53();
    break;
  case 0x54:
    opcode_0xED44();
    break;
  case 0x55:
    opcode_0xED45();
    break;
  case 0x56:
    opcode_0xED56();
    break;
  case 0x57:
    opcode_0xED57();
    break;
  case 0x58:
    opcode_0xED58();
    break;
  case 0x59:
    opcode_0xED59();
    break;
  case 0x5A:
    opcode_0xED5A();
    break;
  case 0x5B:
    opcode_0xED5B();
    break;
  case 0x5C:
    opcode_0xED44();
    break;
  case 0x5D:
    opcode_0xED45();
    break;
  case 0x5E:
    opcode_0xED5E();
    break;
  case 0x5F:
    opcode_0xED5F();
    break;
  case 0x60:
    opcode_0xED60();
    break;
  case 0x61:
    opcode_0xED61();
    break;
  case 0x62:
    opcode_0xED62();
    break;
  case 0x63:
    opcode_0xED63();
    break;
  case 0x64:
    opcode_0xED44();
    break;
  case 0x65:
    opcode_0xED45();
    break;
  case 0x66:
    opcode_0xED46();
    break;
  case 0x67:
    opcode_0xED67();
    break;
  case 0x68:
    opcode_0xED68();
    break;
  case 0x69:
    opcode_0xED69();
    break;
  case 0x6A:
    opcode_0xED6A();
    break;
  case 0x6B:
    opcode_0xED6B();
    break;
  case 0x6C:
    opcode_0xED44();
    break;
  case 0x6D:
    opcode_0xED45();
    break;
  case 0x6E:
    opcode_0x00();
    break;
  case 0x6F:
    opcode_0xED6F();
    break;
  case 0x70:
    opcode_0xED70();
    break;
  case 0x71:
    opcode_0xED71();
    break;
  case 0x72:
    opcode_0xED72();
    break;
  case 0x73:
    opcode_0xED73();
    break;
  case 0x74:
    opcode_0xED44();
    break;
  case 0x75:
    opcode_0xED45();
    break;
  case 0x76:
    opcode_0xED56();
    break;
  case 0x77:
    opcode_0x00();
    break;
  case 0x78:
    opcode_0xED78();
    break;
  case 0x79:
    opcode_0xED79();
    break;
  case 0x7A:
    opcode_0xED7A();
    break;
  case 0x7B:
    opcode_0xED7B();
    break;
  case 0x7C:
    opcode_0xED44();
    break;
  case 0x7D:
    opcode_0xED45();
    break;
  case 0x7E:
    opcode_0xED5E();
    break;
  case 0x7F:
    opcode_0x00();
    break;
  case 0x80:
    opcode_0x00();
    break;
  case 0x81:
    opcode_0x00();
    break;
  case 0x82:
    opcode_0x00();
    break;
  case 0x83:
    opcode_0x00();
    break;
  case 0x84:
    opcode_0x00();
    break;
  case 0x85:
    opcode_0x00();
    break;
  case 0x86:
    opcode_0x00();
    break;
  case 0x87:
    opcode_0x00();
    break;
  case 0x88:
    opcode_0x00();
    break;
  case 0x89:
    opcode_0x00();
    break;
  case 0x8A:
    opcode_0x00();
    break;
  case 0x8B:
    opcode_0x00();
    break;
  case 0x8C:
    opcode_0x00();
    break;
  case 0x8D:
    opcode_0x00();
    break;
  case 0x8E:
    opcode_0x00();
    break;
  case 0x8F:
    opcode_0x00();
    break;
  case 0x90:
    opcode_0x00();
    break;
  case 0x91:
    opcode_0x00();
    break;
  case 0x92:
    opcode_0x00();
    break;
  case 0x93:
    opcode_0x00();
    break;
  case 0x94:
    opcode_0x00();
    break;
  case 0x95:
    opcode_0x00();
    break;
  case 0x96:
    opcode_0x00();
    break;
  case 0x97:
    opcode_0x00();
    break;
  case 0x98:
    opcode_0x00();
    break;
  case 0x99:
    opcode_0x00();
    break;
  case 0x9A:
    opcode_0x00();
    break;
  case 0x9B:
    opcode_0x00();
    break;
  case 0x9C:
    opcode_0x00();
    break;
  case 0x9D:
    opcode_0x00();
    break;
  case 0x9E:
    opcode_0x00();
    break;
  case 0x9F:
    opcode_0x00();
    break;
  case 0xA0:
    opcode_0xEDA0();
    break;
  case 0xA1:
    opcode_0xEDA1();
    break;
  case 0xA2:
    opcode_0xEDA2();
    break;
  case 0xA3:
    opcode_0xEDA3();
    break;
  case 0xA4:
    opcode_0x00();
    break;
  case 0xA5:
    opcode_0x00();
    break;
  case 0xA6:
    opcode_0x00();
    break;
  case 0xA7:
    opcode_0x00();
    break;
  case 0xA8:
    opcode_0xEDA8();
    break;
  case 0xA9:
    opcode_0xEDA9();
    break;
  case 0xAA:
    opcode_0xEDAA();
    break;
  case 0xAB:
    opcode_0xEDAB();
    break;
  case 0xAC:
    opcode_0x00();
    break;
  case 0xAD:
    opcode_0x00();
    break;
  case 0xAE:
    opcode_0x00();
    break;
  case 0xAF:
    opcode_0x00();
    break;
  case 0xB0:
    opcode_0xEDA0();
    break;
  case 0xB1:
    opcode_0xEDA1();
    break;
  case 0xB2:
    opcode_0xEDA2();
    break;
  case 0xB3:
    opcode_0xEDA3();
    break;
  case 0xB4:
    opcode_0x00();
    break;
  case 0xB5:
    opcode_0x00();
    break;
  case 0xB6:
    opcode_0x00();
    break;
  case 0xB7:
    opcode_0x00();
    break;
  case 0xB8:
    opcode_0xEDA8();
    break;
  case 0xB9:
    opcode_0xEDA9();
    break;
  case 0xBA:
    opcode_0xEDAA();
    break;
  case 0xBB:
    opcode_0xEDAB();
    break;
  case 0xBC:
    opcode_0x00();
    break;
  case 0xBD:
    opcode_0x00();
    break;
  case 0xBE:
    opcode_0x00();
    break;
  case 0xBF:
    opcode_0x00();
    break;
  case 0xC0:
    opcode_0x00();
    break;
  case 0xC1:
    opcode_0x00();
    break;
  case 0xC2:
    opcode_0x00();
    break;
  case 0xC3:
    opcode_0x00();
    break;
  case 0xC4:
    opcode_0x00();
    break;
  case 0xC5:
    opcode_0x00();
    break;
  case 0xC6:
    opcode_0x00();
    break;
  case 0xC7:
    opcode_0x00();
    break;
  case 0xC8:
    opcode_0x00();
    break;
  case 0xC9:
    opcode_0x00();
    break;
  case 0xCA:
    opcode_0x00();
    break;
  case 0xCB:
    opcode_0x00();
    break;
  case 0xCC:
    opcode_0x00();
    break;
  case 0xCD:
    opcode_0x00();
    break;
  case 0xCE:
    opcode_0x00();
    break;
  case 0xCF:
    opcode_0x00();
    break;
  case 0xD0:
    opcode_0x00();
    break;
  case 0xD1:
    opcode_0x00();
    break;
  case 0xD2:
    opcode_0x00();
    break;
  case 0xD3:
    opcode_0x00();
    break;
  case 0xD4:
    opcode_0x00();
    break;
  case 0xD5:
    opcode_0x00();
    break;
  case 0xD6:
    opcode_0x00();
    break;
  case 0xD7:
    opcode_0x00();
    break;
  case 0xD8:
    opcode_0x00();
    break;
  case 0xD9:
    opcode_0x00();
    break;
  case 0xDA:
    opcode_0x00();
    break;
  case 0xDB:
    opcode_0x00();
    break;
  case 0xDC:
    opcode_0x00();
    break;
  case 0xDD:
    opcode_0x00();
    break;
  case 0xDE:
    opcode_0x00();
    break;
  case 0xDF:
    opcode_0x00();
    break;
  case 0xE0:
    opcode_0x00();
    break;
  case 0xE1:
    opcode_0x00();
    break;
  case 0xE2:
    opcode_0x00();
    break;
  case 0xE3:
    opcode_0x00();
    break;
  case 0xE4:
    opcode_0x00();
    break;
  case 0xE5:
    opcode_0x00();
    break;
  case 0xE6:
    opcode_0x00();
    break;
  case 0xE7:
    opcode_0x00();
    break;
  case 0xE8:
    opcode_0x00();
    break;
  case 0xE9:
    opcode_0x00();
    break;
  case 0xEA:
    opcode_0x00();
    break;
  case 0xEB:
    opcode_0x00();
    break;
  case 0xEC:
    opcode_0x00();
    break;
  case 0xED:
    opcode_0x00();
    break;
  case 0xEE:
    opcode_0x00();
    break;
  case 0xEF:
    opcode_0x00();
    break;
  case 0xF0:
    opcode_0x00();
    break;
  case 0xF1:
    opcode_0x00();
    break;
  case 0xF2:
    opcode_0x00();
    break;
  case 0xF3:
    opcode_0x00();
    break;
  case 0xF4:
    opcode_0x00();
    break;
  case 0xF5:
    opcode_0x00();
    break;
  case 0xF6:
    opcode_0x00();
    break;
  case 0xF7:
    opcode_0x00();
    break;
  case 0xF8:
    opcode_0x00();
    break;
  case 0xF9:
    opcode_0x00();
    break;
  case 0xFA:
    opcode_0x00();
    break;
  case 0xFB:
    opcode_0x00();
    break;
  case 0xFC:
    opcode_0x00();
    break;
  case 0xFD:
    opcode_0x00();
    break;
  case 0xFE:
    opcode_0x00();
    break;
  case 0xFF:
    opcode_0x00();
    break;
  }

  return;
}


// Check if reset pin is low and invoke reset
inline void checkReset(void)  __attribute__((always_inline));
inline void checkReset()
{
  if (direct_reset == 0)
    initAfterReset();
}

// Check and execute if Interrupts
//  Poll for interrupts between instructions,
//  but not when immediately after instruction enabling interrupts,
//  or if the last opcode was a prefix.

inline void checkInterrupts(void)  __attribute__((always_inline));

inline void checkInterrupts()
{
// Check is reorganised to speed up code execution if there is no interrupt
// However NMI handling takes more CPU cycles
  if (nmi_latched == 1)
    {
      if (last_instruction_set_a_prefix == 0 && pause_interrupts == 0) NMI_Handler();
    }   else if (direct_intr == 0 && register_iff1 == 1) {
      if (last_instruction_set_a_prefix == 0 && pause_interrupts == 0) INTR_Handler();
    } 
  pause_interrupts = 0; // debounce
}

// ------------------------------------------------------------------------------------------------------------
// Decode the first byte of the opcode
// ------------------------------------------------------------------------------------------------------------
void executeInstruction()
{while (true) {

  // Check reset pin and in case it is active handle same as power on
  checkReset();

  // Do we need to execute an interrupt?
  checkInterrupts();

  // Check if there is a call towards load menu
  // PC points to BASIC entry vectors -> call relevant event
  // Implemented in machine specific cpp
  checkBasicEntryPoint();

  last_instruction_set_a_prefix = 0; // prefix_fd _dd and _cb already
  Fetch_opcode();
  opcode_byte = fetched_byte;
  clock_counter = Opcode_Timing_Main[opcode_byte];

  switch (opcode_byte)
  {
  case 0x00:
    opcode_0x00();
    break;
  case 0x01:
    opcode_0x01();
    break;
  case 0x02:
    opcode_0x02();
    break;
  case 0x03:
    opcode_0x03();
    break;
  case 0x04:
    opcode_0x04();
    break;
  case 0x05:
    opcode_0x05();
    break;
  case 0x06:
    opcode_0x06();
    break;
  case 0x07:
    opcode_0x07();
    break;
  case 0x08:
    opcode_0x08();
    break;
  case 0x09:
    opcode_0x09();
    break;
  case 0x0A:
    opcode_0x0A();
    break;
  case 0x0B:
    opcode_0x0B();
    break;
  case 0x0C:
    opcode_0x0C();
    break;
  case 0x0D:
    opcode_0x0D();
    break;
  case 0x0E:
    opcode_0x0E();
    break;
  case 0x0F:
    opcode_0x0F();
    break;
  case 0x10:
    opcode_0x10();
    break;
  case 0x11:
    opcode_0x11();
    break;
  case 0x12:
    opcode_0x12();
    break;
  case 0x13:
    opcode_0x13();
    break;
  case 0x14:
    opcode_0x14();
    break;
  case 0x15:
    opcode_0x15();
    break;
  case 0x16:
    opcode_0x16();
    break;
  case 0x17:
    opcode_0x17();
    break;
  case 0x18:
    opcode_0x18();
    break;
  case 0x19:
    opcode_0x19();
    break;
  case 0x1A:
    opcode_0x1A();
    break;
  case 0x1B:
    opcode_0x1B();
    break;
  case 0x1C:
    opcode_0x1C();
    break;
  case 0x1D:
    opcode_0x1D();
    break;
  case 0x1E:
    opcode_0x1E();
    break;
  case 0x1F:
    opcode_0x1F();
    break;
  case 0x20:
    opcode_0x20();
    break;
  case 0x21:
    opcode_0x21();
    break;
  case 0x22:
    opcode_0x22();
    break;
  case 0x23:
    opcode_0x23();
    break;
  case 0x24:
    opcode_0x24();
    break;
  case 0x25:
    opcode_0x25();
    break;
  case 0x26:
    opcode_0x26();
    break;
  case 0x27:
    opcode_0x27();
    break;
  case 0x28:
    opcode_0x28();
    break;
  case 0x29:
    opcode_0x29();
    break;
  case 0x2A:
    opcode_0x2A();
    break;
  case 0x2B:
    opcode_0x2B();
    break;
  case 0x2C:
    opcode_0x2C();
    break;
  case 0x2D:
    opcode_0x2D();
    break;
  case 0x2E:
    opcode_0x2E();
    break;
  case 0x2F:
    opcode_0x2F();
    break;
  case 0x30:
    opcode_0x30();
    break;
  case 0x31:
    opcode_0x31();
    break;
  case 0x32:
    opcode_0x32();
    break;
  case 0x33:
    opcode_0x33();
    break;
  case 0x34:
    opcode_0x34();
    break;
  case 0x35:
    opcode_0x35();
    break;
  case 0x36:
    opcode_0x36();
    break;
  case 0x37:
    opcode_0x37();
    break;
  case 0x38:
    opcode_0x38();
    break;
  case 0x39:
    opcode_0x39();
    break;
  case 0x3a:
    opcode_0x3A();
    break;
  case 0x3B:
    opcode_0x3B();
    break;
  case 0x3C:
    opcode_0x3C();
    break;
  case 0x3D:
    opcode_0x3D();
    break;
  case 0x3E:
    opcode_0x3E();
    break;
  case 0x3F:
    opcode_0x3F();
    break;
  case 0x40:
    opcode_0x40();
    break;
  case 0x41:
    opcode_0x41();
    break;
  case 0x42:
    opcode_0x42();
    break;
  case 0x43:
    opcode_0x43();
    break;
  case 0x44:
    opcode_0x44();
    break;
  case 0x45:
    opcode_0x45();
    break;
  case 0x46:
    opcode_0x46();
    break;
  case 0x47:
    opcode_0x47();
    break;
  case 0x48:
    opcode_0x48();
    break;
  case 0x49:
    opcode_0x49();
    break;
  case 0x4A:
    opcode_0x4A();
    break;
  case 0x4B:
    opcode_0x4B();
    break;
  case 0x4C:
    opcode_0x4C();
    break;
  case 0x4D:
    opcode_0x4D();
    break;
  case 0x4E:
    opcode_0x4E();
    break;
  case 0x4F:
    opcode_0x4F();
    break;
  case 0x50:
    opcode_0x50();
    break;
  case 0x51:
    opcode_0x51();
    break;
  case 0x52:
    opcode_0x52();
    break;
  case 0x53:
    opcode_0x53();
    break;
  case 0x54:
    opcode_0x54();
    break;
  case 0x55:
    opcode_0x55();
    break;
  case 0x56:
    opcode_0x56();
    break;
  case 0x57:
    opcode_0x57();
    break;
  case 0x58:
    opcode_0x58();
    break;
  case 0x59:
    opcode_0x59();
    break;
  case 0x5A:
    opcode_0x5A();
    break;
  case 0x5B:
    opcode_0x5B();
    break;
  case 0x5C:
    opcode_0x5C();
    break;
  case 0x5D:
    opcode_0x5D();
    break;
  case 0x5E:
    opcode_0x5E();
    break;
  case 0x5F:
    opcode_0x5F();
    break;
  case 0x60:
    opcode_0x60();
    break;
  case 0x61:
    opcode_0x61();
    break;
  case 0x62:
    opcode_0x62();
    break;
  case 0x63:
    opcode_0x63();
    break;
  case 0x64:
    opcode_0x64();
    break;
  case 0x65:
    opcode_0x65();
    break;
  case 0x66:
    opcode_0x66();
    break;
  case 0x67:
    opcode_0x67();
    break;
  case 0x68:
    opcode_0x68();
    break;
  case 0x69:
    opcode_0x69();
    break;
  case 0x6A:
    opcode_0x6A();
    break;
  case 0x6B:
    opcode_0x6B();
    break;
  case 0x6C:
    opcode_0x6C();
    break;
  case 0x6D:
    opcode_0x6D();
    break;
  case 0x6E:
    opcode_0x6E();
    break;
  case 0x6F:
    opcode_0x6F();
    break;
  case 0x70:
    opcode_0x70();
    break;
  case 0x71:
    opcode_0x71();
    break;
  case 0x72:
    opcode_0x72();
    break;
  case 0x73:
    opcode_0x73();
    break;
  case 0x74:
    opcode_0x74();
    break;
  case 0x75:
    opcode_0x75();
    break;
  case 0x76:
    opcode_0x76();
    break;
  case 0x77:
    opcode_0x77();
    break;
  case 0x78:
    opcode_0x78();
    break;
  case 0x79:
    opcode_0x79();
    break;
  case 0x7A:
    opcode_0x7A();
    break;
  case 0x7B:
    opcode_0x7B();
    break;
  case 0x7C:
    opcode_0x7C();
    break;
  case 0x7D:
    opcode_0x7D();
    break;
  case 0x7E:
    opcode_0x7E();
    break;
  case 0x7F:
    opcode_0x7F();
    break;
  case 0x80:
    opcode_0x80();
    break;
  case 0x81:
    opcode_0x81();
    break;
  case 0x82:
    opcode_0x82();
    break;
  case 0x83:
    opcode_0x83();
    break;
  case 0x84:
    opcode_0x84();
    break;
  case 0x85:
    opcode_0x85();
    break;
  case 0x86:
    opcode_0x86();
    break;
  case 0x87:
    opcode_0x87();
    break;
  case 0x88:
    opcode_0x88();
    break;
  case 0x89:
    opcode_0x89();
    break;
  case 0x8A:
    opcode_0x8A();
    break;
  case 0x8B:
    opcode_0x8B();
    break;
  case 0x8C:
    opcode_0x8C();
    break;
  case 0x8D:
    opcode_0x8D();
    break;
  case 0x8E:
    opcode_0x8E();
    break;
  case 0x8F:
    opcode_0x8F();
    break;
  case 0x90:
    opcode_0x90();
    break;
  case 0x91:
    opcode_0x91();
    break;
  case 0x92:
    opcode_0x92();
    break;
  case 0x93:
    opcode_0x93();
    break;
  case 0x94:
    opcode_0x94();
    break;
  case 0x95:
    opcode_0x95();
    break;
  case 0x96:
    opcode_0x96();
    break;
  case 0x97:
    opcode_0x97();
    break;
  case 0x98:
    opcode_0x98();
    break;
  case 0x99:
    opcode_0x99();
    break;
  case 0x9A:
    opcode_0x9A();
    break;
  case 0x9B:
    opcode_0x9B();
    break;
  case 0x9C:
    opcode_0x9C();
    break;
  case 0x9D:
    opcode_0x9D();
    break;
  case 0x9E:
    opcode_0x9E();
    break;
  case 0x9F:
    opcode_0x9F();
    break;
  case 0xA0:
    opcode_0xA0();
    break;
  case 0xA1:
    opcode_0xA1();
    break;
  case 0xA2:
    opcode_0xA2();
    break;
  case 0xA3:
    opcode_0xA3();
    break;
  case 0xA4:
    opcode_0xA4();
    break;
  case 0xA5:
    opcode_0xA5();
    break;
  case 0xA6:
    opcode_0xA6();
    break;
  case 0xA7:
    opcode_0xA7();
    break;
  case 0xA8:
    opcode_0xA8();
    break;
  case 0xA9:
    opcode_0xA9();
    break;
  case 0xAA:
    opcode_0xAA();
    break;
  case 0xAB:
    opcode_0xAB();
    break;
  case 0xAC:
    opcode_0xAC();
    break;
  case 0xAD:
    opcode_0xAD();
    break;
  case 0xAE:
    opcode_0xAE();
    break;
  case 0xAF:
    opcode_0xAF();
    break;
  case 0xB0:
    opcode_0xB0();
    break;
  case 0xB1:
    opcode_0xB1();
    break;
  case 0xB2:
    opcode_0xB2();
    break;
  case 0xB3:
    opcode_0xB3();
    break;
  case 0xB4:
    opcode_0xB4();
    break;
  case 0xB5:
    opcode_0xB5();
    break;
  case 0xB6:
    opcode_0xB6();
    break;
  case 0xB7:
    opcode_0xB7();
    break;
  case 0xB8:
    opcode_0xB8();
    break;
  case 0xB9:
    opcode_0xB9();
    break;
  case 0xBA:
    opcode_0xBA();
    break;
  case 0xBB:
    opcode_0xBB();
    break;
  case 0xBC:
    opcode_0xBC();
    break;
  case 0xBD:
    opcode_0xBD();
    break;
  case 0xBE:
    opcode_0xBE();
    break;
  case 0xBF:
    opcode_0xBF();
    break;
  case 0xC0:
    opcode_0xC0();
    break;
  case 0xC1:
    opcode_0xC1();
    break;
  case 0xC2:
    opcode_0xC2();
    break;
  case 0xC3:
    opcode_0xC3();
    break;
  case 0xC4:
    opcode_0xC4();
    break;
  case 0xC5:
    opcode_0xC5();
    break;
  case 0xC6:
    opcode_0xC6();
    break;
  case 0xC7:
    opcode_0xC7();
    break;
  case 0xC8:
    opcode_0xC8();
    break;
  case 0xC9:
    opcode_0xC9();
    break;
  case 0xCA:
    opcode_0xCA();
    break;
  case 0xCB:
    decode_table_0xCB();
    break;
  case 0xCC:
    opcode_0xCC();
    break;
  case 0xCD:
    opcode_0xCD();
    break;
  case 0xCE:
    opcode_0xCE();
    break;
  case 0xCF:
    opcode_0xCF();
    break;
  case 0xD0:
    opcode_0xD0();
    break;
  case 0xD1:
    opcode_0xD1();
    break;
  case 0xD2:
    opcode_0xD2();
    break;
  case 0xD3:
    opcode_0xD3();
    break;
  case 0xD4:
    opcode_0xD4();
    break;
  case 0xD5:
    opcode_0xD5();
    break;
  case 0xD6:
    opcode_0xD6();
    break;
  case 0xD7:
    opcode_0xD7();
    break;
  case 0xD8:
    opcode_0xD8();
    break;
  case 0xD9:
    opcode_0xD9();
    break;
  case 0xDA:
    opcode_0xDA();
    break;
  case 0xDB:
    opcode_0xDB();
    break;
  case 0xDC:
    opcode_0xDC();
    break;
  case 0xDD:
    opcode_0xDD();
    break;
  case 0xDE:
    opcode_0xDE();
    break;
  case 0xDF:
    opcode_0xDF();
    break;
  case 0xE0:
    opcode_0xE0();
    break;
  case 0xE1:
    opcode_0xE1();
    break;
  case 0xE2:
    opcode_0xE2();
    break;
  case 0xE3:
    opcode_0xE3();
    break;
  case 0xE4:
    opcode_0xE4();
    break;
  case 0xE5:
    opcode_0xE5();
    break;
  case 0xE6:
    opcode_0xE6();
    break;
  case 0xE7:
    opcode_0xE7();
    break;
  case 0xE8:
    opcode_0xE8();
    break;
  case 0xE9:
    opcode_0xE9();
    break;
  case 0xEA:
    opcode_0xEA();
    break;
  case 0xEB:
    opcode_0xEB();
    break;
  case 0xEC:
    opcode_0xEC();
    break;
  case 0xED:
    decode_table_0xED();
    break;
  case 0xEE:
    opcode_0xEE();
    break;
  case 0xEF:
    opcode_0xEF();
    break;
  case 0xF0:
    opcode_0xF0();
    break;
  case 0xF1:
    opcode_0xF1();
    break;
  case 0xF2:
    opcode_0xF2();
    break;
  case 0xF3:
    opcode_0xF3();
    break;
  case 0xF4:
    opcode_0xF4();
    break;
  case 0xF5:
    opcode_0xF5();
    break;
  case 0xF6:
    opcode_0xF6();
    break;
  case 0xF7:
    opcode_0xF7();
    break;
  case 0xF8:
    opcode_0xF8();
    break;
  case 0xF9:
    opcode_0xF9();
    break;
  case 0xFA:
    opcode_0xFA();
    break;
  case 0xFB:
    opcode_0xFB();
    break;
  case 0xFC:
    opcode_0xFC();
    break;
  case 0xFD:
    opcode_0xFD();
    break;
  case 0xFE:
    opcode_0xFE();
    break;
  case 0xFF:
    opcode_0xFF();
    break;
  }

  // Clear prefixes if no prefix set
  if (last_instruction_set_a_prefix == 0)
  {
    prefix_dd = 0;
    prefix_fd = 0;
    prefix_cb = 0;
  }

  // Wait for cycle counter to reach zero before processing interrupts or the next instruction
  // In case of full acceleration (mode >3) pedal to metal
  if (accelerationMode < 3)
    while (clock_counter > 0)
    {
      waitForClockRisingEdge();
      waitForclockFallingEdge();
    }
}}

// Initalise Z80 emulation after power ON or reset
void initAfterReset()
{
  // Give Teensy 4.1 a moment
  delay(100);
  waitForclockFallingEdge();
  waitForclockFallingEdge();
  waitForclockFallingEdge();
  resetSequence();
}

uint16_t getHLregister(void)
{
  return REGISTER_HL;
}
