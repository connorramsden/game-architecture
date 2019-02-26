/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "Game.h"
#include "UnitManager.h"
#include "GraphicsBufferManager.h"
#include "InputTranslator.h"

// Initialize Game / System / Manager Instances
Game * Game::mpsGameInstance = nullptr;
System * Game::mpsSystemInstance = nullptr;
UnitManager * Game::mpsUnitManager = nullptr;
GraphicsBufferManager * Game::mpsGraphicsBufferManager = nullptr;

// Initialize tracker & Timer
PerformanceTracker * Game::mpPerformanceTrackerInstance = nullptr;
Timer * Game::mpTimerInstance = nullptr;

// Returns mpsGameInstance
Game * Game::getGameInstance()
{
	assert(mpsGameInstance != nullptr);

	return mpsGameInstance;
}

// Returns mpsSystemInstance
System * Game::getSystemInstance()
{
	assert(mpsSystemInstance != nullptr);

	return mpsSystemInstance;
}

// Returns mpsUnitManager
UnitManager * Game::getUnitManagerInstance()
{
	assert(mpsUnitManager != nullptr);

	return mpsUnitManager;
}

// returns mpsGraphicsBufferManager
GraphicsBufferManager * Game::getGraphicsBufferManager()
{
	assert(mpsGraphicsBufferManager != nullptr);

	return mpsGraphicsBufferManager;
}

// Returns mpPerforamnceTracker
PerformanceTracker * Game::getPerformanceTrackerInstance()
{
	assert(mpPerformanceTrackerInstance != nullptr);

	return mpPerformanceTrackerInstance;
}

// Returns mpTimerInstance
Timer * Game::getTimerInstance()
{
	assert(mpTimerInstance != nullptr);

	return mpTimerInstance;
}

// Initializes a new Game instance
void Game::initInstance()
{
	// If the instance has not been initialized, initialize the instance
	if (!mpsGameInstance)
	{
		mpsGameInstance = new Game();
	}
	// Otherwise, print that the instance has already been initt'd
	else { std::cout << "Game instance already exists." << std::endl; return; }

	// Now that the Instance has been initialized, initialize the game
	mpsGameInstance->initGame();

	return;
}

// Clean up the existing Game instance
void Game::cleanupInstance()
{
	// If a Game instance exists, delete & null out the instance
	if (mpsGameInstance)
	{
		delete mpsGameInstance;

		mpsGameInstance = nullptr;
	}
	// Otherwise, report to console that no instance exists
	else { std::cout << "No game instance exists" << std::endl; return; }

	return;
}

// Initialize System/Managers within the game
void Game::initGame()
{
	// If the system instance has been properly initialized
	if (mpsSystemInstance)
	{
		// Init the display
		mpsSystemInstance->systemInit();
	}
	else { std::cout << "No system instance exists." << std::endl; }

	// If the UMI has been properly initialized
	if (mpsUnitManager && mpsGraphicsBufferManager)
	{
		// Create a graphics buffer from 'smurf_sprites.png'
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(SMURF_SPRITE_INDEX, ASSET_PATH, SMURF_SPRITE_FILENAME);

		// Create a graphics buffer from 'dean_sprites.png'
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(DEAN_SPRITE_INDEX, ASSET_PATH, DEAN_SPRITE_FILENAME);

		// Add the woods background to mpsGraphicsBufferManager
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(BACKGROUND_INDEX, ASSET_PATH, WOODS_FILENAME);
	}

	return;
}

// Delete System/Managers
void Game::cleanupGame()
{
	// Clean up the GBM
	if (mpsGraphicsBufferManager)
	{
		delete mpsGraphicsBufferManager;

		mpsGraphicsBufferManager = nullptr;
	}

	// Clean up the UMI
	if (mpsUnitManager)
	{
		delete mpsUnitManager;

		mpsUnitManager = nullptr;
	}
	else { std::cout << "No UnitManager exists" << std::endl; }

	// Clean up the System Instance
	if (mpsSystemInstance)
	{
		delete mpsSystemInstance;

		mpsSystemInstance = nullptr;
	}
	else { std::cout << "No System instance exists" << std::endl; }
}

// Initialize components necessary for the game loop to function
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

