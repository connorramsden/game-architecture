/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
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
	SPRITE_SWAP,
	PAUSE_UNITS,
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

class SpriteSwap : public Event
{
public:
	SpriteSwap()
		:Event((EventType)GameEventType::SPRITE_SWAP)
	{};
};

class PauseUnits : public Event
{
public:
	PauseUnits()
		:Event((EventType)GameEventType::PAUSE_UNITS)
	{};
};

#endif