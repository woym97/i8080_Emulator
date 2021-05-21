/**
 * [FILE] i8080_Registers.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents the registers in an i8080
 * [DATE] 2021-05-21
*/

#pragma once
#include <cstdint>

/**
 * [DESCRIPTION] Class representing the registers on an i8080
 * 
*/
class i8080_Registers {
public:
    /**
     * [DESCRIPTION] General 8 bit register class
     * 
    */
    class Register_8Bit {
        private:
            uint8_t val;
        public:
            uint8_t get();
            void set(uint8_t i);
    };
    
    /**
     * [DESCRIPTION] General 16 bit register class
     * 
    */
    class Register_16Bit {
        private:
            uint16_t val;
        public:
            uint16_t get();
            void set(uint16_t i);
    };

    // I8080 REGISTERS
    Register_8Bit A;    // Register A
    Register_8Bit B;    // Register B
    Register_8Bit C;    // Register C
    Register_8Bit D;    // Register D
    Register_8Bit E;    // Register E
    Register_8Bit H;    // Register H
    Register_8Bit L;    // Register L
    Register_16Bit SP;  // Stack Pointer
    Register_16Bit PC;  // Program Counter

    // SPECIAL REGISTER GET/SET
    uint16_t    get_BC();
    uint16_t    get_HL();
    uint16_t    get_DE();
    void        set_BC(uint16_t val);
    void        set_HL(uint16_t val);
    void        set_DE(uint16_t val);

    // PROGRAM COUNTER
    void        inc_PC(int steps);

    i8080_Registers();

private:
    uint16_t getCombinedReg(Register_8Bit reg1, Register_8Bit reg2);
    void     setCombinedReg(Register_8Bit reg1, Register_8Bit reg2, uint16_t val);
};