/**
 * [FILE] i8080_Opcodes.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Implementation of the opcodes for i8080
 *      RESOURCES:
 *          https://pastraiser.com/cpu/i8080/i8080_opcodes.html - Good Page for visual layout of Opcodes
 *          http://www.emulator101.com/8080-by-opcode.html
 *          http://www.classicgaming.cc/classics/space-invaders/sounds
 *          https://computerarcheology.com/Arcade/SpaceInvaders/Hardware.html
 * [DATE] 2021-05-21
*/

#include "i8080.h"

/**
 * [DESCRIPTION] Construct a new i8080::i8080 OpCodes::i8080 OpCodes object and point it to the
 *               parent members
 * 
 * [PARAM] parent_register 
 * [PARAM] parent_memory 
 * [PARAM] parent_flags 
*/
i8080::i8080_OpCodes::i8080_OpCodes(i8080_Registers* parent_register, i8080_Memory* parent_memory, i8080_Flags* parent_flags)
{
    registers = parent_register;
    memory    = parent_memory;
    flags     = parent_flags;
}

/**
 * [DESCRIPTION] Main caller of all the opcodes
 *      - Also performs a preliminary increment of the PC
 * 
 * [PARAM] passed_code 
*/
void i8080::i8080_OpCodes::runOpCode(uint8_t passed_code) 
{

    // Inc the PC tha default step of 1
    registers->inc_PC(1);

    switch(passed_code) {
        case 0x00: func_NOP();        break;
        case 0x01: func_LXI_B_D16();  break;
        case 0x02: func_STAX_B();     break;
        case 0x03: func_INX_B();      break;
        case 0x04: func_INR_B();      break;
        case 0x05: func_DCR_B();      break;
        case 0x06: func_MVI_B_D8();   break;
        case 0x07: func_RLC();        break;
        case 0x08: func_NOP();        break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0x09: func_DAD_B();      break;
        case 0x0a: func_LDAX_B();     break;
        case 0x0b: func_DCX_B();      break;
        case 0x0c: func_INR_C();      break;
        case 0x0d: func_DCR_C();      break;
        case 0x0e: func_MVI_C_D8();   break;
        case 0x0f: func_RRC();        break;
        case 0x10: func_NOP();        break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0x11: func_LXI_D_D16();  break;
        case 0x12: func_STAX_D();     break;
        case 0x13: func_INX_D();      break;
        case 0x14: func_INR_D();      break;
        case 0x15: func_DCR_D();      break;
        case 0x16: func_MVI_D_D8();   break;
        case 0x17: func_RAL();        break;
        case 0x18: func_NOP();        break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0x19: func_DAD_D();      break;
        case 0x1a: func_LDAX_D();     break;
        case 0x1b: func_DCX_D();      break;
        case 0x1c: func_INR_E();      break;
        case 0x1d: func_DCR_E();      break;
        case 0x1e: func_MVI_E_D8();   break;
        case 0x1f: func_RAR();        break;
        case 0x20: func_NOP();        break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0x21: func_LXI_H_D16();  break;
        case 0x22: func_SHLD_ADR();   break;
        case 0x23: func_INX_H();      break;
        case 0x24: func_INR_H();      break;
        case 0x25: func_DCR_H();      break;
        case 0x26: func_MVI_H_D8();   break;
        case 0x27: func_DAA();        break;
        case 0x28: func_NOP();        break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0x29: func_DAD_H();      break;
        case 0x2a: func_LHLD_ADR();   break;
        case 0x2b: func_DCX_H();      break;
        case 0x2c: func_INR_L();      break;
        case 0x2d: func_DCR_L();      break;
        case 0x2e: func_MVI_L_D8();   break;
        case 0x2f: func_CMA();        break;
        case 0x30: func_NOP();        break;
        case 0x31: func_LXI_SP_D16(); break;
        case 0x32: func_STA_ADR();    break;
        case 0x33: func_INX_SP();     break;
        case 0x34: func_INR_M();      break;
        case 0x35: func_DCR_M();      break;
        case 0x36: func_MVI_M_D8();   break;
        case 0x37: func_STC();        break;
        case 0x38: func_NOP();        break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0x39: func_DAD_SP();     break;
        case 0x3a: func_LDA_ADR();    break;
        case 0x3b: func_DCX_SP();     break;
        case 0x3c: func_INR_A();      break;
        case 0x3d: func_DCR_A();      break;
        case 0x3e: func_MVI_A_D8();   break;
        case 0x3f: func_CMC();        break;
        case 0x40: func_MOV_B_B();    break;
        case 0x41: func_MOV_B_C();    break;
        case 0x42: func_MOV_B_D();    break;
        case 0x43: func_MOV_B_E();    break;
        case 0x44: func_MOV_B_H();    break;
        case 0x45: func_MOV_B_L();    break;
        case 0x46: func_MOV_B_M();    break;
        case 0x47: func_MOV_B_A();    break;
        case 0x48: func_MOV_C_B();    break;
        case 0x49: func_MOV_C_C();    break;
        case 0x4a: func_MOV_C_D();    break;
        case 0x4b: func_MOV_C_E();    break;
        case 0x4c: func_MOV_C_H();    break;
        case 0x4d: func_MOV_C_L();    break;
        case 0x4e: func_MOV_C_M();    break;
        case 0x4f: func_MOV_C_A();    break;
        case 0x50: func_MOV_D_B();    break;
        case 0x51: func_MOV_D_C();    break;
        case 0x52: func_MOV_D_D();    break;
        case 0x53: func_MOV_D_E();    break;
        case 0x54: func_MOV_D_H();    break;
        case 0x55: func_MOV_D_L();    break;
        case 0x56: func_MOV_D_M();    break;
        case 0x57: func_MOV_D_A();    break;
        case 0x58: func_MOV_E_B();    break;
        case 0x59: func_MOV_E_C();    break;
        case 0x5a: func_MOV_E_D();    break;
        case 0x5b: func_MOV_E_E();    break;
        case 0x5c: func_MOV_E_H();    break;
        case 0x5d: func_MOV_E_L();    break;
        case 0x5e: func_MOV_E_M();    break;
        case 0x5f: func_MOV_E_A();    break;
        case 0x60: func_MOV_H_B();    break;
        case 0x61: func_MOV_H_C();    break;
        case 0x62: func_MOV_H_D();    break;
        case 0x63: func_MOV_H_E();    break;
        case 0x64: func_MOV_H_H();    break;
        case 0x65: func_MOV_H_L();    break;
        case 0x66: func_MOV_H_M();    break;
        case 0x67: func_MOV_H_A();    break;
        case 0x68: func_MOV_L_B();    break;
        case 0x69: func_MOV_L_C();    break;
        case 0x6a: func_MOV_L_D();    break;
        case 0x6b: func_MOV_L_E();    break;
        case 0x6c: func_MOV_L_H();    break;
        case 0x6d: func_MOV_L_L();    break;
        case 0x6e: func_MOV_L_M();    break;
        case 0x6f: func_MOV_L_A();    break;
        case 0x70: func_MOV_M_B();    break;
        case 0x71: func_MOV_M_C();    break;
        case 0x72: func_MOV_M_D();    break;
        case 0x73: func_MOV_M_E();    break;
        case 0x74: func_MOV_M_H();    break;
        case 0x75: func_MOV_M_L();    break;
        case 0x76: func_HLT();        break;
        case 0x77: func_MOV_M_A();    break;
        case 0x78: func_MOV_A_B();    break;
        case 0x79: func_MOV_A_C();    break;
        case 0x7a: func_MOV_A_D();    break;
        case 0x7b: func_MOV_A_E();    break;
        case 0x7c: func_MOV_A_H();    break;
        case 0x7d: func_MOV_A_L();    break;
        case 0x7e: func_MOV_A_M();    break;
        case 0x7f: func_MOV_A_A();    break;
        case 0x80: func_ADD_B();      break;
        case 0x81: func_ADD_C();      break;
        case 0x82: func_ADD_D();      break;
        case 0x83: func_ADD_E();      break;
        case 0x84: func_ADD_H();      break;
        case 0x85: func_ADD_L();      break;
        case 0x86: func_ADD_M();      break;
        case 0x87: func_ADD_A();      break;
        case 0x88: func_ADC_B();      break;
        case 0x89: func_ADC_C();      break;
        case 0x8a: func_ADC_D();      break;
        case 0x8b: func_ADC_E();      break;
        case 0x8c: func_ADC_H();      break;
        case 0x8d: func_ADC_L();      break;
        case 0x8e: func_ADC_M();      break;
        case 0x8f: func_ADC_A();      break;
        case 0x90: func_SUB_B();      break;
        case 0x91: func_SUB_C();      break;
        case 0x92: func_SUB_D();      break;
        case 0x93: func_SUB_E();      break;
        case 0x94: func_SUB_H();      break;
        case 0x95: func_SUB_L();      break;
        case 0x96: func_SUB_M();      break;
        case 0x97: func_SUB_A();      break;
        case 0x98: func_SBB_B();      break;
        case 0x99: func_SBB_C();      break;
        case 0x9a: func_SBB_D();      break;
        case 0x9b: func_SBB_E();      break;
        case 0x9c: func_SBB_H();      break;
        case 0x9d: func_SBB_L();      break;
        case 0x9e: func_SBB_M();      break;
        case 0x9f: func_SBB_A();      break;
        case 0xa0: func_ANA_B();      break;
        case 0xa1: func_ANA_C();      break;
        case 0xa2: func_ANA_D();      break;
        case 0xa3: func_ANA_E();      break;
        case 0xa4: func_ANA_H();      break;
        case 0xa5: func_ANA_L();      break;
        case 0xa6: func_ANA_M();      break;
        case 0xa7: func_ANA_A();      break;
        case 0xa8: func_XRA_B();      break;
        case 0xa9: func_XRA_C();      break;
        case 0xaa: func_XRA_D();      break;
        case 0xab: func_XRA_E();      break;
        case 0xac: func_XRA_H();      break;
        case 0xad: func_XRA_L();      break;
        case 0xae: func_XRA_M();      break;
        case 0xaf: func_XRA_A();      break;
        case 0xb0: func_ORA_B();      break;
        case 0xb1: func_ORA_C();      break;
        case 0xb2: func_ORA_D();      break;
        case 0xb3: func_ORA_E();      break;
        case 0xb4: func_ORA_H();      break;
        case 0xb5: func_ORA_L();      break;
        case 0xb6: func_ORA_M();      break;
        case 0xb7: func_ORA_A();      break;
        case 0xb8: func_CMP_B();      break;
        case 0xb9: func_CMP_C();      break;
        case 0xba: func_CMP_D();      break;
        case 0xbb: func_CMP_E();      break;
        case 0xbc: func_CMP_H();      break;
        case 0xbd: func_CMP_L();      break;
        case 0xbe: func_CMP_M();      break;
        case 0xbf: func_CMP_A();      break;
        case 0xc0: func_RNZ();        break;
        case 0xc1: func_POP_B();      break;
        case 0xc2: func_JNZ_ADR();    break;
        case 0xc3: func_JMP_ADR();    break;
        case 0xc4: func_CNZ_ADR();    break;
        case 0xc5: func_PUSH_B();     break;
        case 0xc6: func_ADI_D8();     break;
        case 0xc7: func_RST_0();      break;
        case 0xc8: func_RZ();         break;
        case 0xc9: func_RET();        break;
        case 0xca: func_JZ_ADR();     break;
        case 0xcb: func_JMP_ADR();    break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0xcc: func_CZ_ADR();     break;
        case 0xcd: func_CALL_ADR();   break;
        case 0xce: func_ACI_D8();     break;
        case 0xcf: func_RST_1();      break;
        case 0xd0: func_RNC();        break;
        case 0xd1: func_POP_D();      break;
        case 0xd2: func_JNC_ADR();    break;
        case 0xd3: func_OUT_D8();     break;
        case 0xd4: func_CNC_ADR();    break;
        case 0xd5: func_PUSH_D();     break;
        case 0xd6: func_SUI_D8();     break;
        case 0xd7: func_RST_2();      break;
        case 0xd8: func_RC();         break;
        case 0xd9: func_RET();        break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0xda: func_JC_ADR();     break;
        case 0xdb: func_IN_D8();      break;
        case 0xdc: func_CC_ADR();     break;
        case 0xdd: func_CALL_ADR();   break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0xde: func_SBI_D8();     break;
        case 0xdf: func_RST_3();      break;
        case 0xe0: func_RPO();        break;
        case 0xe1: func_POP_H();      break;
        case 0xe2: func_JPO_ADR();    break;
        case 0xe3: func_XTHL();       break;
        case 0xe4: func_CPO_ADR();    break;
        case 0xe5: func_PUSH_H();     break;
        case 0xe6: func_ANI_D8();     break;
        case 0xe7: func_RST_4();      break;
        case 0xe8: func_RPE();        break;
        case 0xe9: func_PCHL();       break;
        case 0xea: func_JPE_ADR();    break;
        case 0xeb: func_XCHG();       break;
        case 0xec: func_CPE_ADR();    break;
        case 0xed: func_CALL_ADR();   break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0xee: func_XRI_D8();     break;
        case 0xef: func_RST_5();      break;
        case 0xf0: func_RP();         break;
        case 0xf1: func_POP_PSW();    break;
        case 0xf2: func_JP_ADR();     break;
        case 0xf3: func_DI();         break;
        case 0xf4: func_CP_ADR();     break;
        case 0xf5: func_PUSH_PSW();   break;
        case 0xf6: func_ORI_D8();     break;
        case 0xf7: func_RST_6();      break;
        case 0xf8: func_RM();         break;
        case 0xf9: func_SPHL();       break;
        case 0xfa: func_JM_ADR();     break;
        case 0xfb: func_EI();         break;
        case 0xfc: func_CM_ADR();     break;
        case 0xfd: func_CALL_ADR();   break;        // SHOULD NOT BE USED, Repeated OpCode
        case 0xfe: func_CPI_D8();     break;
        case 0xff: func_RST_7();      break;
    }
}


