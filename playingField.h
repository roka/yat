#ifndef __PLAYING_FIELD_H__
#define __PLAYING_FIELD_H__


#define NUM_COLS 10
#define NUM_ROWS 22

#include "block.h"
#include "tetriminos.h"

class PlayingField {
	private:
		int well[NUM_COLS][NUM_ROWS];
		//int **well;
		unsigned int gravity;
		unsigned int level;
	public:
		PlayingField() {
			this->gravity=1;
			this->level=1;
			int i,j;

			// zero initialize the well 
			for(i=0, j=0; j < NUM_ROWS; i++) {
				if( i % NUM_COLS == 0 && i != 0) {
					i=-1;
					j++;
					continue;
				}
				this->well[i][j] = 0;
			}
		}
		PlayingField(unsigned int gravity) {
			this->gravity = gravity;
		}
		int clearLines(); // Check if any lines should be cleared and returns the num of cleared lines	

		bool checkCollisionDown(Tetrimino t, int x, int y) const; // Checks if the falling terimino collieded with anything

		void addToWell(Tetrimino t, int x, int y); // Add a tetrimino to the well

		unsigned int getGravity() const;
		void updateGravity(unsigned int gravity);
		unsigned int getLevel() const;
		void updateLevel(unsigned int level);
		int getSquare(int x, int y) const {
			return (this->well[x][y]);
		}
		int checkWallKick(Tetrimino *t, int x, int y) const; // checks if a wall kick is possible

};

#endif
