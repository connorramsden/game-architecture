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
	KEYBOARD_EVENT,
	MOUSE_EVENT,
	NUM_EVENT_TYPES
};

enum KeypressType
{
	INVALID_KEYPRESS = -1,
	KEY_DOWN,
	KEY_UP,
	KEY_HELD,
	NUM_KEYPRESS_TYPES
};

enum MousepressType
{
	INVALID_MOUSEPRESS = -1,
	MOUSE_DOWN,
	MOUSE_UP,
	MOUSE_HELD,
	NUM_MOUSEPRESS_TYPES
};

const std::string EVENT_NAMES[NUM_EVENT_TYPES] = 
{"Keyboard Event", "Mouse Event"};

const std::string KEYPRESS_NAMES[NUM_KEYPRESS_TYPES] =
{ "Key Down", "Key Up", "Key Held" };

const std::string MOUSEPRESS_NAMES[NUM_MOUSEPRESS_TYPES] =
{ "Mouse  Down", "Mouse Up", "Mouse Held" };

class Event : public Trackable
{
public:
	Event(EventType type);
	virtual ~Event();

	EventType getEventType() const { return mEventType; }

	KeypressType getInputType() const { return mKeypressType; }

	MousepressType getMousepressType() const { return mMousepressType; }

	const std::string & getEventName() const;
	const std::string & getKeypressName() const;
	const std::string & getMousepressName() const;

private:
	EventType mEventType;
	KeypressType mKeypressType;
	MousepressType mMousepressType;
};

#endif