/**
 * [FILE] SpaceInvaders.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an objects that will run the space invaders game
 * [DATE] 2021-05-21
*/

#include "SpaceInvaders.h"
#include "../testWriter.h"

/**
 * [DESCRIPTION] Get the input from SDL and convert it to a
 * 				 action recognized by the game
 * 
 * [RETURN] SI_INPUT 
*/
SI_INPUT SpaceInvaders::getInput(SDL_Event &evnt)
{
	SI_INPUT return_action = SI_INPUT::NO_ACTION;

	// handle the case where the user has hit the "X"
	if (evnt.type == SDL_QUIT) {
		return_action = SI_INPUT::QUIT;
	}
	// handle the case where the user presses a key
	else if (evnt.type == SDL_KEYDOWN) {
		// evaluate the case based on the keypressed
		switch (evnt.key.keysym.sym) {
		case SDLK_q:
			// User has opted to quit so set the quit flag
			return_action = SI_INPUT::QUIT;
			break;

			// cases where player 1 starts
		case SDLK_s:
			return_action = SI_INPUT::P1_START;
			break;

			// cases where player 2 starts
		case SDLK_k:
			return_action = SI_INPUT::P2_START;
			break;

			// cases where a left move is made
		case SDLK_a:
			return_action = SI_INPUT::P1_MOVE_LEFT;
			break;
		case SDLK_LEFT:
			return_action = SI_INPUT::P1_MOVE_LEFT;
			break;
			// cases where a right move is made
		case SDLK_d:
			return_action = SI_INPUT::P1_MOVE_RIGHT;
			break;
		case SDLK_RIGHT:
			return_action = SI_INPUT::P1_MOVE_RIGHT;
			break;
			// cases where the fire button is pressed
		case SDLK_w:
			return_action = SI_INPUT::P1_FIRE;
			break;
		case SDLK_SPACE:
			return_action = SI_INPUT::P1_FIRE;
			break;
		case SDLK_c:
			return_action = SI_INPUT::INSERT_COIN;
			break;
		default:
			break;
		}
	}
	// handle joystick motion case
	else if (evnt.type == SDL_JOYAXISMOTION) {
		// look for motion on the controller 0
		if (evnt.jaxis.which == 0) {
			// look for x axis motion left
			if (evnt.jaxis.value < -8000) {
				return_action = SI_INPUT::P1_MOVE_LEFT;
			}
			// look for y axis motion right
			else if (evnt.jaxis.value > 8000) {
				return_action = SI_INPUT::P1_MOVE_RIGHT;
			}
		}
	}
	// handle joystick button down
	else if (evnt.type == SDL_JOYBUTTONDOWN) {
		switch (evnt.jbutton.button) {
		// A button
		case 0: 
			return_action = SI_INPUT::P1_FIRE;
			break;
		// R middle button
		case 6: 
			return_action = SI_INPUT::QUIT;
			break;
		// L middle button
		case 7: 
			return_action = SI_INPUT::INSERT_COIN; 
			break;
		}
	}
	
	return return_action;
}

