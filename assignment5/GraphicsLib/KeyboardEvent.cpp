/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "KeyboardEvent.h"

KeyboardEvent::KeyboardEvent(KeyCode keyCode)
	:Event(KEYBOARD_EVENT)
	,mKeyCode(keyCode)
{}

KeyboardEvent::KeyboardEvent(KeyCode keyCode, EventInputState inputState)
	:Event(KEYBOARD_EVENT)
	, mKeyCode(keyCode)
	, mInputState(inputState)
{}

KeyboardEvent::~KeyboardEvent()
{}