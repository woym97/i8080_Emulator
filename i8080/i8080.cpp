/**
 * [FILE] i8080.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Implements the i8080 functions
 * [DATE] 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
*/

#include "i8080.h"

/**
 * [DESCRIPTION] Send an interrupt to the processor
 * 
 * [PARAM] itr_num 
*/
void i8080::sendInterrupt(int itr_num)
{
     // first check if interuppts are enabled, only act if they are
    if (flags->INTE.get()) {

        // break the Program Counter into two bytes so that it can be stored in memory
        uint16_t uint16_InitialSP = registers->SP.get();
        uint16_t uint16_InitialPC = registers->PC.get();
        uint8_t uint8_PCAddrLow = 0x00;
        uint8_t uint8_PCAddrHigh = 0x00;
        uint8_PCAddrLow = uint8_PCAddrLow | uint16_InitialPC;
        uint8_PCAddrHigh = uint8_PCAddrHigh | (uint16_InitialPC >> 8);

        // push the Program Counter to memory where the Stack Pointer - 1 and Stack Pointer - 2 point
        memory->set((uint16_InitialSP - 0x0001), uint8_PCAddrHigh);
        memory->set((uint16_InitialSP - 0x0002), uint8_PCAddrLow);

        // the Stack Pointer is updated
        registers->SP.set(uint16_InitialSP - 0x0002);

        // set the PC to the low memory vector.    
        // this is identical to an "RST interrupt_num" instruction.
        switch (itr_num)
        {
            case 0x00: registers->PC.set(0x0000); break;
            case 0x01: registers->PC.set(0x0008); break;
            case 0x02: registers->PC.set(0x0010); break;
            case 0x03: registers->PC.set(0x0018); break;
            case 0x04: registers->PC.set(0x0020); break;
            case 0x05: registers->PC.set(0x0028); break;
            case 0x06: registers->PC.set(0x0030); break;
            case 0x07: registers->PC.set(0x0038); break;
            default: break;
        }
        
        // reset the int enable bit
        flags->INTE.set(true);
    }
};

/**
 * [DESCRIPTION] Construct a new i8080::i8080 object by pointing the
 *               child components to this object (only if they need access)
 * 
*/
i8080::i8080() 
{
    registers   = new i8080_Registers;
    flags       = new i8080_Flags(registers);
    memory      = new i8080_Memory(registers);
    clock       = new i8080_Clock;
    io          = new i8080_IO;
    execute     = new i8080_OpCodes(registers, memory);
}

/**
 * [DESCRIPTION] Delete i8080::i8080 
 *
*/
i8080::~i8080()
{
    delete registers;
    delete flags;
    delete memory;
    delete clock;
    delete io;
    delete execute;
}