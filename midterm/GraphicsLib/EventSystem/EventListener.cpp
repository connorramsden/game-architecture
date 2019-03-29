/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
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
