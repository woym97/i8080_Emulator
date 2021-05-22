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
 * [DESCRIPTION] Construct a new i8080::i8080 OpCodes::i8080 OpCodes object
 *      - Point the new class to the parents members
 * [PARAM] parent_register 
 * [PARAM] parent_memory 
 * [PARAM] parent_flags 
 * [PARAM] parent_clock 
 * [PARAM] parent_IO 
*/
i8080::i8080_OpCodes::i8080_OpCodes(i8080_Registers* parent_register, 
                                    i8080_Memory*    parent_memory, 
                                    i8080_Flags*     parent_flags, 
                                    i8080_Clock*     parent_clock, 
                                    i8080_IO*        parent_IO)
{
    registers   = parent_register;
    memory      = parent_memory;
    flags       = parent_flags;
    clock       = parent_clock;
    io          = parent_IO;
}

/**
 * [DESCRIPTION] Main caller of all the opcodes
 *      - Also performs a preliminary increment of the PC
 *
 * [PARAM] passed_code
*/
void i8080::i8080_OpCodes::runOpCode()
{
    // Inc the PC tha default step of 1
    registers->inc_PC(1);
    //printf("%d\n", memory->opCode_Array[0]);

    switch(memory->opCode_Array[0]) {
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
void i8080::i8080_OpCodes::func_LXI_Registers(i8080_Registers::Register_8Bit& reg_Source1, i8080_Registers::Register_8Bit& reg_Source2)
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
void i8080::i8080_OpCodes::func_INR_Registers(i8080_Registers::Register_8Bit& reg_Source)
{
	uint8_t uint8_RegisterTemp = reg_Source.get();
	uint8_t uint8_ResultTemp = uint8_RegisterTemp + 0x01;
	
	reg_Source.set(uint8_ResultTemp);
	
	// S	Z	AC	P
	
	//flags->set_S_Z_P();
    flags->set_S(uint8_ResultTemp);
    flags->set_Z(uint8_ResultTemp);
    flags->set_P(uint8_ResultTemp);
	flags->set_AC(uint8_RegisterTemp, 0x01);
	
};

/**
 * [DESCRIPTION] Generic Decrement Function to pass the DCR OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_DCR_Registers(i8080_Registers::Register_8Bit& reg_Source)
{
	uint8_t uint8_RegisterTemp = reg_Source.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get())) + 0x01;
	uint8_t uint8_ResultTemp = uint8_RegisterTemp - 0x01;

	reg_Source.set(uint8_ResultTemp);
	
	// S	Z	AC	P
	//flags->set_S_Z_P();
    flags->set_S(uint8_ResultTemp);
    flags->set_Z(uint8_ResultTemp);
    flags->set_P(uint8_ResultTemp);
    
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
        uint8_RegisterTwosCompliment = (~(uint8_RegisterTemp)) + 0x01;
	}
	
	uint8_t uint8_ResultTemp = uint8_InitialA - uint8_RegisterTemp;
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_RegisterTemp, uint8_RegisterTwosCompliment);
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_RegisterTemp, uint8_RegisterTwosCompliment, true);;
	
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
	flags->AC.set(false);
	flags->C.set(false);
	
	
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
	flags->C.set(false);
	
};

/**
 * [DESCRIPTION] Generic Compare Function to pass the CMP OpCodes to
 * 
 * [PARAM] reg_Source 
*/
void i8080::i8080_OpCodes::func_CMP_Registers(i8080_Registers::Register_8Bit &reg_Source)
{
	uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(reg_Source.get()) + 0x01);
	uint8_t uint8_ResultTemp = uint8_InitialA - reg_Source.get();
	
	// S	Z	AC	P	CY
	flags->set_S(uint8_ResultTemp);
	
	if (uint8_InitialA == reg_Source.get()){
		flags->Z.set(true);
	}
	else {
		flags->Z.set(false);
	}
	
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	
	flags->set_P(uint8_ResultTemp);
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);
	
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

////////////////////
// Description:
// OpCode: 0x00	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_NOP() {

    // NO ACTION
    clock->incClockCycles(4);
}

////////////////////
// Description: 16 Bit Immediate Load from Memory
// OpCode: 0x01	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_LXI_B_D16() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: B <- byte 3, C <- byte 2
    func_LXI_Registers(registers->B, registers->C);

    clock->incClockCycles(10);

}

