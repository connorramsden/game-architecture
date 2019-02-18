/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 03									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 03 Author: Connor Ramsden						**
*********************************************************************/

#ifndef GAME_H
#define GAME_H

// C/C++ Includes
#include <vector>
#include <string>

// DeanLib Includes
#include <Timer.h>
#include <PerformanceTracker.h>

// Game Includes
#include "Unit.h"

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
	// Default Game Constructor
	Game();

	// Default Game Deconstructor
	~Game();

	// Initializes the Game system
	void gameInit(int displayWidth, int displayHeight);

	// Cleans up the Game system
	void gameCleanup();

	// Cleans up any new'd vector pointers
	void vectorCleanup();

	// Begins the core gameplay loop
	// Utilizing Fixed Interval Time + Render catch-up
	void runGameLoop(Timer &gameTimer);

	// Checks for Mouse / Keyboard input from the user
	void getUserInput();

	// Create a new GraphicsBuffer in graphicsBuffers
	void addNewBuffer(std::string assetPath, std::string fileName);

	// Update the game state based on input / automatic stuff
	void update();

	// Render out background & units
	void render();

	System *getGameSystem() { return gameSystem; }

private:
	// Access to a System object
	System *gameSystem = nullptr;

	// Vector of GraphicsBuffers
	// Index 0 must always be your background image
	std::vector<GraphicsBuffer *> gameBuffers;

	// Vector of type Unit
	std::vector<Unit *> gameObjects;

	// Vector of type Animation
	std::vector<Animation *> animSet;

	// Scale for drawn background image
	const float BACKGROUND_SCALE = 0.5f;

	// Framerate Variables
	const double MS_PER_FRAME = 16.7;

	// Tracker for game loop frame speed
	const std::string GAME_LOOP_TRACKER = "game_loop";

	// TODO: Clean up variables when keypress / mouse state is fixed
	// Controls runGameLoop
	bool gameRunning = false;

	// Controls speed of unit animations
	double animSpeed = 1.0;
};

extern Game *gpGame;

#endif