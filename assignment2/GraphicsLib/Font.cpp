#include "Font.h"

namespace Graphics
{
	Font::Font(std::string assetPath, std::string fileName, int size)
	{
		fontSize = size;

		pFont = al_load_ttf_font((assetPath + fileName).c_str(), fontSize, 0);
	}
	
	Font::~Font()
	{
		al_destroy_font(pFont);
	}
}