#ifndef FONT_H
#define FONT_H

// Includes from C/C++ library
#include <string>
#include <iostream>

// Includes from Allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// Includes from DeanLib
#include <PerformanceTracker.h>
#include <MemoryTracker.h>

// Part of the 'Graphics' namespace
namespace Graphics
{
	// Class 'Font', extends DeanLib's Trackable
	class Font : public Trackable
	{
	public:
		// Font class Constructor
		Font(std::string assetPath, std::string fileName, int size);
		// Font class Deconstructor
		~Font();

		// Font class Getters
		int getFontSize() { return fontSize; }

		ALLEGRO_FONT * getFont() { return pFont; }

		// Font class Setters
		void setFontSize(int size) { fontSize = size; }


	private:
		ALLEGRO_FONT *pFont;
		int fontSize;

		friend class GraphicsSystem;
	};
}

#endif