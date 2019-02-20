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
	Unit *mpUnit = nullptr;

	UnitMap::iterator iter = mUnitMap.find(key);

	// Is iter already in map?
	if (iter == mUnitMap.end())
	{
		// if the given unit doesn't exist, create and add it to the map
		mpUnit = new Unit();

		mUnitMap[key] = mpUnit;
	}

	return mpUnit;
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

	return;
}

void UnitManager::deleteUnit(Unit * mpUnit)
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); iter++)
	{
		if (mpUnit == iter->second)
		{
			delete mpUnit;

			mpUnit = nullptr;

			mUnitMap.erase(iter);

			return;
		}
	}

	return;
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