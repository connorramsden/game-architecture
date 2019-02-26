/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

// Event System Includes
#include "InputTranslator.h"
#include "EventSystem.h"
#include "Event.h"

// Event Type Includes

int InputTranslator::msListenerID = 0;

InputTranslator::InputTranslator(EventSystem * pEventSystem)
	:EventListener(pEventSystem), mListenerID(msListenerID)
{
	initInputTranslator();

	return;
}

InputTranslator::~InputTranslator()
{
	cleanupInputTranslator();

	return;
}

void InputTranslator::initInputTranslator()
{
	msListenerID++;

	// ADD-LISTENER PER EVENT TYPE
}

void InputTranslator::cleanupInputTranslator()
{
}

void InputTranslator::handleEvent(const Event & eventToHandle)
{
	std::cout << std::endl << "ExampleListener #" << mListenerID << std::endl;

	std::cout << "\t" << eventToHandle.getEventName() << " Received";

	// TODO: Handle determined event types below
}