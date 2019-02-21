/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

#include "Game.h"

// Initialize Game / System / Manager Instances
Game * Game::mpsGameInstance = nullptr;
System * Game::mpsSystemInstance = nullptr;
UnitManager * Game::mpsUnitManager = nullptr;
GraphicsBufferManager * Game::mpsGraphicsBufferManager = nullptr;

// Initialize tracker & Timer
PerformanceTracker * Game::mpPerformanceTrackerInstance = nullptr;
Timer * Game::mpTimerInstance = nullptr;

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

GraphicsBufferManager * Game::getGraphicsBufferManager()
{
	assert(mpsGraphicsBufferManager != nullptr);

	return mpsGraphicsBufferManager;
}

PerformanceTracker * Game::getPerformanceTrackerInstance()
{
	assert(mpPerformanceTrackerInstance != nullptr);

	return mpPerformanceTrackerInstance;
}

Timer * Game::getTimerInstance()
{
	assert(mpTimerInstance != nullptr);

	return mpTimerInstance;
}

void Game::initInstance()
{
	if (!mpsGameInstance)
	{
		mpsGameInstance = new Game();
	}
	else { std::cout << "Game instance already exists." << std::endl; }

	if (mpsSystemInstance)
	{
		mpsSystemInstance->systemInit();
	}
	else { std::cout << "No system instance exists." << std::endl; }


	// TODO: GRAPHICS BUFFERS / UNITS / ANIMATIONS
	if (mpsGraphicsBufferManager)
	{
		mpsGraphicsBufferManager->addNewBuffer(ASSET_PATH, SMURF_SPRITE_FILENAME);
	}

	return;
}

void Game::cleanupInstance()
{
	// TODO: clean up static vectors

	if (mpsGameInstance != nullptr)
	{
		delete mpsGameInstance;

		mpsGameInstance = nullptr;
	}
	else { std::cout << "No game instance exists" << std::endl; }

	return;
}

void Game::initGameLoop()
{
	if (!mpPerformanceTrackerInstance)
	{
		mpPerformanceTrackerInstance = new PerformanceTracker();
	}
	else { std::cout << "PerformanceTracker already exists." << std::endl; }

	if (!mpTimerInstance)
	{
		mpTimerInstance = new Timer();
	}
	else { std::cout << "Timer already exists." << std::endl; }

	std::cout << "Press 'Escape' to stop the game." << std::endl;

	return;
}

void Game::runGameLoop()
{
	initGameLoop();

	static const std::string GAME_LOOP_TRACKER = "game_loop";

	static double MS_PER_FRAME = 16.67;

	static bool mGameIsRunning = true;

	while (mGameIsRunning)
	{
		// Clear the performance tracke for the game loop
		mpPerformanceTrackerInstance->clearTracker(GAME_LOOP_TRACKER);

		// Begin tracking this frame
		mpPerformanceTrackerInstance->startTracking(GAME_LOOP_TRACKER);

		// Start the timer for this frame
		mpTimerInstance->start();

		// Get mouse / keyboard input
		getUserInput();

		// Update Unit(s) on screen
		updateLoop();

		// Render background / units / etc to display
		renderToDisplay();

		// Sleep for ~16 ms
		mpTimerInstance->sleepUntilElapsed(MS_PER_FRAME);

		// Stop tracking the performance of this frame
		mpPerformanceTrackerInstance->stopTracking(GAME_LOOP_TRACKER);

		// Print elapsed time to console
		std::cout << "Elapsed Time: " << mpPerformanceTrackerInstance->getElapsedTime(GAME_LOOP_TRACKER) << std::endl;
	}

	// Stop the game loop, delete pointers, etc.
	stopGameLoop();

	return;
}

// Cleans up all game loop objects / pointers
void Game::stopGameLoop()
{
	// Stops game timer
	mpTimerInstance->stop();

	if (mpTimerInstance)
	{
		// Delete & nullify the game timer
		delete mpTimerInstance;
		mpTimerInstance = nullptr;
	}
	else { std::cout << "No Timer instance exists" << std::endl; }

	if (mpPerformanceTrackerInstance)
	{
		// Delete & nullify game performance tracker
		delete mpPerformanceTrackerInstance;
		mpPerformanceTrackerInstance = nullptr;
	}
	else { std::cout << "No PerformanceTracker instance exists" << std::endl; }

	return;
}

void Game::getUserInput()
{
	if (mpsSystemInstance != nullptr)
	{
		mpsSystemInstance->getMouseState();
		mpsSystemInstance->getKeyState();
	}

	return;
}

void Game::updateLoop()
{


	return;
}

void Game::renderToDisplay()
{

	// Flip the display to render graphics to user
	mpsSystemInstance->getGraphicsSystem()->updateDisplay();

	return;
}

Game::Game()
{
	if (!mpsSystemInstance)
	{
		// Create new System/Managers
		mpsSystemInstance = new System();
	}
	else { std::cout << "A system instance already exists" << std::endl; }

	if (!mpsUnitManager)
	{
		mpsUnitManager = new UnitManager();
	}
	else { std::cout << "A UnitManager already exists" << std::endl; }

	if (!mpsGraphicsBufferManager)
	{
		mpsGraphicsBufferManager = new GraphicsBufferManager();
	}
	else { std::cout << "A GraphicsBufferManager already exists" << std::endl; }

	return;
}

Game::~Game()
{
	// Clean up System / Managers
	if (mpsUnitManager)
	{
		delete mpsUnitManager;

		mpsUnitManager = nullptr;
	}
	else { std::cout << "No UnitManager exists" << std::endl; }

	if (mpsSystemInstance)
	{
		delete mpsSystemInstance;

		mpsSystemInstance = nullptr;
	}
	else { std::cout << "No System instance exists" << std::endl; }

	return;
}