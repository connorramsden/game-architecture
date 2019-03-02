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

// GraphicsLib Includes
#include "InputCodes.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"

// GraphicsLib Class References
class Event;
class EventSystem;

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

	// Cleans up the Input System
	void cleanupInputSystem();

	// Dispatch events through an event system
	void updateInputSystem();
	// Get/Set the current mouse position
	Vector2D getMousePosition() { return mMousePosition; }
	void setMousePosition(int newMouseX, int newMouseY);

private:
	bool mInputSystemInitialized = false;

	// Stores cursor x/y position in 2D space
	Vector2D mMousePosition;

	ALLEGRO_KEYBOARD_STATE mKeyboardState;
	ALLEGRO_MOUSE_STATE mMouseState;

	// Used in updateInputSystem() to fire keyboard inputs
	void fireKeyboardEvent(ALLEGRO_KEYBOARD_STATE kbState);

	// Used in updateInputSystem() to fire mouse inputs
	void fireMouseEvent(ALLEGRO_MOUSE_STATE mouseState);
};

#endif