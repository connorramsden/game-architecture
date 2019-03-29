/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef GAMEEVENT_H
#define GAMEEVENT_H

// DeanLib Includes
#include <Vector2D.h>

// GraphicsLib Includes
#include <Event.h>

enum GameEventType
{
	EXIT = NUM_EVENT_TYPES,
	START_GAME,
	MOVE_SNAKE,
};

class ExitEvent : public Event
{
public:
	ExitEvent()
		:Event((EventType)GameEventType::EXIT)
	{};
};

class StartEvent : public Event
{
public:
	StartEvent()
		:Event((EventType)GameEventType::START_GAME)
	{};
};

class MoveSnake : public Event
{
public:
	MoveSnake(Vector2D newDirection)
		:Event((EventType)GameEventType::MOVE_SNAKE)
	{
		mMoveDirection = newDirection;
	};

	inline Vector2D getMoveDirection() const { return mMoveDirection; }

private:
	Vector2D mMoveDirection;
};

#endif