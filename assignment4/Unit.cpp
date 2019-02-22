/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

#include "Unit.h"
#include "Game.h"

// Add a new Animation to mUnitAnimations
void Unit::addNewAnimation(Animation & newAnim)
{
	mUnitAnimations.push_back(new Animation(newAnim));
}

void Unit::updateUnit(const int currentUnitState)
{
	mpCurrentAnimation = mUnitAnimations.at(currentUnitState);

	std::cout << "UU Debug\n";
}

void Unit::drawUnit()
{
	Sprite spr = mpCurrentAnimation->getCurrentSprite();

	std::cout << "DU Debug\n";

	// BREAKING HERE
	// COME BACK IN MORNING
	gpGame->getSystemInstance()->getGraphicsSystem()->draw(spr, 400, 300);
}

// Loop through all Animation(s) in mUnitAnimations
// and delete + null each one
void Unit::cleanupUnit()
{
	for (Animation *mpDeadAnim : mUnitAnimations)
	{
		delete mpDeadAnim;

		mpDeadAnim = nullptr;
	}
}

// Default Unit Constructor
Unit::Unit()
{
	mUnitAnimations = std::vector<Animation *>();

	mpCurrentAnimation = nullptr;

	return;
}

// Unit Constructor with Position(V2D)
Unit::Unit(Vector2D &newPosition)
{
	mUnitPosition = newPosition;

	mUnitAnimations = std::vector<Animation *>();

	mpCurrentAnimation = nullptr;

	return;
}

// Default Unit Deconstructor
Unit::~Unit()
{
	cleanupUnit();

	return;
}

/*
void Unit::drawUnit(int animToDraw)
{
	currentAnimIndex = animToDraw;

	Sprite spr = unitAnimSet.at(currentAnimIndex)->getCurrentSprite();

	Vector2D unitPos = gpGame->getGameSystem()->getMousePosition();

	gpGame->getGameSystem()->getGraphicsSystem()->draw(spr, unitPos.getX(), unitPos.getY());
}
*/