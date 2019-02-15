#include "Unit.h"
#include "Game.h"

// Default Unit Constructor
Unit::Unit(Vector2D &newLocation)
{
	// Initialize unit location
	unitLocation = newLocation;

	// Initialize animation vector
	unitAnimSet = std::vector<Animation *>();

	return;
}

Unit::~Unit()
{
	unitCleanup();

	return;
}

void Unit::unitCleanup()
{
	for (Animation *deadAnim : unitAnimSet)
	{
		delete deadAnim;

		deadAnim = nullptr;
	}
}

void Unit::addNewAnimation(Animation & newAnim)
{
	unitAnimSet.push_back(new Animation(newAnim));
}

void Unit::drawUnit(int animToDraw)
{
	currentAnimIndex = animToDraw;

	Sprite spr = unitAnimSet.at(currentAnimIndex)->getCurrentSprite();
	
	Vector2D unitPos = gpGame->getGameSystem()->getMousePosition();

	gpGame->getGameSystem()->getGraphicsSystem()->draw(spr, unitPos.getX(), unitPos.getY());
}