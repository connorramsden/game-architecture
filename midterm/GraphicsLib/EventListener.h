/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

// DeanLib Includes
#include <Trackable.h>

// EventSystem Classes
class Event;
class EventSystem;

class EventListener : public Trackable
{
public:
	// Default EventListener Constructor
	EventListener(EventSystem *pEventSystem);

	// Virtual EventListener Deconstructor
	virtual ~EventListener();

	virtual void handleEvent(const Event &eventToHandle) = 0;

private:
	// Points to the EventSystem this listener is listening to
	EventSystem *mpEventSystem;

protected:
	// Return mpEventSystem
	EventSystem *getEventSystem() const { return mpEventSystem; }
};

#endif