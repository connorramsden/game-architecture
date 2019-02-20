#ifndef UNITMANAGER_H
#define UNITMANAGER_H

// C/C++ Includes
#include <string>
#include <vector>

// DeanLib Includes
#include <Trackable.h>

// Reference to Unit class
class Unit;

typedef int UnitKey;

typedef std::vector<Unit *> UnitList;

class UnitManager : public Trackable
{
public:
	// Default UnitManager Constructor
	UnitManager() { return; }

	// Default UnitManager Deconstructor
	~UnitManager();

	// Loops through mUnitMap and deletes all Unit(s)
	void cleanupUnitManager();

	// Creates a new Unit and adds it into mUnitMap
	void addNewUnit(Unit *newUnit);
	
	// Deletes the passed unit from mUnitMap
	void deleteUnit(Unit *pUnit);

	// returns the Unit located at &key in mUnitMap
	Unit *getUnit(const UnitKey key) const;

private:
	UnitList mUnitList;
};

#endif