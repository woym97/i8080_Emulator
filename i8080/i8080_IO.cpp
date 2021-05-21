/**
 * [FILE] i8080_IO.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains the implementation for the i8080 IO processes
 * [DATE] 2021-05-21
*/

#include "i8080.h"

/**
 * [DESCRIPTION] Set an index in the IO buffer to the passed value
 * 
 * [PARAM] index 
 * [PARAM] val 
*/
void i8080::i8080_IO::IO::set(int index, uint8_t val)
{
	buffer[index] = val;
}

/**
 * [DESCRIPTION] Get a value from the buffer that is in the passed index
 * 		- Must make sure this value is less than 255 (limit of buffer)
 * [PARAM] index 
 * [RETURN] uint8_t 
*/
uint8_t i8080::i8080_IO::IO::get(int index)
{
	if (index < 256) {
        return buffer[index];
    }
    else {
        return NULL;
    }
}

/**
 * [DESCRIPTION] Construct a new i8080_IO::IO::IO object
 * 
*/
i8080::i8080_IO::IO::IO()
{
	buffer[255] = { 0 };
};

