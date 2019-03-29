/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

// Game Includes
#include "Game.h"
#include "DataManager.h"
#include "InputTranslator.h"
#include "MenuManager.h"
#include "UnitManager.h"
#include "GraphicsBufferManager.h"
#include "Snake.h"
#include "PickupManager.h"
#include "GameEvent.h"

// C/C++ Includes
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <sstream>
#include <vector>

// C/C++ Usings
using std::vector;
using std::cout;
using std::endl;

// GraphicsLib Incldues
#include <EventSystem.h>
#include <Event.h>

#pragma region Static Accessors & Variables
int Game::msID = 0;

// Initialize Game / System / Manager Instances
Game* Game::mpsGameInstance = nullptr;
DataManager* Game::mpsDataManager = nullptr;
System* Game::mpsSystemInstance = nullptr;
InputTranslator* Game::mpsInputTranslatorInstance = nullptr;
MenuManager* Game::mpsMenuManager = nullptr;
UnitManager* Game::mpsUnitManager = nullptr;
GraphicsBufferManager* Game::mpsGraphicsBufferManager = nullptr;
Snake* Game::mpsSnakeInstance = nullptr;
PickupManager* Game::mpsPickupManager = nullptr;

// Initialize tracker & Timer
PerformanceTracker* Game::mpPerformanceTrackerInstance = nullptr;
Timer* Game::mpTimerInstance = nullptr;

// Returns mpsGameInstance
Game* Game::getGameInstance()
{
	assert(mpsGameInstance != nullptr);

	return mpsGameInstance;
}

// Returns mpsDataManager
DataManager* Game::getDataManager()
{
	assert(mpsDataManager != nullptr);

	return mpsDataManager;
}

// Returns mpsSystemInstance
System* Game::getSystemInstance()
{
	assert(mpsSystemInstance != nullptr);

	return mpsSystemInstance;
}

// Returns mpsInputTranslatorInstance
InputTranslator* Game::getInputTranslatorInstance()
{
	assert(mpsInputTranslatorInstance != nullptr);

	return mpsInputTranslatorInstance;
}

MenuManager * Game::getMenuManager()
{
	assert(mpsMenuManager != nullptr);

	return mpsMenuManager;
}

// Returns mpsUnitManager
UnitManager* Game::getUnitManagerInstance()
{
	assert(mpsUnitManager != nullptr);

	return mpsUnitManager;
}

// Returns mpsGraphicsBufferManager
GraphicsBufferManager* Game::getGraphicsBufferManager()
{
	assert(mpsGraphicsBufferManager != nullptr);

	return mpsGraphicsBufferManager;
}

// Returns mpsSnakeInstance
Snake* Game::getSnakeInstance()
{
	assert(mpsSnakeInstance != nullptr);

	return mpsSnakeInstance;
}

// Returns mpsPickupManager
PickupManager* Game::getPickupManager()
{
	assert(mpsPickupManager != nullptr);

	return mpsPickupManager;
}

// Returns mpPerforamnceTracker
PerformanceTracker* Game::getPerformanceTrackerInstance()
{
	assert(mpPerformanceTrackerInstance != nullptr);

	return mpPerformanceTrackerInstance;
}

// Returns mpTimerInstance
Timer* Game::getTimerInstance()
{
	assert(mpTimerInstance != nullptr);

	return mpTimerInstance;
}
#pragma endregion

#pragma region Game Management
// Initializes a new Game instance
void Game::initInstance()
{
	// If the instance has not been initialized, initialize the instance
	if (!mpsGameInstance)
		mpsGameInstance = new Game(EventSystem::getEventSystemInstance());
	// Otherwise, print that the instance has already been initt'd
	else
		cout << "Game instance already exists." << endl;

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
	else { cout << "No game instance exists" << endl; return; }

	return;
}

// Called in main.cpp, displays menu & awaits user input
void Game::startGame()
{
	mpsGameInstance->mpsMenuManager->generateMenu();

	mpsGameInstance->runGameLoop();
}

// Initialize System/Managers within the game
void Game::initGame()
{
	// If the system instance has been properly created
	if (mpsSystemInstance)
		// Init the display
		mpsSystemInstance->systemInit();
	else { cout << "No System instance exists." << endl; }

	if (mpsInputTranslatorInstance)
		mpsInputTranslatorInstance->initInputTranslator();


	// Register the event system instance with this listener
	EventSystem::getEventSystemInstance()->addListener((EventType)EXIT, this);
	EventSystem::getEventSystemInstance()->addListener((EventType)START_GAME, this);
	EventSystem::getEventSystemInstance()->addListener((EventType)MOVE_SNAKE, this);

	return;
}

