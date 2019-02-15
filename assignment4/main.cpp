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
#include <PerformanceTracker.h>
#include <MemoryTracker.h>

// GraphicsLib Includes
#include "Game.h"

// Display dimensions.
const int DISPLAY_WIDTH = 800;
const int DISPLAY_HEIGHT = 600;

int main()
{
	// Create a performance tracker.
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;

	// Create a timer for framerate
	Timer *gameTimer = new Timer;

	/*********************
		Tracker names.
	**********************/
	const std::string INIT_TRACKER_NAME = "init";
	const std::string LOOP_TRACKER_NAME = "loop";

	// Start tracking the initialization.
	pPerformanceTracker->startTracking(INIT_TRACKER_NAME);

	// Ensure the global Game object is created
	gpGame = new Game();

	// Initialize the global Game object
	gpGame->gameInit(DISPLAY_WIDTH, DISPLAY_HEIGHT);

	// Stop tracking initialization.
	pPerformanceTracker->stopTracking(INIT_TRACKER_NAME);

	// Start tracking game loop.
	pPerformanceTracker->startTracking(LOOP_TRACKER_NAME);

	gpGame->runGameLoop(*gameTimer);

	// Stop tracking game loop.
	pPerformanceTracker->stopTracking(LOOP_TRACKER_NAME);

	/****************************
		Report elapsed times.
	*****************************/
	std::cout << "Time to Init:" << pPerformanceTracker->getElapsedTime(INIT_TRACKER_NAME) << " ms" << std::endl;
	std::cout << "Time in Game Loop:" << pPerformanceTracker->getElapsedTime(LOOP_TRACKER_NAME) << " ms" << std::endl;

	// Delete all the pointers to free memory.
	delete gpGame;
	delete gameTimer;
	delete pPerformanceTracker;

	// Make sure the pointers are nulled.
	gpGame = nullptr;
	gameTimer = nullptr;
	pPerformanceTracker = nullptr;

	MemoryTracker::getInstance()->reportAllocations(std::cout);
	system("pause");

	return 0;
}