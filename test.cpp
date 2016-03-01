#include "graphics.h"
#include "tetriminos.h"
#include "playingField.h"

#include <iostream>

using namespace std;
using namespace sf;

int main() 
{
	Graphics graphics(1024, 769);
	PlayingField *play = new PlayingField();
	int k=1;
	int score = 0;

	//Tetrimino t( k, 24 );
	Tetrimino *t = new Tetrimino(k,24);

	Clock clock;
	Time deltaTime;
	deltaTime = clock.restart();

	int cur_x = 5;
	int cur_y = 0;

	Clock gameClock;
	gameClock.restart();

	while(graphics.isOpen()) {
		sf::Event event;
		while( graphics.pollEvent(event) )
		{
			// Close Window: exit
			if (event.type == Event::Closed)
				graphics.close();
		}

		if(clock.getElapsedTime().asSeconds() > 0.1) {
			/* Rotate left */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				t->rotateLeft();
				if(play->checkCollisionDown(*t, cur_x, cur_y))
					t->rotateRight();
			}
			/* Rotate Right */
		       	else if (Keyboard::isKeyPressed(sf::Keyboard::X)) {
				t->rotateRight();
				if(play->checkCollisionDown(*t, cur_x, cur_y))
					t->rotateLeft();
			}
			/* Move left */
		       	else if(Keyboard::isKeyPressed(Keyboard::Left) ||
					Keyboard::isKeyPressed(Keyboard::H)) {
				if(!play->checkCollisionDown(*t, cur_x-1, cur_y))
					cur_x--;
			} 
			/* Move Right */
		       	else if(Keyboard::isKeyPressed(Keyboard::Right) ||
					Keyboard::isKeyPressed(Keyboard::L)) {
				if(!play->checkCollisionDown(*t, cur_x+1, cur_y))
					cur_x++;
			}
			/* Move Down */
		       	else if(Keyboard::isKeyPressed(Keyboard::Down)) {
				if(!play->checkCollisionDown(*t, cur_x, cur_y+1))
					cur_y++;
			}
			/* Hard Drop */
			else if(Keyboard::isKeyPressed(Keyboard::Up)) {
				while(!play->checkCollisionDown(*t, cur_x, cur_y+1))
					cur_y++;
			}

			//printf("%d:%d\n", cur_x, cur_y);

			clock.restart();
		}
		graphics.clear();
		graphics.drawBorders();
		graphics.drawGrid();
		graphics.drawWell(*play);
		if(gameClock.getElapsedTime().asSeconds() > 0.25) {
			if(!play->checkCollisionDown(*t, cur_x, cur_y+1))
				cur_y++;
			else { // collision, add the tetrimino to the well
				play->addToWell(*t, cur_x, cur_y);
				score += play->clearLines();
				/* reset x and y */
				cur_x = 5;
				cur_y = 0;
				k++;
				if(k==8)
					k=1;
				t = new Tetrimino( k, 24 );
			}
			/* Check game over */
			if(cur_y == 0 && play->checkCollisionDown(*t, cur_x, cur_y)) {
				graphics.printGameOver();
				graphics.drawScore(score);
				graphics.display();
				sleep( seconds(2) );
				delete play;
				play = new PlayingField();
				score = 0;
			}

			gameClock.restart();
		}
		graphics.drawTetrimino(*t, cur_x, cur_y);
		graphics.drawGhost(*t, cur_x, cur_y, *play);
		graphics.drawScore(score);

		graphics.display();
	}
	return 0;
}
