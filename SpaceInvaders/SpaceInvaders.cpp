/**
 * [FILE] SpaceInvaders.cpp
 * [AUTHOR] Madison Woy 
 * [DESCRIPTION] Contains an objects that will run the space invaders game
 * [DATE] 2021-05-21
*/

#include "SpaceInvaders.h"
#include "../testWriter.h"

/**
 * [DESCRIPTION] Handle user input
 *
*/
void SpaceInvaders::handleUserInput(bool& quit_flag)
{
	// event to handle 
	SDL_Event evnt;
	bool event_handled = false;
	static bool joystick_motion = false;

	// look at the event queue and handle events on it until
	// there are none left to handle (the queue is empty)
	while (SDL_PollEvent(&evnt) != 0 ) {
	//while (SDL_PollEvent(&evnt) != 0 && !event_handled) {
		// HANDLE MOUSE CLICKS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		if (evnt.type == SDL_QUIT) {
			quit_flag = true;
		}
		// HANDLE KEYDOWNS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		// key downs == start action
		else if (evnt.type == SDL_KEYDOWN) {
			switch (evnt.key.keysym.sym) {
			case SDLK_q:
				quit_flag = true;
				event_handled = true;
				break;
			case SDLK_s:
				act_start_p1->start();
				event_handled = true;
				break;
			case SDLK_LEFT:
			case SDLK_a:
				act_left_p1->start();
				event_handled = true;
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				act_right_p1->start();
				event_handled = true;
				break;
			case SDLK_SPACE:
			case SDLK_w:
				act_fire_p1->start();
				event_handled = true;
				break;
			case SDLK_k:
				act_start_p2->start();
				event_handled = true;
				break;
			case SDLK_j:
				act_left_p2->start();
				event_handled = true;
				break;
			case SDLK_l:
				act_right_p2->start();
				event_handled = true;
				break;
			case SDLK_i:
				act_fire_p2->start();
				event_handled = true;
				break;
			case SDLK_c:
				act_coin->start();
				event_handled = true;
				break;
			default:
				break;
			}
		}

		// HANDLE KEYUPS =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
		// key downs == stopaction
		else if (evnt.type == SDL_KEYUP) {
			switch (evnt.key.keysym.sym) {
			case SDLK_q:
				quit_flag = true;
				event_handled = true;
				break;
			case SDLK_s:
				act_start_p1->stop();
				event_handled = true;
				break;
			case SDLK_LEFT:
			case SDLK_a:
				act_left_p1->stop();
				event_handled = true;
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				act_right_p1->stop();
				event_handled = true;
				break;
			case SDLK_SPACE:
			case SDLK_w:
				act_fire_p1->stop();
				event_handled = true;
				break;
			case SDLK_k:
				act_start_p2->stop();
				event_handled = true;
				break;
			case SDLK_j:
				act_left_p2->stop();
				event_handled = true;
				break;
			case SDLK_l:
				act_right_p2->stop();
				event_handled = true;
				break;
			case SDLK_i:
				act_fire_p2->stop();
				event_handled = true;
				break;
			case SDLK_c:
				act_coin->stop();
				event_handled = true;
				break;
			default:
				break;
			}
		}

		// HANDLE CONTROLLER BUTTONS =-=-=-=-=-=-=-=-=-=-=-=-
		else if (evnt.type == SDL_JOYBUTTONDOWN) {
			if (evnt.jdevice.which == 0) {
				switch (evnt.jbutton.button) {
					// A button
				case 0:
					act_fire_p1->start();
					break;
					// B button
				case 1:
					act_start_p1->start();
					break;
					// R middle button
				case 6:
					quit_flag = true;
					event_handled = true;
					break;
					// L middle button
				case 7:
					act_coin->start();
					break;
				}
			}
			else if (evnt.jdevice.which == 1) {
				switch (evnt.jbutton.button) {
					// A button
				case 0:
					act_fire_p2->start();
					break;
					// B button
				case 1:
					act_start_p2->start();
					break;
					// R middle button
				case 6:
					quit_flag = true;
					event_handled = true;
					break;
					// L middle button
				case 7:
					act_coin->start();
					break;
				}
			}
		}
		else if (evnt.type == SDL_JOYBUTTONUP) {
			if (evnt.jdevice.which == 0) {
				switch (evnt.jbutton.button) {
					// A button
				case 0:
					act_fire_p1->stop();
					break;
					// B button
				case 1:
					act_start_p1->stop();
					break;
					// R middle button
				case 6:
					quit_flag = true;
					event_handled = true;
					break;
					// L middle button
				case 7:
					act_coin->stop();
					break;
				}
			}
			else if (evnt.jdevice.which == 1) {
				switch (evnt.jbutton.button) {
					// A button
				case 0:
					act_fire_p2->stop();
					break;
					// B button
				case 1:
					act_start_p2->stop();
					break;
					// R middle button
				case 6:
					quit_flag = true;
					event_handled = true;
					break;
					// L middle button
				case 7:
					act_coin->stop();
					break;
				}
			}
		}

		// HANDLE JOYSTICK MOVEMENTS =-=-=-=-=-=-=-=-=-=-=-=-
		else if (evnt.type == SDL_JOYAXISMOTION) {
			// look for motion on the controller 0
			if (evnt.jaxis.which == 0) {
				// look for x axis motion left
				if (evnt.jaxis.value < -8000) {
					act_left_p1->start();
					event_handled = true;
					joystick_motion = true;
				}
				// look for y axis motion right
				else if (evnt.jaxis.value > 8000) {
					act_right_p1->start();
					event_handled = true;
					joystick_motion = true;
				}
			}
			// look for motion on the controller 1
			else if (evnt.jaxis.which == 1) {
				// look for x axis motion left
				if (evnt.jaxis.value < -8000) {
					act_left_p2->start();
					event_handled = true;
					joystick_motion = true;
				}
				// look for y axis motion right
				else if (evnt.jaxis.value > 8000) {
					act_right_p2->start();
					event_handled = true;
					joystick_motion = true;
				}
			}
		}

	}

	// see if its time to stop a joystick movement
	if (gc_1 != NULL && joystick_motion) {
		if (std::abs(SDL_JoystickGetAxis(gc_1, 0)) < 8000) {
			act_right_p1->stop();
			act_left_p1->stop();
			joystick_motion = false;
		}
	}
	if (gc_2 != NULL && joystick_motion) {
		if (std::abs(SDL_JoystickGetAxis(gc_2, 0)) < 8000) {
			act_right_p2->stop();
			act_left_p2->stop();
			joystick_motion = false;
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
		// GET CLOCK =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		// get the amount of clock cycles to run
		clock_cycles_to_run = cpu->clock->getCyclesToRun();
		goal_clock_cycles = cpu->clock->getCyclesToRun() + cpu->clock->getCurrentCCs();

		// USER INPUT =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		handleUserInput(quit_flag);

		// RUN CPU =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
		// execute opcodes until the desired number of ccs has been reached
		while (cpu->clock->getCurrentCCs() < goal_clock_cycles) {

			// INTERRUPT =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
			// check for interrupt condition
			// 2 clock cycles per micro second 
			// 1/60 second = 16666 micro seconds
			// so interrupt every 2 * 16666 = 33333 clock cycles
			if (cpu->clock->getCurrentCCs() >= next_interrupt_cc) {
				cpu->sendInterrupt(next_interrupt_to_send);
				next_interrupt_to_send = next_interrupt_to_send == 1 ? 2 : 1;
				next_interrupt_cc += interrupt_interval;
			}
			
			// CPU STEP =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
			// step the cpu to the next cycle
			cpu->step();

			// DEBUG
			//writeOpcode(cpu->memory->opCode_Array[0], cpu->registers->PC.get(), 0,
			//	cpu->registers->SP.get(), cpu->registers->A.get(), cpu->registers->B.get(), cpu->registers->C.get(),
			//	cpu->registers->D.get(), cpu->registers->E.get(), cpu->registers->H.get(), cpu->registers->L.get(),
			//	cpu->flags->Z.get(), cpu->flags->S.get(), cpu->flags->P.get(), cpu->flags->C.get(), cpu->flags->AC.get());

			// EXE CPU =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
			// execute the opcode
			cpu->execute->runOpCode();

			// SHIFT CHECK =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=
			// check for shift condition
			if ((cpu->memory->opCode_Array[0] == 0xD3) &&
				(cpu->memory->opCode_Array[1] == 0x04)) {
				performShift();
			}

			// SCREEN UPDATE =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=
			if (SDL_GetTicks() - game_timer > (1000 / 60)) {
				game_timer = SDL_GetTicks();
				loadScreenUpdate();
			}

			updateSound();

		}

		// RESET CLOCK =-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
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
 * [DESCRIPTION] Emulate the SI register shift
 * 
*/
void SpaceInvaders::performShift()
{
	// https://computerarcheology.com/Arcade/SpaceInvaders/Hardware.html
	//f              0	bit
	//	xxxxxxxxyyyyyyyy

	//	Writing to Port 4 shifts x into y, and the new value into x, eg.
	//	$0000,
	//	write $aa->$aa00,
	//	write $ff->$ffaa,
	//	write $12->$12ff, ..
	//printf("PreShiftRegister: %4X\n", shift_register.get());
	uint16_t uint16_InitialShiftRegister = shift_register.get();
	uint16_t uint16_ShiftRegisterTemp = 0x0000;
	uint8_t uint8_ShiftLow = 0x00;
	uint8_t uint8_ShiftHigh = 0x00;

	uint8_ShiftLow = uint8_ShiftLow | uint16_InitialShiftRegister;
	uint8_ShiftHigh = uint8_ShiftHigh | (uint16_InitialShiftRegister >> 8);

	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp | cpu->io->output.get_port(4)->port_val.byte_val;
	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp << 0x08;
	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp | uint8_ShiftHigh;
		
	shift_register.set(uint16_ShiftRegisterTemp);
	//printf("PostShiftRegister: %4X\n", shift_register.get());

	//	Writing to Port 2 (bits 0, 1, 2) sets the offset for the 8 bit result, eg.
	
	uint8_t uint8_Offset = (cpu->io->output.get_port(2)->port_val.byte_val & 0x07);
	uint8_t uint8_RegisterTemp = 0x00;
	//printf("Offset: %4X\n", uint8_Offset);
	// 
	//	offset 0:
	//rrrrrrrr		result = xxxxxxxx
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x00) {
		uint8_RegisterTemp = shift_register.get() >> 0x08;
	}

	//	offset 1:
	//rrrrrrrr		result = xxxxxxxy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x01) {
		uint8_RegisterTemp = shift_register.get() >> 0x07;
	}

	//	offset 2 :
	//	rrrrrrrr	result = xxxxxxyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x02) {
		uint8_RegisterTemp = shift_register.get() >> 0x06;
	}

	//	offset 3:
	//rrrrrrrr		result = xxxxxyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x03) {
		uint8_RegisterTemp = shift_register.get() >> 0x05;
	}

	//	offset 4:
	//rrrrrrrr		result = xxxxyyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x04) {
		uint8_RegisterTemp = shift_register.get() >> 0x04;
	}

	//	offset 5:
	//rrrrrrrr		result = xxxyyyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x05) {
		uint8_RegisterTemp = shift_register.get() >> 0x03;
	}

	//	offset 6:
	//rrrrrrrr		result = xxyyyyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x06) {
		uint8_RegisterTemp = shift_register.get() >> 0x02;
	}

	//	offset 7 :
	//	rrrrrrrr	result = xyyyyyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x07) {
		uint8_RegisterTemp = shift_register.get() >> 0x01;
	}

	//	offset 8 :
	//	rrrrrrrr	result = yyyyyyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x08) {
		uint8_RegisterTemp = shift_register.get() >> 0x00;
	}

	cpu->io->input.get_port(3)->port_val.byte_val = uint8_RegisterTemp;
	// cpu->io->input.set(3, uint8_RegisterTemp);

}

