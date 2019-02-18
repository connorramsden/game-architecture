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
#include "Unit.h"

// GraphicsLib Includes
#include <System.h>

/*
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
*/

class Game : public Trackable
{
public:
	// System / Manager Accessors
	static Game *getGameInstance();
	static System *getSystemInstance();
	static UnitManager *getUnitManagerInstance();
	// static GraphicsBufferManager *getGraphicsBufferManager();

	// Game Init / Cleanup
	static void initInstance(int displayWidth, int displayHeight);
	static void cleanupInstance();

	// Game Operations
	static void runGame(Timer &gameTimer, PerformanceTracker &perfTracker);

	static void getUserInput();

	static void updateLoop();

	static void renderToScreen();

private:
	Game();
	~Game();

	static Game *mpsGameInstance;

	static System *mpsSystemInstance;

	static UnitManager *mpsUnitManager;
	// static GraphicsBufferManager *mpsGraphicsBufferManager;
};

#endif