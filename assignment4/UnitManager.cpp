#include "UnitManager.h"
#include "Unit.h"

UnitManager::~UnitManager()
{
	cleanupUnitManager();

	return;
}

void UnitManager::cleanupUnitManager()
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); ++iter)
	{
		Unit *pUnit = iter->second;

		delete pUnit;

		pUnit = nullptr;
	}

	mUnitMap.clear();

	return;
}

Unit * UnitManager::createAndManageUnit(const UnitKey & key)
{
	Unit *pUnit = nullptr;

	UnitMap::iterator iter = mUnitMap.find(key);

	// Is iter already in map?
	if (iter == mUnitMap.end())
	{
		// if the given unit doesn't exist, create and add it to the map
		pUnit = new Unit();

		mUnitMap[key] = pUnit;
	}

	return pUnit;
}

void UnitManager::deleteUnit(const UnitKey & key)
{
	UnitMap::iterator iter = mUnitMap.find(key);

	if (iter != mUnitMap.end())
	{
		delete iter->second;

		iter->second = nullptr;
		
		mUnitMap.erase(iter);

		return;
	}
}

void UnitManager::deleteUnit(Unit * pUnit)
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); iter++)
	{
		if (pUnit == iter->second)
		{
			delete pUnit;

			pUnit = nullptr;

			mUnitMap.erase(iter);

			return;
		}
	}
}

Unit * UnitManager::getUnit(const UnitKey & key) const
{
	UnitMap::const_iterator iter = mUnitMap.find(key);

	if (iter != mUnitMap.end())
	{
		return iter->second;
	}
	else
	{
		return nullptr;
	}
}