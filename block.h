#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <cstdint>
#include <SFML/Graphics.hpp>

using namespace sf;

class Block {
	private:
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
		float	textureSize;
	public:
		Block() {
		}
		Block(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha, float textureSize) {
			this->red = red;
			this->green = green;
			this->blue = blue;
			this->alpha = alpha;
			this->textureSize = textureSize;
		};

		RectangleShape getSolid() const; // Returns a solid square
		RectangleShape getGhost() const; // Returns a transparent square
		
};

#endif
