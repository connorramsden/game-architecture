/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "InputSystem.h"
#include "EventSystem.h"
#include "Event.h"

InputSystem::InputSystem()
{
	return;
}

InputSystem::~InputSystem()
{
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
		cleanupInputSystem();
	}

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

void InputSystem::cleanupInputSystem()
{
	// Clean-up Allegro components
	al_uninstall_mouse();
	al_uninstall_keyboard();

	return;
}

void InputSystem::updateInputSystem()
{
	
}

void InputSystem::setMousePosition(int newMouseX, int newMouseY)
{
	mMousePosition.setX(newMouseX);
	mMousePosition.setY(newMouseY);

	return;
}