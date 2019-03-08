/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
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
	inline Animation *getCurrentAnimation() const { return mpCurrentAnimation; };

	// Returns the current unit position as a Vector2D
	inline Vector2D getUnitPosition() const { return mUnitPosition; };

	// Adds a new Animation to the Unit's animation sheet
	void addNewAnimation(Animation &newAnim);

	// Update the unit currently selected
	void updateUnit(const int currentUnitState);

	// Draw the unit's current animation to screen
	void drawUnit();

	// Determines if unit is colliding with the passed in point
	// Credit to Jacob Rose for this method
	bool isUnitColliding(Vector2D collisionPoint);

	// Cleans up the unit & its animation sheet
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