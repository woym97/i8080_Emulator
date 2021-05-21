/**
 * [FILE] i8080_Flags.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains the implementation of the i8080 flags
 * 		RESOURCES:
 * 			https://www.cprogramming.com/tutorial/bitwise_operators.html
 * [DATE] 2021-05-21
 * 
*/

#pragma once
#include "i8080_Flags.h"

/**
 * [DESCRIPTION] Set the flag to the passed value
 * 
 * [PARAM] new_val 
*/
void i8080_Flags::Flag::set(bool new_val)
{
	val = new_val;
}

/**
 * [DESCRIPTION] Get the value that the flag is currently set to 
 * 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::Flag::get()
{
	return val;
}

/**
 * [DESCRIPTION] Construct a new i8080 Flags::i8080 Flags object
 * 
*/
i8080_Flags::i8080_Flags()
{
	/* Set the starting value of the flags */
	Z.set(true);
    S.set(false);
    P.set(true);
    C.set(true);
    AC.set(false);
    INTE.set(false);
}

/**
 * [DESCRIPTION] Returns the sign of the accumulator value
 * 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_S()
{
	return (0x80 == (p_cpu->registers.A.get() & 0x80));
}

/**
 * [DESCRIPTION] Checks and returns the sign of a register
 * 
 * [PARAM] reg 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_S(i8080_Registers::Register_8Bit reg)
{
	return (0x80 == (reg.get() & 0x80));
}

/**
 * [DESCRIPTION] Checks the accumulator value for a zero value
 * 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_Z()
{
	return p_cpu->registers.A.get() == 0x00 ? 1 : 0;
}

/**
 * [DESCRIPTION] Checks and returns if a register is 0
 * 
 * [PARAM] reg 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_Z(i8080_Registers::Register_8Bit reg)
{
	return reg.get() == 0x00 ? 1 : 0;
}

/**
 * [DESCRIPTION] Check Auxiliary Carry Function to return if 
 * 				 there was a carry from the bit position 3 
 * 				 addition/subtraction/etc
 * 
 * [PARAM] reg1 
 * [PARAM] reg2 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_AC(i8080_Registers::Register_8Bit reg1, 
					i8080_Registers::Register_8Bit reg2)
{
	bool boolResult = false;
	
	uint8_t uint8_Carry = 0x00;
	
	int intBitPosition;
	uint8_t uint8_Source1Temp = 0x00;
	uint8_t uint8_Source2Temp = 0x00;
	uint8_t uint8_ResultTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 4 ; intBitPosition++){
		
		uint8_Source1Temp = 0x00;
		uint8_Source2Temp = 0x00;
		
		uint8_Carry = uint8_Carry >> 1;
		
		uint8_Source1Temp = ((reg1.get() >> intBitPosition) & 0x01);
		uint8_Source2Temp = ((reg2.get() >> intBitPosition) & 0x01);
		
		uint8_ResultTemp = uint8_Source1Temp + uint8_Source2Temp + uint8_Carry;
		
		if ((uint8_ResultTemp & 0x02) != 0x00){
			boolResult = true;
		}
		else {
			boolResult = 0;
		};
		
		uint8_Carry = uint8_ResultTemp;
		 
		
	};
	
	return boolResult;
}

/**
 * [DESCRIPTION] Check and return the parity of the accumulator value
 * 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_P()
{
		bool boolResult = false;
	
	int intBitPosition = 0;
	int intBitCount = 0;
	
	uint8_t uint8_InitialA = p_cpu->registers.A.get();
	
	uint8_t uint8_RegisterTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_RegisterTemp = 0x00;
		
		uint8_RegisterTemp = ((uint8_InitialA >> intBitPosition) & 0x01);
		
		if (uint8_RegisterTemp == 0x01){
			intBitCount = intBitCount + 1;
		}
		 	
	}
	
	if (intBitCount % 2 == 0){
		boolResult = true;
	}
	
	return boolResult;
}

/**
 * [DESCRIPTION] Check and return the parity of a register value
 * 
 * [PARAM] reg 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_P(i8080_Registers::Register_8Bit reg)
{
	bool boolResult = false;
	
	int intBitPosition = 0;
	int intBitCount = 0;
	
	uint8_t uint8_RegisterTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_RegisterTemp = 0x00;
		
		uint8_RegisterTemp = ((reg.get() >> intBitPosition) & 0x01);
		
		if (uint8_RegisterTemp == 0x01){
			intBitCount = intBitCount + 1;
		}
		 
		
	}

	if (intBitCount % 2 == 0){
		boolResult = true;
	}
	
	return boolResult;
}

/**
 * [DESCRIPTION] Check Carry Function to return if there was a carry 
 * 				 from the bit position 7 addition/subtraction/etc.
 * 
 * [PARAM] reg1 
 * [PARAM] reg2 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_C(i8080_Registers::Register_8Bit reg1, 
					i8080_Registers::Register_8Bit reg2)
{
	bool boolResult = 0;
	
	uint8_t uint8_Carry = 0x00;
	
	int intBitPosition;
	uint8_t uint8_Source1Temp = 0x00;
	uint8_t uint8_Source2Temp = 0x00;
	uint8_t uint8_ResultTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_Source1Temp = 0x00;
		uint8_Source2Temp = 0x00;
		
		uint8_Carry = uint8_Carry >> 1;
		
		uint8_Source1Temp = ((reg1.get() >> intBitPosition) & 0x01);
		uint8_Source2Temp = ((reg2.get() >> intBitPosition) & 0x01);
		
		uint8_ResultTemp = uint8_Source1Temp + uint8_Source2Temp + uint8_Carry;
		
		if ((uint8_ResultTemp & 0x02) != 0x00){
			boolResult = 1;
		}
		else {
			boolResult = 0;
		};
		
		uint8_Carry = uint8_ResultTemp;
		 
		
	};
	
	return boolResult;
}

/**
 * [DESCRIPTION] Check Carry Function for 16 bit values to return 
 * 				 if there was a carry from the bit position 7 
 * 				 addition/subtraction/etc.
 * 
 * [PARAM] reg1 
 * [PARAM] reg2 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080_Flags::check_C(i8080_Registers::Register_16Bit reg1, i8080_Registers::Register_16Bit reg2)
{
	bool boolResult = 0;

	uint16_t uint16_Carry = 0x0000;

	int intBitPosition;
	uint16_t uint16_Source1Temp = 0x0000;
	uint16_t uint16_Source2Temp = 0x0000;
	uint16_t uint16_ResultTemp = 0x0000;

	for (intBitPosition = 0; intBitPosition < 16; intBitPosition++) {

		uint16_Source1Temp = 0x0000;
		uint16_Source2Temp = 0x0000;

		uint16_Carry = uint16_Carry >> 1;

		uint16_Source1Temp = ((reg1.get() >> intBitPosition) & 0x01);
		uint16_Source2Temp = ((reg1.get() >> intBitPosition) & 0x01);

		uint16_ResultTemp = uint16_Source1Temp + uint16_Source2Temp + uint16_Carry;

		if ((uint16_ResultTemp & 0x02) != 0x00) {
			boolResult = 1;
		}
		else {
			boolResult = 0;
		};

		uint16_Carry = uint16_ResultTemp;


	};

	return boolResult;
}
