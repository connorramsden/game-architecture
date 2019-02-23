/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

/*
	Disclosures:
	1. I BORROWED Nick Da Costa's Assignment 02 as a baseline for my Assignment 03 work.
		This was done with EXPLICIT PERMISSION from the author.
		I have NOT removed his certificate(s) of authenticity from his files so that this is clearly apparent.
	2. I did NOT borrow anyone's work for the assignment 03 files used to start assignment 04
	3. I did NOT borrow anyone's work for the assignment 04 files used to start assignment 05
	4. NO other help was received in the creation of this assignmnet
*/

// C/C++ Includes
#include <iostream>
#include <string>

// DeanLib Includes
#include <MemoryTracker.h>

// GraphicsLib Includes
#include "Game.h"

int main()
{
	// Initialize a Game instance
	Game::initInstance();

	// Instantiate a Game object from the initialized instance
	gpGame = Game::getGameInstance();

	// Run the core game loop
	gpGame->runGameLoop();

	// When the game loop breaks, clean up the Game instance
	Game::cleanupInstance();

	// Report memory leaks to console
	MemoryTracker::getInstance()->reportAllocations(std::cout);

	// Wait for user input before returning
	system("pause");

	// Exit the console window
	return 0;
}