// BEGIN GENERAL FUNCTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

/**
 * [DESCRIPTION] Generic Move Imediate 16 bit Function to pass the LXI OpCodes to
 * 
 * [PARAM] reg_Source1 
 * [PARAM] reg_Source2 
*/
void i8080::i8080_OpCodes::func_LXI_Registers(i8080_Registers::Register_8Bit &reg_Source1, i8080_Registers::Register_8Bit &reg_Source2)
{
	reg_Source1.set(memory->opCode_Array[2]);
	reg_Source2.set(memory->opCode_Array[1]);
};

/**
 * [DESCRIPTION] Generic Increment 16 bit Function to pass the INX 8bit OpCodes to
 * 
 * [PARAM] reg_Source1 
 * [PARAM] reg_Source2 
*/
void i8080::i8080_OpCodes::func_INX_Registers(i8080_Registers::Register_8Bit &reg_Source1, i8080_Registers::Register_8Bit &reg_Source2) 
{
	uint8_t uint8_Source1Temp = reg_Source1.get();
	uint8_t uint8_Source2Temp = reg_Source2.get();

	uint16_t uint16_RegisterTemp = 0x0000;

	uint16_RegisterTemp = uint16_RegisterTemp | uint8_Source1Temp;
	uint16_RegisterTemp = uint16_RegisterTemp << 8;

	uint16_RegisterTemp = uint16_RegisterTemp | uint8_Source2Temp;

	uint16_RegisterTemp = uint16_RegisterTemp + 0x0001;

	uint8_t uint8_ResultTemp = uint16_RegisterTemp & 0x00FF;

	reg_Source2.set(uint8_ResultTemp);

	uint8_ResultTemp = (uint16_RegisterTemp >> 8) & 0x00FF;

	reg_Source1.set(uint8_ResultTemp);

}