/**
* [DESCRIPTION] Function to update the Sound Effects of the game
* Helpful links:	https://gigi.nullneuron.net/gigilabs/playing-a-wav-file-using-sdl2/
*					https://soundprogramming.net/programming/tutorial-using-sdl2-and-sdl_mixer-to-play-samples/
*/
void SpaceInvaders::updateSound()
{	
	//static bool soundUFO = false;
	static bool soundShot = false;
	static bool soundExplosion = false;
	static bool soundInvaderKilled = false;
	static bool soundInvader1 = false;
	static bool soundInvader2 = false;
	static bool soundInvader3 = false;
	static bool soundInvader4 = false;

	//Port 3: (discrete sounds)
	//bit 0 = UFO(repeats)        SX0 0.raw
	if ((cpu->io->output.get_port(3)->port_val.bit_struct.b0) == true) {
		Mix_PlayChannel(-1, wav_UFOHighPitchSoundEffect, 0);
	}

	////bit 1 = Shot                 SX1 1.raw
	if ((cpu->io->output.get_port(3)->port_val.bit_struct.b1) == true && !soundShot) {
		Mix_PlayChannel(-1, wav_ShotSoundEffect, 0);
		soundShot = true;
	}
	else if ((cpu->io->output.get_port(3)->port_val.bit_struct.b1) == false) {
		soundShot = false;
	}

	////bit 2 = Flash(player die)   SX2 2.raw
	if ((cpu->io->output.get_port(3)->port_val.bit_struct.b2) == true && !soundExplosion) {
		Mix_PlayChannel(-1, wav_ExplosionSoundEffect, 0);
		soundExplosion = true;
	}
	else if ((cpu->io->output.get_port(3)->port_val.bit_struct.b2) == false) {
		soundExplosion = false;
	}

	////bit 3 = Invader die          SX3 3.raw
	if ((cpu->io->output.get_port(3)->port_val.bit_struct.b3) == true && !soundInvaderKilled)
	{
		Mix_PlayChannel(-1, wav_InvaderKilledSoundEffect, 0);
		soundInvaderKilled = true;
	}
	else if ((cpu->io->output.get_port(3)->port_val.bit_struct.b3) == false) {
		soundInvaderKilled = false;
	}

	////Port 5 :
	////bit 0 = Fleet movement 1     SX6 4.raw
	if ((cpu->io->output.get_port(5)->port_val.bit_struct.b0) == true && !soundInvader1)
	{
		Mix_PlayChannel(-1, wav_FastInvader1SoundEffect, 0);
		soundInvader1 = true;
	}
	else if ((cpu->io->output.get_port(5)->port_val.bit_struct.b0) == false) {
		soundInvader1 = false;
	}

	////bit 1 = Fleet movement 2     SX7 5.raw
	if ((cpu->io->output.get_port(5)->port_val.bit_struct.b1) == true && !soundInvader2) 
	{
		Mix_PlayChannel(-1, wav_FastInvader2SoundEffect, 0);
		soundInvader2 = true;
	}
	else if ((cpu->io->output.get_port(5)->port_val.bit_struct.b1) == false) {
		soundInvader2 = false;
	}

	////bit 2 = Fleet movement 3     SX8 6.raw
	if ((cpu->io->output.get_port(5)->port_val.bit_struct.b2) == true && !soundInvader3)
	{
		Mix_PlayChannel(-1, wav_FastInvader3SoundEffect, 0);
		soundInvader3 = true;
	}
	else if ((cpu->io->output.get_port(5)->port_val.bit_struct.b2) == false) {
		soundInvader3 = false;
	}

	////bit 3 = Fleet movement 4     SX9 7.raw
	if ((cpu->io->output.get_port(5)->port_val.bit_struct.b3) == true && !soundInvader4)
	{
		Mix_PlayChannel(-1, wav_FastInvader4SoundEffect, 0);
		soundInvader4 = true;
	}
	else if ((cpu->io->output.get_port(5)->port_val.bit_struct.b3) == false) {
		soundInvader4 = false;
	}

	////bit 4 = UFO Hit              SX10 8.raw

}

