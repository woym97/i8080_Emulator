/**
 * [FILE] i8080_Flags.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains the implementation of the i8080 flags
 * 		RESOURCES:
 * 			https://www.cprogramming.com/tutorial/bitwise_operators.html
 * [DATE] 2021-05-21
 * 
*/

#include "i8080.h"

/**
 * [DESCRIPTION] Set the flag to the passed value
 * 
 * [PARAM] new_val 
*/
void i8080::i8080_Flags::Flag::set(bool new_val)
{
	val = new_val;
}

/**
 * [DESCRIPTION] Get the value that the flag is currently set to 
 * 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080::i8080_Flags::Flag::get()
{
	return val;
}

/**
 * [DESCRIPTION] Construct a new i8080 Flags::i8080 Flags object
 * 
*/
i8080::i8080_Flags::i8080_Flags(i8080_Registers* parent_registers)
{
	/* Set the starting value of the flags */
	Z.set(true);
    S.set(false);
    P.set(true);
    C.set(true);
    AC.set(false);
    INTE.set(false);

	/* Point to the parents registers */
	registers = parent_registers;
}

/**
 * [DESCRIPTION] Sets the sign flag based on the Accumulator
*/
void i8080::i8080_Flags::set_S()
{	
	S.set((0x80 == (registers->A.get() & 0x80)));
}

/**
 * [DESCRIPTION] Set sign flag based on the passed value
 * 
 * [PARAM] src 
*/
void i8080::i8080_Flags::set_S(uint8_t src)
{
	S.set(0x80 == (src & 0x80));
}

/**
 * [DESCRIPTION] Checks the accumulator value for a zero value
 * 
 * [RETURN] true 
 * [RETURN] false 
*/
void i8080::i8080_Flags::set_Z()
{
	Z.set(registers->A.get() == 0x00 ? 1 : 0);
}

/**
 * [DESCRIPTION] Set the sero flag off the passed value
 * 
 * [PARAM] src 
*/
void i8080::i8080_Flags::set_Z(uint8_t src)
{
	Z.set(src == 0x00 ? 1 : 0);
}

/**
 * [DESCRIPTION] Set the AC flag if there was a carry
 * 
 * [PARAM] src1 
 * [PARAM] src2 
*/
void i8080::i8080_Flags::set_AC(uint8_t src1, uint8_t src2)
{
	AC.set(check_AC(src1, src2));
}

/**
 * [DESCRIPTION] Check Auxiliary Carry Function to return if 
 * 				 there was a carry from the bit position 3 
 * 				 addition/subtraction/etc
 * 
 * [PARAM] src1
 * [PARAM] src2 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080::i8080_Flags::check_AC(uint8_t src1, uint8_t src2)
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
		
		uint8_Source1Temp = ((src1 >> intBitPosition) & 0x01);
		uint8_Source2Temp = ((src2 >> intBitPosition) & 0x01);
		
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
void i8080::i8080_Flags::set_P()
{
	bool boolResult = false;
	
	int intBitPosition = 0;
	int intBitCount = 0;
	
	uint8_t uint8_InitialA = registers->A.get();
	
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
	
	P.set(boolResult);
}

/**
 * [DESCRIPTION] Check and return the parity of a register value
 * 
 * [PARAM] reg 
 * [RETURN] true 
 * [RETURN] false 
*/
void i8080::i8080_Flags::set_P(uint8_t src)
{
	bool boolResult = false;
	
	int intBitPosition = 0;
	int intBitCount = 0;
	
	uint8_t uint8_RegisterTemp = 0x00;
	
	for (intBitPosition = 0; intBitPosition < 8 ; intBitPosition++){
		
		uint8_RegisterTemp = 0x00;
		
		uint8_RegisterTemp = ((src >> intBitPosition) & 0x01);
		
		if (uint8_RegisterTemp == 0x01){
			intBitCount = intBitCount + 1;
		}
		 
		
	}

	if (intBitCount % 2 == 0){
		boolResult = true;
	}
	
	P.set(boolResult);
}

/**
 * [DESCRIPTION] Checks if there was a carry from the bit position 
 * 				 7 addition/subtraction/etc.
 * 
 * [PARAM] src1 
 * [PARAM] src2 
 * [PARAM] negate 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080::i8080_Flags::check_C(uint8_t src1, uint8_t src2)
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
		
		uint8_Source1Temp = ((src1 >> intBitPosition) & 0x01);
		uint8_Source2Temp = ((src2 >> intBitPosition) & 0x01);
		
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
 * [DESCRIPTION] Carry Function to set the carry flag if there was a carry 
 * 				 from the bit position 7 addition/subtraction/etc.
 * 
 * [PARAM] src1 
 * [PARAM] src2 
 * [PARAM] negate - if true then set to the negation of the result
*/
void i8080::i8080_Flags::set_C(uint8_t src1, uint8_t src2, bool negate)
{
	bool boolResult = check_C(src1, src2);
	
	if (negate) {
		C.set(!boolResult);
	} else {
		C.set(boolResult);
	}

}

/**
 * [DESCRIPTION] Carry Function to set the carry flag if there was a carry 
 * 				 from the bit position 7 addition/subtraction/etc.
 * 
 * [PARAM] src1 
 * [PARAM] src2 
 * [PARAM] negate - if true then set to the negation of the result
*/
void i8080::i8080_Flags::set_C(uint16_t src1, uint16_t src2, bool negate)
{
	bool boolResult = check_C(src1, src2);
	
	if (negate) {
		C.set(!boolResult);
	} else {
		C.set(boolResult);
	}

}

/**
 * [DESCRIPTION] Check Carry Function for 16 bit values to set the carry flag
 * 				 if there was a carry from the bit position 7 
 * 				 addition/subtraction/etc.
 * 
 * [PARAM] reg1 
 * [PARAM] reg2 
 * [RETURN] true 
 * [RETURN] false 
*/
bool i8080::i8080_Flags::check_C(uint16_t src1, uint16_t src2)
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

		uint16_Source1Temp = ((src1 >> intBitPosition) & 0x01);
		uint16_Source2Temp = ((src2 >> intBitPosition) & 0x01);

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

/**
 * [DESCRIPTION] Set the S & Z & P flags
 * 
*/
void i8080::i8080_Flags::set_S_Z_P() 
{
	set_P();
	set_S();
	set_Z();
}