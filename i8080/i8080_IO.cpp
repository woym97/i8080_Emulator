/**
 * [FILE] i8080_IO.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains the implementation for the i8080 IO processes
 * [DATE] 2021-05-21
*/

#include "i8080.h"

/**
 * [DESCRIPTION] Sets the passed bit
 *
 * [PARAM] port_num
 * [PARAM] bit
*/
void i8080::i8080_IO::IO::Port::set_bit(char bit)
{
	mod_bit(bit, 1);
}

/**
 * [DESCRIPTION] Unsets the passed bit
 *
 * [PARAM] port_num
 * [PARAM] bit
*/
void i8080::i8080_IO::IO::Port::unset_bit(char bit)
{
	mod_bit(bit, 0);
}

/**
 * [DESCRIPTION] Set the passed bit to the passed val
 *
 * [PARAM] bit
 * [PARAM] val
*/
void i8080::i8080_IO::IO::Port::mod_bit(char bit, bool val)
{
	switch (bit) {
	case 0:
		port_val.bit_struct.b0 = val;
		break;
	case 1:
		port_val.bit_struct.b1 = val;
		break;
	case 2:
		port_val.bit_struct.b2 = val;
		break;
	case 3:
		port_val.bit_struct.b3 = val;
		break;
	case 4:
		port_val.bit_struct.b4 = val;
		break;
	case 5:
		port_val.bit_struct.b5 = val;
		break;
	case 6:
		port_val.bit_struct.b6 = val;
		break;
	case 7:
		port_val.bit_struct.b7 = val;
		break;
	}
}

i8080::i8080_IO::IO::Port::Port()
{
	port_val.byte_val = 0;
	/*port_val.bit_struct.b0 = 0;
	port_val.bit_struct.b1 = 0;
	port_val.bit_struct.b2 = 0;
	port_val.bit_struct.b3 = 0;
	port_val.bit_struct.b4 = 0;
	port_val.bit_struct.b5 = 0;
	port_val.bit_struct.b6 = 0;
	port_val.bit_struct.b7 = 0;*/
}

/**
 * [DESCRIPTION] Gets a pointer to the desired Port
 * 
 * [PARAM] index 
 * [RETURN] uint8_t 
*/
i8080::i8080_IO::IO::Port *i8080::i8080_IO::IO::get_port(unsigned char port_num)
{
	return &port_list[port_num];
}

/**
 * [DESCRIPTION] Construct a new i8080_IO::IO::IO object
 * 
*/
i8080::i8080_IO::IO::IO()
{
};