/**
 * [DESCRIPTION] Handle user input
 *
*/
void SpaceInvaders::handleUserInput(bool& quit_flag)
{
	// event to handle 
	SDL_Event evnt;

	// look at the event queue and handle events on it until
	// there are none left to handle (the queue is empty)
	while (SDL_PollEvent(&evnt) != 0) {
		// get the user action converted into an enum value 
		switch (getInput(evnt)) {
		case SI_INPUT::QUIT:
			printf("QUIT\n");
			quit_flag = true;
			break;
		case SI_INPUT::P1_MOVE_LEFT:
			cpu->io->input.set(1, cpu->io->input.get(1) | 0x20);
			break;
		case SI_INPUT::P1_MOVE_RIGHT:
			cpu->io->input.set(1, cpu->io->input.get(1) | 0x40);
			break;
		case SI_INPUT::P1_FIRE:
			cpu->io->input.set(1, cpu->io->input.get(1) | 0x10);
			break;
		case SI_INPUT::INSERT_COIN:
			cpu->io->input.set(1, cpu->io->input.get(1) | 0x01);
			break;
		case SI_INPUT::P2_MOVE_LEFT:
			cpu->io->input.set(1, cpu->io->input.get(2) | 0x20);
			break;
		case SI_INPUT::P2_MOVE_RIGHT:
			cpu->io->input.set(1, cpu->io->input.get(2) | 0x40);
			break;
		case SI_INPUT::P2_FIRE:
			cpu->io->input.set(1, cpu->io->input.get(2) | 0x10);
			break;
		case SI_INPUT::P1_START:
			cpu->io->input.set(1, cpu->io->input.get(1) | 0x04);
			break;
		case SI_INPUT::P2_START:
			cpu->io->input.set(1, cpu->io->input.get(1) | 0x02);
			break;
		default: break;
		}
	}
}

/**
 * [DESCRIPTION] Load the game ROM files into memory
 * 
*/
void SpaceInvaders::loadRomFiles()
{
	cpu->memory->loadRom("SpaceInvaders/rom/invaders.h", 0);
    cpu->memory->loadRom("SpaceInvaders/rom/invaders.g", 0x800);
    cpu->memory->loadRom("SpaceInvaders/rom/invaders.f", 0x1000);
    cpu->memory->loadRom("SpaceInvaders/rom/invaders.e", 0x1800);
}

/**
 * [DESCRIPTION] Load an update to the screen from VRAM
 * 
*/
void SpaceInvaders::loadScreenUpdate()
{
	// update the screen pixels (the VRAM)
	prepareVRAM();
	// apply the updated VRAM to the screen
	SDL_UpdateTexture(siContainer, NULL, video_RAM, 4 * 224);
	// clear the old renderer
	SDL_RenderClear(gwRenderer);
	// re apply the background bezel
	SDL_RenderCopy(gwRenderer, siBackground, NULL, NULL);
	// apply the si container to the background
	SDL_RenderCopy(gwRenderer, siContainer, NULL, &fillRect);
	// display the screen
	SDL_RenderPresent(gwRenderer);
}

/**
 * [DESCRIPTION] Main game loop
 * 
*/
void SpaceInvaders::mainLoop()
{
	// define a condition to quit
	bool quit_flag = false;

	// to render screen update
	int game_timer = 0;

	// to hold clock cycles for loop
	int clock_cycles_to_run = 0;
	int goal_clock_cycles = 0;

	// to handle interrupts
	int interrupt_interval = 33333;
	uint64_t next_interrupt_cc = interrupt_interval;
	int next_interrupt_to_send = 1;

	while (!quit_flag) {
		// reset the inputs
		resetInputs();

		// handle the user input
		handleUserInput(quit_flag);

		// get the amount of clock cycles to run
		clock_cycles_to_run = cpu->clock->getCyclesToRun();
		goal_clock_cycles = cpu->clock->getCyclesToRun() + cpu->clock->getCurrentCCs();
		// execute opcodes until the desired number of ccs has been reached
		while (cpu->clock->getCurrentCCs() < goal_clock_cycles) {
			// step the cpu to the next cycle
			cpu->step();

			// check for shift condition
			if ((cpu->memory->opCode_Array[0] == 0xD3) && 
				(cpu->memory->opCode_Array[1] == 0x04)) {
				performShift();
			}

			// check for interrupt condition
			// 2 clock cycles per micro second 
			// 1/60 second = 16666 micro seconds
			// so interrupt every 2 * 16666 = 33333 clock cycles
			if (cpu->clock->getCurrentCCs() >= next_interrupt_cc) {
				cpu->sendInterrupt(next_interrupt_to_send);
				next_interrupt_to_send = next_interrupt_to_send == 1 ? 2 : 1;
				next_interrupt_cc += interrupt_interval;
			}

			// DEBUG
			writeOpcode(cpu->memory->opCode_Array[0], cpu->registers->PC.get(), cpu->clock->getCurrentCCs(),
				cpu->registers->PC.get(), cpu->registers->A.get(), cpu->registers->B.get(), cpu->registers->C.get(),
				cpu->registers->D.get(), cpu->registers->E.get(), cpu->registers->H.get(), cpu->registers->L.get(),
				cpu->flags->Z.get(), cpu->flags->S.get(), cpu->flags->P.get(), cpu->flags->C.get(), cpu->flags->AC.get());

			// execute the opcode
			cpu->execute->runOpCode();
		}

		// every 1/60 seconds update the screen and reset timer
		if (SDL_GetTicks() - game_timer > (1000 / 60)) {
			game_timer = SDL_GetTicks();
			loadScreenUpdate();
		}

		cpu->clock->resetClockTimer();

	}
}

