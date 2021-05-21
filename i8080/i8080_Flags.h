/**
 * [FILE] i8080_Flags.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents the flags in an
 *               i8080 register
 * [DATE] 2021-05-21 
*/

#pragma once
#include <cstdint>

/**
 * [DESCRIPTION] Class representing the flags on an i8080 processor 
 * 
*/
class i8080_Flags {
private: 
    /**
     * [DESCRIPTION] General flag class 
     * 
    */
    class Flag {
        private:
            bool val;
        public:
            void set(bool new_val);
            bool get();
    };
public:
    Flag Z;     // Zero 
    Flag S;     // Sign
    Flag P;     // Parity
    Flag C;     // Carry
    Flag AC;    // Auxillary Carry
    Flag INTE;  // Interrupt flag

    // FLAG FUNCTIONS
    bool check_S();
    bool check_S(uint8_t uint8_Register);
    bool check_Z();
    bool check_Z(uint8_t uint8_Register);
    bool check_AC(uint8_t uint8_Source1, uint8_t uint8_Source2);
    bool check_P();
    bool check_P(uint8_t uint8_Register);
    bool check_C(uint8_t uint8_Source1, uint8_t uint8_Source2);
    bool check_C(uint16_t uint16_Source1, uint16_t uint16_Source2);

    i8080_Flags();
};