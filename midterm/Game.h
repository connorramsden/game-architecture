/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
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

// GraphicsLib Includes
#include <System.h>
#include <EventListener.h>

// GraphicsLib Class References
class EventSystem;

// Game Includes
#include "GameAssets.h"

// Game Class References
class InputTranslator;
class UnitManager;
class GraphicsBufferManager;

// Game Event Class References
class ExitEvent;
class CreateUnit;
class DeleteUnit;
class SpriteSwap;
class PauseUnits;

class Game : public EventListener
{
// Public Game Instance Functions
public:
	// System / Manager Accessors
	static Game *getGameInstance();
	static System *getSystemInstance();
	static InputTranslator *getInputTranslatorInstance();
	static UnitManager *getUnitManagerInstance();
	static GraphicsBufferManager *getGraphicsBufferManager();

	// Performance Accessors
	static PerformanceTracker *getPerformanceTrackerInstance();
	static Timer *getTimerInstance();

// Public Game Functions
public:
	// Game Instance Init / Cleanup
	static void initInstance();
	static void cleanupInstance();

	// Game Operations
	static void runGameLoop();

	// Handle incoming Game events
	void handleEvent(const Event &eventToHandle);

// Private Game Instances & Constructors
private:
	// Default Game Constructor
	Game(EventSystem *pEventSystem);

	// Default Game Deconstructor
	~Game();

	static int msID;

	int mID;

	// An instance of the Game class
	static Game *mpsGameInstance;

	// An instance of the System class, referenced by the Game
	static System *mpsSystemInstance;

	// An instance of the InputTranslator class, referenced by the Game
	static InputTranslator *mpsInputTranslatorInstance;

	// An instance of the UnitManager class, referenced by the Game
	static UnitManager *mpsUnitManager;

	// An instance of the GraphicsBufferManager class, referenced by the Game
	static GraphicsBufferManager *mpsGraphicsBufferManager;

	// Game Performance Tracker
	static PerformanceTracker *mpPerformanceTrackerInstance;

	// Game Timer
	static Timer *mpTimerInstance;

	// Private Game Variables
private:
	// Game Loop Variables
	// PerformanceTracker string to track frame performance
	const std::string GAME_LOOP_TRACKER = "game_loop";;

	// Target frame elapsed time
	const double FRAMES_PER_SECOND = 60.0;
	const double MS_PER_FRAME = 1000 / FRAMES_PER_SECOND;

	// Controls whether or not the game loop can run
	bool mGameIsRunning;

	// Determines how many units exist in mpsUnitManager
	int mNumUnits;

	Font *mpGameFont;

	// Stores the x/y position of the snake head
	Vector2D mSnakeHeadPosition;

	// Stores the direction the snake is moving at any given time
	Vector2D mCurrentSnakeDirection;

// Private Game Functions
private:
	// Game Init / Cleanup
	void initGame();
	void cleanupGame();

	// Initializers for runGameLoop()
	void initGameLoop();
	void stopGameLoop();

	// Retrieve user input from KB&M
	void getUserInput();

	// Update all game objects
	void updateLoop();

	// Render all game objects and backgrounds to the display
	void renderToDisplay();
	
// Private Game Event Functions
private:
	// Stop the game loop from running
	void exitGame();

	// Similar to exitGame(), but not as instant
	void failState();

	// Create the 'head' piece of the Snake
	void createHead(Vector2D targetPos);

	void moveHead(Vector2D targetPos);
	void updateSnakeHead();

	bool isSnakeWithinBounds();
};

#endif