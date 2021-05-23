/**
 * [FILE] SpaceInvaders.h
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] File which contains an object that represents the game Space Invaders
 * [VERSION] 0.1
 * [DATE] 2021-05-19 
*/

#pragma once
#include "../i8080/i8080.h"
#include "../Emulator/Emulator.h"
#include <SDL.h>
#include <SDL_mixer.h>

/**
 * [DESCRIPTION] Object that represents the possible inputs in
 *               space invaders
*/
enum class SI_INPUT {
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

/**
 * [DESCRIPTION] Class representing the space invaders game
 * 
*/
class SpaceInvaders {
    private:
        const int       EM_WIDTH  = 224;    // space invaders pixel width
        const int       EM_HEIGHT = 256;    // space invaders pixel height
        const SDL_Rect  fillRect = { 165,181,
                        EM_WIDTH,EM_HEIGHT };// defines the area for the emulator on top of the bezel
        SDL_Texture     *siContainer;       // VRAM container
        SDL_Texture     *siBackground;      // SI Bezel background
        SDL_Renderer    *gwRenderer;        // game window to render to
        i8080           *cpu;               // cpu to run the game on
        unsigned int    *video_RAM;          // VRAM from space invaders
        i8080::i8080_Registers::Register_16Bit shift_register;   // special i8080 hardware 
        SI_INPUT        getInput(SDL_Event &evnt);               // get the input from the user
        void            handleUserInput(bool& quit_flag); // handle the input from the user
        void            loadRomFiles();     // load the rom files for the game
        void            loadScreenUpdate(); // load an update to the screen
        void            mainLoop();         // main game loop
        void            prepareVRAM();      // prepare the VRAM for the space invaders screen
        void            resetInputs();      // reset inputs specific to space invaders
        void            performShift();     // special i8080 hardware
        void            updateSound();      // function to play the sound effects
    public:
        void            runGame();          // run the game
                        SpaceInvaders(SDL_Renderer* renderer);   // constructor
                        ~SpaceInvaders();   // destructor           
};