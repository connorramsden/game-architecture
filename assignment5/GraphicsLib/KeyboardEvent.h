/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

// GraphicsLib Includes
#include "Event.h"
#include "InputCodes.h"

class KeyboardEvent : public Event
{
public:
	KeyboardEvent(KeyCode keyCode);
	KeyboardEvent(KeyCode keyCode, EventInputState inputState);
	~KeyboardEvent();

	inline KeyCode getKeyNum() const { return mKeyCode; }
	inline EventInputState getInputState() const { return mInputState; }

private:
	KeyCode mKeyCode;

	EventInputState mInputState;
};

#endif