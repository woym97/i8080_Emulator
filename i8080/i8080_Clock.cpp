/**
 * [FILE] i8080_Clock.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains the implementation of the i8080 clock
 * [DATE] 2021-05-21
*/

#include "i8080_Clock.h"


/**
 * [DESCRIPTION] Since the i8080 runs at 2Mhz we need to periodically calculate 
 * 				 how many clock cycles we need to run since the last time we ran 
 * 				 opcodes (2 clock cycles per micro second passed)
 * 
 * [RETURN] int (clock cycles that need to be run according to the timer)
*/
int i8080_Clock::getCyclesToRun()
{
	// on the first call (when the timer is 0) just start the timer
    if (timer == 0) {
        resetClockTimer();
        return 0;
    }
    
    // on all subsequesnt calls see how much time has passed on the timer and calculate
    // how many clock cycles need to be executed
    uint64_t now_micro = std::chrono::duration_cast<std::chrono::microseconds>
		(std::chrono::high_resolution_clock::now().time_since_epoch()).count();

    // number of clock cycles = (time in micro seconds) * 2
    return (now_micro - timer) * 2;
}

/**
 * [DESCRIPTION] Increment the clock cycles based on the opcode that was just run
 * 		- This is called from the individual opcodes 
 * [PARAM] cyc 
*/
void i8080_Clock::incClockCycles(int cyc)
{
	cycles += cyc;
}

/**
 * [DESCRIPTION] Construct a new i8080 Clock::i8080 Clock object
 * 
*/
i8080_Clock::i8080_Clock() {
	timer 	= 0;
	cycles 	= 0;
}

/**
 * [DESCRIPTION] Reset the clock timer to the current tim ein microseconds
 * 
*/
void i8080_Clock::resetClockTimer()
{
	timer = std::chrono::duration_cast<std::chrono::microseconds>
	(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

