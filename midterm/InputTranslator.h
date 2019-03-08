/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
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
	// Default InputTranslator Constructor
	InputTranslator(EventSystem *pEventSystem);

	// Default InputTranslator Deconstructor
	~InputTranslator();

	// Initialize an instance of this class
	void initInputTranslator();

	// Clean up an instance of this class
	void cleanupInputTranslator();

	// Handles / translates incoming events
	void handleEvent(const Event &eventToHandle);

private:
	static int msID;

	int mID;
};

#endif