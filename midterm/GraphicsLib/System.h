/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// GraphicsLib Includes
#include "GraphicsSystem.h"
#include "Animation.h"
#include "InputSystem.h"

class System : public Trackable
{
public:
	// Default System Constructor
	System();

	// Default System Deconstructor
	~System();

	// Initializes System
	void systemInit();

	// Cleans up the System
	void systemCleanup();

	// Get the team-defined DISPLAY_WIDTH & DISPLAY_HEIGHT as a clean Vector2D
	inline Vector2D getDisplayDimensions() const { return Vector2D(DISPLAY_WIDTH, DISPLAY_HEIGHT); }

	inline Vector2D getCenterScreen() const { return Vector2D(DISPLAY_WIDTH / 2.0f, DISPLAY_HEIGHT / 2.0f); }
	
	// Return mpGraphicsSystem
	inline GraphicsSystem *getGraphicsSystem() const { return mpGraphicsSystem; }

	// Return mpInputSystem
	inline InputSystem *getInputSystem() const { return mpInputSystem; }

private:
	// Stores a GraphicsSystem object
	GraphicsSystem *mpGraphicsSystem = nullptr;

	// Stores an InputSystem object
	InputSystem *mpInputSystem = nullptr;

	// Display dimensions.
	const int DISPLAY_WIDTH = 1280;
	const int DISPLAY_HEIGHT = 720;
};

#endif