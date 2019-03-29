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
#include <string>
#include <random>

// C/C++ Usings
using std::string;

// DeanLib Includes
#include <Timer.h>
#include <PerformanceTracker.h>

// GraphicsLib Includes
#include <System.h>
#include <EventListener.h>

// GraphicsLib Class References
class EventSystem;

// Game Class References
class DataManager;
class InputTranslator;
class MenuManager;
class UnitManager;
class GraphicsBufferManager;
class Snake;
class PickupManager;

// Game Event Class References
class ExitEvent;

class Game : public EventListener
{
#pragma region Public Game Instance Functions
	public:
	// System / Manager Accessors
	static Game* getGameInstance();
	static DataManager* getDataManager();
	static System* getSystemInstance();
	static InputTranslator* getInputTranslatorInstance();
	static MenuManager* getMenuManager();
	static UnitManager* getUnitManagerInstance();
	static GraphicsBufferManager* getGraphicsBufferManager();
	static Snake* getSnakeInstance();
	static PickupManager* getPickupManager();

	// Performance Accessors
	static PerformanceTracker* getPerformanceTrackerInstance();
	static Timer* getTimerInstance();

	// Iterate mNumUnits
	inline void increaseNumUnits() { mNumUnits++; return; }
	// Decrement mNumUnits
	inline void decreaseNumUnits() { mNumUnits--; return; }
	// Return mNumUnits
	inline int getNumUnits() const { return mNumUnits; }
	// Return mTotalElapsedFrames
	inline double getTotalElapsedFrames() const { return mTotalElapsedFrames; }

	inline int getUpdateOffset() const { return mUpdateOffset; }
	inline void setUpdateOffset(int newUpdateOffset) { mUpdateOffset = newUpdateOffset; return; }
#pragma endregion

#pragma region Public Game Functions
	public:
	// Game Instance Init / Cleanup
	static void initInstance();
	static void cleanupInstance();

	// Start the Game, display its Main Menu
	static void startGame();

	// Handle incoming Game events
	void handleEvent(const Event& eventToHandle);

	// Stop game loop & exit to main menu
	void exitToMenu();
#pragma endregion

#pragma region Static Game Variables
	private:
	// Default Game Constructor
	Game(EventSystem* pEventSystem);

	// Default Game Deconstructor
	~Game();

	static int msID;

	int mID;

	// An instance of the Game class
	static Game* mpsGameInstance;

	// An instance of the DataManager struct, referenced by the Game
	static DataManager* mpsDataManager;

	// An instance of the System class, referenced by the Game
	static System* mpsSystemInstance;

	// An instance of the InputTranslator class, referenced by the Game
	static InputTranslator* mpsInputTranslatorInstance;

	static MenuManager* mpsMenuManager;

	// An instance of the UnitManager class, referenced by the Game
	static UnitManager* mpsUnitManager;

	// An instance of the GraphicsBufferManager class, referenced by the Game
	static GraphicsBufferManager* mpsGraphicsBufferManager;

	// An instance of the PickupManager class, referenced by the Game
	static PickupManager* mpsPickupManager;

	// An instance of the Snake class, referenced by the Game
	static Snake* mpsSnakeInstance;

	// Game Performance Tracker
	static PerformanceTracker* mpPerformanceTrackerInstance;

	// Game Timer
	static Timer* mpTimerInstance;

#pragma endregion

#pragma region Private Game Variables
	private:
	// Game Loop Variables
	// PerformanceTracker string to track frame performance
	const string GAME_LOOP_TRACKER = "game_loop";
	const string ASSET_PATH = "assets/";

	// Target frame elapsed time
	const double FRAMES_PER_SECOND = 60.0;
	const double MS_PER_FRAME = 1000 / FRAMES_PER_SECOND;

	// Limits how often the snake's position is updated
	int mUpdateOffset;

	// Total frames during gameplay
	int mTotalElapsedFrames;
	
	// Controls whether or not the game loop can run
	bool mGameIsRunning;
	bool mStartLevel;

	// Determines how many units exist in mpsUnitManager
	int mNumUnits;

	int mNumBuffers;

#pragma endregion

#pragma region Private Game Functions
	private:
	// Game Init / Cleanup
	void initGame();
	void cleanupGame();

	// Initializer for runGameLoop()
	void initGameLoop();
	// Called from startGame() once player indicates readiness
	void runGameLoop();
	// Cleans up anything initialized in initGameLoop()
	void stopGameLoop();

	// Retrieve user input from KB&M
	void getUserInput();

	// Update all game objects
	void updateLoop(int updateLimiter);

	// Render all game objects and backgrounds to the display
	void renderToDisplay();
#pragma endregion
};

#endif