/**
 * [FILE] i8080_Memory.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents the memory of an i8080
 * [DATE] 2021-05-21
*/

#pragma once
#include <cstdint>
#include <array>
#include "i8080_Component.h"

/**
 * [DESCRIPTION] Class representing the memory on an i8080
 * 
*/
class i8080_Memory : public i8080_Component{
    uint8_t*    memory;                             // array representing RAM
public:
    std::array<uint8_t, 3> opCode_Array;            // array of surrent opcodes
    uint8_t     get(uint16_t index);                // get memory
    void        set(uint16_t index, uint8_t val);   // set memory
    uint16_t    get_Adr();                          // get ADR location from memory                    
    uint8_t     get_M();                            // get M location from memory
    void        set_M(uint8_t val);                 // set M location from memory
    void        loadRom(const char* fileName, size_t address);  // load ROM into mem
    i8080_Memory();
};