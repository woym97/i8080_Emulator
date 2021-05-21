/**
 * [FILE] SpaceInvaders.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] File which contains an object that represents the game Space Invaders
 * [VERSION] 0.1
 * [DATE] 2021-05-19 
*/

#pragma once
#include "i8080.h"

/**
 * [DESCRIPTION] Class representing the space invaders game
 * 
*/
class SpaceInvaders {
    private:
        i8080           cpu;                // cpu to run the game on
        unsigned int*   video_RAM;          // VRAM from space invaders
        /**
         * [DESCRIPTION] Object that represents the possible inputs in
         *               space invaders
        */
        enum class      SI_INPUT {
            P1_MOVE_LEFT,
            P1_MOVE_RIGHT,
            P1_FIRE,
            QUIT,
            INSERT_COIN,
            P2_MOVE_LEFT,
            P2_MOVE_RIGHT,
            P2_FIRE,
            P1_START,
            P2_START,
            TILT,
            NO_ACTION
        };
        SI_INPUT        getInput();        // get the input from the user
        void            loadRomFiles();    // load the rom files for the game
        void            loadScreenUpdate();// load an update to the screen
        void            mainLoop();        // main game loop
        void            prepareVRAM();     // prepare the VRAM for the space invaders screen
        void            resetInputs();     // reset inputs specific to space invaders
        void            shiftRegister();   // special i8080 hardware 
    public:
        void            runGame();         // run the game
};