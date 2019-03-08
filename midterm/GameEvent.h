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
	CREATE_UNIT,
	DELETE_UNIT,
	MOVE_SNAKE,
};

class ExitEvent : public Event
{
public:
	ExitEvent()
		:Event((EventType)GameEventType::EXIT)
	{};
};

class CreateUnit : public Event
{
public:
	CreateUnit(Vector2D targetPos)
		:Event((EventType)GameEventType::CREATE_UNIT)
	{
		mCreatePosition = targetPos;
	};

	inline Vector2D getUnitPosition() const { return mCreatePosition; }

private:
	Vector2D mCreatePosition;
};

// TODO: DeleteUnit should function differently for snake
class DeleteUnit : public Event
{
public:
	DeleteUnit(Vector2D targetPos)
		:Event((EventType)GameEventType::DELETE_UNIT)
	{
		mDeletePosition = targetPos;
	};

	inline Vector2D getDestroyPosition() const { return mDeletePosition; }

private:
	Vector2D mDeletePosition;
};

class MoveSnake : public Event
{
public:
	MoveSnake()
		:Event((EventType)GameEventType::MOVE_SNAKE)
	{
	};

	inline Vector2D getMovementDirection() const { return mMovementDirection; }

private:
	Vector2D mMovementDirection;
};

#endif