/*
	Certification of Authenticity: Assignment 03
	I, Connor Ramsden, certify that the contents of this assignment are my work and my work alone

	Disclosures:
	- I borrowed Nick da Costa's Assignment 02 as a baseline for my Assignment 03 work. This was done with explicit permission from the author.
		I will not remove his certificate(s) of authenticity from his scripts so that this is obvious and apparent.
	- No other help was received in the creation of this assignment.
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