/**
 * [DESCRIPTION] Generic Increment Function to pass the INR OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_INR_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_RegisterTemp = reg_Source.get();
	uint8_t uint8_ResultTemp = uint8_RegisterTemp + 0x01;
	
	reg_Source.set(uint8_ResultTemp);
	
	// S	Z	AC	P
	
	flags->set_S_Z_P();
	flags->set_AC(uint8_RegisterTemp, 0x01);
	
};

/**
 * [DESCRIPTION] Generic Decrement Function to pass the DCR OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_DCR_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_RegisterTemp = reg_Source.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get())) + 0x01;
	uint8_t uint8_ResultTemp = uint8_RegisterTemp - 0x01;

	reg_Source.set(uint8_ResultTemp);
	
	// S	Z	AC	P
	flags->set_S_Z_P();
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->AC.set(false);	
};

/**
 * [DESCRIPTION] Generic Move Function to pass the MOV OpCodes to
 * 
 * [PARAM] reg_Destination 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_MOV_Registers(i8080_Registers::Register_8Bit &reg_Destination, i8080_Registers::Register_8Bit &reg_Source)
{
	reg_Destination.set(reg_Source.get());
};

/**
 * [DESCRIPTION] // Generic Immediate Move Function to pass the MVI OpCodes to
 * 
 * [PARAM] reg_Destination 
 * [PARAM] uint8_Source 
*/
void i8080::i8080_OpCodes::func_MVI_Registers(i8080_Registers::Register_8Bit &reg_Destination, uint8_t uint8_Source)
{
	reg_Destination.set(uint8_Source);
};

