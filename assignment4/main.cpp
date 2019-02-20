/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 04									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 04 Author: Connor Ramsden						**
*********************************************************************/

/*
	Disclosures:
	1. I BORROWED Nick Da Costa's Assignment 02 as a baseline for my Assignment 03 work.
		This was done with EXPLICIT PERMISSION from the author.
		I have NOT removed his certificate(s) of authenticity from his files so that this is clearly apparent.
	2. I did NOT borrow anyone's work for the assignment 03 files used to start Assignment 04
	3. NO other help was received in the creation of this assignmnet
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
	Game::initInstance();

	Game *mpGame = Game::getGameInstance();

	mpGame->runGameLoop();

	Game::cleanupInstance();

	MemoryTracker::getInstance()->reportAllocations(std::cout);
	system("pause");

	return 0;
}