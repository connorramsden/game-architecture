/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#include "InputSystem.h"
#include "EventSystem.h"
#include "Event.h"

InputSystem::InputSystem()
{
	return;
}

InputSystem::~InputSystem()
{
	cleanupInputSystem();

	return;
}

void InputSystem::initInputSystem()
{
	if (!mInputSystemInitialized)
	{
		initAllegroInputComponents();
	}
	else
	{
		cleanupInputSystem();
	}

	// Store 'last' input state at system initialization
	al_get_keyboard_state(&mPreviousKeyboardState);
	al_get_mouse_state(&mPreviousMouseState);

	return;
}

void InputSystem::initAllegroInputComponents()
{
	// Initialize Allegro.
	if (!al_init())
	{
		std::cout << "Error initializing Allegro!" << std::endl;
		return;
	}

	if (!al_install_mouse())
	{
		std::cout << "Error initializing Allegro mouse addon!" << std::endl;

		system("pause");

		return;
	}

	if (!al_install_keyboard())
	{
		std::cout << "Error initializing Allegro keyboard addon!" << std::endl;

		system("pause");

		return;
	}

	mInputSystemInitialized = true;

	return;
}

void InputSystem::cleanupInputSystem()
{
	if (mInputSystemInitialized)
	{
		mInputSystemInitialized = false;

		// Clean-up Allegro components
		al_uninstall_mouse();
		al_uninstall_keyboard();
	}

	return;
}

void InputSystem::updateInputSystem()
{
	// Update keyboard & mouse states on Allegro side
	al_get_keyboard_state(&mKeyboardState);
	al_get_mouse_state(&mMouseState);

	// Update mouse position to current mouse position
	setMousePosition(mMouseState.x, mMouseState.y);

	// Fire current keyboard state
	// TODO: Modular fireKeyboardEvent, no need to account for all game keys
	fireKeyboardEvent(A);
	fireKeyboardEvent(D);
	fireKeyboardEvent(S);
	fireKeyboardEvent(W);
	fireKeyboardEvent(ESCAPE);
	fireKeyboardEvent(SPACEBAR);
	fireKeyboardEvent(ENTER);

	// Fire current mouse state
	fireMouseEvent(LEFTBUTTON);
	fireMouseEvent(RIGHTBUTTON);

	// Update previous input state to current input state
	mPreviousKeyboardState = mKeyboardState;
	mPreviousMouseState = mMouseState;

	return;
}

void InputSystem::setMousePosition(int newMouseX, int newMouseY)
{
	mMousePosition.setX(newMouseX);
	mMousePosition.setY(newMouseY);

	return;
}

void InputSystem::fireKeyboardEvent(KeyCode keyCode)
{
	if (al_key_down(&mKeyboardState, keyCode) && al_key_down(&mPreviousKeyboardState, keyCode))
	{
		EventSystem::getEventSystemInstance()->fireEvent(KeyboardEvent(keyCode, STATE_HELD));
	}
	else if (al_key_down(&mKeyboardState, keyCode) && !al_key_down(&mPreviousKeyboardState, keyCode))
	{
		EventSystem::getEventSystemInstance()->fireEvent(KeyboardEvent(keyCode, STATE_PRESSED));
	}
	else if (!al_key_down(&mKeyboardState, keyCode) && al_key_down(&mPreviousKeyboardState, keyCode))
	{
		EventSystem::getEventSystemInstance()->fireEvent(KeyboardEvent(keyCode, STATE_RELEASED));
	}
}

void InputSystem::fireMouseEvent(MouseCode mouseCode)
{
	if (mMouseState.buttons & mouseCode && mPreviousMouseState.buttons & mouseCode)
	{
		EventSystem::getEventSystemInstance()->fireEvent(MouseEvent(mouseCode, mMousePosition, STATE_HELD));
	}
	else if (mMouseState.buttons & mouseCode && !mPreviousMouseState.buttons & mouseCode)
	{
		EventSystem::getEventSystemInstance()->fireEvent(MouseEvent(mouseCode, mMousePosition, STATE_PRESSED));
	}
	else if (!mMouseState.buttons & mouseCode && mPreviousMouseState.buttons & mouseCode)
	{
		EventSystem::getEventSystemInstance()->fireEvent(MouseEvent(mouseCode, mMousePosition, STATE_RELEASED));
	}
}