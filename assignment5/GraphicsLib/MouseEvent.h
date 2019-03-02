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
	MouseEvent(MouseCode mouseNum, MousepressType mpType, Vector2D mousePos);
	~MouseEvent();

	inline MouseCode getMouseNum() const { return mMouseCode; }

	inline Vector2D getMousePosition() const { return mMousePosition; }

	inline MousepressType getMousepressType() const { return mMousepressType; }

private:
	MouseCode mMouseCode;
	
	Vector2D mMousePosition;
	
	MousepressType mMousepressType;
};

#endif