/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef SPRITE_H
#define SPRITE_H

// GraphicsLib Includes
#include "GraphicsBuffer.h"

class Sprite : public Trackable
{
public:
	// Default constructor.
	Sprite();

	// Copy constructor.
	Sprite(const Sprite & _oldSprite);

	// Create a sprite with the given specifications.
	Sprite(GraphicsBuffer &_pBuffer, int _sourceX, int _sourceY, int _width, int _height);

	// Clean up the sprite instance.
	~Sprite();

	// Get the source x location on the buffer.
	int getSourceX();

	// Get the source y location on the buffer.
	int getSourceY();

	// Get the width.
	int getWidth();

	// Get the height.
	int getHeight();

	// Get the buffer associated with this sprite.
	GraphicsBuffer &getBuffer();

private:
	// Graphics buffer associated with this sprite.
	GraphicsBuffer *mpBuffer;

	// Source x location of the sprite on the buffer.
	int mSourceX;

	// Source y location of the sprite on the buffer.
	int mSourceY;

	// Width of the sprite.
	int mWidth;

	// Height of the sprite.
	int mHeight;
};

#endif