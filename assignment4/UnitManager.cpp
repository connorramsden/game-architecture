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
	for (int i = 0; i < (int)mUnitList.size() - 1; i++)
	{
		Unit *pUnit = mUnitList.at(i);

		delete pUnit;

		pUnit = nullptr;
	}

	mUnitList.clear();

	return;
}

// Creates a new Unit and adds it into mUnitMap
void UnitManager::addNewUnit(Unit *newUnit)
{
	mUnitList.push_back(newUnit);
}

// Deletes the passed unit from mUnitMap
void UnitManager::deleteUnit(Unit *mpUnit)
{
	if (!mUnitList.empty())
	{
		for (int i = 0; i < (int)mUnitList.size() - 1;)
		{
			if (mpUnit == mUnitList.at(i))
			{
				delete mpUnit;

				mpUnit = nullptr;
			}
			else
			{
				i++;
			}
		}
	}
	
	return;
}

// returns the Unit located at &key in mUnitMap
Unit * UnitManager::getUnit(const UnitKey key) const
{
	if (!mUnitList.empty())
	{
		if (mUnitList.at(key))
		{
			return mUnitList.at(key);
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}