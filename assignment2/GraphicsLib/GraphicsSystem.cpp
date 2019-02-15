#include "GraphicsSystem.h"

namespace Graphics
{
	GraphicsSystem::GraphicsSystem()
	{
		pDisplay = NULL;
		pBackbuffer = NULL;
	}

	GraphicsSystem::~GraphicsSystem()
	{
		cleanupGS();
	}

	int GraphicsSystem::initGS(int displayWidth, int displayHeight)
	{
		// Ensures all Allegro add-ons are properly initialized
		if (!al_init())
		{
			std::cout << "error initting Allegro\n";
			return 1;
		}
		if (!al_init_image_addon())
		{
			std::cout << "error - Image Add-on not initted\n";
			return 1;
		}
		if (!al_init_font_addon())
		{
			std::cout << "error - Font Add-on not initted\n";
			return 1;
		}
		if (!al_init_ttf_addon())
		{
			std::cout << "error - TTF Add-on not initted\n";
			return 1;
		}
		if (!al_init_primitives_addon())
		{
			std::cout << "error - primitives Add-on not initted\n";
			return 1;
		}
		if (!al_install_audio())
		{
			std::cout << "error - Audio Add-on not initted\n";
			return 1;
		}
		if (!al_init_acodec_addon())
		{
			std::cout << "error - Audio Codec Add-on not initted\n";
			return 1;
		}
		if (!al_reserve_samples(1))
		{
			std::cout << "error - samples not reserved\n";
			return 1;
		}

		// Creates a new display with the passed resolution
		pDisplay = al_create_display(displayWidth, displayHeight);

		// Assets the display into memory
		assert(pDisplay);

		// Clears the backbuffer to the passed color
		al_clear_to_color(al_map_rgb(255, 255, 255));

		pBackbuffer = al_get_backbuffer(pDisplay);

		return 0;
	}

	void GraphicsSystem::cleanupGS()
	{
		al_destroy_display(pDisplay);
	}

	void GraphicsSystem::flipDisplay()
	{
		al_flip_display();
	}

	int GraphicsSystem::getDisplayWidth()
	{
		return al_get_display_width(pDisplay);
	}

	int GraphicsSystem::getDisplayHeight()
	{
		return al_get_display_height(pDisplay);
	}

	ALLEGRO_BITMAP * GraphicsSystem::getBackbuffer()
	{
		return pBackbuffer;
	}

	void GraphicsSystem::Draw(int xLoc, int yLoc, GraphicsBuffer * bmpToDraw)
	{
		ALLEGRO_BITMAP *bmp = bmpToDraw->getBuffer();

		al_draw_bitmap(bmp, xLoc, yLoc, 0);
	}

	void GraphicsSystem::Draw(ALLEGRO_BITMAP * targetBuffer, int xLoc, int yLoc, GraphicsBuffer * bmpToDraw, float scaleBy)
	{
		ALLEGRO_BITMAP *bmp = bmpToDraw->getBuffer();
		int bmpWidth = bmpToDraw->getBmpWidth();
		int bmpHeight = bmpToDraw->getBmpHeight();

		al_set_target_bitmap(targetBuffer);

		al_draw_scaled_bitmap(bmp, xLoc, yLoc, bmpWidth, bmpHeight, xLoc, yLoc, bmpWidth * scaleBy, bmpHeight * scaleBy, 0);
	}

	void GraphicsSystem::Draw(int xLoc, int yLoc, GraphicsBuffer * bmpToDraw, float scaleBy)
	{
		ALLEGRO_BITMAP *bmp = bmpToDraw->getBuffer();
		int bmpWidth = bmpToDraw->getBmpWidth();
		int bmpHeight = bmpToDraw->getBmpHeight();

		al_draw_scaled_bitmap(bmp, xLoc, yLoc, bmpWidth, bmpHeight, xLoc, yLoc, bmpWidth * scaleBy, bmpHeight * scaleBy, 0);
		
	}

	void GraphicsSystem::Draw(GraphicsBuffer * targetBuffer, int xLoc, int yLoc, GraphicsBuffer * bmpToDraw, float scaleBy)
	{
		ALLEGRO_BITMAP *bmp = bmpToDraw->getBuffer();
		ALLEGRO_BITMAP *newTarget = targetBuffer->getBuffer();
		int bmpWidth = bmpToDraw->getBmpWidth();
		int bmpHeight = bmpToDraw->getBmpHeight();

		al_set_target_bitmap(newTarget);

		al_draw_scaled_bitmap(bmp, xLoc, yLoc, bmpWidth, bmpHeight, xLoc, yLoc, bmpWidth * scaleBy, bmpHeight * scaleBy, 0);
	}

	void GraphicsSystem::Draw(int xLoc, int yLoc, Sprite * spriteToDraw)
	{
		ALLEGRO_BITMAP *bmp = spriteToDraw->getSprite();

		al_draw_bitmap(bmp, xLoc, yLoc, 0);
	}
	
	void GraphicsSystem::Write(int xLoc, int yLoc, Font * font, ALLEGRO_COLOR txtClr, std::string txt)
	{
		al_draw_text(font->getFont(), txtClr, xLoc, yLoc, 0, txt.c_str());
	}
	
	void GraphicsSystem::Write(GraphicsBuffer * targetBuffer, int xLoc, int yLoc, Font * font, ALLEGRO_COLOR txtClr, std::string txt)
	{
		ALLEGRO_BITMAP *newTarget = targetBuffer->getBuffer();

		al_set_target_bitmap(newTarget);

		al_draw_text(font->getFont(), txtClr, xLoc, yLoc, 0, txt.c_str());
	}

	void GraphicsSystem::SaveBuffer(std::string fileName, GraphicsBuffer * bmpToSave)
	{
		ALLEGRO_BITMAP *bmp = bmpToSave->getBuffer();

		al_save_bitmap((fileName).c_str(), bmp);
	}

	void GraphicsSystem::SaveBuffer(std::string fileName, ALLEGRO_BITMAP * bmpToSave)
	{
		al_save_bitmap((fileName).c_str(), bmpToSave);
	}
}