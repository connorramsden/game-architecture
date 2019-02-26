/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "EventListener.h"
#include "EventSystem.h"

EventListener::EventListener(EventSystem * pEventSystem)
	:mpEventSystem(pEventSystem)
{}

EventListener::~EventListener()
{
	mpEventSystem->removeListenerFromAllEvents(this);
}