/**
 * [DESCRIPTION] Prepare the moast recent VRAM screen
 * 
*/
void SpaceInvaders::prepareVRAM()
{
	// Load the current state of memory into an array that will 
    // eventually be loaded to the screen
    
    // Loop through the bytes 
    for (int byte_cnt = 0; byte_cnt < 256 * 224 / 8; byte_cnt++) {
        // Get the row and column of the current byte
        int row = (byte_cnt * 8) / 256;
        int col = (byte_cnt * 8) % 256;

        // Get the value of the byte out of memory
        uint8_t* byte = (uint8_t*)(cpu->memory->returnPtrToMem(0x2400)) + byte_cnt;

        unsigned int* pix;
        for (int bit = 0; bit < 8; bit++) {

            int offset = (255 - (col + bit)) * 224 * 4 + (row * 4);

            pix = (unsigned int*)((uint8_t*)video_RAM + offset);

            if ((*byte & (1 << bit)) != 0) {
                *pix = 0xffffffffL;
            }                
            else {
                *pix = 0x00000000L;
            }
        }
    }
}

/**
 * [DESCRIPTION] Reset the game inputs
 * 
*/
void SpaceInvaders::resetInputs()
{
	// Initializing Inputs
	// https://computerarcheology.com/Arcade/SpaceInvaders/Hardware.html
	// Port 0
	//		bit 0 DIP4(Seems to be self - test - request read at power up)
	//		bit 1 Always 1
	//		bit 2 Always 1
	//		bit 3 Always 1
	//		bit 4 Fire
	//		bit 5 Left
	//		bit 6 Right
	//		bit 7 ? tied to demux port 7 ?
	cpu->io->input.set(0, 0x0E);

	// Port 1
	//		bit 0 = CREDIT(1 if deposit)
	//		bit 1 = 2P start(1 if pressed)
	//		bit 2 = 1P start(1 if pressed)
	//		bit 3 = Always 1
	//		bit 4 = 1P shot(1 if pressed)
	//		bit 5 = 1P left(1 if pressed)
	//		bit 6 = 1P right(1 if pressed)
	//		bit 7 = Not connected
	cpu->io->input.set(1, 0x08);

	// Port 2
	//		bit 0 = DIP3 00 = 3 ships  10 = 5 ships
	//		bit 1 = DIP5 01 = 4 ships  11 = 6 ships
	//		bit 2 = Tilt
	//		bit 3 = DIP6 0 = extra ship at 1500, 1 = extra ship at 1000
	//		bit 4 = P2 shot(1 if pressed)
	//		bit 5 = P2 left(1 if pressed)
	//		bit 6 = P2 right(1 if pressed)
	//		bit 7 = DIP7 Coin info displayed in demo screen 0 = ON
	cpu->io->input.set(2, 0x0B);

	//Port 3
	//		bit 0 - 7 Shift register data
	//i8080.state.inputs[3] = 0x00;
}

