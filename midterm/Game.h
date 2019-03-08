/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
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

// Converts a string to its ascii / char values, and returns the sum of those values
int stringToASCII(std::string s);
int basicHashFunction(std::string s);

// Asset locations / file names for use in the Game
// Real game would have a better asset management system
const std::string ASSET_PATH = "Assets/";
const std::string SNAKE_HEAD_FILENAME = "snake_head.png";
const std::string SNAKE_BODY_FILENAME = "snake_body.png";
const std::string OBJECTIVE_FILENAME = "objective.png";
const std::string WALLS_FILENAME = "walls.png";

const int SNAKE_HEAD_INDEX = stringToASCII(SNAKE_HEAD_FILENAME);
const int SNAKE_BODY_INDEX = stringToASCII(SNAKE_BODY_FILENAME);
const int OBJECTIVE_INDEX = stringToASCII(OBJECTIVE_FILENAME);
const int WALLS_INDEX = stringToASCII(WALLS_FILENAME);

// Decent table size to hash-map with
const int HASH_MOD = 127;

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

	// Controls which index of mpsUnitManager to show
	int mUnitAnimIndex;

	// Determines how many units exist in mpsUnitManager
	int mNumUnits;

	// Determines how quickly the units are animated
	double mUnitSpeed;

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
	void updateLoop(double newUnitSpeed);

	// Render all game objects and backgrounds to the display
	void renderToDisplay();
	
	// Private Game Event Functions
private:
	void exitGame();

	void createUnit(Vector2D targetPos);

	void deleteUnit(Vector2D targetPos);

	void swapSprites();

	void pauseUnits();
};

#endif