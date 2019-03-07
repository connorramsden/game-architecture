/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
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
