/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#include "EventSystem.h"
#include "Event.h"
#include "EventListener.h"

EventSystem * EventSystem::mpsEventSystemInstance = nullptr;

EventSystem * EventSystem::getEventSystemInstance()
{
	assert(mpsEventSystemInstance != nullptr);

	return mpsEventSystemInstance;
}

void EventSystem::initEventSystem()
{
	if (!mpsEventSystemInstance)
	{
		mpsEventSystemInstance = new EventSystem();
	}
	else { std::cout << "EventSystem already exists." << std::endl; return;	}

	return;
}

void EventSystem::cleanupEventSystem()
{
	if (mpsEventSystemInstance)
	{
		delete mpsEventSystemInstance;

		mpsEventSystemInstance = nullptr;
	}
	else { std::cout << "No EventSystem instance exists" << std::endl; return; }

	return;
}

void EventSystem::fireEvent(const Event & eventToFire)
{
	dispatchAllEvents(eventToFire);

	return;
}

void EventSystem::addListener(EventType evType, EventListener * pListener)
{
	mListenerMap.insert(ListenerPair(evType, pListener));

	return;
}

void EventSystem::removeListener(EventType evType, EventListener * pListener)
{
	ListenerMapPair ret;

	ret = mListenerMap.equal_range(evType);

	ListenerMap::iterator iter;

	for (iter = ret.first; iter != ret.second; ++iter)
	{
		if (iter->second == pListener)
		{
			mListenerMap.erase(iter);
			break;
		}
	}

	return;
}

void EventSystem::removeListenerFromAllEvents(EventListener * pListener)
{
	ListenerMap::iterator iter;

	bool allTheWayThrough = false;

	while (!allTheWayThrough)
	{
		allTheWayThrough = true;

		for (iter = mListenerMap.begin(); iter != mListenerMap.end(); ++iter)
		{
			if (iter->second == pListener)
			{
				mListenerMap.erase(iter);
				allTheWayThrough = false;
				break;
			}
		}
	}

	return;
}

EventSystem::EventSystem()
{
	return;
}

EventSystem::~EventSystem()
{
	return;
}

void EventSystem::dispatchAllEvents(const Event & eventToDispatch)
{
	ListenerMapPair ret;

	ret = mListenerMap.equal_range(eventToDispatch.getEventType());

	ListenerMap::iterator iter;

	for (iter = ret.first; iter != ret.second; ++iter)
	{
		iter->second->handleEvent(eventToDispatch);
	}

	return;
}