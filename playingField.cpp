#include "playingField.h"

using namespace std;
/* Adds a tetrimino to the well */
void PlayingField::addToWell(Tetrimino t, int x, int y)
{
	int terimino[16];
	t.getArray(terimino);
	int ydelta=0, xdelta=0;

	/* Loop through the tetrimino and add it to the well matrix */
	for(int i=0; i < 16; i++) {
		if(i != 0 && i % 4 == 0) {
			ydelta++;
			xdelta=0;
		}

		if( (x+xdelta) <= NUM_COLS && (y+ydelta) <= NUM_ROWS ) { 
			if(terimino[i] != 0) {
				this->well[x+xdelta][y+ydelta] = terimino[i];
			}
		}
		xdelta++;
	}
}

bool PlayingField::checkCollisionDown(Tetrimino t, int x, int y) const
{
	bool collision = false;
	int tetrimino[16];
	int ydelta = 0;
	int xdelta = 0;
	t.getArray(tetrimino);

	for(int i=0; i < 16; i++) {
		if(i != 0 && i % 4 == 0) {
			ydelta++;
			xdelta=0;
		}

		if( (tetrimino[i] != 0 && this->well[x+xdelta][y+ydelta] != 0) || (tetrimino[i] && y+ydelta == NUM_ROWS)) {
			collision=true; break;
		}
		else if( (tetrimino[i] != 0 && (xdelta+x) < 0) || (tetrimino[i] != 0 && (xdelta+x) >= NUM_COLS)) {
			collision=true;
		}


		xdelta++;
	}

	return collision;
}

/* Check if any lines need to be cleared and returns the number of cleared lines */
int PlayingField::clearLines() 
{
	int linesCleared = 0;
	int x,y,ytmp;
	bool clear=true;

	for(y=0; y < NUM_ROWS; y++) {
		for(x=0; x < NUM_COLS; x++) {
			if(this->well[x][y] == 0) // check if line contains empty square
				clear=false;
		}
		if(clear) {
			linesCleared++;

			/* Move all rows one step down */
			for(ytmp=y; ytmp > 1; ytmp--) {
				for(x=0; x < NUM_COLS; x++) {
					this->well[x][ytmp] = this->well[x][ytmp-1];
					this->well[x][ytmp-1] = 0;
				}
			}
			y--;
		}
		clear=true;
	}
	return linesCleared;
}

/* Checks if a wall kick is possible
 * return 0 if the wallkick fails
 * return the x delta if the wallkick is successfull */
int PlayingField::checkWallKick(Tetrimino *t, int x, int y) const
{
	bool kick;
	int cur_x = x;
	for(int i=0; i < 4 && (cur_x+i) < NUM_COLS; i++) {
		if(!this->checkCollisionDown(*t, cur_x+i, y)) {
			cur_x += i;
			i=3;
			kick=true;
		}
	}
	if(kick == false) {
		for(int i=0; i > -4 && (cur_x+i) < NUM_COLS && (cur_x+i) > 0; i--) {
			if(!this->checkCollisionDown(*t, cur_x+i, y)) {
				cur_x += i;
				i=-4;
				kick=true;
			}
		}
	}

	if(kick)
		return (cur_x-x);
	return 0;
}

unsigned int PlayingField::getGravity() const
{
	return this->gravity;
}

void PlayingField::updateGravity(unsigned int gravity)
{
	this->gravity = gravity;
}