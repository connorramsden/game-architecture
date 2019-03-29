/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef UNIT_H
#define UNIT_H

// C/C++ Using

// GraphicsLib Includes
#include <Animation.h>

class Unit : public Trackable
{
	friend class UnitManager;
	friend class PickupManager;
	friend class Snake;

public:
	// Public Unit Accessors
	inline std::vector<Animation *> getAnimations() const { return mUnitAnimations; };
	inline Animation *getCurrentAnimation() const { return mpCurrentAnimation; };

	// Returns the current unit position as a Vector2D
	inline Vector2D getUnitPosition() const { return mUnitPosition; };

	// Update the current unit position with the passed Vector2D
	inline void setUnitPosition(Vector2D newPos) { mUnitPosition = newPos; }

	// Adds a new Animation to the Unit's animation sheet
	void addNewAnimation(Animation &newAnim);

	// Draw the unit's current animation to screen
	void drawUnit(float unitScale = 1.0f);

	void updateUnitAnim(int newAnimIndex);

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