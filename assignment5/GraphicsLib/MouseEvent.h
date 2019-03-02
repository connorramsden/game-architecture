/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

// DeanLib Includes
#include <Vector2D.h>

// GraphicsLib Includes
#include "Event.h"
#include "InputCodes.h"

class MouseEvent : public Event
{
public:
	MouseEvent(MouseCode mouseNum, Vector2D mousePos, EventInputState inputState);
	~MouseEvent();

	inline MouseCode getMouseNum() const { return mMouseCode; }

	inline Vector2D getMousePosition() const { return mMousePosition; }

	inline EventInputState getInputState() const { return mInputState; }

private:
	MouseCode mMouseCode;
	
	Vector2D mMousePosition;

	EventInputState mInputState;
};

#endif