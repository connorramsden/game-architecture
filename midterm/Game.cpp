/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

// GraphicsLib Incldues
#include <EventSystem.h>
#include <Event.h>

// Game Includes
#include "Game.h"
#include "UnitManager.h"
#include "GraphicsBufferManager.h"
#include "InputTranslator.h"
#include "GameEvent.h"

int Game::msID = 0;

// Initialize Game / System / Manager Instances
Game * Game::mpsGameInstance = nullptr;
System * Game::mpsSystemInstance = nullptr;
UnitManager * Game::mpsUnitManager = nullptr;
GraphicsBufferManager * Game::mpsGraphicsBufferManager = nullptr;
InputTranslator * Game::mpsInputTranslatorInstance = nullptr;

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

// Returns mpsInputTranslatorInstance
InputTranslator * Game::getInputTranslatorInstance()
{
	assert(mpsInputTranslatorInstance != nullptr);

	return mpsInputTranslatorInstance;
}

// Returns mpsUnitManager
UnitManager * Game::getUnitManagerInstance()
{
	assert(mpsUnitManager != nullptr);

	return mpsUnitManager;
}

// Returns mpsGraphicsBufferManager
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
		mpsGameInstance = new Game(EventSystem::getEventSystemInstance());
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

		// Set head start position to center of screen
		// TODO: Load start position from a data file
		mHeadStartPosition = mpsSystemInstance->getCenterScreen();
	}
	else { std::cout << "No System instance exists." << std::endl; }

	if (mpsInputTranslatorInstance)
	{
		mpsInputTranslatorInstance->initInputTranslator();
	}

	// Register the event system instance with this listener
	EventSystem::getEventSystemInstance()->addListener((EventType)EXIT, this);
	EventSystem::getEventSystemInstance()->addListener((EventType)CREATE_UNIT, this);
	EventSystem::getEventSystemInstance()->addListener((EventType)MOVE_SNAKE, this);

	// If the UMI has been properly initialized
	if (mpsUnitManager && mpsGraphicsBufferManager)
	{
		// Create a graphics buffer from 'smurf_sprites.png'
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(SNAKE_HEAD_INDEX, ASSET_PATH, SNAKE_HEAD_FILENAME);
	}

	return;
}

// Delete System/Managers
void Game::cleanupGame()
{
	EventSystem::getEventSystemInstance()->removeListener((EventType)MOVE_SNAKE, this);
	EventSystem::getEventSystemInstance()->removeListener((EventType)CREATE_UNIT, this);
	EventSystem::getEventSystemInstance()->removeListener((EventType)EXIT, this);

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

	if (mpsInputTranslatorInstance)
	{
		delete mpsInputTranslatorInstance;

		mpsInputTranslatorInstance = nullptr;
	}
	else { std::cout << "No InputTranslator instance exists" << std::endl; }

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

		// Ensures first user click will bring map count to 0, instead of 1
		mpsGameInstance->mNumUnits = -1;

		// Creates the snake head at the file-specified starting position
		mpsGameInstance->createHead(mpsGameInstance->mHeadStartPosition);
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

		// Get user input from System
		mpsGameInstance->getUserInput();

		// Update Unit(s) on screen
		mpsGameInstance->updateLoop();

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

// Handle incoming Game events
void Game::handleEvent(const Event & eventToHandle)
{
	if (eventToHandle.getEventType() == GameEventType::EXIT)
	{
		exitGame();
		return;
	}
	// TODO: CreateUnit behavior will be different for Snake
	else if (eventToHandle.getEventType() == GameEventType::CREATE_UNIT)
	{
		const CreateUnit & createUnitEvent = static_cast<const CreateUnit &>(eventToHandle);

		// createUnit(createUnitEvent.getUnitPosition());
		return;
	}
	else if (eventToHandle.getEventType() == GameEventType::MOVE_SNAKE)
	{
		const MoveSnake & moveSnakeEvent = static_cast<const MoveSnake &>(eventToHandle);
	}

	return;
}

// Checks for user input from the System
void Game::getUserInput()
{
	mpsSystemInstance->getInputSystem()->updateInputSystem();

	return;
}

// Update all game objects / units
void Game::updateLoop()
{
	// Ensure that there is at least one unit present
	if (mpsGameInstance->mNumUnits >= 0)
	{
		// TODO: Update snake position based on passed movement
		mpsUnitManager->updateUnitInMap(mpsGameInstance->mNumUnits, Vector2D(400,0));
	}

	return;
}

// Render all units / backgrounds
void Game::renderToDisplay()
{
	// Clear backbuffer to black
	mpsSystemInstance->getGraphicsSystem()->setBufferColor(mpsSystemInstance->getGraphicsSystem()->getBackBuffer(), Color(0, 0, 0));

	mpsUnitManager->drawUnitsInMap();

	// Flip the display to render graphics to user
	mpsSystemInstance->getGraphicsSystem()->updateDisplay();

	return;
}

// Stop the game loop from running
void Game::exitGame()
{
	mpsGameInstance->mGameIsRunning = false;
}

// Create the 'head' piece of the Snake
void Game::createHead(Vector2D targetPos)
{
	// Runs at start of SNAKE, creates the 'head' at the center of the screen
	if(mpsGameInstance->mNumUnits < 0)
	{
		// mNumUnits => 0
		mpsGameInstance->mNumUnits++;

		mpsUnitManager->createAndManageUnit(mpsGameInstance->mNumUnits, targetPos);
		
		Animation snakeHead(*mpsGraphicsBufferManager->getGraphicsBuffer(SNAKE_HEAD_INDEX), Vector2D(1.0f, 1.0f), false);

		mpsUnitManager->addAnimationToUnit(mpsGameInstance->mNumUnits, snakeHead);
	}
}

// Default Game Constructor
Game::Game(EventSystem *pEventSystem)
	:EventListener(pEventSystem)
	,mID(msID)
{
	msID++;

	if (!mpsSystemInstance)
	{
		// Create new System/Managers
		mpsSystemInstance = new System();
	}
	else { std::cout << "A System instance already exists" << std::endl; }

	if (!mpsInputTranslatorInstance)
	{
		mpsInputTranslatorInstance = new InputTranslator(EventSystem::getEventSystemInstance());
	}
	else { std::cout << "An InputTranslator instance already exists" << std::endl; }

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