/**
 * [DESCRIPTION] Emulate the SI register shift
 * 
*/
void SpaceInvaders::performShift()
{
	// https://computerarcheology.com/Arcade/SpaceInvaders/Hardware.html
	//f              0	bit
	//	xxxxxxxxyyyyyyyy

	//	Writing to port 4 shifts x into y, and the new value into x, eg.
	//	$0000,
	//	write $aa->$aa00,
	//	write $ff->$ffaa,
	//	write $12->$12ff, ..
	//printf("PreShiftRegister: %4X\n", i8080.state.get_ShiftRegister());
	uint16_t uint16_InitialShiftRegister = shift_register.get();
	uint16_t uint16_ShiftRegisterTemp = 0x0000;
	uint8_t uint8_ShiftLow = 0x00;
	uint8_t uint8_ShiftHigh = 0x00;

	uint8_ShiftLow = uint8_ShiftLow | uint16_InitialShiftRegister;
	uint8_ShiftHigh = uint8_ShiftHigh | (uint16_InitialShiftRegister >> 8);

	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp | cpu->io->output.get(4);
	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp << 0x08;
	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp | uint8_ShiftHigh;
		
	shift_register.set(uint16_ShiftRegisterTemp);

	//	Writing to port 2 (bits 0, 1, 2) sets the offset for the 8 bit result, eg.
	//	offset 0:
	//rrrrrrrr		result = xxxxxxxx
	//	xxxxxxxxyyyyyyyy
	uint8_t uint8_Offset = cpu->io->output.get(2) & 0x07;
	uint8_t uint8_RegisterTemp = 0x00;

	if (uint8_Offset == 0x00) {
		uint8_RegisterTemp = shift_register.get() >> 0x08;
	}

	//	offset 2 :
	//	rrrrrrrr	result = xxxxxxyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x02) {
		uint8_RegisterTemp = shift_register.get() >> 0x06;
	}

	//	offset 7 :
	//	rrrrrrrr	result = xyyyyyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x07) {
		uint8_RegisterTemp = shift_register.get() >> 0x01;
	}

	cpu->io->input.set(3, uint8_RegisterTemp);

}

/**
 * [DESCRIPTION] Outside caller to initiate the game
 * 
*/
void SpaceInvaders::runGame()
{
	/* Create space invader specific SDL structures */
	SDL_Surface* siBezel = SDL_LoadBMP("SpaceInvaders/space_invaders_bezel.bmp");
	if (siBezel == NULL) {
		printf("ERROR LOADING BEZEL\n");
	}
	siBackground = SDL_CreateTextureFromSurface(gwRenderer, siBezel);
	if (siBackground == NULL) {
		printf("ERROR LOADING BACKGROUND\n");
	}

	// create a texture to run the emulator inside of 
	siContainer = SDL_CreateTexture(
		gwRenderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING,
		EM_WIDTH,
		EM_HEIGHT);

	// load the rom files for the game
	loadRomFiles();

	// enter the main game loop
	mainLoop();

	// when done clean up the bezel
	SDL_FreeSurface(siBezel);
}

/**
 * [DESCRIPTION] Construct a new Space Invaders:: Space Invaders object
 * 
*/
SpaceInvaders::SpaceInvaders(SDL_Renderer* renderer)
{
	cpu = new i8080;
	gwRenderer = renderer;
	video_RAM = (unsigned int*)malloc(224 * 256 * 4);
	memset(video_RAM, 1, 224 * 256 * 4);

}

/**
 * [DESCRIPTION] Destroy the Space Invaders:: Space Invaders object
 * 
*/
SpaceInvaders::~SpaceInvaders()
{
	free(video_RAM);
	delete cpu;
	SDL_DestroyTexture(siContainer);
	SDL_DestroyTexture(siBackground);
	siContainer = NULL;
	siBackground = NULL;
}