/**
 * [FILE] i8080_Flags.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents the flags in an
 *               i8080 register
 * [DATE] 2021-05-21 
*/

#pragma once
#include <cstdint>
#include "i8080_Component.h"
#include "i8080_Registers.h"

/**
 * [DESCRIPTION] Class representing the flags on an i8080 processor 
 * 
*/
class i8080_Flags: public i8080_Component {
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

    // CHECK FLAG FUNCTIONS
    bool check_S();
    bool check_S(i8080_Registers::Register_8Bit reg);
    bool check_Z();
    bool check_Z(i8080_Registers::Register_8Bit reg);
    bool check_AC(i8080_Registers::Register_8Bit reg1, 
                  i8080_Registers::Register_8Bit reg2);
    bool check_P();
    bool check_P(i8080_Registers::Register_8Bit reg);
    bool check_C(i8080_Registers::Register_8Bit reg1, 
                 i8080_Registers::Register_8Bit reg2);
    bool check_C(i8080_Registers::Register_16Bit reg1, 
                 i8080_Registers::Register_16Bit reg2);

    i8080_Flags();
};