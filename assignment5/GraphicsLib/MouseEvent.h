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

class MouseEvent : public Event
{
public:
	MouseEvent(int mouseNum, MousepressType mpType, Vector2D mousePos);
	~MouseEvent();

	inline int getMouseNum() const { return mMouseNum; }

	inline Vector2D getMousePosition() const { return mMousePosition; }

	inline MousepressType getMousepressType() const { return mMousepressType; }

private:
	int mMouseNum;
	
	Vector2D mMousePosition;
	
	MousepressType mMousepressType;
};

#endif