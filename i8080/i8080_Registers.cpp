/**
 * [FILE] i8080_Registers.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains the implementation of the i8080 registers
 * [DATE] 2021-05-21
*/

#include "i8080.h"

/**
 * [DESCRIPTION] Get the value of two combined 8 bit registers
 * 
 * [PARAM] reg1 
 * [PARAM] reg2 
 * [RETURN] uint16_t 
*/
uint16_t i8080::i8080_Registers::getCombinedReg(Register_8Bit reg1, Register_8Bit reg2)
{
	return (reg1.get() << 8) | reg2.get();
}

/**
 * [DESCRIPTION] Returns the value fo the register BL combination
 * 
 * [RETURN] uint16_t 
*/
uint16_t i8080::i8080_Registers::get_BC()
{
	return getCombinedReg(B,C);
}

/**
 * [DESCRIPTION] Returns the value fo the register HL combination
 * 
 * [RETURN] uint16_t 
*/
uint16_t i8080::i8080_Registers::get_HL()
{
	return getCombinedReg(H,L);
}

/**
 * [DESCRIPTION] Returns the value fo the register DE combination
 * 
 * [RETURN] uint16_t 
*/
uint16_t i8080::i8080_Registers::get_DE()
{
	return getCombinedReg(D,E);
}

/**
 * [DESCRIPTION] Get the value of two combined 8 bit registers
 * 
 * [PARAM] reg1 
 * [PARAM] reg2 
 * [RETURN] uint16_t 
*/
void i8080::i8080_Registers::setCombinedReg(Register_8Bit reg1, Register_8Bit reg2, uint16_t val)
{
	reg1.set(val & 0xff); 
    reg2.set((val >> 8) & 0xff);
}

/**
 * [DESCRIPTION] Returns the value fo the register BC combination
 * 
 * [RETURN] uint16_t 
*/
void i8080::i8080_Registers::set_BC(uint16_t val)
{
	setCombinedReg(B, C, val);
}

/**
 * [DESCRIPTION] Returns the value fo the register HL combination
 * 
 * [RETURN] uint16_t 
*/
void i8080::i8080_Registers::set_HL(uint16_t val)
{
	setCombinedReg(H, L, val);
}

/**
 * [DESCRIPTION] Sets the value fo the register BL combination
 * 
 * [RETURN] uint16_t 
*/
void i8080::i8080_Registers::set_DE(uint16_t val)
{
	setCombinedReg(D, E, val);
}

/**
 * [DESCRIPTION] Increment the program counter
 * 
 * [PARAM] steps 
*/
void i8080::i8080_Registers::inc_PC(int steps)
{
	PC.set(PC.get() + steps);
}

/**
 * [DESCRIPTION] Construct a new i8080 Registers::i8080 Registers object
 * 
*/
i8080::i8080_Registers::i8080_Registers()
{
	A.set(0);
	B.set(0);
	C.set(0);
	D.set(0);
	E.set(0);
	H.set(0);
	L.set(0);
	SP.set(0);
	PC.set(0);
}

/**
 * [DESCRIPTION] Get the value out of a 16 bit register
 * 
 * [RETURN] uint16_t 
*/
uint16_t i8080::i8080_Registers::Register_16Bit::get()
{
	return val;
}

/**
 * [DESCRIPTION] Set the value in a 16 bit register
 * 
 * [PARAM] i 
*/
void i8080::i8080_Registers::Register_16Bit::set(uint16_t i)
{
	val = i;
}

/**
 * [DESCRIPTION] Get the value out of an 8 bit register
 * 
 * [RETURN] uint8_t 
*/
uint8_t i8080::i8080_Registers::Register_8Bit::get()
{
	return val;
}

/**
 * [DESCRIPTION] set the value in an 8 bit register
 * 
 * [PARAM] i 
*/
void i8080::i8080_Registers::Register_8Bit::set(uint8_t i)
{
	val = i;
}
