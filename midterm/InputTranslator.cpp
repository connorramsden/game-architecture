/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

// Game Includes
#include "InputTranslator.h"
#include "GameEvent.h"

// GraphicsLib Includes
#include <EventSystem.h>
#include <Event.h>
#include <KeyboardEvent.h>
#include <MouseEvent.h>

int InputTranslator::msID = 0;

// Default InputTranslator Constructor
InputTranslator::InputTranslator(EventSystem *pEventSystem)
	:EventListener(pEventSystem)
	, mID(msID)
{
	msID++;
}

// Default InputTranslator Deconstructor
InputTranslator::~InputTranslator()
{
	cleanupInputTranslator();

	return;
}

// Initialize an EventSystem Instance with this listener
void InputTranslator::initInputTranslator()
{
	EventSystem::getEventSystemInstance()->addListener(KEYBOARD_EVENT, this);
	EventSystem::getEventSystemInstance()->addListener(MOUSEINPUT_EVENT, this);

	return;
}

// Remove this listener from an EventSystem instance
void InputTranslator::cleanupInputTranslator()
{
	EventSystem::getEventSystemInstance()->removeListener(MOUSEINPUT_EVENT, this);
	EventSystem::getEventSystemInstance()->removeListener(KEYBOARD_EVENT, this);

	return;
}

// Translate Allegro events into GameEvents
void InputTranslator::handleEvent(const Event &eventToHandle)
{
	if (eventToHandle.getEventType() == KEYBOARD_EVENT)
	{
		const KeyboardEvent &keyboardEvent = static_cast<const KeyboardEvent&>(eventToHandle);

		if (keyboardEvent.getInputState() == STATE_PRESSED)
		{
			if (keyboardEvent.getKeyNum() == ESCAPE)
			{
				EventSystem::getEventSystemInstance()->fireEvent(ExitEvent());
			}
		}		
		else if (keyboardEvent.getInputState() == STATE_RELEASED)
		{			
			if (keyboardEvent.getKeyNum() == ENTER)
			{
				EventSystem::getEventSystemInstance()->fireEvent(SpriteSwap());
			}
			else if (keyboardEvent.getKeyNum() == SPACEBAR)
			{
				EventSystem::getEventSystemInstance()->fireEvent(PauseUnits());
			}
		}
		
	}
	else if (eventToHandle.getEventType() == MOUSEINPUT_EVENT)
	{
		const MouseEvent &mouseEvent = static_cast<const MouseEvent&>(eventToHandle);

		Vector2D mousePosition = mouseEvent.getMousePosition();

		if (mouseEvent.getInputState() == STATE_PRESSED || mouseEvent.getInputState() == STATE_HELD)
		{
			if (mouseEvent.getMouseNum() == LEFTBUTTON)
			{
				EventSystem::getEventSystemInstance()->fireEvent(CreateUnit(mousePosition));
			}
			else if (mouseEvent.getMouseNum() == RIGHTBUTTON)
			{
				EventSystem::getEventSystemInstance()->fireEvent(DeleteUnit(mousePosition));
			}
		}
	}

	return;
}