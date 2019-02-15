#include "GraphicsBuffer.h"

// Part of the 'Graphics' namespace
namespace Graphics
{
	GraphicsBuffer::GraphicsBuffer()
	{
		pBitmap = NULL;
	}

	GraphicsBuffer::GraphicsBuffer(std::string assetPath, std::string fileName)
	{
		pBitmap = al_load_bitmap((assetPath + fileName).c_str());
	}

	GraphicsBuffer::GraphicsBuffer(int bmpWidth, int bmpHeight)
	{
		pBitmap = al_create_bitmap(bmpWidth, bmpHeight);
	}

	GraphicsBuffer::~GraphicsBuffer()
	{
		al_destroy_bitmap(pBitmap);
	}

	int GraphicsBuffer::getBmpWidth()
	{
		return al_get_bitmap_width(pBitmap);
	}

	int GraphicsBuffer::getBmpHeight()
	{
		return al_get_bitmap_height(pBitmap);
	}

	ALLEGRO_COLOR GraphicsBuffer::getColor(std::string clr)
	{
		if (clr == "RED" || clr == "red")
		{
			return RED;
		}
		else if (clr == "WHITE" || clr == "white")
		{
			return WHITE;
		}
		else if (clr == "BLACK" || clr == "black")
		{
			return BLACK;
		}
	}
	
	void GraphicsBuffer::clearBufferToColor(std::string color)
	{
		al_set_target_bitmap(pBitmap);

		if (color == "RED" || color == "red")
		{
			al_clear_to_color(RED);
		}
		else if (color == "WHITE" || color == "white")
		{
			al_clear_to_color(WHITE);
		}
		else if (color == "BLACK" || color == "black")
		{
			al_clear_to_color(BLACK);
		}
	}
}