/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

// GraphicsLib Includes
#include "System.h"

// Creates a new GraphicsSystem within this System
System::System()
{
	mpGraphicsSystem = new GraphicsSystem();

	mpInputSystem = new InputSystem();

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
	// Initialize Input System
	mpInputSystem->initInputSystem();

	// Initialize graphicsSystem with passed width & height
	mpGraphicsSystem->initialize(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	return;
}

// Cleans up graphicsSystem when this object is being deleted
void System::systemCleanup()
{
	// Call InputSystem deconstructor
	delete mpInputSystem;

	// Ensure InputSystem is null'd
	mpInputSystem = nullptr;

	// Call GraphicsSystem deconstructor
	delete mpGraphicsSystem;

	// Ensure GraphicsSystem is null'd
	mpGraphicsSystem = nullptr;

	return;
}