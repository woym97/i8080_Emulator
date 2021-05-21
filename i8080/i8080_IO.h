/**
 * [FILE] i8080_IO.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents the IO of an i8080
 * [DATE] 2021-05-21
*/

#pragma once
#include <cstdint>

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
        uint8_t buffer[256];
    public:
        void    set(int index, uint8_t val);
        uint8_t get(int index);
        IO();
    };

    IO input;
    IO output;

    i8080_IO();
    ~i8080_IO();
};