/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 03									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 03 Author: Connor Ramsden						**
*********************************************************************/

#ifndef UNIT_H
#define UNIT_H

// C/C++ Includes
#include <vector>

// DeanLib Includes
#include <Vector2D.h>

// GraphicsLib Includes
#include <Animation.h>

class Unit : public Trackable
{
public:
	// Default Unit Constructor
	Unit(Vector2D &newLocation);

	~Unit();

	void unitCleanup();

	void addNewAnimation(Animation &newAnim);

	void drawUnit(int animToDraw);

	Vector2D getUnitPosition() { return unitLocation; }

	std::vector<Animation *> getAnimSet() { return unitAnimSet; }

private:
	// Set of Animations associated with this Unit
	std::vector<Animation *> unitAnimSet;

	// Current Animation to display on-screen
	int currentAnimIndex = 0;

	// Location of the unit in 2D Space
	Vector2D unitLocation;
};

#endif