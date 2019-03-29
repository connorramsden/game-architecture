/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#include "Unit.h"
#include "Game.h"

// Add a new Animation to mUnitAnimations
void Unit::addNewAnimation(Animation & newAnim)
{
	// If this is the first animation being added to the unit,
	if (mUnitAnimations.empty())
	{
		mUnitAnimations.push_back(new Animation(newAnim));
		mpCurrentAnimation = mUnitAnimations.at(0);
	}
	else
	{
		mUnitAnimations.push_back(new Animation(newAnim));
	}
}

void Unit::drawUnit(float unitScale)
{
	Sprite spr = mpCurrentAnimation->getCurrentSprite();
	System* systemInstance = Game::getSystemInstance();

	if (unitScale != 1.0f)
	{
		systemInstance->getGraphicsSystem()->drawScaledSprite(spr, mUnitPosition.getX(), mUnitPosition.getY(), unitScale);
	}
	else
	{
		systemInstance->getGraphicsSystem()->draw(spr, mUnitPosition.getX(), mUnitPosition.getY());
	}

	return;
}

void Unit::updateUnitAnim(int newAnimIndex)
{
	if (mUnitAnimations.empty())
	{
		std::cout << "Animation sheet empty, BUG" << std::endl;
		return;
	}
	else
	{
		mpCurrentAnimation = mUnitAnimations.at(newAnimIndex);
	}
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