/**
 * [DESCRIPTION] Generic Add Function to pass the ADD OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_ADD_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_ResultTemp = uint8_InitialA + reg_Source.get();
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();
	flags->set_AC(uint8_InitialA, reg_Source.get());
	flags->set_C(uint8_InitialA, reg_Source.get(), false);
	
};

/**
 * [DESCRIPTION] Generic Add Plus Carry Function to pass ADC OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_ADC_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_InitialA = registers->A.get();
	
	if (flags->C.get() == true){
		uint8_InitialA = uint8_InitialA + 0x01;
	}
	
	uint8_t uint8_ResultTemp = uint8_InitialA + reg_Source.get();
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
    flags->set_S_Z_P();
	flags->set_AC(uint8_InitialA, reg_Source.get());
	flags->set_C(uint8_InitialA, reg_Source.get(), false);
	
};

/**
 * [DESCRIPTION] Generic Sub Function to pass the SUB OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_SUB_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get())) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - reg_Source.get();
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	flags->set_S_Z_P();
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);;
	
};

/**
 * [DESCRIPTION] Generic Sub with Borrow Function to pass the SBB OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_SBB_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get())) + 0x01;
	uint8_t uint8_RegisterTemp = reg_Source.get();
	
	if (flags->C.get() == true){
		uint8_RegisterTemp = uint8_RegisterTemp + 0x01;
	}
	
	uint8_t uint8_ResultTemp = uint8_InitialA - uint8_RegisterTemp;
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);;
	
};

/**
 * [DESCRIPTION] Generic And Function to pass the ANA OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_ANA_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_ResultTemp = registers->A.get() & reg_Source.get();
	
	registers->A.set(uint8_ResultTemp);
	
	// According to the i8080 Programming Manual the ANA instructions do not affect the AC Flag (pg 19)
	// This differs from the documentation on other sites.
	// S	Z	P	CY
	
	flags->set_S_Z_P();
	flags->C.set(false);
};

/**
 * [DESCRIPTION] Generic Exclusive OR Function to pass XRA OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_XRA_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTemp = reg_Source.get();
	uint8_t uint8_ResultTemp = uint8_InitialA ^ uint8_RegisterTemp;
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();
	flags->AC.set(0);
	flags->C.set(0);
	
	
};

/**
 * [DESCRIPTION] Generic Or Function to pass the ORA OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_ORA_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_ResultTemp = registers->A.get() | reg_Source.get();
	
	registers->A.set(uint8_ResultTemp);
	
	// According to the i8080 Programming Manual the ORA instructions do not affect the AC Flag (pg 19)
	// This differs from the documentation on other sites.
	// S	Z	P	CY
	flags->set_S_Z_P();
	flags->C.set(0);
	
};

/**
 * [DESCRIPTION] Generic Compare Function to pass the CMP OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_CMP_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~reg_Source.get()) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - reg_Source.get();
	
	// S	Z	AC	P	CY
	flags->set_S(reg_Source);
	
	if (uint8_InitialA == reg_Source.get()){
		flags->Z.set(1);
	}
	else {
		flags->Z.set(0);
	}
	
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	
	flags->set_P(uint8_ResultTemp);
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);;
	
};

/**
 * [DESCRIPTION] Generic Push Function to pass the PUSH OpCodes to
 * 
 * [PARAM] reg_Source1 
 * [PARAM] reg_Source2 
*/
void i8080::i8080_OpCodes::func_PUSH_Registers(i8080_Registers::Register_8Bit &reg_Source1, i8080_Registers::Register_8Bit &reg_Source2)
{
	uint16_t uint16_TempSP = registers->SP.get();
	
	// Function to push data to memory
	memory->set(uint16_TempSP - 0x0001, reg_Source1.get());
	
	// Function to push data to memory
	memory->set(uint16_TempSP - 0x0002, reg_Source2.get());
	
	registers->SP.set(uint16_TempSP - 0x0002);
};

