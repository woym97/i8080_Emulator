/**
 * [FILE] i8080_IO.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents the IO of an i8080
 * [DATE] 2021-05-21
*/

#pragma once
#include <cstdint>
#include <array>

/**
 * [DESCRIPTION] Class representing IO on an i8080 processor
 * 
*/
class i8080_IO {
    /**
     * [DESCRIPTION] Class representing general IO with a buffer
     * 
    */
    class IO {
    private:
        std::array<uint8_t, 256> buffer;
    public:
        void    set(int index, uint8_t val);
        uint8_t get(int index);
        IO();
    };

    IO input;
    IO output;

    i8080_IO();
};