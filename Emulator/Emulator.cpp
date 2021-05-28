/**
 * [FILE] Emulator.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] 
 * [VERSION] 0.1
 * [DATE] 2021-05-19
*/

#include "Emulator.h"

/**
 * [DESCRIPTION] Initialize all SDL items 
 * 
 * [RETURN] true on success
 * [RETURN] false on failure
*/
bool Emulator::initSDL()
{
	bool load_success = true;

	// initialize all SDL attributes
	if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_JOYSTICK) < 0) {
		printf("Error initSDL [init] Error Message: %s\n", SDL_GetError());
		load_success = false;
	}
	else {
		// create the game window
		// SDL_Window = struct that holds info about the window itself
		gameWindow = SDL_CreateWindow(
			"8080 Emulator",			// title of the window
			SDL_WINDOWPOS_CENTERED,		// x pos of window on screen
			SDL_WINDOWPOS_CENTERED,		// y pos of window on screen
			WIND_WIDTH,					// width of window
			WIND_HEIGHT,				// height of window
			SDL_WINDOW_SHOWN			// flag to show window when created
		);
		// check that the window was successfully created before moving on
		if (gameWindow == NULL) {
			printf("Error initSDL [window] Error Message: %s\n", SDL_GetError());
			load_success = false;
		}

		// initialize the renderer for the game window
		gwRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		// check for successful creation of the renderer
		if (gwRenderer == NULL) {
			printf("Error initSDL [renderer] Error Message: %s\n", SDL_GetError());
			load_success = false;
		}

		// Check for connected joysticks (ok if there are not any)
		if (SDL_NumJoysticks() < 1) {
			printf("No Joysticks connected \n");
		}
		else {
			gameController_1 = SDL_JoystickOpen(0);
			if (gameController_1 == NULL) {
				printf("ERROR: Unable to load joystick");
			}
			else {
				printf("Joystick 1 connected\n");
			}
			if (SDL_NumJoysticks() > 1) {
				gameController_2 = SDL_JoystickOpen(1);
				if (gameController_2 == NULL) {
					printf("ERROR: Unable to load joystick");
				}
				else {
					printf("Joystick 2 connected\n");
				}
			}
		}

		// Initialize Sound Mixer
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
			// Error message if can't initialize
			printf("Error initializing Sound Mixer\n");
		}

		// Amount of channels (Max amount of sounds playing at the same time)
		Mix_AllocateChannels(2);
	}
	return load_success;
}

/**
 * [DESCRIPTION] Wait on the i8080 menu screen until the user makes a selection
 * 
*/
void Emulator::waitForMenuEvent()
{
	// flag to signal program exit
	bool quit_flag = false;

	// event to handle 
	SDL_Event evnt;

	while (!quit_flag) {
		// look at the event queue and handle events on it until
		// there are none left to handle (the queue is empty)
		while (SDL_PollEvent(&evnt) != 0) {
			// handle the case where the user has hit the "X"
			if (evnt.type == SDL_QUIT) {
				quit_flag = true;
			}
			// handle the case where the user presses a key
			else if (evnt.type == SDL_KEYDOWN) {
				switch (evnt.key.keysym.sym) {
				case SDLK_q:
					quit_flag = true;
					break;
				case SDLK_c:
					runSpaceInvaders();
					break;
				}
			} else if (evnt.type == SDL_JOYBUTTONDOWN) {
				switch (evnt.jbutton.button) {
				// R middle button
				case 6:
					quit_flag = true;
					break;
				// L middle button
				case 7:
					runSpaceInvaders();
					break;
				}
			}
		}
		// after the events have been handled switch to the next screen
		menuAnimation(false);
		SDL_Delay(200);
	}
	// destory the menu textures
	menuAnimation(true);
}

/**
 * [DESCRIPTION] Cycle through the menu animation
 * 
 * [PARAM] destroy_flag - when passed destory the internal hooks to the bmps
*/
void Emulator::menuAnimation(bool destroy_flag)
{
	// declare the static variables curresponding to the textures loaded
	static SDL_Texture* gwMenu_1 = NULL;
	static SDL_Texture* gwMenu_2 = NULL;
	static SDL_Texture* gwMenu_3 = NULL;

	// check if the images need to be loaded and if so load them
	if (gwMenu_1 == NULL) {
		SDL_Surface* imageLoader = SDL_LoadBMP("bmp_files/menu_1.bmp");
		gwMenu_1 = SDL_CreateTextureFromSurface(gwRenderer, imageLoader);
		imageLoader = SDL_LoadBMP("bmp_files/menu_2.bmp");
		gwMenu_2 = SDL_CreateTextureFromSurface(gwRenderer, imageLoader);
		imageLoader = SDL_LoadBMP("bmp_files/menu_3.bmp");
		gwMenu_3 = SDL_CreateTextureFromSurface(gwRenderer, imageLoader);
		SDL_FreeSurface(imageLoader);
	}

	// keeps track of the current background image of the menu
	static int cur_menu_ind = 1;

	switch (cur_menu_ind) {
	case 1:
		SDL_RenderCopy(gwRenderer, gwMenu_2, NULL, NULL);
		cur_menu_ind++;
		break;
	case 2:
		SDL_RenderCopy(gwRenderer, gwMenu_3, NULL, NULL);
		cur_menu_ind++;
		break;
	case 3:
		SDL_RenderCopy(gwRenderer, gwMenu_1, NULL, NULL);
		cur_menu_ind = 1;
		break;
	}

	SDL_RenderPresent(gwRenderer);

	// check if the destroy flag is set, if it is destroy the textures
	if (destroy_flag) {
		SDL_DestroyTexture(gwMenu_1);
		gwMenu_1 = NULL;
		SDL_DestroyTexture(gwMenu_2);
		gwMenu_2 = NULL;
		SDL_DestroyTexture(gwMenu_3);
		gwMenu_3 = NULL;
	}

}

/**
 * [DESCRIPTION] The user has quit so destory the SDL objects
 * 
*/
void Emulator::closeGameWindow()
{
	// release the window variable
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	// close the joystick
	SDL_JoystickClose(gameController_1);
	gameController_1 = NULL;

		// close the joystick
	SDL_JoystickClose(gameController_2);
	gameController_2 = NULL;

	// destroy the renderer
	SDL_DestroyRenderer(gwRenderer);
	gwRenderer = NULL;

	// close all SDL processes
	SDL_Quit();
}

/**
 * [DESCRIPTION] Construct a new Emulator:: Emulator object
 * 
*/
Emulator::Emulator()
{
	initSDL();
	waitForMenuEvent();
};

/**
 * [DESCRIPTION] Destroy the Emulator:: Emulator object
 * 
*/
Emulator::~Emulator()
{
	closeGameWindow();
};

/**
 * [DESCRIPTION] Run Space invaders
 *
*/
void Emulator::runSpaceInvaders()
{
	SpaceInvaders* game;
	game = new SpaceInvaders(gwRenderer, gameController_1, gameController_2);
	game->runGame();
}
