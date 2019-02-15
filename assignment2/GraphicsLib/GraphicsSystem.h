#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

// Includes from C/C++ library
#include <string>

// Includes from Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

// Includes from DeanLib
#include <PerformanceTracker.h>
#include <MemoryTracker.h>

// Includes from GraphicsLib
#include "GraphicsBuffer.h"
#include "Font.h"
#include "Sprite.h"

// Part of the 'Graphics' namespace
namespace Graphics
{
	// Class 'GraphicsSystem', extends DeanLib's Trackable
	class GraphicsSystem : public Trackable
	{
	public:
		// GraphicsSystem class Constructor
		GraphicsSystem();
		// GraphicsSystem class Deconstructor
		~GraphicsSystem();

		// GraphicsSystem class initializer
		int initGS(int displayWidth, int displayHeight);

		// GraphicsSystem class clean-up
		void cleanupGS();

		// Flips the display to show what has been drawn
		void flipDisplay();

		// GraphicsSystem class Getters
		int getDisplayWidth();
		int getDisplayHeight();		
		
		ALLEGRO_BITMAP *getBackbuffer();

		// Basic al_draw_bitmap functionality
		static void Draw(int xLoc, int yLoc, GraphicsBuffer *bmpToDraw);

		// al_draws_scaled_bitmap to specific allegro_bitmap (backbuffer)
		static void Draw(ALLEGRO_BITMAP *targetBuffer, int xLoc, int yLoc, GraphicsBuffer *bmpToDraw, float scaleBy);
		
		// al_draw_scaled_bitmap functionality
		static void Draw(int xLoc, int yLoc, GraphicsBuffer *bmpToDraw, float scaleBy);

		static void Draw(GraphicsBuffer *targetBuffer, int xLoc, int yLoc, GraphicsBuffer *bmpToDraw, float scaleBy);

		static void Draw(int xLoc, int yLoc, Sprite *spriteToDraw);

		// al_draw_text functionality
		static void Write(int xLoc, int yLoc, Font *font, ALLEGRO_COLOR txtClr, std::string txt);

		// al_draw_text to specified buffer
		static void Write(GraphicsBuffer *targetBuffer, int xLoc, int yLoc, Font *font, ALLEGRO_COLOR txtClr, std::string txt);

		static void SaveBuffer(std::string fileName, GraphicsBuffer *bmpToSave);

		static void SaveBuffer(std::string fileName, ALLEGRO_BITMAP *bmpToSave);

	private:
		// GrahicsSystem class Data
		ALLEGRO_DISPLAY *pDisplay;

		ALLEGRO_BITMAP *pBackbuffer;
	};
}

#endif