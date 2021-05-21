/**
 * [FILE] i8080_Memory.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains the implementation for the i8080 memory
 * [DATE] 2021-05-21
*/

#include "i8080.h"

/**
 * [DESCRIPTION] Returns the memory value at the passed index
 * 
 * [PARAM] index 
 * [RETURN] uint8_t 
*/
uint8_t i8080::i8080_Memory::get(uint16_t index)
{
	return memory[index];
}

/**
 * [DESCRIPTION] Sets the memory value at the given index
 * 
 * [PARAM] index 
 * [PARAM] val 
*/
void i8080::i8080_Memory::set(uint16_t index, uint8_t val)
{
	memory[index] = val;
}

/**
 * [DESCRIPTION] Gets the adr value from memory
 * 
 * [RETURN] uint16_t 
*/
uint16_t i8080::i8080_Memory::get_Adr()
{
	// MM-Modified this from [1] to [2] first according to i8080 Manual for JMP
    uint16_t uint16_AddrTemp = 0x0000;
    uint16_AddrTemp = uint16_AddrTemp | opCode_Array[2];
    uint16_AddrTemp = uint16_AddrTemp << 8;
    uint16_AddrTemp = uint16_AddrTemp | opCode_Array[1];
    return uint16_AddrTemp;
}

/**
 * [DESCRIPTION] Return the value of memory that the value of HL is pointing to
 * 
 * [RETURN] uint8_t 
*/
uint8_t i8080::i8080_Memory::get_M()
{
	return get(registers->get_HL());
}

/**
 * [DESCRIPTION] Set the value of memory that the value of HL is pointing to
 * 
 * [PARAM] val 
*/
void i8080::i8080_Memory::set_M(uint8_t val)
{
	set(registers->get_HL(), val);
}

/**
 * [DESCRIPTION] Load the passed file into memory
 * 
 * [PARAM] fileName 
 * [PARAM] address 
*/
void i8080::i8080_Memory::loadRom(const char* fileName, size_t address)
{
	// Open the ROM file
#pragma warning(disable:4996)
    FILE *f= fopen(fileName, "rb");

    // Check if the file was opened
	if (f==NULL)
	{
		printf("ERROR OPENING %s\nn", fileName);
	}

    // Find the end of the file
#pragma warning(disable:6387)
	fseek(f, 0L, SEEK_END);
	int file_size = ftell(f);
	fseek(f, 0L, SEEK_SET);
	
    // Create a temporary pointer to the location we want to copy the
    // ROM into 
	uint8_t *temp_buffer = &memory[address];

    // Read the data from the file into the temporary pointer which
    // copies it into the mem_array
	fread(temp_buffer, file_size, 1, f);

    // Close the file
	fclose(f);

    return;
}

/**
 * [DESCRIPTION] Construct a new i8080 Memory::i8080 Memory object
 * 
*/
i8080::i8080_Memory::i8080_Memory(i8080_Registers* parent_registers)
{
	opCode_Array[3] = { 0 };
	registers = parent_registers;
}

