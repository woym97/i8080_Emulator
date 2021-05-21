/**
 * [FILE] i8080_Clock.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object which represents a clock on an i8080 processor
 * [VERSION] 0.1
 * [DATE] 2021-05-21
*/

#pragma once
#include <cstdint>
#include <chrono>

/**
 * [DESCRIPTION] Represents a clock in an i8080 processor
 *      - i8080 runs at 2Mhz which means it processes 2 clock cycles every micro 
 *        second 
 *      - This class faclilitates the synchronization of that timing and the 
 *        system clock 
*/
class i8080_Clock {
private:
    /* values below are uint64_t becuase they will be 
        holding microseconds (prevents overflow) */
    uint64_t    timer;                  // timer in microseconds since last reset
    uint64_t    cycles;                 // total clock cycles that have been run
public:   
    int         getCyclesToRun();       // get the clock cycles to run 
    void        incClockCycles(int cyc);// increment the cycles by passed value
    void        resetClockTimer();      // reset the timer
    i8080_Clock();                      // constructor
};