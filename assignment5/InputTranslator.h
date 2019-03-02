/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef INPUTTRANSLATOR_H
#define INPUTTRANSLATOR_H

// DeanLib Includes
#include <Trackable.h>

// GraphicsLib Includes
#include <EventListener.h>

// GraphicsLib Class References
class EventSystem;

class InputTranslator : public EventListener
{
public:
	InputTranslator(EventSystem *pEventSystem);
	~InputTranslator();

	void handleEvent(const Event &eventToHandle);

private:
	static int msID;

	int mID;
};

#endif