// Run the core game loop (input, update, render)
void Game::runGameLoop()
{
	// Initialize necessary game loop components
	mpsGameInstance->initGameLoop();

	// Ensure all systems & managers are properly initialized
	if (mpsSystemInstance && mpsUnitManager && mpsGraphicsBufferManager)
	{
		// Ensure that the game loop will run
		mpsGameInstance->mGameIsRunning = true;

		// Start all Units from the first Animation frame
		mpsGameInstance->mUnitAnimIndex = 0;

		// Ensures first user click will bring map count to 0, instead of 1
		mpsGameInstance->mNumUnits = -1;

		// Ensure all units move at a normalized speed
		mpsGameInstance->mUnitSpeed = 1.0;
	}

	// Loop functionality
	while (mpsGameInstance->mGameIsRunning)
	{
		// Clear the performance tracke for the game loop
		mpPerformanceTrackerInstance->clearTracker(mpsGameInstance->GAME_LOOP_TRACKER);

		// Begin tracking this frame
		mpPerformanceTrackerInstance->startTracking(mpsGameInstance->GAME_LOOP_TRACKER);

		// Start the timer for this frame
		mpTimerInstance->start();

		// Get mouse / keyboard input
		mpsGameInstance->getUserInput();

		// Update Unit(s) on screen
		mpsGameInstance->updateLoop(mpsGameInstance->mUnitSpeed);

		// Render background / units / etc to display
		mpsGameInstance->renderToDisplay();

		// Sleep for ~16 ms
		mpTimerInstance->sleepUntilElapsed(mpsGameInstance->MS_PER_FRAME);

		// Stop tracking the performance of this frame
		mpPerformanceTrackerInstance->stopTracking(mpsGameInstance->GAME_LOOP_TRACKER);

		// Print elapsed time to console
		std::cout << "Elapsed Time: " << mpPerformanceTrackerInstance->getElapsedTime(mpsGameInstance->GAME_LOOP_TRACKER) << std::endl;
	}

	// Stop the game loop, delete pointers, etc.
	mpsGameInstance->stopGameLoop();

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

// Checks for user input from the system
// TODO: Create KB & Mouse functions to prevent future messiness
void Game::getUserInput()
{
	int keyboardInput = mpsSystemInstance->getInputSystem()->getKeyState();
	int mouseInput = mpsSystemInstance->getInputSystem()->getMouseState();

	// Exit the game gracefully
	if (keyboardInput == ESCAPE)
	{
		mpsGameInstance->mGameIsRunning = false;
	}
	// Toggle last Unit animation state
	else if (keyboardInput == ENTER)
	{
		if (mpsGameInstance->mUnitAnimIndex == 0)
		{
			mpsGameInstance->mUnitAnimIndex = 1;
		}
		else if (mpsGameInstance->mUnitAnimIndex == 1)
		{
			mpsGameInstance->mUnitAnimIndex = 0;
		}
	}
	// Pause all Unit animations
	else if (keyboardInput == SPACEBAR)
	{
		if (mpsGameInstance->mUnitSpeed == 1.0)
		{
			mpsGameInstance->mUnitSpeed = 0.0;
		}
		else
		{
			mpsGameInstance->mUnitSpeed = 1.0;
		}
	}

	// TODO: Fix drawing new units @ mUnitAnimIndex, instead at 0
	if (mouseInput == LEFTBUTTON)
	{
		mpsGameInstance->mNumUnits++;

		// Create a new unit and emplace it at center-screen
		mpsUnitManager->createAndManageUnit(mpsGameInstance->mNumUnits, mpsSystemInstance->getInputSystem()->getMousePosition());

		mpsUnitManager->addAnimationToUnit(mpsGameInstance->mNumUnits, Animation(*mpsGraphicsBufferManager->getGraphicsBuffer(SMURF_SPRITE_INDEX), Vector2D(SPRITESHEET_ROW_COUNT, SPRITESHEET_COLUMN_COUNT), true));

		mpsUnitManager->addAnimationToUnit(mpsGameInstance->mNumUnits, Animation(*mpsGraphicsBufferManager->getGraphicsBuffer(DEAN_SPRITE_INDEX), Vector2D(SPRITESHEET_ROW_COUNT, SPRITESHEET_COLUMN_COUNT), true));
	}
	// TODO: Delete @ mouse position
	else if (mouseInput == RIGHTBUTTON)
	{
		if (mpsGameInstance->mNumUnits >= 0)
		{
			// Deletes last-created unit
			// Have some functionality for deleting @ mouse position, but not working properly.
			mpsUnitManager->deleteUnit(mpsGameInstance->mNumUnits);
			mpsGameInstance->mNumUnits--;
		}
	}

	return;
}

// Update all game objects / units
void Game::updateLoop(double newUnitSpeed)
{
	// Ensure that there is at least one unit present
	if (mpsGameInstance->mNumUnits >= 0)
	{
		mpsUnitManager->updateUnitInMap(mpsGameInstance->mNumUnits, mpsGameInstance->mUnitAnimIndex);
		mpsUnitManager->updateUnitsInMap(newUnitSpeed);
	}

	return;
}

// Render all units / backgrounds
void Game::renderToDisplay()
{
	// Draw 'woods.png' as the background
	mpsSystemInstance->getGraphicsSystem()->draw(*mpsGraphicsBufferManager->getGraphicsBuffer(BACKGROUND_INDEX), 0, BACKGROUND_SCALE);

	mpsUnitManager->drawUnitsInMap();

	// Flip the display to render graphics to user
	mpsSystemInstance->getGraphicsSystem()->updateDisplay();

	return;
}

// Default Game Constructor
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

// Default Game Deconstructor
Game::~Game()
{
	cleanupGame();

	return;
}

// Converts passed string to ASCII characters
int stringToASCII(std::string s)
{
	int sum = 0;

	for (int i = 0; i < (int)s.length(); i++)
	{
		sum += (int)s[i];
	}

	return sum;
}

// Uses ASCII characters to create an integer hash index
int basicHashFunction(std::string s)
{
	return stringToASCII(s) % HASH_MOD;
}