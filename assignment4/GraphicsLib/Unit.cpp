/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

#include "Unit.h"

void Unit::addNewAnimation(Animation & newAnim)
{
	mUnitAnimations.push_back(new Animation(newAnim));
}

void Unit::drawUnit(int animToDraw)
{
	mCurrentAnimIndex = animToDraw;
	
	Sprite spr = mUnitAnimations.at(mCurrentAnimIndex)->getCurrentSprite();
}

void Unit::cleanupUnit()
{
	for (Animation *mpDeadAnim : mUnitAnimations)
	{
		delete mpDeadAnim;

		mpDeadAnim = nullptr;
	}
}

Unit::Unit(Vector2D &newPosition)
{
	mUnitPosition = newPosition;

	mUnitAnimations = std::vector<Animation *>();

	return;
}

Unit::~Unit()
{
	cleanupUnit();

	return;
}

