/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#include "PickupManager.h"
#include <Animation.h>
#include "Unit.h"
#include "Game.h"
#include "DataManager.h"
#include "GraphicsBufferManager.h"

using std::cout;
using std::endl;

PickupManager::PickupManager()
{
	mNumPickups = -1;

	return;
}

PickupManager::~PickupManager()
{
	cleanupPickupManager();

	return;
}

void PickupManager::cleanupPickupManager()
{
	if (!mPickupMap.empty())
	{
		PickupMap::iterator iter;

		for (iter = mPickupMap.begin(); iter != mPickupMap.end(); ++iter)
		{
			Unit* pUnit = iter->second.first;

			delete pUnit;

			pUnit = nullptr;
		}

		mPickupMap.clear();
	}

	return;
}

void PickupManager::addPickup(PickupType type, Vector2D& pickupLocation)
{
	mNumPickups++;

	Unit* pUnit = nullptr;

	PickupMap::iterator iter = mPickupMap.find(mNumPickups);

	if (iter == mPickupMap.end())
	{
		pUnit = new Unit(pickupLocation);

		mPickupMap[mNumPickups] = std::make_pair(pUnit, type);

		addAnimationToPickup(mNumPickups,
			Animation(*Game::getGameInstance()->getGraphicsBufferManager()->getGraphicsBuffer(4), Vector2D(2.0f, 2.0f), false));

		switch (mPickupMap[mNumPickups].second)
		{
			case GROW:
				mPickupMap[mNumPickups].first->getCurrentAnimation()->setCurrentSprite(0);
				break;
			case SPEED_UP:
				mPickupMap[mNumPickups].first->getCurrentAnimation()->setCurrentSprite(1);
				break;
			case SLOW_DOWN:
				mPickupMap[mNumPickups].first->getCurrentAnimation()->setCurrentSprite(2);
				break;
			case INVERT_CONTROLS:
				mPickupMap[mNumPickups].first->getCurrentAnimation()->setCurrentSprite(3);
				break;
		}

		return;
	}
}

PickupType PickupManager::deletePickup(Vector2D& pickupLocation)
{
	PickupType pickupToDeleteType = INVALID_PICKUP;

	PickupMap::iterator iter;

	for (iter = mPickupMap.begin(); iter != mPickupMap.end(); ++iter)
	{
		if (pickupLocation == iter->second.first->getUnitPosition())
		{
			mPickupsToDelete.push_back(iter->first);

			pickupToDeleteType = iter->second.second;
		}
	}

	return pickupToDeleteType;
}

void PickupManager::addAnimationToPickup(int pickupIndex, Animation& anim)
{
	mPickupMap[pickupIndex].first->addNewAnimation(anim);

	return;
}

void PickupManager::generatePickups(int pickupTimer)
{
	if (pickupTimer == 0)
	{
		Game* pGameInstance = Game::getGameInstance();
		System* pSystemInstance = pGameInstance->getSystemInstance();
		int screenX = pSystemInstance->getCenterScreen().getX();
		int screenY = pSystemInstance->getCenterScreen().getY();

		int randomVar = std::rand();
		int randX = floor(randomVar / screenX);
		int randY = floor(randomVar / screenY);
		randX += floor(mNumPickups + randomVar % 8 * 200);

		if (randX % 16 == 0)
		{
			switch (randomVar % 4)
			{
				case 0:
					addPickup(GROW, Vector2D(randX, screenY));
					break;
				case 1:
					addPickup(SPEED_UP, Vector2D(randX, screenY));
					break;
				case 2:
					addPickup(SLOW_DOWN, Vector2D(randX, screenY));
					break;
			}
		}
	}

	return;
}

void PickupManager::drawPickups()
{
	if (!mPickupMap.empty())
	{
		PickupMap::iterator iter;

		for (iter = mPickupMap.begin(); iter != mPickupMap.end(); ++iter)
		{
			Unit* pUnit = iter->second.first;

			pUnit->drawUnit();
		}

		deleteCachedPickups();
	}

	return;
}

void PickupManager::deleteCachedPickups()
{
	if (!mPickupsToDelete.empty())
	{
		for (int i = 0; i <= (int)mPickupsToDelete.size() - 1; i++)
		{
			Unit* pUnit = mPickupMap[mPickupsToDelete[i]].first;

			delete pUnit;

			pUnit = nullptr;

			mPickupMap.erase(mPickupsToDelete[i]);
		}
	}
	else
	{
		mPickupsToDelete.clear();
	}

	return;
}