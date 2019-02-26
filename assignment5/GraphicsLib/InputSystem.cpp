/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "InputSystem.h"

InputSystem::InputSystem()
{
	return;
}

InputSystem::~InputSystem()
{
	inputCleanup();

	return;
}

void InputSystem::initInputSystem()
{
	if (!mInputSystemInitialized)
	{
		initAllegroInputComponents();
	}
	else
	{
		inputCleanup();
	}

	// TODO: Rest of IS initialization requirements
	// Create a new Allegro Event Queue
	mKeyboardQueue = al_create_event_queue();

	// Register keyboard input into the IS event queue
	al_register_event_source(mKeyboardQueue, al_get_keyboard_event_source());

	return;
}

void InputSystem::initAllegroInputComponents()
{
	// Initialize Allegro.
	if (!al_init())
	{
		std::cout << "Error initializing Allegro!" << std::endl;
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

	mInputSystemInitialized = true;

	return;
}

void InputSystem::inputCleanup()
{
	// Un-register keyboard input with the system event queue
	al_unregister_event_source(mKeyboardQueue, al_get_keyboard_event_source());

	// Destroy the system keyboard event queue
	al_destroy_event_queue(mKeyboardQueue);

	// Clean-up Allegro components
	al_uninstall_mouse();
	al_uninstall_keyboard();
}

// Returns index of keyboard button down
int InputSystem::getKeyState()
{
	// Update the current keyboard state
	al_get_keyboard_state(&mKeyboardState);

	// Event managing keyboard input
	ALLEGRO_EVENT keyInput;

	// Wait for 0.0001 seconds to set up a keyboard input
	al_wait_for_event_timed(mKeyboardQueue, &keyInput, 0.0001f);

	return keyInput.keyboard.keycode;
}

// Returns index of mouse button down
int InputSystem::getMouseState()
{
	// Get the current mouse state
	al_get_mouse_state(&mMouseState);

	// Update mouse position
	setMousePosition(mMouseState.x, mMouseState.y);

	// Return any mouse buttons triggered at this time
	return mMouseState.buttons;
}

void InputSystem::setMousePosition(int newMouseX, int newMouseY)
{
	mMousePosition.setX(newMouseX);
	mMousePosition.setY(newMouseY);

	return;
}