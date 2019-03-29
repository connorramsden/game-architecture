/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
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
#include "EventSystem/MouseEvent.h"
#include "EventSystem/KeyboardEvent.h"

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

	inline Vector2D getMousePosition() const { return mMousePosition; }

private:
	bool mInputSystemInitialized = false;

	// Stores cursor x/y position in 2D space
	Vector2D mMousePosition;

	// Set mMousePosition x&y by passed values
	void setMousePosition(int newMouseX, int newMouseY);

	// Stores current Allegro input state
	ALLEGRO_KEYBOARD_STATE mKeyboardState;
	ALLEGRO_MOUSE_STATE mMouseState;

	// Stores last Allegro input state (Credit to Amelia Payne for the idea)
	ALLEGRO_KEYBOARD_STATE mPreviousKeyboardState;
	ALLEGRO_MOUSE_STATE mPreviousMouseState;

	// Used in updateInputSystem() to fire keyboard inputs
	void fireKeyboardEvent(KeyCode keyCode);

	// Used in updateInputSystem() to fire mouse inputs
	void fireMouseEvent(MouseCode mouseCode);
};

#endif