/**
 * [DESCRIPTION] Display the instructions to the user
 *
*/
void SpaceInvaders::displayInstructions()
{
	SDL_Surface* imageLoader;
	SDL_Texture* instructions;
	bool exit_instructions = false;
	SDL_Event evnt;

	// load the correct instruction set
	if (gc_1 == NULL) {
		imageLoader = SDL_LoadBMP("SpaceInvaders/space_invaders_keyboard.bmp");
	}
	else {
		imageLoader = SDL_LoadBMP("SpaceInvaders/space_invaders_controller.bmp");
	}

	instructions = SDL_CreateTextureFromSurface(gwRenderer, imageLoader);
	SDL_RenderCopy(gwRenderer, instructions, NULL, NULL);
	SDL_RenderPresent(gwRenderer);

	// display the instructions on the screen until space OR a button 
	while (!exit_instructions) {
		while (SDL_PollEvent(&evnt) != 0) {
			if (evnt.type == SDL_KEYDOWN) {
				if (evnt.key.keysym.sym == SDLK_SPACE) {
					exit_instructions = true;
				}
			}
			else if (evnt.type == SDL_JOYBUTTONDOWN) {
				if (evnt.jbutton.button == 0) {
					exit_instructions = true;
				}
			}
		}
	}

	SDL_FreeSurface(imageLoader);
	SDL_DestroyTexture(instructions);
}

