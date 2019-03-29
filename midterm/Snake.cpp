/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#include "Snake.h"
#include "Game.h"
#include "GraphicsBufferManager.h"
#include "UnitManager.h"
#include "PickupManager.h"
#include "DataManager.h"
#include "Unit.h"

// Default Snake Constructor
Snake::Snake(Vector2D initialLocation)
{
	// Initializes to -1 for proper vectorization
	mNumSnakePieces = -1;

	mAreControlsInverted = false;

	// Initialize Current & Previous Snake body vectors
	mCurrentSnakeBody = vector<Vector2D>();
	mPreviousSnakeBody = vector<Vector2D>();

	// Initialize the head & tail the passed starting location
	mTailPosition = mHeadPosition = initialLocation;

	return;
}

// Update the direction the snake is moving (Used in Game.cpp)
void Snake::setSnakeDirection(Vector2D newDirection)
{
	mPreviousSnakeDirection = mCurrentSnakeDirection;

	mCurrentSnakeDirection = newDirection;

	return;
}

// Add a new head || body piece to the Snake
void Snake::addPieceToSnake()
{
	// Iterate the number of units in Game's UnitManager map
	mNumSnakePieces++;

	// Get instances from Game
	Game* gameInstance = Game::getGameInstance();
	UnitManager* umInstance = gameInstance->getUnitManagerInstance();
	GraphicsBufferManager* gbmInstance = gameInstance->getGraphicsBufferManager();

	// If only the head exists
	if (mNumSnakePieces == 0)
	{
		// Push the snake head into the current body
		mCurrentSnakeBody.push_back(mHeadPosition);

		// Add the head to the Game's UnitManager map
		gameInstance->getUnitManagerInstance()->createAndManageUnit(mNumSnakePieces, mCurrentSnakeBody[mNumSnakePieces]);

		// Add the snake_head animation sheet
		gameInstance->
			getUnitManagerInstance()->
			addAnimationToUnit(mNumSnakePieces, Animation(*gbmInstance->getGraphicsBuffer(1), Vector2D(2.0f, 2.0f), false));
	}
	// Else if adding a body piece
	else if (mNumSnakePieces > 0)
	{
		float dirX = mCurrentSnakeDirection.getX();
		float dirY = mCurrentSnakeDirection.getY();

		// Add current tail to previous body
		mPreviousSnakeBody.push_back(mTailPosition);

		if (mNumSnakePieces > 1 && dirX != 0 && dirY != 0)
		{
			if (dirX == 1.0f)
				mCurrentSnakeBody.push_back(Vector2D(mTailPosition.getX() - UNIT_LENGTH, mTailPosition.getY()));
			if (dirX == -1.0f)
				mCurrentSnakeBody.push_back(Vector2D(mTailPosition.getX() + UNIT_LENGTH, mTailPosition.getY()));
			if (dirY == 1.0f)
				mCurrentSnakeBody.push_back(Vector2D(mTailPosition.getX(), mTailPosition.getY() + UNIT_LENGTH));
			if (dirY == -1.0f)
				mCurrentSnakeBody.push_back(Vector2D(mTailPosition.getX(), mTailPosition.getY() - UNIT_LENGTH));
		}
		else
			mCurrentSnakeBody.push_back(Vector2D(mTailPosition.getX(), mTailPosition.getY() + UNIT_LENGTH));

		// Update tail position to newly added body piece
		mTailPosition = mCurrentSnakeBody.back();

		// Add the new body piece to the Game's UnitManager Map
		umInstance->createAndManageUnit(mNumSnakePieces, mCurrentSnakeBody[mNumSnakePieces]);

		// Add the snake_body image to the new Unit
		gameInstance->
			getUnitManagerInstance()->
			addAnimationToUnit(mNumSnakePieces, Animation(*gbmInstance->
				getGraphicsBuffer(2), Vector2D(1.0f, 1.0f), false));
	}

	return;
}

// Update the movement direction, and adjust the head animation & body position accordingly.
void Snake::updateSnake()
{
	if (isSnakeWithinBounds())
	{
		moveSnake();
		checkCollisions();
		updateHeadAnim();
		updateSnakePosition();
	}
	else
		Game::getGameInstance()->exitToMenu();

	return;
}

// Update the snake body piece's Vector2D positions & their locations within the unit manager
void Snake::updateSnakePosition()
{
	Game* gameInstance = Game::getGameInstance();
	UnitManager* umInstance = gameInstance->getUnitManagerInstance();

	// Ensure that the previous snake body is as large as the current snake body
	if (mPreviousSnakeBody.size() < mCurrentSnakeBody.size())
		mPreviousSnakeBody.push_back(mTailPosition);
	else if (mPreviousSnakeBody.size() > mCurrentSnakeBody.size())
		mPreviousSnakeBody.pop_back();

	// Update the previous snake body prior to updating the current snake body
	for (int i = 0; i < (int)mPreviousSnakeBody.size() - 1; i++)
		mPreviousSnakeBody.at(i) = mCurrentSnakeBody.at(i);

	// Update the head position
	mCurrentSnakeBody[0] = mHeadPosition;
	umInstance->updateUnitInMap(0, mCurrentSnakeBody.at(0));

	// Update the rest of the body's position to the new 'current body' positioning
	for (int i = 1; i <= (int)mCurrentSnakeBody.size() - 1; i++)
	{
		// Update body render positions
		mCurrentSnakeBody.at(i) = mPreviousSnakeBody.at(i - 1);
		umInstance->updateUnitInMap(i, mCurrentSnakeBody.at(i));

		// body collision detection
		if (i > 1 && mCurrentSnakeBody[i] == mHeadPosition)
			// Exit to the main menu
			gameInstance->exitToMenu();
	}

	// Ensure the tail position is the last piece of the current body
	mTailPosition = mCurrentSnakeBody.back();

	return;
}

