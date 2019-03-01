/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Assignment 05									**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assignment 05 Author: Connor Ramsden						**
*********************************************************************/

#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

// C/C++ Includes
#include <map>
#include <assert.h>

// DeanLib Includes
#include <Trackable.h>

// EventSystem Classes
class Event;
class EventListener;
enum EventType;

// EventSystem Typedefs
// STL Multimap storing EventType & EventListener key-value pairs
typedef std::multimap<EventType, EventListener*> ListenerMap;

// STL Pair storing an EventType & EventListener
typedef std::pair<EventType, EventListener*> ListenerPair;

// STL pair holding two ListenerMaps
typedef std::pair<ListenerMap::iterator, ListenerMap::iterator> ListenerMapPair;

class EventSystem : public Trackable
{
public:
	// EventSystem Accessors
	static EventSystem *getEventSystemInstance();

	// EventSystem Instance Init / Cleanup
	static void initEventSystem();
	static void cleanupEventSystem();

	void fireEvent(const Event &eventToFire);

	void addListener(EventType evType, EventListener *pListener);

	void removeListener(EventType evType, EventListener *pListener);

	void removeListenerFromAllEvents(EventListener *pListener);

private:
	EventSystem();

	~EventSystem();

	static EventSystem *mpsEventSystemInstance;

	ListenerMap mListenerMap;

	void dispatchAllEvents(const Event &eventToDispatch);
};

#endif