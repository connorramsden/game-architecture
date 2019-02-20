#ifndef UNITMANAGER_H
#define UNITMANAGER_H

// C/C++ Includes
#include <string>
#include <map>

// DeanLib Includes
#include <Trackable.h>

// Reference to Unit class
class Unit;

// integer key to reference Unit(s) in UnitMap
typedef int UnitKey;

// STL map storing UnitKey(s) and Unit(s)
typedef std::map<UnitKey, Unit*> UnitMap;

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
	Unit *createAndManageUnit(const UnitKey &key);

	// Deletes a unit in mUnitMap at &key
	void deleteUnit(const UnitKey &key);

	// Deletes the passed unit from mUnitMap
	void deleteUnit(Unit *pUnit);

	// returns the Unit located at &key in mUnitMap
	Unit *getUnit(const UnitKey &key) const;

private:
	// STL map storing UnitKey(s) and Unit(s)
	UnitMap mUnitMap;
};

#endif