/**
 * [FILE] i8080_OpCodes.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] File containing object which executes instructions on the i8080
 * [VERSION] 0.1
 * [DATE] 2021-05-19 
*/

#pragma once
#include <cstdint>
#include "i8080_Registers.h"
#include "i8080_Component.h"

/**
 * [DESCRIPTION] Class which represents the instruction set of an i8080
 * 
*/
class i8080_OpCodes : public i8080_Component {
private:
    // GENERAL FUNCTION PROTOTYPES
    void func_LXI_Registers(i8080_Registers::Register_8Bit &reg_Source1, i8080_Registers::Register_8Bit &reg_Source2);
    void func_INR_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_DCR_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_MOV_Registers(i8080_Registers::Register_8Bit &reg_Destination, i8080_Registers::Register_8Bit &reg_Source);
    void func_MVI_Registers(i8080_Registers::Register_8Bit &reg_Destination, uint8_t uint8_Source);
    void func_ADD_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_ADC_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_SUB_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_SBB_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_AND_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_XOR_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_OR_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_CMP_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_PUSH_Registers(i8080_Registers::Register_8Bit &reg_Source1, i8080_Registers::Register_8Bit &reg_Source2);
    void func_INX_Registers(i8080_Registers::Register_8Bit &reg_Source1, i8080_Registers::Register_8Bit &reg_Source2);
    void func_ANA_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_XRA_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_ORA_Registers(i8080_Registers::Register_8Bit &reg_Source);
    void func_General_RET();
    void func_General_CALL();

