/**
 * [FILE] i8080.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents an i8080 processor 
 *      RESOURCES:
 *          https://altairclone.com/downloads/manuals/8080%20Programmers%20Manual.pdf
 * [DATE] 2021-05-21
*/

#pragma once
#include "i8080_Clock.h"
#include "i8080_Flags.h"
#include "i8080_IO.h"
#include "i8080_OpCodes.h"
#include "i8080_Memory.h"

/**
 * [DESCRIPTION] Class representing an i8080 processor and 
 *               its components
*/
class i8080 {
public:
    i8080_Flags      flags;
    i8080_Registers  registers;
    i8080_Memory     memory;
    i8080_Clock      clock;
    i8080_IO         io;
    i8080_OpCodes    execute;
    void             sendInterrupt(int itr_num);

    i8080();
};