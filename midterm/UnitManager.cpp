/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
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
	if (!mUnitMap.empty())
	{
		UnitMap::iterator iter;

		for (iter = mUnitMap.begin(); iter != mUnitMap.end(); ++iter)
		{
			Unit* pUnit = iter->second;

			delete pUnit;

			pUnit = nullptr;
		}

		mUnitMap.clear();
	}	

	return;
}

// Add a new Unit to the map at the passed UnitKey
void UnitManager::createAndManageUnit(const UnitKey key, Vector2D& unitLocation)
{
	Unit* pUnit = nullptr;

	UnitMap::iterator iter = mUnitMap.find(key);

	if (iter == mUnitMap.end())
	{
		pUnit = new Unit(unitLocation);

		mUnitMap[key] = pUnit;
	}

	return;
}

// Delete the Unit in mUnitMap at the passed UnitKey index
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

// Deletes the passed Unit from mUnitMap
void UnitManager::deleteUnit(Unit* pUnit)
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

// Add the passed Animation to the Unit at the passed UnitKey index
void UnitManager::addAnimationToUnit(const UnitKey key, Animation& animToAdd)
{
	mUnitMap[key]->addNewAnimation(animToAdd);

	return;
}

// Loops through all Unit(s) in mUnitMap and draws their current state
void UnitManager::drawUnitsInMap()
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); ++iter)
	{
		Unit* pUnit = iter->second;

		pUnit->drawUnit();
	}

	return;
}

void UnitManager::updateUnitInMap(const UnitKey key, Vector2D& newUnitLocation)
{
	UnitMap::iterator iter = mUnitMap.find(key);

	if (iter->second)
	{
		Unit* pUnit = iter->second;
		pUnit->setUnitPosition(newUnitLocation);
	}

	return;
}

void UnitManager::updateAnimationsInMap(int newAnimIndex)
{
	UnitMap::iterator iter;

	for (iter = mUnitMap.begin(); iter != mUnitMap.end(); ++iter)
	{
		Unit* pUnit = iter->second;
		pUnit->updateUnitAnim(newAnimIndex);
	}
}

// returns the Unit located at &key in mUnitMap
Unit* UnitManager::getUnit(const UnitKey key) const
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