/**
 * [DESCRIPTION] Generic Return function to pass the RET OpCodes to
 * 
*/
void i8080::i8080_OpCodes::func_General_RET()
{
	uint16_t uint16_InitialSP = registers->SP.get();
	uint8_t uint8_ResultTemp1 = 0x00;
	uint8_t uint8_ResultTemp2 = 0x00;
	uint16_t uint16_ResultTemp = 0x0000;

	uint8_ResultTemp1 = memory->get(uint16_InitialSP); 
	uint8_ResultTemp2 = memory->get(uint16_InitialSP + 0x0001); 
	uint16_ResultTemp = uint16_ResultTemp | uint8_ResultTemp2;
	uint16_ResultTemp = uint16_ResultTemp << 0x08;
	uint16_ResultTemp = uint16_ResultTemp | uint8_ResultTemp1;

	registers->PC.set(uint16_ResultTemp);
	registers->SP.set(uint16_InitialSP + 0x0002);
};

/**
 * [DESCRIPTION] Generic Call function to pass the CALL OpCodes to
 * 
*/
void i8080::i8080_OpCodes::func_General_CALL()
{
	uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8);

    // Combine the two bytes following the OpCode to form the address for where the Call
    // will take the program.
    uint16_t uint16_AddressTemp = 0x0000;
    uint16_t uint16_InitialAddrLow = memory->opCode_Array[1];
    uint16_t uint16_InitialAddrHigh = memory->opCode_Array[2];

    uint16_AddressTemp = uint16_AddressTemp | uint16_InitialAddrHigh;
    uint16_AddressTemp = uint16_AddressTemp << 8;
    uint16_AddressTemp = uint16_AddressTemp | uint16_InitialAddrLow;

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x01), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x02), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x02);
	registers->PC.set(uint16_AddressTemp);

};

// END GENERAL FUNCTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


// BEGIN SPECIFIC FUNCTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// END SPECIFIC FUNCTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-