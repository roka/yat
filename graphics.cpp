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
	text.setPosition(this->wellX,this->wellY - 100 );
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

/* Shows the highscores on the screen */
void Graphics::showHighscores(int *highscores, string *names)
{
	stringstream score;
	for(int i=0; i < MAX_HIGHSCORE; i++)
	{
		// Get text
		Text name(names[i], this->font);
		score.str(string());
		score << highscores[i];
		Text highscore(score.str(), this->font);

		// Set size, pos and color
		name.setCharacterSize(30);
		highscore.setCharacterSize(30);
		name.setColor(Color::White);
		highscore.setColor(Color::White);
		name.setPosition( this->wellX, this->wellY + (i*30) );
		highscore.setPosition( this->wellX+200, this->wellY + (i*30 ));

		// draw
		this->draw(name);
		this->draw(highscore);
	}
}

/* new highscore enter name */
string Graphics::enterName()
{
	string name;
	bool running=true;
	Text enterN("New Highscore\nEnter name:", this->font);	
	enterN.setCharacterSize(30);
	enterN.setColor(Color::White);
	enterN.setPosition(this->wellX, this->wellY);

	sf::Event event;
	while(running) {
	while(this->pollEvent(event)) {
		if(event.type == Event::Closed)
			this->close();
		if (event.type == sf::Event::TextEntered){
			//if(event.KeyPressed == sf::Keyboard::BackSpace && name.size()!=0){
			if(Keyboard::isKeyPressed(Keyboard::BackSpace) && name.size() != 0) {
				name.pop_back();
			}
			else if(Keyboard::isKeyPressed(Keyboard::Return)) {
				running=false;
			}
			else if (event.text.unicode < 128) {
			    name.push_back((char)event.text.unicode);
		}
		this->clear( Color(0,0,0,255) );

		Text nameT(name, this->font);
		nameT.setCharacterSize(30);
		nameT.setColor(Color::White);
		nameT.setPosition(this->wellX, this->wellY+60);
		this->draw(nameT);
		    }
		}
		this->draw(enterN);
		this->display();
	}

	return name;
}