    // OP CODE PROTOTYPES
    void  func_NOP();
    void  func_LXI_B_D16();
    void  func_STAX_B();
    void  func_INX_B();
    void  func_INR_B();
    void  func_DCR_B();
    void  func_MVI_B_D8();
    void  func_RLC();
    // *NOP 0x08 NOT IMPLEMENTED
    void  func_DAD_B();
    void  func_LDAX_B();
    void  func_DCX_B();
    void  func_INR_C();
    void  func_DCR_C();
    void  func_MVI_C_D8();
    void  func_RRC();
    // *NOP 0x10 NOT IMPLEMENTED
    void  func_LXI_D_D16();
    void  func_STAX_D();
    void  func_INX_D();
    void  func_INR_D();
    void  func_DCR_D();
    void  func_MVI_D_D8();
    void  func_RAL();
    // *NOP 0x18 NOT IMPLEMENTED
    void  func_DAD_D();
    void  func_LDAX_D();
    void  func_DCX_D();
    void  func_INR_E();
    void  func_DCR_E();
    void  func_MVI_E_D8();
    void  func_RAR();
    // *NOP 0x20 NOT IMPLEMENTED
    void  func_LXI_H_D16();
    void  func_SHLD_ADR();
    void  func_INX_H();
    void  func_INR_H();
    void  func_DCR_H();
    void  func_MVI_H_D8();
    void  func_DAA();
    // *NOP 0x28 NOT IMPLEMENTED
    void  func_DAD_H();
    void  func_LHLD_ADR();
    void  func_DCX_H();
    void  func_INR_L();
    void  func_DCR_L();
    void  func_MVI_L_D8();
    void  func_CMA();
    void  func_SIM();
    void  func_LXI_SP_D16();
    void  func_STA_ADR();
    void  func_INX_SP();
    void  func_INR_M();
    void  func_DCR_M();
    void  func_MVI_M_D8();
    void  func_STC();
    // *NOP 0x38 NOT IMPLEMENTED
    void  func_DAD_SP();
    void  func_LDA_ADR();
    void  func_DCX_SP();
    void  func_INR_A();
    void  func_DCR_A();
    void  func_MVI_A_D8();
    void  func_CMC();
    void  func_MOV_B_B();
    void  func_MOV_B_C();
    void  func_MOV_B_D();
    void  func_MOV_B_E();
    void  func_MOV_B_H();
    void  func_MOV_B_L();
    void  func_MOV_B_M();
    void  func_MOV_B_A();
    void  func_MOV_C_B();
    void  func_MOV_C_C();
    void  func_MOV_C_D();
    void  func_MOV_C_E();
    void  func_MOV_C_H();
    void  func_MOV_C_L();
    void  func_MOV_C_M();
    void  func_MOV_C_A();
    void  func_MOV_D_B();
    void  func_MOV_D_C();
    void  func_MOV_D_D();
    void  func_MOV_D_E();
    void  func_MOV_D_H();
    void  func_MOV_D_L();
    void  func_MOV_D_M();
    void  func_MOV_D_A();
    void  func_MOV_E_B();
    void  func_MOV_E_C();
    void  func_MOV_E_D();
    void  func_MOV_E_E();
    void  func_MOV_E_H();
    void  func_MOV_E_L();
    void  func_MOV_E_M();
    void  func_MOV_E_A();
    void  func_MOV_H_B();
    void  func_MOV_H_C();
    void  func_MOV_H_D();
    void  func_MOV_H_E();
    void  func_MOV_H_H();
    void  func_MOV_H_L();
    void  func_MOV_H_M();
    void  func_MOV_H_A();
    void  func_MOV_L_B();
    void  func_MOV_L_C();
    void  func_MOV_L_D();
    void  func_MOV_L_E();
    void  func_MOV_L_H();
    void  func_MOV_L_L();
    void  func_MOV_L_M();
    void  func_MOV_L_A();
    void  func_MOV_M_B();
    void  func_MOV_M_C();
    void  func_MOV_M_D();
    void  func_MOV_M_E();
    void  func_MOV_M_H();
    void  func_MOV_M_L();
    void  func_HLT();
    void  func_MOV_M_A();
    void  func_MOV_A_B();
    void  func_MOV_A_C();
    void  func_MOV_A_D();
    void  func_MOV_A_E();
    void  func_MOV_A_H();
    void  func_MOV_A_L();
    void  func_MOV_A_M();
    void  func_MOV_A_A();
    void  func_ADD_B();
    void  func_ADD_C();
    void  func_ADD_D();
    void  func_ADD_E();
    void  func_ADD_H();
    void  func_ADD_L();
    void  func_ADD_M();
    void  func_ADD_A();
    void  func_ADC_B();
    void  func_ADC_C();
    void  func_ADC_D();
    void  func_ADC_E();
    void  func_ADC_H();
    void  func_ADC_L();
    void  func_ADC_M();
    void  func_ADC_A();
    void  func_SUB_B();
    void  func_SUB_C();
    void  func_SUB_D();
    void  func_SUB_E();
    void  func_SUB_H();
    void  func_SUB_L();
    void  func_SUB_M();
    void  func_SUB_A();
    void  func_SBB_B();
    void  func_SBB_C();
    void  func_SBB_D();
    void  func_SBB_E();
    void  func_SBB_H();
    void  func_SBB_L();
    void  func_SBB_M();
    void  func_SBB_A();
    void  func_ANA_B();
    void  func_ANA_C();
    void  func_ANA_D();
    void  func_ANA_E();
    void  func_ANA_H();
    void  func_ANA_L();
    void  func_ANA_M();
    void  func_ANA_A();
    void  func_XRA_B();
    void  func_XRA_C();
    void  func_XRA_D();
    void  func_XRA_E();
    void  func_XRA_H();
    void  func_XRA_L();
    void  func_XRA_M();
    void  func_XRA_A();
    void  func_ORA_B();
    void  func_ORA_C();
    void  func_ORA_D();
    void  func_ORA_E();
    void  func_ORA_H();
    void  func_ORA_L();
    void  func_ORA_M();
    void  func_ORA_A();
    void  func_CMP_B();
    void  func_CMP_C();
    void  func_CMP_D();
    void  func_CMP_E();
    void  func_CMP_H();
    void  func_CMP_L();
    void  func_CMP_M();
    void  func_CMP_A();
    void  func_RNZ();
    void  func_POP_B();
    void  func_JNZ_ADR();
    void  func_JMP_ADR();
    void  func_CNZ_ADR();
    void  func_PUSH_B();
    void  func_ADI_D8();
    void  func_RST_0();
    void  func_RZ();
    void  func_RET();
    void  func_JZ_ADR();
    // *JMP a16 0xcb NOT IMPLEMENTED
    void  func_CZ_ADR();
    void  func_CALL_ADR();
    void  func_ACI_D8();
    void  func_RST_1();
    void  func_RNC();
    void  func_POP_D();
    void  func_JNC_ADR();
    void  func_OUT_D8();
    void  func_CNC_ADR();
    void  func_PUSH_D();
    void  func_SUI_D8();
    void  func_RST_2();
    void  func_RC();
    // *RET 0xd9 NOT IMPLEMENTED
    void  func_JC_ADR();
    void  func_IN_D8();
    void  func_CC_ADR();
    // *CALL a16 0xdd NOT IMPLEMENTED
    void  func_SBI_D8();
    void  func_RST_3();
    void  func_RPO();
    void  func_POP_H();
    void  func_JPO_ADR();
    void  func_XTHL();
    void  func_CPO_ADR();
    void  func_PUSH_H();
    void  func_ANI_D8();
    void  func_RST_4();
    void  func_RPE();
    void  func_PCHL();
    void  func_JPE_ADR();
    void  func_XCHG();
    void  func_CPE_ADR();
    // *CALL a16 0xed NOT IMPLEMENTED
    void  func_XRI_D8();
    void  func_RST_5();
    void  func_RP();
    void  func_POP_PSW();
    void  func_JP_ADR();
    void  func_DI();
    void  func_CP_ADR();
    void  func_PUSH_PSW();
    void  func_ORI_D8();
    void  func_RST_6();
    void  func_RM();
    void  func_SPHL();
    void  func_JM_ADR();
    void  func_EI();
    void  func_CM_ADR();
    // *CALL a16 0xfd NOT IMPLEMENTED
    void  func_CPI_D8();
    void  func_RST_7();
public:
    // MAIN CALLER
    void runOpCode(unsigned char passed_code);
};