// Delete System/Managers
void Game::cleanupGame()
{
	EventSystem::getEventSystemInstance()->removeListener((EventType)MOVE_SNAKE, this);
	EventSystem::getEventSystemInstance()->removeListener((EventType)START_GAME, this);
	EventSystem::getEventSystemInstance()->removeListener((EventType)EXIT, this);

	// Clean up the GraphicsBufferManager
	if (mpsGraphicsBufferManager)
	{
		delete mpsGraphicsBufferManager;
		mpsGraphicsBufferManager = nullptr;
	}

	// Clean up the PickupManager
	if (mpsPickupManager)
	{
		delete mpsPickupManager;
		mpsPickupManager = nullptr;
	}
	else
		cout << "No PickupManager exists." << endl;

	// Clean up the UnitManager
	if (mpsUnitManager)
	{
		delete mpsUnitManager;
		mpsUnitManager = nullptr;
	}
	else
		cout << "No UnitManager exists" << endl;

	if (mpsMenuManager)
	{
		delete mpsMenuManager;
		mpsMenuManager = nullptr;
	}
	else
		cout << "No MenuManager exists." << endl;

	// Clean up the InputTranslator
	if (mpsInputTranslatorInstance)
	{
		delete mpsInputTranslatorInstance;
		mpsInputTranslatorInstance = nullptr;
	}
	else
		cout << "No InputTranslator instance exists" << endl;

	if (mpsDataManager)
	{
		delete mpsDataManager;
		mpsDataManager = nullptr;
	}
	else
		cout << "No DataManager isntance exists" << endl;

	// Clean up the System Instance
	if (mpsSystemInstance)
	{
		delete mpsSystemInstance;
		mpsSystemInstance = nullptr;
	}
	else
		cout << "No System instance exists" << endl;
}
#pragma endregion

#pragma region Game Loop
// Initialize components necessary for the game loop to function
void Game::initGameLoop()
{
	// If the UnitManager, GraphicsBufferManager, and DataManager have been properly initialized
	if (mpsUnitManager && mpsGraphicsBufferManager && mpsDataManager)
	{
		mpsDataManager->readData(ASSET_PATH, "leveldata_1.txt");

		// Create a graphics buffer from 'background.png'
		mNumBuffers++;
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(mNumBuffers, ASSET_PATH, mpsDataManager->getFileName(mNumBuffers));

		// Create a graphics buffer from 'snake_head.png'
		mNumBuffers++;
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(mNumBuffers, ASSET_PATH, mpsDataManager->getFileName(mNumBuffers));

		// Create a graphcis buffer from 'snake_body.png'
		mNumBuffers++;
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(mNumBuffers, ASSET_PATH, mpsDataManager->getFileName(mNumBuffers));

		// Create a graphics buffer from 'walls.png'
		mNumBuffers++;
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(mNumBuffers, ASSET_PATH, mpsDataManager->getFileName(mNumBuffers));

		// Create a graphics buffer from 'yummy_food.png'
		mNumBuffers++;
		mpsGraphicsBufferManager->createAndManageGraphicsBuffer(mNumBuffers, ASSET_PATH, mpsDataManager->getFileName(mNumBuffers));
	}

	if (!mpPerformanceTrackerInstance)
		mpPerformanceTrackerInstance = new PerformanceTracker();
	else
		cout << "PerformanceTracker already exists." << endl;

	if (!mpTimerInstance)
		mpTimerInstance = new Timer();
	else
		cout << "Timer already exists." << endl;

	//TODO Pass starting location from data sheet
	if (!mpsSnakeInstance)
		mpsSnakeInstance = new Snake(mpsSystemInstance->getCenterScreen());
	else
		cout << "A Snake already exists" << endl;

	// Ensure that the game loop will run
	mpsGameInstance->mGameIsRunning = true;

	// Create the snake head
	mpsSnakeInstance->addPieceToSnake();

	cout << "Press 'Escape' to stop the game." << endl;

	return;
}

