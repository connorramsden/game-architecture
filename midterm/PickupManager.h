/*********************************************************************
**		Author:	Connor Ramsden										**
**		Class: EGP-310-02											**
**		Assignment: Midterm Project (Snake)							**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Midterm Project Author: Connor Ramsden						**
*********************************************************************/

#ifndef PICKUPMANAGER_H
#define PICKUPMANAGER_H

// C/C++ Includes
#include <string>
#include <map>
#include <vector>

// C/C++ Usings
using std::map;
using std::pair;
using std::vector;

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// GraphicsLib Class Reference
class Animation;

// Game Class References
class Unit;

enum PickupType
{
	INVALID_PICKUP = -1,
	GROW,
	SPEED_UP,
	SLOW_DOWN,
	INVERT_CONTROLS,
	NUM_PICKUPS
};

typedef pair<Unit*, PickupType> PickupPair;
typedef map<int, PickupPair> PickupMap;


class PickupManager : public Trackable
{
	public:
	PickupManager();

	~PickupManager();

	void cleanupPickupManager();

	void addPickup(PickupType type, Vector2D& pickupLocation);

	PickupType deletePickup(Vector2D& pickupLocation);

	void addAnimationToPickup(int pickupIndex, Animation& anim);

	void generatePickups(int pickupTimer);

	void drawPickups();

	private:
	vector<int> mPickupsToDelete = vector<int>();
	PickupMap mPickupMap;
	int mNumPickups;

	void deleteCachedPickups();
};

#endif