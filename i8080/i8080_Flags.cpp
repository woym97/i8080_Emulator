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
	return (0x80 == (i8080.state.reg_A.get() & 0x80));
}

bool i8080_Flags::check_S(uint8_t uint8_Register)
{
	return false;
}

bool i8080_Flags::check_Z()
{
	return false;
}

bool i8080_Flags::check_Z(uint8_t uint8_Register)
{
	return false;
}

bool i8080_Flags::check_AC(uint8_t uint8_Source1, uint8_t uint8_Source2)
{
	return false;
}

bool i8080_Flags::check_P()
{
	return false;
}

bool i8080_Flags::check_P(uint8_t uint8_Register)
{
	return false;
}

bool i8080_Flags::check_C(uint8_t uint8_Source1, uint8_t uint8_Source2)
{
	return false;
}

bool i8080_Flags::check_C(uint16_t uint16_Source1, uint16_t uint16_Source2)
{
	return false;
}
