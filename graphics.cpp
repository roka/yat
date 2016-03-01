/* Graphics.cpp */
#include "graphics.h"

#include <iostream>
#include <sstream>

using namespace std;

void Graphics::drawBorders() // draw the borders of the tetris well
{
	RectangleShape side(Vector2f(this->textureSize, textureSize*NUM_ROWS)); // rectangle covering the sides	
	RectangleShape bottom(Vector2f(this->textureSize*(NUM_COLS+2), textureSize)); // rectangle covering the bottom
	side.setFillColor(Color(100, 250, 50));
	bottom.setFillColor(Color(100, 250, 50));

	side.setPosition(this->wellX, this->wellY);
	this->draw(side);
	side.setPosition(this->wellX + ((NUM_COLS+1)*this->textureSize), this->wellY);
	this->draw(side);
	bottom.setPosition(this->wellX, this->wellY+(NUM_ROWS*this->textureSize));
	this->draw(bottom);
}

void Graphics::drawScore(int score)
{
	stringstream ss;
	ss << score;

	Text text(ss.str(), this->font);
	text.setCharacterSize(30);
	text.setColor(Color::White);
	text.setPosition(this->wellX + (NUM_COLS*this->textureSize) + 100,this->wellY);
	text.setStyle(Text::Bold);
	this->draw(text);
}

void Graphics::printGameOver()
{
	Text text("Game Over!", this->font);
	text.setCharacterSize(50);
	text.setColor(Color::White);
	text.setPosition(this->wellX,this->wellY + 200 );
	text.setStyle(Text::Bold);
	this->draw(text);
}

void Graphics::drawGrid() // draw the grids inside of the tetris well
{
	float tmpx = this->wellX + this->textureSize;
	float tmpy = this->wellY;

	RectangleShape square(Vector2f(this->textureSize, this->textureSize));
	square.setFillColor(Color(0, 0, 0));
	square.setOutlineThickness(-2.f);
	square.setOutlineColor(Color(250, 150, 100, 50));

	for(int i=0; i < (NUM_ROWS*NUM_COLS); i++) {
		if(i % 10 == 0 && i != 0 ) {
			tmpy+=this->textureSize;
			tmpx=this->wellX + this->textureSize;
		}

		square.setPosition(tmpx, tmpy);
		this->draw(square);
		tmpx+=this->textureSize;
	}
}

bool Graphics::drawBlock(RectangleShape b, int x, int y) // draw block to cord
{
	// check that we are drawing inside of the well
	if( x >= 0 && x < NUM_COLS && y >= 0 && y < NUM_ROWS) {
		b.setPosition( (x * this->textureSize) + this->wellX + textureSize,
				(y * this->textureSize) + this->wellY);
		this->draw(b);
		return true;
	}
	return false; 
}

float Graphics::getTextureSize() const
{
	return this->textureSize;
}

bool Graphics::drawTetrimino(Tetrimino t, int x, int y) // Draw a tetrimino to cord
{
	int tmpx=x;
	int ary[16];
	t.getArray(ary);

	for(int i=0; i < 16; i++) {
		if(i % 4 == 0 && i != 0) {
			tmpx=x;
			y++;
		}
		if( ary[i] != 0)
			this->drawBlock(t.getBlock().getSolid(), tmpx, y);
		tmpx++;
	}

	return true;
}

void Graphics::drawGhost(Tetrimino t, int x, int y, PlayingField p)
{
	int tmpx=x;
	int ary[16];
	t.getArray(ary);
	while(!p.checkCollisionDown(t, x, y+1))
		y++;

	for(int i=0; i < 16; i++) {
		if(i % 4 == 0 && i != 0) {
			tmpx=x;
			y++;
		}
		if( ary[i] != 0)
			this->drawBlock(t.getBlock().getGhost(), tmpx, y);
		tmpx++;
	}
}

void Graphics::drawWell(PlayingField p)
{
	int i,j;

	for(i=0, j=0; j < NUM_ROWS; i++) {
		if( i != 0 && i % NUM_COLS == 0) {
			i=-1;
			j++;
			continue;
		}
		if( p.getSquare(i, j) )
			this->drawBlock(this->bTetrimino[p.getSquare(i,j)-1]->getSolid(), i, j);
	}
}
