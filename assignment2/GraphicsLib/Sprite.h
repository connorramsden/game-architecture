#ifndef SPRITE_H
#define SPRITE_H

// Includes from C/C++ library
#include <string>

// Includes from Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

// Includes from DeanLib
#include <PerformanceTracker.h>
#include <MemoryTracker.h>

// Includes from GraphicsLib
#include "GraphicsBuffer.h"

// Part of the 'Graphics' namespace
namespace Graphics
{
	class Sprite : public Trackable
	{
	public:
		Sprite(int locX, int locY, GraphicsBuffer *srcBmp, int sprWidth, int sprHeight);
		~Sprite();

		// Sprite class Getters
		int getXLoc() { return xLoc; }
		int getYLoc() { return yLoc; }
		int getWidth() { return sprWidth; }
		int getHeight() { return sprHeight; }
		GraphicsBuffer *getBuffer() { return pSource; }
		ALLEGRO_BITMAP *getSprite() { return pSprite; }

		// Sprite class Setters
		void setXLoc(int newLoc) { xLoc = newLoc; }
		void setYLoc(int newLoc) { yLoc = newLoc; }
		void setWidth(int newWidth) { sprWidth = newWidth; }
		void setHeight(int newHeight) { sprHeight = newHeight; }

	private:
		GraphicsBuffer *pSource;
		ALLEGRO_BITMAP *pSprite;

		int xLoc;
		int yLoc;

		int sprWidth;
		int sprHeight;

		friend class GraphicsSystem;
	};
}

#endif