/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#include "MouseEvent.h"

MouseEvent::MouseEvent(MouseCode mouseCode, Vector2D mousePos, EventInputState inputState)
	:Event(MOUSEINPUT_EVENT)
	,mMouseCode(mouseCode)
	,mMousePosition(mousePos)
	,mInputState(inputState)
{}

MouseEvent::~MouseEvent()
{}
