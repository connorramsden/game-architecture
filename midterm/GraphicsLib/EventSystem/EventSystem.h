/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

// C/C++ Includes
#include <map>
#include <assert.h>

// C++ Usings
using std::multimap;
using std::pair;

// DeanLib Includes
#include <Trackable.h>

// EventSystem Classes
class Event;
class EventListener;
enum EventType;

// EventSystem Typedefs
// STL Multimap storing EventType & EventListener key-value pairs
typedef multimap<EventType, EventListener*> ListenerMap;

// STL Pair storing an EventType & EventListener
typedef pair<EventType, EventListener*> ListenerPair;

// STL pair holding two ListenerMaps
typedef pair<ListenerMap::iterator, ListenerMap::iterator> ListenerMapPair;

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