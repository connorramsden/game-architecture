/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

#ifndef GAME_H
#define GAME_H

// C/C++ Includes
#include <vector>
#include <string>
#include <assert.h>

// DeanLib Includes
#include <Timer.h>
#include <PerformanceTracker.h>

// Game Includes
#include "UnitManager.h"
#include "GraphicsBufferManager.h"

// GraphicsLib Includes
#include <System.h>

// Asset locations / file names for use in the Game
// Real game would have a better asset management system
const std::string ASSET_PATH = "..\\..\\shared\\assets\\";
const std::string WOODS_FILENAME = "woods.png";
const std::string SMURF_SPRITE_FILENAME = "smurf_sprites.png";
const std::string DEAN_SPRITE_FILENAME = "dean_sprites.png";

// Number of rows & columns per sprite-sheet, standardized across the Game
const int SPRITESHEET_ROW_COUNT = 4;
const int SPRITESHEET_COLUMN_COUNT = 4;

// Indexing for vector storage
const int SMURF_SPRITE_INDEX = 0;
const int DEAN_SPRITE_INDEX = 1;
const int BACKGROUND_INDEX = 2;

class Game : public Trackable
{
public:
	// System / Manager Accessors
	static Game *getGameInstance();
	static System *getSystemInstance();
	static UnitManager *getUnitManagerInstance();
	static GraphicsBufferManager *getGraphicsBufferManager();

	// Performance Accessors
	static PerformanceTracker *getPerformanceTrackerInstance();
	static Timer *getTimerInstance();

	// Game Instance Init / Cleanup
	static void initInstance();
	static void cleanupInstance();

	// Game Init / Cleanup
	static void initGame();
	static void cleanupGame();

	// Game Operations
	static void initGameLoop();
	static void runGameLoop();
	static void stopGameLoop();

	// Retrieve user input from KB&M
	static void getUserInput();

	// Update all game objects
	static void updateLoop();

	// Render all game objects and backgrounds to the display
	static void renderToDisplay();

private:
	// Default Game Constructor
	Game();

	// Default Game Deconstructor
	~Game();

	// An instance of the Game class
	static Game *mpsGameInstance;

	// An instance of the System class, referenced by the Game
	static System *mpsSystemInstance;

	// An instance of the UnitManager class, referenced by the Game
	static UnitManager *mpsUnitManager;
	
	// A reference the the GraphicsBufferManager class, referenced by the Game
	static GraphicsBufferManager *mpsGraphicsBufferManager;

	// Game Performance Tracker
	static PerformanceTracker *mpPerformanceTrackerInstance;

	// Game Timer
	static Timer *mpTimerInstance;
};

#endif

/*
// Initializes the Game system
void Game::gameInit(int displayWidth, int displayHeight)
{
	// Instantiate the gameSystem
	gameSystem = new System();

	// Initialize the new System
	gameSystem->systemInit(displayWidth, displayHeight);

	// Initialize the GraphicsBuffer vector
	gameBuffers = std::vector<GraphicsBuffer *>();

	// Push back graphics buffers for to-screen display
	addNewBuffer(ASSET_PATH, SMURF_SPRITE_FILENAME);
	addNewBuffer(ASSET_PATH, DEAN_SPRITE_FILENAME);
	addNewBuffer(ASSET_PATH, WOODS_FILENAME);

	// Create the default Unit at center-screen
	Unit *smurfUnit = new Unit(gameSystem->getMousePosition());

	// Initialize the Unit vector
	gameObjects = std::vector<Unit *>();

	// Initialize animation vector
	animSet = std::vector<Animation *>();

	// Create an animation set from SMURF_SPRITE_FILENAME
	animSet.push_back(new Animation(*gameBuffers.at(SMURF_SPRITE_INDEX), Vector2D(SPRITESHEET_ROW_COUNT, SPRITESHEET_COLUMN_COUNT), true));

	// create an animation set from DEAN_SPRITE_FILENAME
	animSet.push_back(new Animation(*gameBuffers.at(DEAN_SPRITE_INDEX), Vector2D(SPRITESHEET_ROW_COUNT, SPRITESHEET_COLUMN_COUNT), true));

	// Set up the smurfUnit with two animation sets
	smurfUnit->addNewAnimation(*animSet.at(SMURF_SPRITE_INDEX));
	smurfUnit->addNewAnimation(*animSet.at(DEAN_SPRITE_INDEX));

	// Ensure that the unit exists in the game object vector
	gameObjects.push_back(smurfUnit);

	return;
}

// Call graphicsBuffers, Deconstructor
void Game::vectorCleanup()
{
	if (animSet.at(0) != nullptr)
	{
		for (Animation *deadAnim : animSet)
		{
			delete deadAnim;

			deadAnim = nullptr;
		}
	}

	if (gameObjects.at(0) != nullptr)
	{
		for (Unit *deadUnit : gameObjects)
		{
			delete deadUnit;

			deadUnit = nullptr;
		}
	}

	if (gameBuffers.at(0) != nullptr)
	{
		for (GraphicsBuffer *deadBuffer : gameBuffers)
		{
			delete deadBuffer;

			deadBuffer = nullptr;
		}
	}

	return;
}

// Checks for Mouse / Keyboard input from the user
void Game::getUserInput()
{
	if (gameSystem != nullptr)
	{
		gameSystem->getMouseState();
		gameSystem->getKeyState();
	}

	return;
}

// Create a new GraphicsBuffer in graphicsBuffers
void Game::addNewBuffer(std::string assetPath, std::string fileName)
{
	gameBuffers.push_back(new GraphicsBuffer(assetPath, fileName));
}

void Game::update()
{
	// Check if game should continue to run
	gameRunning = gameSystem->getGameState();

	animSpeed = gameSystem->getAnimSpeed();

	for (Unit *unitToUpdate : gameObjects)
	{
		for (Animation *anim : unitToUpdate->getAnimSet())
		{
			anim->animUpdate(animSpeed);
		}
	}

	return;
}

void Game::render()
{
	// Draw the background image
	gameSystem->getGraphicsSystem()->draw(*gameBuffers.at(BACKGROUND_INDEX), 0, BACKGROUND_SCALE);

	// Draw units that exist
	for (Unit *unitToDraw : gameObjects)
	{
		unitToDraw->drawUnit(gameSystem->getUnitToDisplay());
	}

	// Flip the display
	gameSystem->getGraphicsSystem()->updateDisplay();

	return;
}

*/