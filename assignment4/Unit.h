/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

#ifndef UNIT_H
#define UNIT_H

// GraphicsLib Includes
#include <Animation.h>

class Unit : public Trackable
{
	friend class UnitManager;

public:
	// Public Unit Accessors
	inline std::vector<Animation *> getAnimations() const { return mUnitAnimations; };

	inline Vector2D getUnitPosition() const { return mUnitPosition; };

	void addNewAnimation(Animation &newAnim);

	void drawUnit();
	
	void cleanupUnit();

private:
	Unit();
	Unit(Vector2D &newPosition);
	~Unit();

	std::vector<Animation *> mUnitAnimations;

	Animation *mpCurrentAnimation;

	Vector2D mUnitPosition;
};

#endif

/*

void Unit::drawUnit(int animToDraw)
{
	currentAnimIndex = animToDraw;

	Sprite spr = unitAnimSet.at(currentAnimIndex)->getCurrentSprite();

	Vector2D unitPos = gpGame->getGameSystem()->getMousePosition();

	gpGame->getGameSystem()->getGraphicsSystem()->draw(spr, unitPos.getX(), unitPos.getY());
}
*/