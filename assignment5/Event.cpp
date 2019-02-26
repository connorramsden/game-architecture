/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "Event.h"

Event::Event(EventType type)
	:mType(type)
{}

Event::~Event()
{
	return;
}

const std::string & Event::getEventName() const
{
	if (mType > INVALID_EVENT_TYPE && mType < NUM_EVENT_TYPES)
	{
		return EVENT_NAMES[mType];
	}
	else
	{
		static const std::string nullString;

		return nullString;
	}
}