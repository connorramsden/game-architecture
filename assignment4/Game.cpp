/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

#include "Game.h"

/*
// Default Game Constructor
Game::Game()
{
	return;
}

// Default Game Deconstructor
Game::~Game()
{
	gameCleanup();

	return;
}

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

// Called from Deconstructor
void Game::gameCleanup()
{
	// call any Vector deconstructors
	vectorCleanup();

	// Clean up gameSystem
	if (gameSystem != nullptr)
	{
		// call gameSystem Deconstructor
		delete gameSystem;

		// Ensure gameSystem is nullptr
		gameSystem = nullptr;
	}

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

// Begins the core gameplay loop
// Utilizing Fixed Interval Time + Render catch-up
void Game::runGameLoop(Timer &gameTimer)
{
	// Ensure player / developer knows to hit Escape to exit loop
	std::cout << "Press 'Escape' to stop program running." << std::endl;

	// Access game state to determine if loop can run
	gameRunning = gameSystem->getGameState();

	while (gameRunning)
	{
		// Start the Timer for the game loop
		gameTimer.start();

		// Check for any Mouse / Keyboard input
		getUserInput();

		// Update game state
		update();

		// Render with Update
		render();

		// Sleep for 16.7 ms. FIXED GAME TIME
		gameTimer.sleepUntilElapsed(MS_PER_FRAME);
	}

	// Stop the timer when game loop ends
	gameTimer.stop();

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

Game * Game::mpsGameInstance = nullptr;
System * Game::mpsSystemInstance = nullptr;
UnitManager *Game::mpsUnitManager = nullptr;

Game * Game::getGameInstance()
{
	assert(mpsGameInstance != nullptr);

	return mpsGameInstance;
}

System * Game::getSystemInstance()
{
	assert(mpsSystemInstance != nullptr);

	return mpsSystemInstance;
}

UnitManager * Game::getUnitManagerInstance()
{
	assert(mpsUnitManager != nullptr);

	return mpsUnitManager;
}

void Game::initInstance(int displayWidth, int displayHeight)
{
	mpsGameInstance = new Game();
}

void Game::cleanupInstance()
{
	delete mpsGameInstance;

	mpsGameInstance = nullptr;
}

Game::Game()
{
	return;
}

Game::~Game()
{
	cleanupInstance();
}

/*
class Game : public Trackable
{
private:
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
*/