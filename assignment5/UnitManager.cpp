/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

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

void UnitManager::deleteUnit(Vector2D unitToDeletePosition)
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); iter++)
	{
		if (unitToDeletePosition == iter->second->getUnitPosition())
		{
			delete iter->second;

			iter->second = nullptr;

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

void UnitManager::updateUnitInMap(const UnitKey key, const int currentUnitState)
{
	UnitMap::iterator iter = mUnitMap.find(key);

	if (iter->second)
	{
		Unit *pUnit = iter->second;
		pUnit->updateUnit(currentUnitState);
	}

	return;
}

void UnitManager::updateUnitsInMap(double newAnimSpeed)
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); ++iter)
	{
		Unit *pUnit = iter->second;

		pUnit->getCurrentAnimation()->animUpdate(newAnimSpeed);
	}
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