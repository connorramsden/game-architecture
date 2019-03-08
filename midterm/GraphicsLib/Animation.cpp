/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#include "Animation.h"

Animation::Animation()
{
	return;
}

Animation::Animation(GraphicsBuffer & src, Vector2D rowColNum, bool loopSheet)
{
	fillSpriteSheet(src, rowColNum);

	mShouldLoop = loopSheet;

	return;
}

Animation::~Animation()
{
	return;
}

void Animation::addSprite(GraphicsBuffer &src, Vector2D sprLoc, Vector2D sprDimensions)
{
	mSpriteSheet.push_back(Sprite(src, sprLoc.getX(), sprLoc.getY(), sprDimensions.getX(), sprDimensions.getY()));

	return;
}

void Animation::fillSpriteSheet(GraphicsBuffer & src, Vector2D rowColNum)
{
	// Clear the sprite sheet before filling it
	// Make sure to add this Animation to a Unit before calling this function
	mSpriteSheet.clear();

	// Temp Vector2D for storing sprite location
	// spriteLocation: X = xLocation && Y = yLocation
	Vector2D spriteLocation;

	// Temp Vector2D for storing sprite dimension
	// sprDimensions: X = WIDTH && Y = HEIGHT
	Vector2D sprDimensions;

	// Set up width & height of new sprite	
	// rowColNum: X = ROW && Y = COLUMN
	sprDimensions.setX(src.getWidth() / rowColNum.getY());
	sprDimensions.setY(src.getHeight() / rowColNum.getX());

	for (int spriteRow = 0; spriteRow < rowColNum.getY(); spriteRow++)
	{
		for (int spriteCol = 0; spriteCol < rowColNum.getX(); spriteCol++)
		{
			// Set up X & Y location for new sprite
			spriteLocation.setX(sprDimensions.getX() * spriteCol);
			spriteLocation.setY(sprDimensions.getY() * spriteRow);

			addSprite(src, spriteLocation, sprDimensions);
		}
	}

	// Set current sprite to 0th index
	mCurrentSprite = mSpriteSheet.at(0);

	return;
}

void Animation::animUpdate(double newSpeed)
{
	// Update speed of the sprite's movement
	updateAnimSpeed(newSpeed);

	// Ensures that sprite index will never go out of bounds
	// and increases keyframe by animSpeed
	if (mCurrentSprIndex < (int)mSpriteSheet.size() - 1)
	{
		if ((mCurrentSprIndex + mAnimSpeed) < (int)mSpriteSheet.size() - 1)
		{
			mCurrentSprIndex += mAnimSpeed;
		}
		else
		{
			mCurrentSprIndex++;
		}
		
	}
	else if (mCurrentSprIndex == (int)mSpriteSheet.size() - 1)
	{
		if (mShouldLoop)
		{
			mCurrentSprIndex = 0;
		}
	}

	// Update current sprite target
	mCurrentSprite = mSpriteSheet.at(mCurrentSprIndex);

	return;
}

void Animation::updateAnimSpeed(double newSpeed)
{
	mAnimSpeed = newSpeed;

	return;
}