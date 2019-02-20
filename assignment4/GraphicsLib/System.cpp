/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

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

	// Initialize first mouse position to center-screen
	mLastMousePos.setX(float(DISPLAY_WIDTH / 2));
	mLastMousePos.setY(float(DISPLAY_HEIGHT / 2));

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
	// Clean-up Allegro components
	al_uninstall_mouse();

	al_uninstall_keyboard();

	// Call GraphicsSystem deconstructor
	delete mpGraphicsSystem;

	// Ensure GraphicsSystem is nullptr
	mpGraphicsSystem = nullptr;

	return;
}

// Gets user keyboard input
void System::getKeyState()
{
	// Checks current keyboard state
	al_get_keyboard_state(&mKeyboardState);

	return;
}

// Gets user mouse input
void System::getMouseState()
{
	// Checks current mouse state
	al_get_mouse_state(&mMouseState);

	// if Mouse1 is pressed, move Unit to location
	if (mMouseState.buttons & 1)
	{
		mLastMousePos.setX(mMouseState.x);
		mLastMousePos.setY(mMouseState.y);
	}

	return;
}