/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
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
	Sprite getCurrentSprite() { return currentSprite; }

	// Returns current Animation speed
	float getAnimSpeed() { return animSpeed; }

	// Adjusts the speed of animation
	void updateAnimSpeed(double newSpeed);

private:
	// List of Sprites
	std::vector<Sprite> spriteSheet;

	// Speed at which animation plays
	double animSpeed = 1.0;

	// Current sprite info
	// Index of spriteList vector where current sprite is
	int currentSprIndex = 0;

	// Actual sprite that is currently selected
	Sprite currentSprite;

	// Determines if an Animation should loop
	bool shouldLoop = true;
};

#endif