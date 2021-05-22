/**
 * [FILE] Emulator.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an object that represents an i8080 emulator
 * [VERSION] 0.1
 * [DATE] 2021-05-19
 * 
 * @copyright Copyright (c) 2021
 * 
*/

#pragma once
#include <SDL.h>
#include <SDL_mixer.h>;
#include <stdio.h>
#include <string>
#include <math.h> 
#include <iostream>
#include "../SpaceInvaders/SpaceInvaders.h"

/**
 * [DESCRIPTION] Class which contains SDL interactions and pathways to begin
 *               the emulated i8080 processor
 * 
*/
class Emulator {
    private:
        /* =-=-=-= Emulator Sizing Constants =-=-=-= */
        const int WIND_WIDTH = 541;                 // width of window
        const int WIND_HEIGHT = 560;                // height of window

        /* =-=-=-= PRIVATE FUNCTIONS =-=-=-= */
        bool initSDL();					            // initializes the game window
        void waitForMenuEvent();				    // wait for the user to make a selection 
        void menuAnimation(bool destroy_flag);	    // handle the main menu animation
        void closeGameWindow();					    // shut down procedure for the game
    public:
        /* =-=-=-= SDL MEMBERS =-=-=-= */
        SDL_Joystick*   gameController = NULL;      // variable to hold handle to joystick
        SDL_Window*     gameWindow = NULL;			// main window for game
        SDL_Renderer*   gwRenderer = NULL;		    // main renderer

        Emulator();
        ~Emulator();
        void runSpaceInvaders();				    // run space invaders on the emulator
};