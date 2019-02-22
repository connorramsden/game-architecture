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

	// Game Loop Variables
	// PerformanceTracker string to track frame performance
	const std::string GAME_LOOP_TRACKER = "game_loop";;

	// Target frame elapsed time
	const double MS_PER_FRAME = 16.67;

	// Controls whether or not the game loop can run
	bool mGameIsRunning;
};

enum KeyCode : int
{
	ESCAPE = 59,
	ENTER = 67,
	SPACEBAR = 75,
};

#endif