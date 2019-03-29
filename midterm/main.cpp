/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

// DeanLib Includes
#include <MemoryTracker.h>

// GraphicsLib Includes
#include "Game.h"
#include "EventSystem.h"

int main()
{
	// Seeding time for any random game operations
	std::srand(time(nullptr));
	
	// Initialize an EventSystem
	EventSystem::initEventSystem();

	// Initialize a Game instance
	Game::initInstance();

	// Run the core game loop
	Game::startGame();

	// When the game loop breaks, clean up the Game instance
	Game::cleanupInstance();

	// Clean up the EventSystem
	EventSystem::cleanupEventSystem();

	// Report memory leaks to console
	MemoryTracker::getInstance()->reportAllocations(std::cout);

	// Wait for user input before returning
	system("pause");

	// Exit the console window
	return 0;
}