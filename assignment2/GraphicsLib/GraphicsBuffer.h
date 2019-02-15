#ifndef GRAPHICSBUFFER_H
#define GRAPHICSBUFFER_H

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

// Part of the 'Graphics' namespace
namespace Graphics
{
	// Class 'GraphicsBuffer', extends DeanLib's Trackable
	class GraphicsBuffer : public Trackable
	{
	public:
		// GraphicsBuffer class Default Constructor
		GraphicsBuffer();

		// GraphicsBuffer class Special Constructor (al_load_bitmap)
		GraphicsBuffer(std::string assetPath, std::string fileName);

		// GraphicsBuffer class Special Constructor (al_create_bitmap)
		GraphicsBuffer(int bmpWidth, int bmpHeight);

		// GraphicsBuffer class Deconstructor
		~GraphicsBuffer();

		// GraphicsBuffer Getters
		int getBmpWidth();
		int getBmpHeight(); 
		ALLEGRO_COLOR getColor(std::string clr);

		// Clears GraphicsBuffer to the passed color
		void clearBufferToColor(std::string color);

	private:
		ALLEGRO_BITMAP *pBitmap;

		ALLEGRO_BITMAP *getBuffer() { return pBitmap; }

		ALLEGRO_COLOR RED = al_map_rgb(255, 0, 0);
		ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
		ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);

		friend class Sprite;
		friend class GraphicsSystem;
	};
}

#endif