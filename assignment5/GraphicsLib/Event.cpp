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
	:mEventType(type)
{}

Event::~Event()
{
	return;
}

const std::string & Event::getEventName() const
{
	if (mEventType > INVALID_EVENT_TYPE && mEventType < NUM_EVENT_TYPES)
	{
		return EVENT_NAMES[mEventType];
	}
	else
	{
		static const std::string nullString;

		return nullString;
	}
}

const std::string & Event::getKeypressName() const
{
	if (mKeypressType > INVALID_KEYPRESS && mKeypressType < NUM_KEYPRESS_TYPES)
	{
		return KEYPRESS_NAMES[mKeypressType];
	}
	else
	{
		static const std::string nullString;

		return nullString;
	}
}

const std::string & Event::getMousepressName() const
{
	if (mMousepressType > INVALID_MOUSEPRESS && mMousepressType < NUM_MOUSEPRESS_TYPES)
	{
		return MOUSEPRESS_NAMES[mMousepressType];
	}
	else
	{
		static const std::string nullString;

		return nullString;
	}
}