////////////////////
// Description: Pushes A into the combined passed register and the next one
// OpCode: 0x02	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_STAX_B() {

    // Logic for: (BC) <- A
    memory->set(registers->get_BC(), registers->A.get());

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x03	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_INX_B() {

    // Logic for: BC <- BC+1
    registers->set_BC(registers->get_BC() + 1);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x04	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: B and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_INR_B() {

    // Logic for: B <- B+1
    func_INR_Registers(registers->B);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x05	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_DCR_B() {

    // Logic for: B <- B-1
    func_DCR_Registers(registers->B);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x06	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: B and A
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_MVI_B_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: B <- byte 2
    func_MVI_Registers(registers->B, memory->opCode_Array[1] );

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x07	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_RLC() {

    // Logic for: A = A << 1; bit 0 = prev bit 7; CY = prev bit 7
    uint8_t uint8_InitialA = registers->A.get();

    uint8_t uint8_ResultTemp;
    bool bool_Result = false;

    // Checks to see if the high order bit is 1 or 0. If it is a one the result
    // value is changed, and will be used to set the carry flag

    if ((uint8_InitialA & 0x80) != 0x00){
        bool_Result = true;
    }

    // The Accumulator value is shifted to the left one position
    uint8_ResultTemp = uint8_InitialA << 1;

    // The least significant bit is set by what the high order bit was when the
    // operation started
    if (bool_Result == true){
        uint8_ResultTemp = uint8_ResultTemp | 0x01;
    }

    // The Accumulator is set to the shifted value
    registers->A.set(uint8_ResultTemp);

    // Set flags: CY
    flags->C.set(bool_Result);

    clock->incClockCycles(4);

}

// Opcode 0x08 NOP() Repeated OpCode

////////////////////
// Description:
// OpCode: 0x09	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers:
// Written By: Madison - FAILED
////////////////////
void i8080::i8080_OpCodes::func_DAD_B() {

    // Logic for: HL = HL + BC
    uint16_t initial_HL = registers->get_HL();
    uint16_t uint16_InitialBC = registers->get_BC();
    registers->set_HL(initial_HL + uint16_InitialBC);

    // Set flags: CY
    flags->set_C(initial_HL, uint16_InitialBC, false);

    clock->incClockCycles(10);

}

////////////////////
// Description: Pushes the combo of the passed register and the meighbor into A
// OpCode: 0x0a	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_LDAX_B() {

    uint16_t uint16_InitialBC = registers->get_BC();
    uint8_t uint8_MemoryValue = memory->get(uint16_InitialBC);
    // Logic for: A <- (BC)
    registers->A.set(uint8_MemoryValue);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x0b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_DCX_B() {

    // Logic for: BC = BC-1
    registers->set_BC(registers->get_BC() - 1);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x0c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: C and A
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_INR_C() {

    // Logic for: C <- C+1
    func_INR_Registers(registers->C);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x0d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_DCR_C() {

    // Logic for: C <-C-1
    func_DCR_Registers(registers->C);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x0e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MVI_C_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: C <- byte 2
    func_MVI_Registers(registers->C, memory->opCode_Array[1]);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x0f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers:
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_RRC() {

    // Logic for: A = A >> 1; bit 7 = prev bit 0; CY = prev bit 0
    uint8_t uint8_InitialA = registers->A.get();

    uint8_t uint8_ResultTemp;
    bool bool_Result = false;

    // Checks to see if the low order bit is 1 or 0. If it is a one the result
    // value is changed, and will be used to set the carry flag
    if ((uint8_InitialA & 0x01) != 0x00){
        bool_Result = true;
    }

    // The Accumulator value is shifted to the right one position
    uint8_ResultTemp = uint8_InitialA >> 1;

    // The most significant bit is set by what the low order bit was when the
    // operation started
    if (bool_Result == true){
        uint8_ResultTemp = uint8_ResultTemp | 0x80;
    }

    // The Accumulator is set to the shifted value
    registers->A.set(uint8_ResultTemp);

    // Set flags: CY
    flags->C.set(bool_Result);

    // Set flags: CY
    clock->incClockCycles(4);

}

// Opcode 0x10 NOP() Repeated OpCode

////////////////////
// Description:
// OpCode: 0x11	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_LXI_D_D16() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: D <- byte 3, E <- byte 2
    func_LXI_Registers(registers->D, registers->E);

    clock->incClockCycles(10);


}

////////////////////
// Description: Pushes A into the combined passed register and the next one
// OpCode: 0x12	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison - FAILED
////////////////////
void i8080::i8080_OpCodes::func_STAX_D() {

    // Logic for: (DE) <- A
    memory->set(registers->get_DE(), registers->A.get());

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x13	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_INX_D() {

    // Logic for: DE <- DE + 1
    registers->set_DE(registers->get_DE() + 1);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x14	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: D and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_INR_D() {

    // Logic for: D <- D+1
    func_INR_Registers(registers->D);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x15	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Madison - FAILED
////////////////////
void i8080::i8080_OpCodes::func_DCR_D() {

    // Logic for: D <- D-1
    func_DCR_Registers(registers->D);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x16	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: D and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MVI_D_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: D <- byte 2
    func_MVI_Registers(registers->D, memory->opCode_Array[1] );

    clock->incClockCycles(7);

}

////////////////////
// Description: Rotates the Accumulator to the left one bit through the Carry Out Flag.
//				The Carry Out Flag becomes the least significant bit of the Accumulator.
// OpCode: 0x17	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_RAL() {

    // Logic for: A = A << 1; bit 0 = prev CY; CY = prev bit 7
    uint8_t uint8_InitialA = registers->A.get();
    bool bool_InitialCY = flags->C.get();

    uint8_t uint8_ResultTemp;
    bool bool_Result = false;

    // Checks to see if the high order bit is 1 or 0. If it is a one the result
    // value is changed, and will be used to set the carry flag
    if ((uint8_InitialA & 0x80) != 0x00){
        bool_Result = true;
    }

    // The Accumulator value is shifted to the left one position
    uint8_ResultTemp = (uint8_InitialA << 1);

    // The least significant bit is set by what the carry flag was when the
    // operation started
    if (bool_InitialCY == true){
        uint8_ResultTemp = (uint8_ResultTemp | 0x01);
    }

    // The Accumulator is set to the shifted value
    registers->A.set(uint8_ResultTemp);

    // Set flags: CY
    flags->C.set(bool_Result);

    clock->incClockCycles(4);

}

// Opcode 0x18 NOP() Repeated OpCode

////////////////////
// Description:
// OpCode: 0x19	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_DAD_D() {

    // Logic for: HL = HL + DE
    uint16_t initial_HL = registers->get_HL();
    registers->set_HL(registers->get_HL() + registers->get_DE());

    // Set flags: CY
    flags->set_C(initial_HL, registers->get_DE(), false);

    // Set flags: CY
    clock->incClockCycles(10);

}

////////////////////
// Description: Pushes the combo of the passed register and the meighbor into A
// OpCode: 0x1a	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_LDAX_D() {

    // Logic for: A <- (DE)
    registers->A.set(memory->get(registers->get_DE()));

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x1b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison - FAILED
////////////////////
void i8080::i8080_OpCodes::func_DCX_D() {

    // Logic for: DE = DE-1
    registers->set_DE(registers->get_DE() - 1);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x1c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: E and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_INR_E() {

    // Logic for: E <-E+1
    func_INR_Registers(registers->E);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x1d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_DCR_E() {

    // Logic for: E <- E-1
    func_DCR_Registers(registers->E);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x1e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: E and A
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_MVI_E_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: E <- byte 2
    func_MVI_Registers(registers->E, memory->opCode_Array[1]);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x1f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_RAR() {

    // Logic for: A = A >> 1; bit 7 = prev bit 7; CY = prev bit 0
    uint8_t uint8_InitialA = registers->A.get();
    bool bool_InitialCY = flags->C.get();

    uint8_t uint8_ResultTemp;
    bool bool_Result = false;

    // Checks to see if the low order bit is 1 or 0. If it is a one the result
    // value is changed, and will be used to set the carry flag
    if ((uint8_InitialA & 0x01) != 0x00){
        bool_Result = true;
    }

    // The Accumulator value is shifted to the left one position
    uint8_ResultTemp = (uint8_InitialA >> 1);

    // The most significant bit is set by what the carry flag was when the
    // operation started
    if (bool_InitialCY == true) {
        uint8_ResultTemp = (uint8_ResultTemp | 0x80);
    }

    // The Accumulator is set to the shifted value
    registers->A.set(uint8_ResultTemp);

    // Set flags: CY
    flags->C.set(bool_Result);

    // Set flags: CY
    clock->incClockCycles(4);

}

// 0x20 NOP() Repeated OpCode

////////////////////
// Description:
// OpCode: 0x21	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_LXI_H_D16() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: H <- byte 3, L <- byte 2
    func_LXI_Registers(registers->H, registers->L);

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0x22	|| Size: 3 bit	|| Clock cycles: 16
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_SHLD_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: (adr) <-L; (adr+1)<-H
    uint16_t uint16_AddressTemp = 0x0000;
    uint16_t uint16_InitialAddrLow = memory->opCode_Array[1];
    uint16_t uint16_InitialAddrHigh = memory->opCode_Array[2];

    uint16_AddressTemp = uint16_AddressTemp | uint16_InitialAddrHigh;
    uint16_AddressTemp = uint16_AddressTemp << 8;
    uint16_AddressTemp = uint16_AddressTemp | uint16_InitialAddrLow;

    memory->set(uint16_AddressTemp, registers->L.get());
    memory->set((uint16_AddressTemp + 0x01), registers->H.get());

    clock->incClockCycles(16);

}

////////////////////
// Description:
// OpCode: 0x23	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_INX_H() {

    // Logic for: HL <- HL + 1
    uint16_t uint16_InitialHL = registers->get_HL();
    uint16_t uint16_ResultTemp = 0x0000;
    uint16_ResultTemp = uint16_InitialHL + 0x0001;
    registers->set_HL(uint16_ResultTemp);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x24	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: H and A
// Written By: Madison - FAILED
////////////////////
void i8080::i8080_OpCodes::func_INR_H() {

    // Logic for: H <- H+1
    func_INR_Registers(registers->H);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x25	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_DCR_H() {

    // Logic for: H <- H-1
    func_DCR_Registers(registers->H);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x26	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MVI_H_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: H <- byte 2
    func_MVI_Registers(registers->H, memory->opCode_Array[1]);

    clock->incClockCycles(7);

}

////////////////////
// Description: Decimal Adjust Accumulator - breaks the 8 bit Accumulator into 2, 4 bit numbers. The values
//				are compared to see if they are greater than 9 (ie A, B, C, D, E, or F). If they are the value
//				is increased by 6.
// OpCode: 0x27	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison* - PASSED
////////////////////
void i8080::i8080_OpCodes::func_DAA() {

    // Logic for: Decimal Adjust Accumulator

    uint8_t uint8_InitialA = registers->A.get();
    uint8_t uint8_ResultTemp1 = 0x00;
    uint8_t uint8_ResultTemp2 = 0x00;
    bool bool_InitialAC = flags->AC.get();
    bool bool_InitialCY = flags->C.get();
    bool bool_Result1 = false;
    bool bool_Result2 = false;

    //(1) If the least significant four bits of the accumulator
    //represents a number greater than 9, or if the Auxiliary
    //Carry bit is equal to one, the accumulator is incremented by six. Otherwise, no incrementing occurs.
    if (((uint8_InitialA & 0x0F) > 0x09) || (bool_InitialAC == true)) {
        // Increments the Accumulator by 6
        uint8_ResultTemp1 = uint8_InitialA + 0x06;

        // Checks Auxiliary Carry of the increment
        bool_Result1 = flags->check_AC(uint8_InitialA, 0x06);

    }

    //(2) If the most significant four bits of the accumulator
    //now represent a number greater than 9, or if the normal carry bit is equal to one, the most sign ificant four
    //bits of the accumulator are incremented by six. Otherwise, no incrementing occurs.
    if (((uint8_ResultTemp1 & 0xF0) > 0x90) || (bool_InitialCY == true)) {
        // Increments the Accumulator by 6 in the upper byte
        uint8_ResultTemp2 = uint8_ResultTemp1 + 0x60;

        // Checks the Carry of the increment
        bool_Result2 = flags->check_C(uint8_ResultTemp1, 0x60);
    }

    // Sets or resets the Auxiliary Carry Flag
    flags->AC.set(bool_Result1);

    if (bool_Result2 == true) {
        flags->C.set(true);
    }

    clock->incClockCycles(4);

}

// Opcode 0x28 NOP() Repeated OpCode

////////////////////
// Description:
// OpCode: 0x29	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_DAD_H() {

    // Logic for: HL = HL + HI
    uint16_t initial_HL = registers->get_HL();
    registers->set_HL(initial_HL + initial_HL);

    // Set flags: CY
    flags->set_C(initial_HL, initial_HL, false);

    // Set flags: CY
    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0x2a	|| Size: 3 bit	|| Clock cycles: 16
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_LHLD_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: L <- (adr); H<-(adr+1)
    registers->L.set(memory->get(memory->get_Adr()));
    registers->H.set(memory->get(memory->get_Adr() + 1));

    clock->incClockCycles(16);


}

////////////////////
// Description:
// OpCode: 0x2b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_DCX_H() {

    // Logic for: HL = HL-1
    registers->set_HL(registers->get_HL() - 1);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x2c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: L and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_INR_L() {

    // Logic for: L <- L+1
    func_INR_Registers(registers->L);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x2d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Madison - FAILED
////////////////////
void i8080::i8080_OpCodes::func_DCR_L() {

    // Logic for: L <- L-1
    func_DCR_Registers(registers->L);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x2e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: L and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MVI_L_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: L <- byte 2
    func_MVI_Registers(registers->L, memory->opCode_Array[1]);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x2f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_CMA() {

    // Logic for: A <- !A
    uint8_t uint8_InitialA = registers->A.get();
    uint8_t uint8_ComplA = ~uint8_InitialA;

    registers->A.set(uint8_ComplA);

    clock->incClockCycles(4);

}


// OpCode: 0x30	NOP() Repeated OpCode

////////////////////
// Description:
// OpCode: 0x31	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_LXI_SP_D16() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: SP.hi <- byte 3, SP.lo <- byte 2
    //func_LXI_Registers(registers->SP, registers-> );
    uint16_t uint16_RegisterTemp = 0x0000;

    uint16_RegisterTemp = uint16_RegisterTemp | memory->opCode_Array[2];
    uint16_RegisterTemp = uint16_RegisterTemp << 8;
    uint16_RegisterTemp = uint16_RegisterTemp | memory->opCode_Array[1];

    registers->SP.set(uint16_RegisterTemp);

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0x32	|| Size: 3 bit	|| Clock cycles: 13
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_STA_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: (adr) <- A
    uint8_t uint8_InitialA = registers->A.get();
    uint16_t uint16_InitialAddress = memory->get_Adr();
    memory->set(uint16_InitialAddress, uint8_InitialA);

    clock->incClockCycles(13);

}

////////////////////
// Description:
// OpCode: 0x33	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison - PASSED
////////////////////
void i8080::i8080_OpCodes::func_INX_SP() {

    // Logic for: SP = SP + 1
    uint16_t uint16_InitialSP = registers->SP.get();

    uint16_t uint16_RegisterTemp = 0x0000;

    if (uint16_InitialSP != 0xFFFF) {
        uint16_RegisterTemp = uint16_InitialSP + 0x0001;
    }

    registers->SP.set(uint16_RegisterTemp);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x34	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_INR_M() {

    // Logic for: (HL) <- (HL)+1
    uint8_t uint8_InitialM = memory->get_M();
    uint8_t uint8_ResultTemp = uint8_InitialM + 0x01;

    memory->set_M(uint8_ResultTemp);

    // Set flags: Z, S, P, AC
    flags->set_S(uint8_ResultTemp);
    flags->set_Z(uint8_ResultTemp);
    flags->set_AC(uint8_InitialM, 0x01);
    flags->set_P(uint8_ResultTemp);

    clock->incClockCycles(10);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x35	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_DCR_M() {

    // Logic for: (HL) <- (HL)-1
    uint8_t uint8_InitialM = memory->get_M();
    uint8_t uint8_ResultTemp = uint8_InitialM + 0x01;

    memory->set_M(uint8_ResultTemp);

    // Set flags: Z, S, P, AC
    flags->set_S(uint8_ResultTemp);
    flags->set_Z(uint8_ResultTemp);
    // When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
    //flags->AC.set(func_Check_AuxCarry(uint8_RegisterTemp, 0xFF));
    flags->AC.set(false);

    flags->set_P(uint8_ResultTemp);

    clock->incClockCycles(10);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x36	|| Size: 2 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers: M and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MVI_M_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: (HL) <- byte 2
    memory->set_M(memory->opCode_Array[1]);

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0x37	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_STC() {

    // Logic for: CY = 1

    // Set flags: CY
    flags->C.set(true);
    clock->incClockCycles(4);

}

// Opcode 0x38 NOP() Repeated OpCode

////////////////////
// Description:
// OpCode: 0x39	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: CY
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_DAD_SP() {

    // Logic for: HL = HL + SP
    uint16_t initial_HL = registers->get_HL();
    uint16_t uint16_InitialSP = registers->SP.get();
    registers->set_HL(initial_HL + uint16_InitialSP);

    // Set flags: CY
    flags->set_C(initial_HL, uint16_InitialSP, false);

    // Set flags: CY
    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0x3a	|| Size: 3 bit	|| Clock cycles: 13
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_LDA_ADR() {

    registers->inc_PC(2);

    // Logic for: A <- (adr)
    uint16_t uint16_AddrTemp = memory->get_Adr();
    uint8_t uint8_InitialMemory = memory->get(uint16_AddrTemp);
    registers->A.set(uint8_InitialMemory);

    clock->incClockCycles(13);

    // Inc PC to account for additional size
    

}

////////////////////
// Description:
// OpCode: 0x3b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_DCX_SP() {

    // Logic for: SP = SP-1
    registers->SP.set(registers->SP.get() - 1);

    clock->incClockCycles(5);

}

////////////////////
// Description: Increments the register below
// OpCode: 0x3c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers: A and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_INR_A() {

    // Logic for: A <- A+1
    func_INR_Registers(registers->A);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Decrements the register below
// OpCode: 0x3d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: Z, S, P, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_DCR_A() {

    // Logic for: A <- A-1
    func_DCR_Registers(registers->A);

    // Set flags: Z, S, P, AC
    clock->incClockCycles(5);

}

////////////////////
// Description: Adds byte 2 to the register below
// OpCode: 0x3e	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MVI_A_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A <- byte 2
    func_MVI_Registers(registers->A, memory->opCode_Array[1]);

    clock->incClockCycles(7);

    
    

}

////////////////////
// Description:
// OpCode: 0x3f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: CY
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_CMC() {

    // Logic for: CY=!CY
    flags->C.set(!(flags->C.get()));

    // Set flags: CY
    clock->incClockCycles(4);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x40	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and B
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_B() {

    // Logic for: B <- B
    func_MOV_Registers(registers->B, registers->B);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x41	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and C
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_C() {

    // Logic for: B <- C
    func_MOV_Registers(registers->B, registers->C);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x42	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and D
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_D() {

    // Logic for: B <- D
    func_MOV_Registers(registers->B, registers->D);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x43	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and E
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_E() {

    // Logic for: B <- E
    func_MOV_Registers(registers->B, registers->E);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x44	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and H
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_H() {

    // Logic for: B <- H
    func_MOV_Registers(registers->B, registers->H);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x45	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and L
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_L() {

    // Logic for: B <- L
    func_MOV_Registers(registers->B, registers->L);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x46	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: B and M
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_M() {

    // Logic for: B <- (HL)
    registers->B.set(memory->get_M());
    //func_MOV_Registers(registers->B, registers->M);

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x47	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: B and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_B_A() {

    // Logic for: B <- A
    func_MOV_Registers(registers->B, registers->A);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x48	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and B
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_B() {

    // Logic for: C <- B
    func_MOV_Registers(registers->C, registers->B);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x49	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and C
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_C() {

    // Logic for: C <- C
    func_MOV_Registers(registers->C, registers->C);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and D
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_D() {

    // Logic for: C <- D
    func_MOV_Registers(registers->C, registers->D);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and E
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_E() {

    // Logic for: C <- E
    func_MOV_Registers(registers->C, registers->E);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and H
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_H() {

    // Logic for: C <- H
    func_MOV_Registers(registers->C, registers->H);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and L
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_L() {

    // Logic for: C <- L
    func_MOV_Registers(registers->C, registers->L);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: C and M
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_M() {

    // Logic for: C <- (HL)
    registers->C.set(memory->get_M());     // MM - This wasn't pulling from memory 

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x4f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: C and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_C_A() {

    // Logic for: C <- A
    func_MOV_Registers(registers->C, registers->A);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x50	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and B
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_B() {

    // Logic for: D <- B
    func_MOV_Registers(registers->D, registers->B);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x51	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and C
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_C() {

    // Logic for: D <- C
    func_MOV_Registers(registers->D, registers->C);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x52	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and D
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_D() {

    // Logic for: D <- D
    func_MOV_Registers(registers->D, registers->D);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x53	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and E
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_E() {

    // Logic for: D <- E
    func_MOV_Registers(registers->D, registers->E);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x54	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and H
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_H() {

    // Logic for: D <- H
    func_MOV_Registers(registers->D, registers->H);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x55	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and L
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_L() {

    // Logic for: D <- L
    func_MOV_Registers(registers->D, registers->L);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x56	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: D and M
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_M() {

    // Logic for: D <- (HL)

    registers->D.set(memory->get_M());
    //func_MOV_Registers(registers->D, registers->M);

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x57	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_D_A() {

    // Logic for: D <- A
    func_MOV_Registers(registers->D, registers->A);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x58	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and B
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_B() {

    // Logic for: E <- B
    func_MOV_Registers(registers->E, registers->B);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x59	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and C
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_C() {

    // Logic for: E <- C
    func_MOV_Registers(registers->E, registers->C);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and D
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_D() {

    // Logic for: E <- D
    func_MOV_Registers(registers->E, registers->D);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and E
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_E() {

    // Logic for: E <- E
    func_MOV_Registers(registers->E, registers->E);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and H
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_H() {

    // Logic for: E <- H
    func_MOV_Registers(registers->E, registers->H);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and L
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_L() {

    // Logic for: E <- L
    func_MOV_Registers(registers->E, registers->L);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: E and M
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_M() {

    // Logic for: E <- (HL)
    //func_MOV_Registers(registers->E, registers->M);

    registers->E.set(memory->get_M());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x5f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: E and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_E_A() {

    // Logic for: E <- A
    func_MOV_Registers(registers->E, registers->A);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x60	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and B
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_B() {

    // Logic for: H <- B
    func_MOV_Registers(registers->H, registers->B);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x61	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and C
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_C() {

    // Logic for: H <- C
    func_MOV_Registers(registers->H, registers->C);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x62	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and D
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_D() {

    // Logic for: H <- D
    func_MOV_Registers(registers->H, registers->D);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x63	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and E
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_E() {

    // Logic for: H <- E
    func_MOV_Registers(registers->H, registers->E);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x64	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and H
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_H() {

    // Logic for: H <- H
    func_MOV_Registers(registers->H, registers->H);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x65	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and L
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_L() {

    // Logic for: H <- L
    func_MOV_Registers(registers->H, registers->L);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x66	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: H and M
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_M() {

    // Logic for: H <- (HL)
    registers->H.set(memory->get_M());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x67	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: H and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_H_A() {

    // Logic for: H <- A
    func_MOV_Registers(registers->H, registers->A);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x68	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and B
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_B() {

    // Logic for: L <- B
    func_MOV_Registers(registers->L, registers->B);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x69	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and C
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_C() {

    // Logic for: L <- C
    func_MOV_Registers(registers->L, registers->C);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and D
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_D() {

    // Logic for: L <- D
    func_MOV_Registers(registers->L, registers->D);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and E
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_E() {

    // Logic for: L <- E
    func_MOV_Registers(registers->L, registers->E);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and H
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_H() {

    // Logic for: L <- H
    func_MOV_Registers(registers->L, registers->H);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and L
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_L() {

    // Logic for: L <- L
    func_MOV_Registers(registers->L, registers->L);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: L and M
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_M() {

    // Logic for: L <- (HL)
    //func_MOV_Registers(registers->L, registers->M);

    registers->L.set(memory->get_M());
    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x6f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_L_A() {

    // Logic for: L <- A
    func_MOV_Registers(registers->L, registers->A);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x70	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and B
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_M_B() {

    // Logic for: (HL) <- B
    memory->set_M(registers->B.get());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x71	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and C
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_M_C() {

    // Logic for: (HL) <- C
    memory->set_M(registers->C.get());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x72	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and D
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_M_D() {

    // Logic for: (HL) <- D
    memory->set_M(registers->D.get());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x73	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and E
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_M_E() {

    // Logic for: (HL) <- E
    memory->set_M(registers->E.get());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x74	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and H
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_M_H() {

    // Logic for: (HL) <- H
    memory->set_M(registers->H.get());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x75	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and L
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_M_L() {

    // Logic for: (HL) <- L
    memory->set_M(registers->L.get());

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x76	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_HLT() {

    // Logic for: special
    // @TODO [Ruben ]: fill in logic

    printf("HLT Function");
    //system("pause"); // MM - Just to see if it has been called

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x77	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: M and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_M_A() {

    // Logic for: (HL) <- C
    //func_MOV_Registers(registers->M, registers->A);
    memory->set_M(registers->A.get());  // MM - Changed to reg_A form reg_C
    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x78	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and B
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_B() {

    // Logic for: A <- B
    func_MOV_Registers(registers->A, registers->B);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x79	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and C
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_C() {

    // Logic for: A <- C
    func_MOV_Registers(registers->A, registers->C);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7a	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and D
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_D() {

    // Logic for: A <- D
    func_MOV_Registers(registers->A, registers->D);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7b	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and E
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_E() {

    // Logic for: A <- E
    func_MOV_Registers(registers->A, registers->E);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7c	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and H
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_H() {

    // Logic for: A <- H
    func_MOV_Registers(registers->A, registers->H);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7d	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and L
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_L() {

    // Logic for: A <- L
    func_MOV_Registers(registers->A, registers->L);

    clock->incClockCycles(5);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: No Flags Effected
// Modifed Registers: A and M
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_M() {

    // Logic for: A <- (HL)
    registers->A.set(memory->get_M());

    clock->incClockCycles(7);

}

////////////////////
// Description: Move function for registers below
// OpCode: 0x7f	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: A and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_MOV_A_A() {

    // Logic for: A <- A
    func_MOV_Registers(registers->A, registers->A);

    clock->incClockCycles(5);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x80	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ADD_B() {

    // Logic for: A <- A + B
    func_ADD_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x81	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ADD_C() {

    // Logic for: A <- A + C
    func_ADD_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x82	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ADD_D() {

    // Logic for: A <- A + D
    func_ADD_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x83	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ADD_E() {

    // Logic for: A <- A + E
    func_ADD_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x84	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ADD_H() {

    // Logic for: A <- A + H
    func_ADD_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x85	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ADD_L() {

    // Logic for: A <- A + L
    func_ADD_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x86	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ADD_M() {

    // Logic for: A <- A + (HL)
    //func_ADD_Registers(registers->M);

    uint8_t uint8_InitialA = registers->A.get();
    uint8_t uint8_InitialM = memory->get_M();
    uint8_t uint8_ResultTemp = uint8_InitialA + uint8_InitialM;

    registers->A.set(uint8_ResultTemp);

    // S	Z	AC	P	CY

    flags->set_S_Z_P();
    flags->set_AC(uint8_InitialA, uint8_InitialM);
    flags->set_C(uint8_InitialA, uint8_InitialM, false);


    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(7);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x87	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ADD_A() {

    // Logic for: A <- A + A
    func_ADD_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x88	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ADC_B() {

    // Logic for: A <- A + B + CY
    func_ADC_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x89	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ADC_C() {

    // Logic for: A <- A + C + CY
    func_ADC_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8a	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ADC_D() {

    // Logic for: A <- A + D + CY
    func_ADC_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8b	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ADC_E() {

    // Logic for: A <- A + E + CY
    func_ADC_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8c	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ADC_H() {

    // Logic for: A <- A + H + CY
    func_ADC_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8d	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ADC_L() {

    // Logic for: A <- A + L + CY
    func_ADC_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ADC_M() {

    // Logic for: A <- A + (HL) + CY
    //func_ADC_Registers(registers->M);

    uint8_t uint8_InitialA = registers->A.get();
    uint8_t uint8_InitialM = memory->get_M();

    if (flags->C.get() == true) {
        uint8_InitialA = uint8_InitialA + 0x01;
    }

    uint8_t uint8_ResultTemp = uint8_InitialA + uint8_InitialM;

    registers->A.set(uint8_ResultTemp);

    // S	Z	AC	P	CY

    flags->set_S_Z_P();
    flags->set_AC(uint8_InitialA, uint8_InitialM);
    flags->set_C(uint8_InitialA, uint8_InitialM, false);

    clock->incClockCycles(7);

}

////////////////////
// Description: Add the two registers below
// OpCode: 0x8f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ADC_A() {

    // Logic for: A <- A + A + CY
    func_ADC_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    // Flags set in AD function

    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0x90	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_SUB_B() {

    // Logic for: A <- A - B
    func_SUB_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0x91	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_SUB_C() {

    // Logic for: A <- A - C
    func_SUB_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0x92	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_SUB_D() {

    // Logic for: A <- A - D
    func_SUB_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0x93	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_SUB_E() {

    // Logic for: A <- A - E
    func_SUB_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0x94	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_SUB_H() {

    // Logic for: A <- A + H
    func_SUB_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0x95	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_SUB_L() {

    // Logic for: A <- A - L
    func_SUB_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0x96	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_SUB_M() {

    // Logic for: A <- A - (HL)

    uint8_t uint8_RegisterTemp = memory->get_M();

    uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(uint8_RegisterTemp)) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - uint8_RegisterTemp;
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	flags->set_S_Z_P();
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0x97	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_SUB_A() {

    // Logic for: A <- A - A
    func_SUB_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x98	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_SBB_B() {

    // Logic for: A <- A - B - CY
    func_SBB_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x99	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_SBB_C() {

    // Logic for: A <- A - C - CY
    func_SBB_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9a	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_SBB_D() {

    // Logic for: A <- A - D - CY
    func_SBB_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9b	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_SBB_E() {

    // Logic for: A <- A - E - CY
    func_SBB_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9c	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_SBB_H() {

    // Logic for: A <- A - H - CY
    func_SBB_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9d	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_SBB_L() {

    // Logic for: A <- A - L - CY
    func_SBB_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9e	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_SBB_M() {

    // Logic for: A <- A - (HL) - CY

    uint8_t uint8_RegisterTemp = memory->get_M();

    uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(uint8_RegisterTemp)) + 0x01;
	
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
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);
    clock->incClockCycles(7);

}

////////////////////
// Description: Subtracts the register below from register A
// OpCode: 0x9f	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_SBB_A() {

    // Logic for: A <- A - A - CY
    func_SBB_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa0	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ANA_B() {

    // Logic for: A <- A & B
    func_ANA_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa1	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ANA_C() {

    // Logic for: A <- A & C
    func_ANA_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa2	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ANA_D() {

    // Logic for: A <- A & D
    func_ANA_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa3	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ANA_E() {

    // Logic for: A <- A & E
    func_ANA_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa4	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ANA_H() {

    // Logic for: A <- A & H
    func_ANA_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa5	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ANA_L() {

    // Logic for: A <- A & L
    func_ANA_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa6	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ANA_M() {

    // Logic for: A <- A & (HL)
    //func_ANA_Registers(registers->H); --MM Removed this because it is wrong
    uint8_t uint8_InitialM = memory->get_M();

    uint8_t uint8_ResultTemp = registers->A.get() & uint8_InitialM;

    registers->A.set(uint8_ResultTemp);

    // According to the i8080 Programming Manual the ANA instructions do not affect the AC Flag (pg 19)
    // This differs from the documentation on other sites.
    // S	Z	P	CY

    flags->set_S_Z_P();
    flags->C.set(false);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(7);

}

////////////////////
// Description: Perform bitwise AND on registers below
// OpCode: 0xa7	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ANA_A() {

    // Logic for: A <- A & A
    func_ANA_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xa8	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_XRA_B() {

    // Logic for: A <- A ^ B
    func_XRA_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xa9	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_XRA_C() {

    // Logic for: A <- A ^ C
    func_XRA_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xaa	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_XRA_D() {

    // Logic for: A <- A ^ D
    func_XRA_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xab	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_XRA_E() {

    // Logic for: A <- A ^ E
    func_XRA_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xac	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_XRA_H() {

    // Logic for: A <- A ^ H
    func_XRA_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xad	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_XRA_L() {

    // Logic for: A <- A ^ L
    func_XRA_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xae	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_XRA_M() {

    // Logic for: A <- A ^ (HL)
    uint8_t uint8_RegisterTemp = memory->get_M();
    uint8_t uint8_ResultTemp = registers->A.get() ^ uint8_RegisterTemp;
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();
	flags->AC.set(false);
	flags->C.set(false);

    clock->incClockCycles(7);

}

////////////////////
// Description: Raises register A to the power of the register below
// OpCode: 0xaf	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_XRA_A() {

    // Logic for: A <- A ^ A
    func_XRA_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb0	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ORA_B() {

    // Logic for: A <- A | B
    func_ORA_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb1	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ORA_C() {

    // Logic for: A <- A | C
    func_ORA_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb2	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ORA_D() {

    // Logic for: A <- A | D
    func_ORA_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb3	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ORA_E() {

    // Logic for: A <- A | E
    func_ORA_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb4	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ORA_H() {

    // Logic for: A <- A | H
    func_ORA_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb5	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_ORA_L() {

    // Logic for: A <- A | L
    func_ORA_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb6	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ORA_M() {

    // Logic for: A <- A | (HL)
    //func_ORA_Registers(registers->M);

    uint8_t uint8_InitialM = memory->get_M();
    uint8_t uint8_ResultTemp = registers->A.get() | uint8_InitialM;

    registers->A.set(uint8_ResultTemp);

    // According to the i8080 Programming Manual the ORA instructions do not affect the AC Flag (pg 19)
    // This differs from the documentation on other sites.
    // S	Z	P	CY
    flags->set_S_Z_P();
    flags->C.set(false);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(7);

}

////////////////////
// Description: Performs OR on the two registers below
// OpCode: 0xb7	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ORA_A() {

    // Logic for: A <- A | A
    func_ORA_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xb8	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: B and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_CMP_B() {

    // Logic for: A - B
    func_CMP_Registers(registers->B);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xb9	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: C and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_CMP_C() {

    // Logic for: A - C
    func_CMP_Registers(registers->C);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xba	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: D and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_CMP_D() {

    // Logic for: A - D
    func_CMP_Registers(registers->D);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbb	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: E and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_CMP_E() {

    // Logic for: A - E
    func_CMP_Registers(registers->E);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbc	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: H and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_CMP_H() {

    // Logic for: A - H
    func_CMP_Registers(registers->H);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbd	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: L and A
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_CMP_L() {

    // Logic for: A - L
    func_CMP_Registers(registers->L);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbe	|| Size: 1 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: M and A
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_CMP_M() {

    // Logic for: A - (HL)
    uint8_t uint8_InitialA = registers->A.get();
    uint8_t uint8_RegisterTemp = memory->get_M();
	uint8_t uint8_RegisterTwosCompliment = (~uint8_RegisterTemp) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - uint8_RegisterTemp;

	// S	Z	AC	P	CY
	flags->set_S(uint8_ResultTemp);
	
	if (uint8_InitialA == uint8_RegisterTemp){
		flags->Z.set(true);
	}
	else {
		flags->Z.set(false);
	}
	
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	
	flags->set_P(uint8_ResultTemp);
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, false);

    clock->incClockCycles(7);

}

////////////////////
// Description: Compares the two registers below
// OpCode: 0xbf	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers: A and A
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_CMP_A() {

    // Logic for: A - A
    func_CMP_Registers(registers->A);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0xc0	|| Size: 1 bit	|| Clock cycles: 11 if taken 5 if not taken
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_RNZ() {

    // Logic for: if NZ, RET
    if (flags->Z.get() == false) {
        func_General_RET();
        clock->incClockCycles(11);
    }

    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xc1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_POP_B() {

    // Logic for: C <- (sp); B <- (sp+1); sp <- sp+2
    uint16_t uint16_InitialSP = registers->SP.get();
    registers->C.set(memory->get(uint16_InitialSP));
    registers->B.set(memory->get(uint16_InitialSP + 0x0001));
    registers->SP.set(uint16_InitialSP + 0x0002);

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xc2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_JNZ_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if NZ, PC<-adr
    if (flags->Z.get() == false) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);
    }

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xc3	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_JMP_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: PC <= adr
    //printf("Address: %4X\n", memory->get_Adr());
    registers->PC.set(memory->get_Adr());
    //printf("NewPC: %4X\n", registers->PC.get());

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xc4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_CNZ_ADR() {

    // Logic for: if NZ, CALL adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialZero = flags->Z.get();

    // Checks to see it the Zero Flag is reset. If reset, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialZero == false) {

        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }

    

}

////////////////////
// Description:
// OpCode: 0xc5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_PUSH_B() {

    // Logic for: (sp-2)<-C; (sp-1)<-B; sp <- sp - 2
    func_PUSH_Registers(registers->B, registers->C);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xc6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_ADI_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A <- A + byte
    uint8_t uint8_InitialA = registers->A.get();
    uint8_t uint8_Data = memory->opCode_Array[1];
    registers->A.set(uint8_InitialA + uint8_Data);

    // Set flags: Z, S, P, CY, AC
    flags->set_S_Z_P();
    flags->set_AC(uint8_InitialA, uint8_Data);
    flags->set_C(uint8_InitialA, uint8_Data, false);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0xc7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_RST_0() {

    // Logic for: CALL $0
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0000);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xc8	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_RZ() {

    // Logic for: if Z, RET
    if (flags->Z.get() == true) {
        func_General_RET();
        clock->incClockCycles(11);
    }

    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xc9	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_RET() {

    // Logic for: PC.lo <- (sp); PC.hi<-(sp+1); SP <- SP+2
    func_General_RET();

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xca	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_JZ_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if Z, PC<-adr
    if (flags->Z.get() == true) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);
    }

    clock->incClockCycles(10);

}

// Opcode 0xcb not implemented

////////////////////
// Description:
// OpCode: 0xcc	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_CZ_ADR() {

    // Logic for: if Z, CALL adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialZero = flags->Z.get();

    // Checks to see it the Zero Flag is set. If set, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialZero == true) {


        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }
}

////////////////////
// Description:
// OpCode: 0xcd	|| Size: 3 bit	|| Clock cycles: 17
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_CALL_ADR() {

    // Logic for: (SP-1)<-PC.hi;(SP-2)<-PC.lo;SP<-SP+2;PC=adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    func_General_CALL();

    clock->incClockCycles(17);

    

}

////////////////////
// Description:
// OpCode: 0xce	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ACI_D8() {

    // Logic for: A <- A + data + CY

    // Inc PC to account for additional size
    registers->inc_PC(1);

    uint8_t uint8_InitialA = registers->A.get();
    uint8_t uint8_OpCodeValue = memory->opCode_Array[1];

	if (flags->C.get() == true){
		uint8_InitialA = uint8_InitialA + 0x01;
	}
	
	uint8_t uint8_ResultTemp = uint8_InitialA + uint8_OpCodeValue;
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();

	flags->set_AC(uint8_InitialA, uint8_OpCodeValue);
    flags->set_C(uint8_InitialA, uint8_OpCodeValue, false);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0xcf	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_RST_1() {

    // Logic for: CALL $8
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0008);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xd0	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_RNC() {

    // Logic for: if NCY, RET
    if (flags->C.get() == false) {
        func_General_RET();
        clock->incClockCycles(11);
    }
    else {
        clock->incClockCycles(5);
    }

}

////////////////////
// Description:
// OpCode: 0xd1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_POP_D() {

    // Logic for: E <- (sp); D <- (sp+1); sp <- sp+2
    uint16_t uint16_InitialSP = registers->SP.get();
    registers->E.set(memory->get(uint16_InitialSP));
    registers->D.set(memory->get(uint16_InitialSP + 0x0001));
    registers->SP.set(uint16_InitialSP + 0x0002);

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xd2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_JNC_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if NCY, PC<-adr
    if (flags->C.get() == false) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);

    }

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xd3	|| Size: 2 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_OUT_D8() {

    // Logic for: OUT_D8
    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Moves the Accumulator into the Output Port specified in opCode_Array[1]
    if ((memory->opCode_Array[1] == 0x02) && (registers->A.get() != 0x00)) {
        printf("Setting Offset\n");
    }
    io->output.set(memory->opCode_Array[1], registers->A.get());
    //system("pause");

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xd4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_CNC_ADR() {

    // Logic for: if NCY, CALL adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialCarry = flags->C.get();

    // Checks to see it the Carry Flag is reset. If reset, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialCarry == false) {

        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }


}

////////////////////
// Description:
// OpCode: 0xd5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_PUSH_D() {

    // Logic for: (sp-2)<-E; (sp-1)<-D; sp <- sp - 2
    func_PUSH_Registers(registers->D, registers->E);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xd6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_SUI_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A <- A - data
    uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(memory->opCode_Array[1])) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - memory->opCode_Array[1];
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	flags->set_S_Z_P();
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);

    // Set flags: Z, S, P, CY, AC
    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0xd7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_RST_2() {

    // Logic for: CALL $10
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0010);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xd8	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_RC() {
    
    // Logic for: if CY, RET
    if (flags->C.get() == true) {
        func_General_RET();
        clock->incClockCycles(11);
    }
    else {
        clock->incClockCycles(5);
    }

}

// Opcode 0xd9 not implemented

////////////////////
// Description:
// OpCode: 0xda	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_JC_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    // Logic for: if CY, PC<-adr
    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if CY, PC<-adr
    if (flags->C.get() == true) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);
    }

    clock->incClockCycles(10);

    

}

////////////////////
// Description:
// OpCode: 0xdb	|| Size: 2 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_IN_D8() {

    // Logic for: IN
    // Inc PC to account for additional size
    registers->inc_PC(1);
    // @TODO [Madison]: fill in logic

    uint8_t uint8_RegisterTemp = io->input.get(memory->opCode_Array[1]);

    registers->A.set(uint8_RegisterTemp);

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xdc	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_CC_ADR() {

    // Logic for: if CY, CALL adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialCarry = flags->C.get();

    // Checks to see it the Carry Flag is set. If set, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialCarry == true) {

        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }

}

// Opcode 0xdd not implemented

////////////////////
// Description:
// OpCode: 0xde	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_SBI_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A <- A - data - CY
    uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~(memory->opCode_Array[1])) + 0x01;
	uint8_t uint8_RegisterTemp = memory->opCode_Array[1];
	
	if (flags->C.get() == true){
		uint8_RegisterTemp = uint8_RegisterTemp + 0x01;
        uint8_RegisterTwosCompliment = (~(uint8_RegisterTemp) + 0x01);

	}
	
	uint8_t uint8_ResultTemp = uint8_InitialA - uint8_RegisterTemp;
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);

    clock->incClockCycles(7);


}

////////////////////
// Description:
// OpCode: 0xdf	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_RST_3() {

    // Logic for: CALL $18
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0018);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xe0	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_RPO() {

    // Logic for: if PO, RET
    if (flags->P.get() == false) {
        func_General_RET();
        clock->incClockCycles(11);
    }

    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xe1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_POP_H() {

    // Logic for: L <- (sp); H <- (sp+1); sp <- sp+2
    uint16_t uint16_InitialSP = registers->SP.get();
    registers->L.set(memory->get(uint16_InitialSP));
    registers->H.set(memory->get(uint16_InitialSP + 0x0001));
    registers->SP.set(uint16_InitialSP + 0x0002);

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xe2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_JPO_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if PO, PC<-adr
    if (flags->P.get() == false) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);
    }

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xe3	|| Size: 1 bit	|| Clock cycles: 18
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_XTHL() {

    // Logic for: L <-> (SP); H <-> (SP+1)
    uint16_t uint16_InitialSP = registers->SP.get();
    uint8_t uint8_InitialH = registers->H.get();
    uint8_t uint8_InitialL = registers->L.get();
    uint8_t uint8_RegisterTempL = memory->get(uint16_InitialSP);
    uint8_t uint8_RegisterTempH = memory->get(uint16_InitialSP + 0x0001);

    memory->set(uint16_InitialSP, uint8_InitialL);
    memory->set((uint16_InitialSP + 0x0001), uint8_InitialH);

    registers->H.set(uint8_RegisterTempH);
    registers->L.set(uint8_RegisterTempL);

    //registers->SP.set(uint16_InitialSP + 0x0002);

    clock->incClockCycles(18);

}

////////////////////
// Description:
// OpCode: 0xe4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_CPO_ADR() {

    // Logic for: if PO, CALL adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialParity = flags->P.get();

    // Checks to see it the Parity Flag is reset. If reset, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialParity == false) {

        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }

}

////////////////////
// Description:
// OpCode: 0xe5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_PUSH_H() {

    // Logic for: (sp-2)<-L; (sp-1)<-H; sp <- sp - 2
    func_PUSH_Registers(registers->H, registers->L);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xe6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_ANI_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A <- A & data
    uint8_t uint8_ResultTemp = registers->A.get() & memory->opCode_Array[1];
	
	registers->A.set(uint8_ResultTemp);
	
	// According to the i8080 Programming Manual the ANA instructions do not affect the AC Flag (pg 19)
	// This differs from the documentation on other sites.
	// S	Z	P	CY
	
	flags->set_S_Z_P();
	flags->C.set(false);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0xe7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_RST_4() {

    // Logic for: CALL $20
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0020);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xe8	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_RPE() {

    // Logic for: if PE, RET
    if (flags->P.get() == true) {
        func_General_RET();
        clock->incClockCycles(11);
    }

    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xe9	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_PCHL() {

    // Logic for: PC.hi <- H; PC.lo <- L

    uint8_t uint8_InitialH = registers->H.get();
    uint8_t uint8_InitialL = registers->L.get();
    uint16_t uint16_RegisterTemp = 0x0000;

    uint16_RegisterTemp = uint16_RegisterTemp | uint8_InitialH;
    uint16_RegisterTemp = uint16_RegisterTemp << 8;
    uint16_RegisterTemp = uint16_RegisterTemp | uint8_InitialL;

    registers->PC.set(uint16_RegisterTemp);

    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xea	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_JPE_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if PE, PC<-adr
    if (flags->P.get() == true) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);
    }

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xeb	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_XCHG() {

    // Logic for: H <-> D; L <-> E

    uint8_t uint8_InitialH = registers->H.get();
    uint8_t uint8_InitialL = registers->L.get();
    uint8_t uint8_InitialD = registers->D.get();
    uint8_t uint8_InitialE = registers->E.get();

    registers->H.set(uint8_InitialD);
    registers->L.set(uint8_InitialE);
    registers->D.set(uint8_InitialH);
    registers->E.set(uint8_InitialL);

    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xec	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_CPE_ADR() {

    // Logic for: if PE, CALL adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialParity = flags->P.get();

    // Checks to see it the Parity Flag is set. If set, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialParity == true) {

        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }

}

// Opcode 0xed not implemented

////////////////////
// Description:
// OpCode: 0xee	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_XRI_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A <- A ^ data
    uint8_t uint8_ResultTemp = registers->A.get() ^ memory->opCode_Array[1];
	
	registers->A.set(uint8_ResultTemp);
	
	// S	Z	AC	P	CY
	
	flags->set_S_Z_P();
	flags->AC.set(0);
	flags->C.set(0);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0xef	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_RST_5() {

    // Logic for: CALL $28
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0028);

    clock->incClockCycles(11);

}

////////////////////
// Description:
// OpCode: 0xf0	|| Size: 1 bit	|| Clock cycles: 44505
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_RP() {

    // Logic for: if P, RET
    if (flags->S.get() == false) {
        func_General_RET();
        clock->incClockCycles(11);
    }

    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xf1	|| Size: 1 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_POP_PSW()
{
    // Logic for: flags <- (sp); A <- (sp+1); sp <- sp+2
    uint16_t uint16_InitialSP = registers->SP.get();
    uint8_t uint8_TempPSW = memory->get(uint16_InitialSP);

    if ((uint8_TempPSW & 0x80) != 0x00) {
        flags->S.set(true);
    }

    if ((uint8_TempPSW & 0x40) != 0x00) {
        flags->Z.set(true);
    }

    if ((uint8_TempPSW & 0x10) != 0x00) {
        flags->AC.set(true);
    }

    if ((uint8_TempPSW & 0x04) != 0x00) {
        flags->P.set(true);
    }

    if ((uint8_TempPSW & 0x01) != 0x00) {
        flags->C.set(true);
    }

    registers->A.set(memory->get(uint16_InitialSP + 0x0001));
    registers->SP.set(uint16_InitialSP + 0x0002);

    clock->incClockCycles(10);
}

////////////////////
// Description:
// OpCode: 0xf2	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_JP_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if NS, PC<-adr
    if (flags->S.get() == false) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);
    }

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xf3	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_DI() {

    // Logic for: special

    flags->INTE.set(false);

    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0xf4	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_CP_ADR() {

    // Logic for: if P, PC <- adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialSign = flags->S.get();

    // Checks to see it the Sign Flag is reset. If reset, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialSign == false) {

        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }

}

////////////////////
// Description:
// OpCode: 0xf5	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_PUSH_PSW() {

    // Logic for: (sp-2)<-flags; (sp-1)<-A; sp <- sp - 2

    // get the value of PSW
    uint8_t uint8_RegPSW = 0x00;
	
	if (flags->S.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;

	}
	
	uint8_RegPSW = uint8_RegPSW << 1;
	
	if (flags->Z.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
		
	}
	
	uint8_RegPSW = uint8_RegPSW << 2;
	
	if (flags->AC.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
	}
	
	uint8_RegPSW = uint8_RegPSW << 2;
	
	if (flags->P.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
	}
	
	uint8_RegPSW = uint8_RegPSW << 1;
	uint8_RegPSW = uint8_RegPSW | 0x01;
	uint8_RegPSW = uint8_RegPSW << 1;
	
	if (flags->C.get() == true) {
		uint8_RegPSW = uint8_RegPSW | 0x01;
	}

    // perform the push
	uint16_t uint16_TempSP = registers->SP.get();
	
	// Function to push data to memory
	memory->set(uint16_TempSP - 0x0001, registers->A.get());
	
	// Function to push data to memory
	memory->set(uint16_TempSP - 0x0002, uint8_RegPSW);
	
	registers->SP.set(uint16_TempSP - 0x0002);

    clock->incClockCycles(11);

}

////////////////////
// Description: OR Accumulator with Immediate Data
// OpCode: 0xf6	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Madison*
////////////////////
void i8080::i8080_OpCodes::func_ORI_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A <- A | data
    uint8_t uint8_ResultTemp = registers->A.get() | memory->opCode_Array[1];

    registers->A.set(uint8_ResultTemp);

    // According to the i8080 Programming Manual the ORI instructions do not affect the AC Flag (pg 19)
    // This differs from the documentation on other sites.
    // Set flags: Z, S, P, CY
    flags->set_S_Z_P();
    flags->C.set(0);


    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0xf7	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_RST_6() {

    // Logic for: CALL $30
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0030);

    clock->incClockCycles(11);

}

////////////////////
// Description: Return if Minus
// OpCode: 0xf8	|| Size: 1 bit	|| Clock cycles: 11/5
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_RM() {

    // Logic for: if M, RET

    if (flags->S.get() == true) {
        func_General_RET();
        clock->incClockCycles(11);
    }
    else {
        clock->incClockCycles(5);
    }

}

////////////////////
// Description: Load SP from H and L
// OpCode: 0xf9	|| Size: 1 bit	|| Clock cycles: 5
// Modifed Flags: No Flags Effected
// Modifed Registers: SP
// Written By: Madison*
////////////////////
void i8080::i8080_OpCodes::func_SPHL() {

    // Logic for: SP=HL
    //
    uint16_t uint16_ResultTemp = 0x0000;

    uint16_ResultTemp = uint16_ResultTemp + registers->H.get();

    uint16_ResultTemp = uint16_ResultTemp << 0x08;

    uint16_ResultTemp = uint16_ResultTemp + registers->L.get();

    registers->SP.set(uint16_ResultTemp);


    clock->incClockCycles(5);

}

////////////////////
// Description:
// OpCode: 0xfa	|| Size: 3 bit	|| Clock cycles: 10
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Ruben
////////////////////
void i8080::i8080_OpCodes::func_JM_ADR() {

    // Inc PC to account for additional size
    registers->inc_PC(2);

    uint8_t uint8_PCAddrLow = memory->opCode_Array[1];
    uint8_t uint8_PCAddrHigh = memory->opCode_Array[2];
    uint16_t uint16_AddressTemp = 0x0000;

    // Logic for: if S, PC<-adr
    if (flags->S.get() == true) {

        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrHigh;
        uint16_AddressTemp = uint16_AddressTemp << 8;
        uint16_AddressTemp = uint16_AddressTemp | uint8_PCAddrLow;

        registers->PC.set(uint16_AddressTemp);
    }

    clock->incClockCycles(10);

}

////////////////////
// Description:
// OpCode: 0xfb	|| Size: 1 bit	|| Clock cycles: 4
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_EI() {

    // Logic for: special
    // @TODO [Michael]: fill in logic

    flags->INTE.set(true);

    clock->incClockCycles(4);

}

////////////////////
// Description:
// OpCode: 0xfc	|| Size: 3 bit	|| Clock cycles: 17/11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_CM_ADR() {

    // Logic for: if M, CALL adr
    // Inc PC to account for additional size
    registers->inc_PC(2);

    bool bool_InitialSign = flags->S.get();

    // Checks to see it the Sign Flag is set. If set, the PC is stored at the Stack Pointer - 1
    // and Stack Pointer - 2 addresses in memory. The two data values after the Opcode are
    // used to set the Program Counter.
    if (bool_InitialSign == true) {

        func_General_CALL();

        clock->incClockCycles(17);
    }
    else {
        clock->incClockCycles(11);
    }

}

// Opcode 0xfd not implemented

////////////////////
// Description:
// OpCode: 0xfe	|| Size: 2 bit	|| Clock cycles: 7
// Modifed Flags: Z, S, P, CY, AC
// Modifed Registers:
// Written By: Michael
////////////////////
void i8080::i8080_OpCodes::func_CPI_D8() {

    // Inc PC to account for additional size
    registers->inc_PC(1);

    // Logic for: A - data
    uint8_t uint8_InitialA = registers->A.get();
	uint8_t uint8_RegisterTwosCompliment = (~memory->opCode_Array[1]) + 0x01;
	uint8_t uint8_ResultTemp = uint8_InitialA - memory->opCode_Array[1];
	
	// S	Z	AC	P	CY
	flags->set_S(uint8_ResultTemp);
	
	if (uint8_InitialA == memory->opCode_Array[1]) {
		flags->Z.set(true);
	}
	else {
		flags->Z.set(false);
	}
	
	// When checking the Auxiliary Carry Bit Source2 needs to be a 2's compliment
	flags->set_AC(uint8_InitialA, uint8_RegisterTwosCompliment);
	
	flags->set_P(uint8_ResultTemp);
	
	// When checking the Carry Bit Source2 needs to be a 2's compliment
	// the result has to be negated also before setting/resetting the flag.
	flags->set_C(uint8_InitialA, uint8_RegisterTwosCompliment, true);

    clock->incClockCycles(7);

}

////////////////////
// Description:
// OpCode: 0xff	|| Size: 1 bit	|| Clock cycles: 11
// Modifed Flags: No Flags Effected
// Modifed Registers:
// Written By: Madison
////////////////////
void i8080::i8080_OpCodes::func_RST_7() {

    // Logic for: CALL $38
    uint16_t uint16_InitialPC = registers->PC.get();
	uint16_t uint16_InitialSP = registers->SP.get();

    // Break the Program Counter into two bytes so that it can be stored in memory.
    uint8_t uint8_PCAddrLow = 0x00;
    uint8_t uint8_PCAddrHigh = 0x00;
    uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
    uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8); 

	// Push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
	memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
    memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);
	
	// The Stack Pointer is updated
	registers->SP.set(uint16_InitialSP - 0x0002);

	registers->PC.set(0x0038);

    clock->incClockCycles(11);

}

// END SPECIFIC FUNCTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-