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

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// Allegro Includes
#include <allegro5/allegro.h>
#include <allegro5/mouse.h>
#include <allegro5/mouse_cursor.h>
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
	void systemInit(int displayWidth, int displayHeight);

	// Initializes Allegro components for user input
	void initAllegroInput();

	// Cleans up the System
	void systemCleanup();

	// Gets user keyboard input
	void getKeyState();

	// Gets user mouse input
	void getMouseState();

	// Returns graphicsSystem
	GraphicsSystem *getGraphicsSystem() { return graphicsSystem; }

	// Returns last known mouse position
	Vector2D getMousePosition() { return lastMousePos; }

	// TODO: Clean up functions when keypress / mouse state is fixed
	// Functions accessed by Game
	// returns game state to determine if game loop should continue or stop
	bool getGameState() { return loopController; }

	double getAnimSpeed() { return animSpeed; }

	int getUnitToDisplay() { return unitToDisplay; }
	
private:
	// Stores a GraphicsSystem object
	GraphicsSystem *graphicsSystem = nullptr;

	// Resolves user mouse input calls
	ALLEGRO_MOUSE_STATE mouseState;

	// Resolves user keyboard input calls
	ALLEGRO_KEYBOARD_STATE keyboardState;

	// Stores last known mouse position
	Vector2D lastMousePos;

	// TODO: Clean up variables when keypress / mouse state is fixed
	// Variables pass to Game
	// Determines if game should run or stop
	bool loopController = true;

	double animSpeed = 1.0;

	int unitToDisplay = 0;
};

#endif