// Update the direction the head is facing based on movement
void Snake::updateHeadAnim()
{
	UnitManager* umInstance = Game::getUnitManagerInstance();

	float snakeX = mCurrentSnakeDirection.getX();
	float snakeY = mCurrentSnakeDirection.getY();

	if (!mAreControlsInverted)
	{
		if (snakeY == 1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(0);
		else if (snakeY == -1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(1);
		if (snakeX == 1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(3);
		else if (snakeX == -1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(2);
	}
	else
	{
		if (snakeY == 1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(1);
		else if (snakeY == -1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(0);
		if (snakeX == 1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(2);
		else if (snakeX == -1.0f)
			umInstance->getUnit(0)->getCurrentAnimation()->setCurrentSprite(3);
	}

	return;
}

// Adjust the snake's movement direction based on user input
void Snake::moveSnake()
{
	float prevX = mPreviousSnakeDirection.getX();
	float prevY = mPreviousSnakeDirection.getY();
	float currX = mCurrentSnakeDirection.getX();
	float currY = mCurrentSnakeDirection.getY();

	if (!mAreControlsInverted)
	{
		if (currY == 1.0f && prevY != -1.0f)
			mHeadPosition += Vector2D(0.0f, -UNIT_LENGTH);
		else if (currY == -1.0f && prevY != 1.0f)
			mHeadPosition += Vector2D(0.0f, UNIT_LENGTH);
		else if (currX == 1.0f && prevX != -1.0f)
			mHeadPosition += Vector2D(UNIT_LENGTH, 0.0f);
		else if (currX == -1.0f && prevX != 1.0f)
			mHeadPosition += Vector2D(-UNIT_LENGTH, 0.0f);
		else
			mCurrentSnakeDirection = mPreviousSnakeDirection;
	}
	else
	{
		if (currY == 1.0f && prevY != -1.0f)
			mHeadPosition += Vector2D(0.0f, UNIT_LENGTH);
		else if (currY == -1.0f && prevY != 1.0f)
			mHeadPosition += Vector2D(0.0f, -UNIT_LENGTH);
		else if (currX == 1.0f && prevX != -1.0f)
			mHeadPosition += Vector2D(-UNIT_LENGTH, 0.0f);
		else if (currX == -1.0f && prevX != 1.0f)
			mHeadPosition += Vector2D(UNIT_LENGTH, 0.0f);
		else
			// HACK: Breaks body collision detection
			mCurrentSnakeDirection = mPreviousSnakeDirection;
	}

	return;
}

// Check for all object collisions within the scene
void Snake::checkCollisions()
{
	checkPickupCollisions();

	return;
}

// Check for collisions with pickups
void Snake::checkPickupCollisions()
{
	Game* gameInstance = Game::getGameInstance();

	// Checks Game's mpsPickupManager for collisions
	// Check if there is a pick-up at the current head position
	// If yes, delete it (pick it up)
	int currUpdateOffset = gameInstance->getUpdateOffset();

	switch (Game::getPickupManager()->deletePickup(mHeadPosition))
	{
		case GROW:
			addPieceToSnake();
			break;
		case SPEED_UP:
			if (currUpdateOffset > 2)
				gameInstance->setUpdateOffset(currUpdateOffset - 2);
			else
				gameInstance->setUpdateOffset(2);
			break;
		case SLOW_DOWN:
			if (currUpdateOffset < 10)
				gameInstance->setUpdateOffset(currUpdateOffset + 2);
			else
				gameInstance->setUpdateOffset(10);
			break;
		case INVERT_CONTROLS:
			invertControls();
			break;
		case INVALID_PICKUP:
			break;
	}
}

// Ensure the snake is within the bounds of the screen
bool Snake::isSnakeWithinBounds()
{
	float snakeHeadX = mHeadPosition.getX();
	float snakeHeadY = mHeadPosition.getY();

	System* systemInstance = Game::getSystemInstance();

	float screenX = systemInstance->getDisplayDimensions().getX();
	float screenY = systemInstance->getDisplayDimensions().getY();

	if (snakeHeadY > 0 && snakeHeadY < screenY)
	{
		if (snakeHeadX > 0 && snakeHeadX < screenX)
			return true;
		else
			return false;
	}
	else
		return false;
}