/*
	Certification of Authenticity:
	I, Connor Ramsden, certify that this assignment is my own work.

	Disclosures:
	- I received some math / formula help and general assistance from a Game Architecture tutor in Joyce 101 (forgot his name),
		though all written code is my own
*/

// Includes from C/C++ library
#include <iostream>
#include <cstdlib>
#include <time.h>

// Includes from GraphicsLib
#include <Font.h>
#include <GraphicsBuffer.h>
#include <GraphicsSystem.h>
#include <Sprite.h>

// Includes from DeanLib
#include <PerformanceTracker.h>
#include <MemoryTracker.h>

// Namespace access
using namespace Graphics;
using namespace std;

// Constant variables for program operation

// Display width,height, and scale
const int DISP_WIDTH = 800;
const int DISP_HEIGHT = 600;
const float scaleBy = 0.33f;
const int NUM_SPRITES = 16;
const int SPRITE_COL = (int)sqrt(NUM_SPRITES);
const int SPRITE_ROW = (int)sqrt(NUM_SPRITES);

// DeanLib performance tracking constants
const string INIT_TRACKER_NAME = "init";
const string DRAW_TRACKER_NAME = "draw";
const string WAIT_TRACKER_NAME = "wait";

// External asset access
const string ASSET_PATH = "..\\..\\shared\\assets\\";
const string STEPS_FILENAME = "steps.png";
const string SMURF_FILENAME = "smurf_sprites.png";
const string FONT_FILENAME = "cour.ttf";
const string smurfMsg = "Curse you Papa Smurf!";
const string redSave = "redbuffer.jpg";
const string backSave = "backbuffer.jpg";
const int FONT_SIZE = 42;
const double SLEEP_TIME = 5.0;

int main()
{
	// Seed time for sprite positioning later
	srand(time(NULL));

	// Initialize a DeanLib performance tracker
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;

	// Start tracking the initialization process
	pPerformanceTracker->startTracking(INIT_TRACKER_NAME);

	// Constructing components from GraphicsLib
	// GraphicsSystem, primarily operates the show
	GraphicsSystem *customDisplay = new GraphicsSystem;

	// Initialized the GraphicsSystem
	customDisplay->initGS(DISP_WIDTH, DISP_HEIGHT);

	// Font to display on the screen
	Font *cour = new Font(ASSET_PATH, FONT_FILENAME, FONT_SIZE);

	// GraphicsBuffer to display entirely red screen
	GraphicsBuffer *redBuffer = new GraphicsBuffer(DISP_WIDTH, DISP_HEIGHT);

	// Clears buffer to entirely red
	redBuffer->clearBufferToColor("RED");

	// Write text to the redBuffer buffer
	customDisplay->Write(redBuffer, 150, 0, cour, redBuffer->getColor("BLACK"), smurfMsg);

	// Graphics buffer used to display "steps.png"
	GraphicsBuffer *stepsBuffer = new GraphicsBuffer(ASSET_PATH, STEPS_FILENAME);

	// Center out steps.png in the red buffer
	int stepX = ((DISP_WIDTH - stepsBuffer->getBmpWidth() * scaleBy) / 2.0f);
	int stepY = ((DISP_HEIGHT - stepsBuffer->getBmpHeight() * scaleBy) / 2.0f);

	// Graphics buffer used to insert "smurf_sprites.png" into a sprite set
	GraphicsBuffer *smurfBuffer = new GraphicsBuffer(ASSET_PATH, SMURF_FILENAME);

	// Determines height / width of a single sprite emplaced in the set
	int spriteWidth = smurfBuffer->getBmpWidth() / sqrt(NUM_SPRITES);
	int spriteHeight = smurfBuffer->getBmpHeight() / sqrt(NUM_SPRITES);

	// Establish a sprite set from smurfBuffer
	Sprite *smurfSprites[NUM_SPRITES];	

	// Initialization phase over, stop tracking
	pPerformanceTracker->stopTracking(INIT_TRACKER_NAME);

	// Start tracking drawing to screen phase
	pPerformanceTracker->startTracking(DRAW_TRACKER_NAME);

	// Select 16 sprites from the smurf_sprites sheet and randomly place them in the scene
	for (int i = 0; i < SPRITE_COL; i++)
	{
		for (int j = 0; j < SPRITE_ROW; j++)
		{
			smurfSprites[(i * SPRITE_COL) + j] = new Sprite((i * spriteWidth), (j*spriteHeight), smurfBuffer, spriteWidth, spriteHeight);

			int xLoc = rand() % customDisplay->getDisplayWidth();
			int yLoc = rand() % customDisplay->getDisplayHeight();

			customDisplay->Draw(xLoc, yLoc, smurfSprites[(i * SPRITE_COL) + j]);
		}
	}

	// Draw the red buffer to the backbuffer
	customDisplay->Draw(customDisplay->getBackbuffer(), 0, 0, redBuffer, 1.0f);

	// Draw "steps.png" to the center of the screen
	customDisplay->Draw(customDisplay->getBackbuffer(), stepX, stepY, stepsBuffer, scaleBy);	

	// Save the backbuffer to a file
	customDisplay->SaveBuffer(backSave, customDisplay->getBackbuffer());

	// Save the redbuffer to a file
	customDisplay->SaveBuffer(redSave, redBuffer);

	// Flip the display to show what is being drawn to customDisplay
	customDisplay->flipDisplay();

	// stop tracking the drawing phase
	pPerformanceTracker->stopTracking(DRAW_TRACKER_NAME);

	// Start tracking the display phase
	pPerformanceTracker->startTracking(WAIT_TRACKER_NAME);

	// Wait for SLEEP_TIME to demonstrate program
	al_rest(SLEEP_TIME);

	// Stop tracking the display phase
	pPerformanceTracker->stopTracking(WAIT_TRACKER_NAME);	

	//  De-allocate initialized pointers
	delete smurfBuffer;
	delete stepsBuffer;
	delete redBuffer;
	delete cour;
	delete customDisplay;

	//  De-allocate initialized sprites
	for (int i = 0; i < NUM_SPRITES; i++)
	{
		delete smurfSprites[i];
	}

	//report elapsed times
	cout << endl << "Time to Init:" << pPerformanceTracker->getElapsedTime(INIT_TRACKER_NAME) << " ms" << endl;
	cout << endl << "Time to Draw:" << pPerformanceTracker->getElapsedTime(DRAW_TRACKER_NAME) << " ms" << endl;
	cout << endl << "Time spent waiting:" << pPerformanceTracker->getElapsedTime(WAIT_TRACKER_NAME) << " ms" << endl;

	// De-allocate performance tracker from memory
	delete pPerformanceTracker;

	// Report any memory leaks to console
	MemoryTracker::getInstance()->reportAllocations(cout);
	
	system("pause");
	return 0;
}