/**
 * [DESCRIPTION] Outside caller to initiate the game
 * 
*/
void SpaceInvaders::runGame()
{
	displayInstructions();

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

	// to setup the sound
	wav_ShotSoundEffect				= Mix_LoadWAV("SpaceInvaders/sound/shoot.wav");
	wav_ExplosionSoundEffect		= Mix_LoadWAV("SpaceInvaders/sound/explosion.wav");
	wav_FastInvader1SoundEffect		= Mix_LoadWAV("SpaceInvaders/sound/fastinvader1.wav");
	wav_FastInvader2SoundEffect		= Mix_LoadWAV("SpaceInvaders/sound/fastinvader2.wav");
	wav_FastInvader3SoundEffect		= Mix_LoadWAV("SpaceInvaders/sound/fastinvader3.wav");
	wav_FastInvader4SoundEffect		= Mix_LoadWAV("SpaceInvaders/sound/fastinvader4.wav");
	wav_InvaderKilledSoundEffect	= Mix_LoadWAV("SpaceInvaders/sound/invaderkilled.wav");
	wav_UFOHighPitchSoundEffect		= Mix_LoadWAV("SpaceInvaders/sound/ufo_highpitch.wav");
	wav_UFOLowPitchSoundEffect		= Mix_LoadWAV("SpaceInvaders/sound/ufo_lowpitch.wav");

	// enter the main game loop
	mainLoop();

	// when done clean up the bezel
	SDL_FreeSurface(siBezel);

	// clean up audio
	Mix_FreeChunk(wav_ShotSoundEffect);
	Mix_FreeChunk(wav_ExplosionSoundEffect);
	Mix_FreeChunk(wav_FastInvader1SoundEffect);
	Mix_FreeChunk(wav_FastInvader2SoundEffect);
	Mix_FreeChunk(wav_FastInvader3SoundEffect);
	Mix_FreeChunk(wav_FastInvader4SoundEffect);
	Mix_FreeChunk(wav_InvaderKilledSoundEffect);
	Mix_FreeChunk(wav_UFOHighPitchSoundEffect);
	Mix_FreeChunk(wav_UFOLowPitchSoundEffect);
	Mix_CloseAudio();
}

