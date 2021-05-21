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
     * [DESCRIPTION] General register class
     * 
    */
    class Register {
        private:
            uint8_t val;
            uint16_t large_val;
        public:
            uint16_t get_Large();
            uint8_t get();
            void set(uint8_t i);
            void set_Large(uint16_t i);
    };
    Register A;
    Register B;
    Register C;
    Register D;
    Register E;
    Register H;
    Register L;
    Register SP;
    Register PC;
    Register PSW;

    uint16_t    get_BC();
    uint16_t    get_HL();
    uint16_t    get_DE();
    void        set_BC(uint16_t val);
    void        set_HL(uint16_t val);
    void        set_DE(uint16_t val);
    uint8_t     get_PSW();
    void        inc_PC(int steps);

    i8080_Registers();
};