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
#include <cmath>        // std::abs

/**
 * [DESCRIPTION] Class representing the space invaders game
 * 
*/
class SpaceInvaders {
private:

    // GAME ACTIONS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
    class Si_Action {
    private:
        i8080::i8080_IO::IO::Port* port; // port that the action is mapped to
        unsigned char bit;               // bit that the action is mapped to
    public:
        void start();                    // stop the action
        void stop();                     // start the action
        Si_Action(i8080::i8080_IO::IO::Port* p_port, unsigned char p_bit);
    };
    Si_Action* act_left_p1;
    Si_Action* act_right_p1;
    Si_Action* act_fire_p1;
    Si_Action* act_start_p1;

    Si_Action* act_left_p2;
    Si_Action* act_right_p2;
    Si_Action* act_fire_p2;
    Si_Action* act_start_p2;

    Si_Action* act_tilt;
    Si_Action* act_coin;

    Mix_Chunk* wav_ShotSoundEffect;
    Mix_Chunk* wav_ExplosionSoundEffect;
    Mix_Chunk* wav_FastInvader1SoundEffect;
    Mix_Chunk* wav_FastInvader2SoundEffect;
    Mix_Chunk* wav_FastInvader3SoundEffect;
    Mix_Chunk* wav_FastInvader4SoundEffect;
    Mix_Chunk* wav_InvaderKilledSoundEffect;
    Mix_Chunk* wav_UFOHighPitchSoundEffect;
    Mix_Chunk* wav_UFOLowPitchSoundEffect;

    const int       EM_WIDTH = 224;         // space invaders pixel width
    const int       EM_HEIGHT = 256;        // space invaders pixel height
    const SDL_Rect  fillRect = { 165,181,
                    EM_WIDTH,EM_HEIGHT };   // defines the area for the emulator on top of the bezel
    SDL_Texture* siContainer;               // VRAM container
    SDL_Texture* siBackground;              // SI Bezel background
    SDL_Renderer* gwRenderer;               // game window to render to
    SDL_Joystick* gc_1;
    SDL_Joystick* gc_2;
    i8080* cpu;                             // cpu to run the game on
    unsigned int* video_RAM;                // VRAM from space invaders
    i8080::i8080_Registers::Register_16Bit shift_register;   // special i8080 hardware 
    void            handleUserInput(bool& quit_flag); // handle the input from the user
    void            loadRomFiles();     // load the rom files for the game
    void            mapActions();       // map the actions to the cpu ports
    void            loadScreenUpdate(); // load an update to the screen
    void            mainLoop();         // main game loop
    void            prepareVRAM();      // prepare the VRAM for the space invaders screen
    void            performShift();     // special i8080 hardware
    void            updateSound();      // function to play the sound effects
    void            displayInstructions();
public:
    void            runGame();          // run the game
    SpaceInvaders(SDL_Renderer* renderer, SDL_Joystick* gameController_1, SDL_Joystick* gameController_2);   // constructor
    ~SpaceInvaders();   // destructor           
};