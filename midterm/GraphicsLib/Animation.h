/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef ANIMATION_H
#define ANIMATION_H

// C/C++ Includes
#include <vector>

// DeanLib Includes
#include <Vector2D.h>

// GraphicsLib Includes
#include "Sprite.h"

class Animation : public Trackable
{
	friend class System;

public:
	// Default Animation Constructor
	Animation();

	// Specialized Animation Constructor
	Animation(GraphicsBuffer &src, Vector2D rowColNum, bool loopSheet);

	// Default Animation Deconstructor
	~Animation();

	// Add a new sprite to the spriteList
	void addSprite(GraphicsBuffer &src, Vector2D sprLoc, Vector2D sprDimensions);

	// Fill the spriteSheet from the source buffer
	void fillSpriteSheet(GraphicsBuffer &src, Vector2D rowColNum);

	// Update the sprite index & current sprite
	void animUpdate(double newSpeed);

	// Returns the current sprite
	Sprite getCurrentSprite() { return mCurrentSprite; }

	// Returns current Animation speed
	float getAnimSpeed() { return mAnimSpeed; }

	// Adjusts the speed of animation
	void updateAnimSpeed(double newSpeed);

private:
	// List of Sprites
	std::vector<Sprite> mSpriteSheet;

	// Speed at which animation plays
	double mAnimSpeed = 1.0;

	// Current sprite info
	// Index of spriteList vector where current sprite is
	int mCurrentSprIndex = 0;

	// Actual sprite that is currently selected
	Sprite mCurrentSprite;

	// Determines if an Animation should loop
	bool mShouldLoop = true;
};

#endif