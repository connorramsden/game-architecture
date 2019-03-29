/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
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
InputTranslator::InputTranslator(EventSystem* pEventSystem)
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
void InputTranslator::handleEvent(const Event& eventToHandle)
{
	// Handles events dealing with keyboard input
	if (eventToHandle.getEventType() == KEYBOARD_EVENT)
	{
		const KeyboardEvent& kbEvent = static_cast<const KeyboardEvent&>(eventToHandle);

		// Events fired on key hold or press
		if (kbEvent.getInputState() == STATE_PRESSED)
		{
			switch (kbEvent.getKeyNum())
			{
				case W:
				{
					Vector2D moveDirection(0.0f, 1.0f);

					EventSystem::getEventSystemInstance()->fireEvent(MoveSnake(moveDirection));
					break;
				}
				case S:
				{
					Vector2D moveDirection(0.0f, -1.0f);
					EventSystem::getEventSystemInstance()->fireEvent(MoveSnake(moveDirection));

					break;
				}
				case A:
				{
					Vector2D moveDirection(-1.0f, 0.0f);

					EventSystem::getEventSystemInstance()->fireEvent(MoveSnake(moveDirection));

					break;
				}
				case D:
				{
					Vector2D moveDirection(1.0f, 0.0f);
					EventSystem::getEventSystemInstance()->fireEvent(MoveSnake(moveDirection));

					break;
				}
			}
		}
		// Events fired on key release
		else if (kbEvent.getInputState() == STATE_RELEASED)
		{
			switch (kbEvent.getKeyNum())
			{
				case ESCAPE:
					EventSystem::getEventSystemInstance()->fireEvent(ExitEvent());
					break;
				case SPACEBAR:
					EventSystem::getEventSystemInstance()->fireEvent(StartEvent());
					break;
			}
		}

	}
	//TODO Clean up mouse button input, not important for Snake
	else if (eventToHandle.getEventType() == MOUSEINPUT_EVENT)
	{
		const MouseEvent& mouseEvent = static_cast<const MouseEvent&>(eventToHandle);

		Vector2D mousePosition = mouseEvent.getMousePosition();

		if (mouseEvent.getInputState() == STATE_PRESSED || mouseEvent.getInputState() == STATE_HELD)
		{
			if (mouseEvent.getMouseNum() == LEFTBUTTON)
			{
				// EventSystem::getEventSystemInstance()->fireEvent(CreateUnit(mousePosition));
			}
			else if (mouseEvent.getMouseNum() == RIGHTBUTTON)
			{
				// EventSystem::getEventSystemInstance()->fireEvent(DeleteUnit(mousePosition));
			}
		}
	}

	return;
}