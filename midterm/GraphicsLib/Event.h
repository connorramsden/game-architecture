/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef EVENT_H
#define EVENT_H

// DeanLib Includes
#include <Trackable.h>

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	KEYBOARD_EVENT,
	MOUSEINPUT_EVENT,
	NUM_EVENT_TYPES
};

enum EventInputState
{
	STATE_INVALID = -1,
	STATE_PRESSED,
	STATE_RELEASED,
	STATE_HELD,
	NUM_STATE
};

class Event : public Trackable
{
public:
	Event(EventType type);
	
	virtual ~Event();

	EventType getEventType() const { return mEventType; }

private:
	EventType mEventType;
};

#endif