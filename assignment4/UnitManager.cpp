#include "UnitManager.h"
#include "Unit.h"

// Default UnitManager Deconstructor
UnitManager::~UnitManager()
{
	cleanupUnitManager();

	return;
}

// Loops through mUnitMap and deletes all Unit(s)
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

Unit * UnitManager::createAndManageUnit(const UnitKey key, Vector2D &unitLocation)
{
	Unit *pUnit = nullptr;

	UnitMap::iterator iter = mUnitMap.find(key);

	if (iter == mUnitMap.end())
	{
		pUnit = new Unit(unitLocation);

		mUnitMap[key] = pUnit;
	}

	return pUnit;
}

void UnitManager::deleteUnit(const UnitKey key)
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

// Deletes the passed unit from mUnitMap
void UnitManager::deleteUnit(Unit *pUnit)
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

	return;
}

void UnitManager::addAnimationToUnit(const UnitKey key, Animation & animToAdd)
{
	mUnitMap[key]->addNewAnimation(animToAdd);
}

// Loops through all Unit(s) in mUnitMap and draws their current state
void UnitManager::drawUnitsInMap()
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); ++iter)
	{
		Unit *pUnit = iter->second;

		pUnit->drawUnit();
	}

	return;
}

void UnitManager::updateUnitsInMap(const int currentUnitState)
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); ++iter)
	{
		Unit *pUnit = iter->second;

		pUnit->updateUnit(currentUnitState);
	}

	return;
}

// returns the Unit located at &key in mUnitMap
Unit * UnitManager::getUnit(const UnitKey key) const
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