/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

// Input Setup referenced from https://wiki.allegro.cc/index.php?title=Basic_Keyboard_Example

#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// Allegro Includes
#include <allegro5/allegro.h>
#include <allegro5/mouse.h>
#include <allegro5/keyboard.h>

class InputSystem : public Trackable
{
public:
	// Default InputSystem Constructor
	InputSystem();

	// Default InputSystem Deconstructor
	~InputSystem();

	// Initializes 
	void initAllegroInputComponents();

	// Initializes InputSystem
	void initInputSystem();

	void cleanupInputSystem();

	// Gets user keyboard input
	int getKeyState();

	void fireKeyboardEvent();

	// Gets user mouse input
	int getMouseState();

	Vector2D getMousePosition() { return mMousePosition; }
	void setMousePosition(int newMouseX, int newMouseY);

private:
	bool mInputSystemInitialized = false;

	// Stores keyboard inputs in an Allegro event queue
	ALLEGRO_EVENT_QUEUE *mKeyboardQueue;

	// Retrieves mouse state at time of access
	ALLEGRO_MOUSE_STATE mMouseState;

	// Retrieves keyboard state at time of access
	ALLEGRO_KEYBOARD_STATE mKeyboardState;

	Vector2D mMousePosition;
};

#endif