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

// C/C++ Includes
#include <string>

// DeanLib Includes
#include <Trackable.h>

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	KEY_EVENT,
	MOUSE_EVENT,
	NUM_EVENT_TYPES
};

const std::string EVENT_NAMES[NUM_EVENT_TYPES] = 
{ "Key Event", "Mouse Event" };

class Event : public Trackable
{
public:
	Event(EventType type);
	virtual ~Event();

	EventType getType() const { return mType; }

	const std::string & getEventName() const;

private:
	EventType mType;
};

#endif