/**
 * [DESCRIPTION] Construct a new Space Invaders:: Space Invaders object
 * 
*/
SpaceInvaders::SpaceInvaders(SDL_Renderer* renderer, SDL_Joystick* gameController_1, SDL_Joystick* gameController_2)
{
	cpu = new i8080;
	gwRenderer = renderer;
	video_RAM = (unsigned int*)malloc(224 * 256 * 4);
	memset(video_RAM, 1, 224 * 256 * 4);
	mapActions();
	gc_1 = gameController_1;
	gc_2 = gameController_2;
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

/**
 * [DESCRIPTION] Map the space invader actions to the bit on the CPU 
 *	they correspond to
*/
void SpaceInvaders::mapActions()
{
	// Player 1 Commands
	act_fire_p1		= new Si_Action(cpu->io->input.get_port(1), 4);
	act_left_p1		= new Si_Action(cpu->io->input.get_port(1), 5);
	act_right_p1	= new Si_Action(cpu->io->input.get_port(1), 6);
	act_start_p1	= new Si_Action(cpu->io->input.get_port(1), 2);

	// Player 2 Commands
	act_fire_p2 = new Si_Action(cpu->io->input.get_port(2), 4);
	act_left_p2 = new Si_Action(cpu->io->input.get_port(2), 5);
	act_right_p2 = new Si_Action(cpu->io->input.get_port(2), 6);
	act_start_p2 = new Si_Action(cpu->io->input.get_port(1), 1);

	// General Commands
	act_tilt		= new Si_Action(cpu->io->input.get_port(2), 2);
	act_coin		= new Si_Action(cpu->io->input.get_port(1), 0);
}

/**
 * [DESCRIPTION] Start the desired action by setting the bit
 *
*/
void SpaceInvaders::Si_Action::start()
{
	port->set_bit(bit);
}

/**
 * [DESCRIPTION] Stop the desired action by unsetting the bit
 *
*/
void SpaceInvaders::Si_Action::stop()
{
	port->unset_bit(bit);
}

/**
 * [DESCRIPTION] Construct the action by passing to it the Port it belings to
 *
*/
SpaceInvaders::Si_Action::Si_Action(i8080::i8080_IO::IO::Port* p_port, unsigned char p_bit)
{
	port = p_port;
	bit  = p_bit;
}
