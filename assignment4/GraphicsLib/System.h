/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

#ifndef SYSTEM_H
#define SYSTEM_H

// C/C++ includes
#include <tuple>

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// Allegro Includes
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/mouse.h>
#include <allegro5/keyboard.h>

// GraphicsLib Includes
#include "GraphicsSystem.h"
#include "Animation.h"

class System : public Trackable
{
public:
	// Default System Constructor
	System();

	// Default System Deconstructor
	~System();

	// Initializes System
	void systemInit();

	// Initializes Allegro components for user input
	void initAllegroInput();

	// Cleans up the System
	void systemCleanup();

	// Gets user keyboard input
	int getKeyState();

	// Gets user mouse input
	int getMouseState();

	// Returns graphicsSystem
	GraphicsSystem *getGraphicsSystem() { return mpGraphicsSystem; }

	// Returns last known mouse position
	Vector2D getMousePosition() { return mLastMousePos; }

	// Sets mLastMousePos X&Y
	void setMousePosition(int xPos, int yPos);

private:
	// Stores a GraphicsSystem object
	GraphicsSystem *mpGraphicsSystem = nullptr;

	// Resolves user mouse input calls
	ALLEGRO_MOUSE_STATE mMouseState;

	// Resolves user keyboard input calls
	ALLEGRO_KEYBOARD_STATE mKeyboardState;

	ALLEGRO_EVENT_QUEUE *mKeyboardQueue;
	ALLEGRO_EVENT_QUEUE *mMouseQueue;

	// Stores last known mouse position
	Vector2D mLastMousePos;

	// Display dimensions.
	const int DISPLAY_WIDTH = 800;
	const int DISPLAY_HEIGHT = 600;
};

#endif