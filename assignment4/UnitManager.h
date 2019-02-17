#ifndef UNITMANAGER_H
#define UNITMANAGER_H

// C/C++ Includes
#include <string>
#include <map>

// DeanLib Includes
#include <Trackable.h>

class Unit;

typedef std::string UnitKey;

typedef std::map<UnitKey, Unit*> UnitMap;

class UnitManager : public Trackable
{
public:
	UnitManager() { return;  };
	~UnitManager();

	void cleanupUnitManager();

	Unit *createAndManageUnit(const UnitKey &key);

	void deleteUnit(const UnitKey &key);
	void deleteUnit(Unit *pUnit);

	Unit *getUnit(const UnitKey &key) const;

private:
	UnitMap mUnitMap;
};

#endif