/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef UNITMANAGER_H
#define UNITMANAGER_H

// C/C++ Includes
#include <string>
#include <map>
#include <vector>

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// GraphicsLib Includes
#include <Animation.h>

// Reference to Unit class
class Unit;

typedef int UnitKey;

typedef std::map<UnitKey, Unit *> UnitMap;

class UnitManager : public Trackable
{
public:
	// Default UnitManager Constructor
	UnitManager() { return; }

	// Default UnitManager Deconstructor
	~UnitManager();

	// Loops through mUnitMap and deletes all Unit(s)
	void cleanupUnitManager();

	// Add a new Unit to the map at the passed UnitKey
	Unit *createAndManageUnit(const UnitKey key, Vector2D &unitLocation);

	// Delete the Unit in mUnitMap at the specified key
	void deleteUnit(const UnitKey key);

	// Deletes the passed unit from mUnitMap
	void deleteUnit(Unit *pUnit);

	// Delete the unit at unitToDeletePostion from mUnitMap
	void deleteUnit(Vector2D unitToDeletePosition);

	void addAnimationToUnit(const UnitKey key, Animation &animToAdd);

	// Draws all units in mUnitMap to screen
	void drawUnitsInMap();

	// Update all units in mUnitMap
	void updateUnitInMap(const UnitKey key, const int currentUnitState);
	void updateUnitsInMap(double newAnimSpeed);

	// returns the Unit located at &key in mUnitMap
	Unit *getUnit(const UnitKey key) const;

private:
	// An STL map storing Units
	UnitMap mUnitMap;
};

#endif