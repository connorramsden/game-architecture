/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
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