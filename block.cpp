#include "block.h"

using namespace sf;

RectangleShape Block::getSolid() const // Returns a solid square
{
	RectangleShape b(Vector2f(this->textureSize, this->textureSize));
	b.setFillColor(Color(this->red,this->green,this->blue));
	b.setOutlineThickness(-2.f);
	b.setOutlineColor(Color((this->red) + 10, (this->green) + 10, (this->blue) + 10));

	return b;
	
}

RectangleShape Block::getGhost() const // Returns a transparent square
{
	RectangleShape b(Vector2f(this->textureSize, this->textureSize));
	b.setFillColor(Color(this->red,this->green,this->blue, this->alpha));
	b.setOutlineThickness(-2.f);
	b.setOutlineColor(Color((this->red) + 10, (this->green) + 10, (this->blue) + 10, this->alpha));

	return b;
}
