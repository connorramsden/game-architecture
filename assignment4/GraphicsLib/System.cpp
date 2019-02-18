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
	graphicsSystem = new GraphicsSystem();

	return;
}

// Cleans up the system on delete
System::~System()
{
	systemCleanup();

	return;
}

// Initializes the system for gameplay use
void System::systemInit(int displayWidth, int displayHeight)
{
	// Initialize Allegro components
	initAllegroInput();

	// Initialize first mouse position to center-screen
	lastMousePos.setX(float(displayWidth / 2));
	lastMousePos.setY(float(displayHeight / 2));

	// Initialize graphicsSystem with passed width & height
	graphicsSystem->initialize(displayWidth, displayHeight);

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
	delete graphicsSystem;

	// Ensure GraphicsSystem is nullptr
	graphicsSystem = nullptr;

	return;
}

// Gets user keyboard input
void System::getKeyState()
{	// TODO: Expand to all possible key-presses, instead of these 4

	// Checks current keyboard state
	al_get_keyboard_state(&keyboardState);


	// If F is pressed, respond accordingly
	if (al_key_down(&keyboardState, ALLEGRO_KEY_F))
	{
		animSpeed += 0.1;
	}

	// if S is pressed, respond accordingly
	if (al_key_down(&keyboardState, ALLEGRO_KEY_S))
	{
		if (animSpeed > 1.0)
		{
			animSpeed -= 0.1;
		}
	}

	// if Enter is pressed, respond accordingly
	if (al_key_down(&keyboardState, ALLEGRO_KEY_ENTER))
	{
		if (unitToDisplay == 0)
		{
			unitToDisplay = 1;
		}
		else
		{
			unitToDisplay = 0;
		}
	}

	// if Escape is pressed, shut down the System
	if (al_key_down(&keyboardState, ALLEGRO_KEY_ESCAPE))
	{
		loopController = false;
	}

	return;
}

// Gets user mouse input
void System::getMouseState()
{
	// Checks current mouse state
	al_get_mouse_state(&mouseState);

	// if Mouse1 is pressed, move Unit to location
	if (mouseState.buttons & 1)
	{
		lastMousePos.setX(mouseState.x);
		lastMousePos.setY(mouseState.y);
	}

	return;
}