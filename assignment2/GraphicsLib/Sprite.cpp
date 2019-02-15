#include "Sprite.h"

namespace Graphics
{
	Sprite::Sprite(int newX, int newY, GraphicsBuffer * srcBmp, int newWidth, int newHeight)
	{
		pSource = srcBmp;

		pSprite = pSource->getBuffer();

		xLoc = newX;
		yLoc = newY;

		sprWidth = newWidth;

		sprHeight = newHeight;
	}
	
	Sprite::~Sprite() {}
}