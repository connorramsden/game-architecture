/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef SNAKE_H
#define SNAKE_H

// C/C++ Includes
#include <vector>

// C/C++ Usings
using std::vector;

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// Game Class References
class Unit;

class Snake : public Trackable
{
#pragma region Public Functions
public:
	Snake(Vector2D initialDirection);
	~Snake() { return; }

	inline int getNumPieces() const { return mNumSnakePieces; }

	inline float getUnitLength() const { return UNIT_LENGTH; }

	inline void invertControls() { mAreControlsInverted = !mAreControlsInverted; }

	void setSnakeDirection(Vector2D newDirection);

	inline Vector2D getSnakeDirection() const { return mCurrentSnakeDirection; }

	inline Vector2D getHeadPosition() const { return mHeadPosition; }

	void addPieceToSnake();
	void updateSnake();
#pragma endregion

#pragma region Private Snake functions
private:
	void updateHeadAnim();
	void moveSnake();
	void checkCollisions();
	void checkPickupCollisions();
	void updateSnakePosition();
	bool isSnakeWithinBounds();
#pragma endregion

#pragma region Private Snake data
private:
	// Size of a single Snake body piece
	const float UNIT_LENGTH = 16.0f;

	// number of pieces the snake contains
	int mNumSnakePieces;

	bool mAreControlsInverted;

	// Store current head + all body part locations
	vector<Vector2D> mCurrentSnakeBody;
	// Store last head + all body part locations
	vector<Vector2D> mPreviousSnakeBody;

	// Store head position
	Vector2D mHeadPosition;
	// Store Tail position
	Vector2D mTailPosition;

	// Store current movement direction
	Vector2D mCurrentSnakeDirection;
	// Store last movement direction
	Vector2D mPreviousSnakeDirection;
#pragma endregion
};

#endif