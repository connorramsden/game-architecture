/*********************************************************************
**		Author:														**
**		Class: 310 <Section 0>										**
**		Assignment: pa 2											**
**		Certification of Authenticity:								**
**		I certify that this assignment is entirely my own work.	    **
**		Assingment 2 Author: Nick DaCosta							**
*********************************************************************/

#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

// C/C++ Includes
#include <iostream>

// DeanLib Includes
#include <Trackable.h>
#include <Vector2D.h>

// Allegro Includes
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// GraphicsLib Includes
#include "Font.h"
#include "GraphicsBuffer.h"
#include "Sprite.h"
#include "Color.h"

/// <summary>
///		Creates and maintains the display.
/// </summary>
/// <seealso cref="PerformanceTracker" />

class GraphicsSystem : public Trackable
{
public:
	// Create default graphics system.
	GraphicsSystem();

	// Destroy the display pointer.
	~GraphicsSystem();

	// GraphicsSystem initialize (don't call from constructor).
	void initialize(int _width, int _height);

	// Initialize Allegro components (call in initialize)
	void initAllegro();

	// Clean up the allegro system.
	void cleanUp();

	// Get the width of the display.
	int getWidth();

	// Get the height of the display.
	int getHeight();

	// Bring the back buffer to the main buffer.
	void updateDisplay();

	// Draw sprites.
	static void draw(Sprite _sprite, float _destinationX, float _destinationY, float _scale = 1.0);

	void drawScaledSprite(Sprite _sprite, float _destinationX, float _destinationY, float _scale);

	// Draw a buffer to a target buffer.
	static void draw(GraphicsBuffer& _drawBuffer, GraphicsBuffer& _targetBuffer, int _flag = BUFFER_TOP_LEFT, float _scale = 1.0f);

	// Draw directly to the back buffer.
	static void draw(GraphicsBuffer& _drawBuffer, int _justification = BUFFER_TOP_LEFT, float _scale = 1.0f);

	// Write text to the current back buffer.
	static void writeText(float _destinationX, float _destinationY, Font& _font, Color _color, std::string _text, int _flag = FONT_ALIGN_LEFT);

	// Write text to current backbuffer || ADDED BY CONNOR RAMSDEN
	static void writeText(Vector2D _destination, Font& _font, Color _color, std::string _text, int _flag = FONT_ALIGN_LEFT);

	// Write text to the given buffer.
	static void writeText(GraphicsBuffer& _buffer, float _destinationX, float _destinationY, Font& _font, Color _color, std::string _text, int _flag = FONT_ALIGN_LEFT);

	static void writeText(GraphicsBuffer& _buffer, Vector2D _destination, Font& _font, Color _color, std::string _text, int _flag = FONT_ALIGN_LEFT);

	// Save a buffer.
	static void saveBuffer(GraphicsBuffer& _buffer, std::string _fileName);

	// Set the buffer as a color.
	void setBufferColor(GraphicsBuffer& _buffer, Color _color);

	// Set the drawing position based on the flag.
	static void setDrawPosition(float& _positionX, float& _positionY, float _drawWidth, float _drawHeight, int _flag);

	// Get the back buffer of the display.
	GraphicsBuffer getBackBuffer();

private:
	// Member variable allegro display.
	ALLEGRO_DISPLAY* mpDisplay = nullptr;

	// Member variable to store a back buffer.
	GraphicsBuffer* mpBackBuffer = nullptr;

	// Member variable check for initialization.
	bool mIsInitialized = false;

	// Set the back buffer of the display.
	void setBackBuffer();

	// Set the buffer to draw on.
	void setBackBuffer(GraphicsBuffer& _buffer);

	// Get an Allegro color.
	static ALLEGRO_COLOR getColor(Color _color);
};

#endif