/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

// Input Setup referenced from https://wiki.allegro.cc/index.php?title=Basic_Keyboard_Example

// GraphicsLib Includes
#include "System.h"

// Creates a new GraphicsSystem within this System
System::System()
{
	mpGraphicsSystem = new GraphicsSystem();

	return;
}

// Cleans up the system on delete
System::~System()
{
	systemCleanup();

	return;
}

// Initializes the system for gameplay use
void System::systemInit()
{
	// Initialize Allegro components
	initAllegroInput();

	// Start a new Allegro Event Queue
	mKeyboardQueue = al_create_event_queue();
	mMouseQueue = al_create_event_queue();

	// Register keyboard input with the new Event Queue
	al_register_event_source(mKeyboardQueue, al_get_keyboard_event_source());

	// Register mouse input with the new Event Queue
	al_register_event_source(mMouseQueue, al_get_mouse_event_source());

	// Initialize graphicsSystem with passed width & height
	mpGraphicsSystem->initialize(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	return;
}

// Initializes Allegro components for user input
void System::initAllegroInput()
{
	// Initialize Allegro.
	if (!al_init())
	{
		std::cout << "Error initializing Allegro!" << std::endl;
		return;
	}

	if (!al_init_primitives_addon())
	{
		std::cout << "Error initializing Allegro primitives addon!" << std::endl;

		system("pause");

		return;
	}

	if (!al_install_mouse())
	{
		std::cout << "Error initializing Allegro mouse addon!" << std::endl;

		system("pause");

		return;
	}

	if (!al_install_keyboard())
	{
		std::cout << "Error initializing Allegro keyboard addon!" << std::endl;

		system("pause");

		return;
	}

	return;
}

// Cleans up graphicsSystem when this object is being deleted
void System::systemCleanup()
{
	// Destroy the system mouse event queue
	al_destroy_event_queue(mMouseQueue);

	// Destroy the system keyboard event queue
	al_destroy_event_queue(mKeyboardQueue);

	// Clean-up Allegro components
	al_uninstall_mouse();

	al_uninstall_keyboard();

	// Call GraphicsSystem deconstructor
	delete mpGraphicsSystem;

	// Ensure GraphicsSystem is nullptr
	mpGraphicsSystem = nullptr;

	return;
}

// Returns index of keyboard button down
int System::getKeyState()
{
	ALLEGRO_EVENT keyInput;

	// Wait for 0.0001 seconds to set up a keyboard input
	al_wait_for_event_timed(mKeyboardQueue, &keyInput, 0.0001f);

	return keyInput.keyboard.keycode;
}

// TODO: Much more hacky / janky than keyboard input, not 100% sure why
// Returns index of mouse button down
int System::getMouseState()
{
	ALLEGRO_EVENT mouseInput;

	al_wait_for_event_timed(mMouseQueue, &mouseInput, 0.0001f);

	return mouseInput.mouse.button;
}