// Run the core game loop (input, update, render)
void Game::runGameLoop()
{
	// Initialize necessary game loop components
	mpsGameInstance->initGameLoop();

	// Loop functionality
	while (mpsGameInstance->mGameIsRunning)
	{
		// Clear the performance tracke for the game loop
		mpPerformanceTrackerInstance->clearTracker(mpsGameInstance->GAME_LOOP_TRACKER);

		// Begin tracking this frame
		mpPerformanceTrackerInstance->startTracking(mpsGameInstance->GAME_LOOP_TRACKER);

		// Start the timer for this frame
		mpTimerInstance->start();

		// Update the snake every 6 frames
		int updateCheck = mpsGameInstance->mTotalElapsedFrames % mpsGameInstance->mUpdateOffset;

		// Get user input from System
		mpsGameInstance->getUserInput();

		// Update Unit(s) on screen
		mpsGameInstance->updateLoop(updateCheck);

		// Render background / units / etc to display
		mpsGameInstance->renderToDisplay();

		// Sleep for ~16 ms
		mpTimerInstance->sleepUntilElapsed(mpsGameInstance->MS_PER_FRAME);

		// Stop tracking the performance of this frame
		mpPerformanceTrackerInstance->stopTracking(mpsGameInstance->GAME_LOOP_TRACKER);

		mpsGameInstance->mTotalElapsedFrames++;

		// Print elapsed time to console
		cout << "Elapsed Time: " << mpPerformanceTrackerInstance->getElapsedTime(mpsGameInstance->GAME_LOOP_TRACKER) << endl;
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

	// Clean up the Snake
	if (mpsSnakeInstance)
	{
		delete mpsSnakeInstance;
		mpsSnakeInstance = nullptr;
	}
	else { cout << "No Snake exists." << endl; }

	if (mpTimerInstance)
	{
		// Delete & nullify the game timer
		delete mpTimerInstance;
		mpTimerInstance = nullptr;
	}
	else { cout << "No Timer instance exists" << endl; }

	if (mpPerformanceTrackerInstance)
	{
		// Delete & nullify game performance tracker
		delete mpPerformanceTrackerInstance;
		mpPerformanceTrackerInstance = nullptr;
	}
	else { cout << "No PerformanceTracker instance exists" << endl; }

	cout << "Total Elapsed Frames: " << getTotalElapsedFrames() << endl;

	return;
}

// Handle incoming Game events
void Game::handleEvent(const Event & eventToHandle)
{
	switch (eventToHandle.getEventType())
	{
		if (mpsGameInstance->mGameIsRunning)
		{
		case EXIT:
			exitToMenu();
			return;
		case MOVE_SNAKE:
			const MoveSnake& moveSnakeEvent = static_cast<const MoveSnake&>(eventToHandle);
			mpsSnakeInstance->setSnakeDirection(moveSnakeEvent.getMoveDirection());
			return;
		}
		else
		{
		case START_GAME:
			// Stop the start loop
			mpsGameInstance->mpsMenuManager->setInMenu(false);
			return;
		}

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
void Game::updateLoop(int updateLimiter)
{
	// Ensure that there is at least one unit present
	if (mpsGameInstance->getSnakeInstance()->getNumPieces() >= 0)
	{
		if (updateLimiter == 0)
			mpsSnakeInstance->updateSnake();
	}

	mpsPickupManager->generatePickups(0);

	return;
}

// Render all units / backgrounds
void Game::renderToDisplay()
{
	// Clear backbuffer to black
	mpsSystemInstance->getGraphicsSystem()->setBufferColor(mpsSystemInstance->getGraphicsSystem()->getBackBuffer(), Color(0, 0, 0));

	// Render the background image
	mpsSystemInstance->getGraphicsSystem()->draw(*mpsGameInstance->getGraphicsBufferManager()->getGraphicsBuffer(0), 0, 1.0f);

	// Draw all pieces of the snake
	mpsUnitManager->drawUnitsInMap();

	// Draw all pickups in mPickupMap
	mpsPickupManager->drawPickups();

	// Flip the display to render graphics to user
	mpsSystemInstance->getGraphicsSystem()->updateDisplay();
	return;
}

// Stop the game loop from running
void Game::exitToMenu()
{
	if (mpsGameInstance->mGameIsRunning)
		mpsGameInstance->mGameIsRunning = false;

	return;
}
#pragma endregion

// Default Game Constructor
Game::Game(EventSystem * pEventSystem)
	:EventListener(pEventSystem)
	, mID(msID)
{
	msID++;
	mGameIsRunning = false;
	mNumUnits = -1;
	mNumBuffers = -1;
	mTotalElapsedFrames = 0;
	mUpdateOffset = 4;

	// Create new System/Managers
	if (!mpsSystemInstance)
		mpsSystemInstance = new System();
	else
		cout << "A System instance already exists" << endl;

	if (!mpsDataManager)
		mpsDataManager = new DataManager();
	else
		cout << "A DataManager instance already exists." << endl;

	if (!mpsInputTranslatorInstance)
		mpsInputTranslatorInstance = new InputTranslator(EventSystem::getEventSystemInstance());
	else
		cout << "An InputTranslator instance already exists" << endl;

	if (!mpsMenuManager)
		mpsMenuManager = new MenuManager();
	else
		cout << "A MenuManager instance already exists." << endl;

	if (!mpsUnitManager)
		mpsUnitManager = new UnitManager();
	else
		cout << "A UnitManager already exists" << endl;

	if (!mpsGraphicsBufferManager)
		mpsGraphicsBufferManager = new GraphicsBufferManager();
	else
		cout << "A GraphicsBufferManager already exists" << endl;

	if (!mpsPickupManager)
		mpsPickupManager = new PickupManager();
	else
		cout << "A PickupManager instance already exists" << endl;

	if (!(mpsSystemInstance && mpsDataManager && mpsInputTranslatorInstance && mpsMenuManager && mpsUnitManager && mpsGraphicsBufferManager && mpsPickupManager))
	{
		cout << "An initializer has not been properly initialized. Breaking game." << endl;

		system("pause");
	}

	return;
}

// Default Game Deconstructor
Game::~Game()
{
	cleanupGame();

	return;
}