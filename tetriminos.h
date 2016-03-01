#ifndef __TETRIMINOS_H__
#define __TETRIMINOS_H__

#define TETRIMINO_I	1
#define TETRIMINO_J	2
#define TETRIMINO_L	3
#define TETRIMINO_O	4
#define TETRIMINO_S	5
#define TETRIMINO_T	6
#define TETRIMINO_Z	7

#include "block.h"

#include <iostream>
#include <algorithm>

using namespace std;

class Tetrimino {
	private:
		Block block;
		int array[4][16];
		int rotation;

	public:
		Tetrimino(int tetrimino, float textureSize) {
			int i,j;
			
			if( tetrimino == TETRIMINO_I )  {
				// Teal
				Block b(0x00, 0xff, 0xff, 0x8c, textureSize);

				
				int ary[4][16] = {
					0,0,0,0,
					1,1,1,1,
					0,0,0,0,
					0,0,0,0,

					0,0,1,0,
					0,0,1,0,
					0,0,1,0,
					0,0,1,0,

					0,0,0,0,
					0,0,0,0,
					1,1,1,1,
					0,0,0,0,

					0,1,0,0,
					0,1,0,0,
					0,1,0,0,
					0,1,0,0
				};
				for(i=0, j=0; j < 4; i++) {
				if(i%16 == 0 && i != 0) {
					i=0;
					j++;
				}
				if( j< 4)
				array[j][i] = ary[j][i];
				this->block = b;
			}}
			else if( tetrimino == TETRIMINO_J )  {
				Block b(0x00, 0x00, 0xff, 0x8c, textureSize);
				
				int ary[4][16] = {
					2,0,0,0,
					2,2,2,0,
					0,0,0,0,
					0,0,0,0,

					0,2,2,0,
					0,2,0,0,
					0,2,0,0,
					0,0,0,0,

					0,0,0,0,
					2,2,2,0,
					0,0,2,0,
					0,0,0,0,

					0,2,0,0,
					0,2,0,0,
					2,2,0,0,
					0,0,0,0
				};
				for(i=0, j=0; j < 4; i++) {
				if(i%16 == 0 && i != 0) {
					i=0;
					j++;
				}
				if( j< 4)
				array[j][i] = ary[j][i];
				this->block = b;
			}}
			else if( tetrimino == TETRIMINO_L )  {
				Block b(0xff, 0xaa, 0x00, 0x8c, textureSize);
				
				int ary[4][16] = {
					0,0,3,0,
					3,3,3,0,
					0,0,0,0,
					0,0,0,0,

					0,3,0,0,
					0,3,0,0,
					0,3,3,0,
					0,0,0,0,

					0,0,0,0,
					3,3,3,0,
					3,0,0,0,
					0,0,0,0,

					3,3,0,0,
					0,3,0,0,
					0,3,0,0,
					0,0,0,0
				};
				for(i=0, j=0; j < 4; i++) {
				if(i%16 == 0 && i != 0) {
					i=0;
					j++;
				}
				if( j< 4)
				array[j][i] = ary[j][i];
				this->block = b;
			}}
			else if( tetrimino == TETRIMINO_O )  {
				Block b(0xff, 0xff, 0x00, 0x8c, textureSize);
				
				int ary[4][16] = {
					0,4,4,0,
					0,4,4,0,
					0,0,0,0,
					0,0,0,0,

					0,4,4,0,
					0,4,4,0,
					0,0,0,0,
					0,0,0,0,

					0,4,4,0,
					0,4,4,0,
					0,0,0,0,
					0,0,0,0,

					0,4,4,0,
					0,4,4,0,
					0,0,0,0,
					0,0,0,0
				};
				for(i=0, j=0; j < 4; i++) {
				if(i%16 == 0 && i != 0) {
					i=0;
					j++;
				}
				if( j< 4)
				array[j][i] = ary[j][i];
				this->block = b;
			}}
			else if( tetrimino == TETRIMINO_S )  {
				Block b(0x00, 0xff, 0x00, 0x8c, textureSize);
				
				int ary[4][16] = {
					0,5,5,0,
					5,5,0,0,
					0,0,0,0,
					0,0,0,0,

					0,5,0,0,
					0,5,5,0,
					0,0,5,0,
					0,0,0,0,

					0,0,0,0,
					0,5,5,0,
					5,5,0,0,
					0,0,0,0,

					5,0,0,0,
					5,5,0,0,
					0,5,0,0,
					0,0,0,0
				};
				for(i=0, j=0; j < 4; i++) {
				if(i%16 == 0 && i != 0) {
					i=0;
					j++;
				}
				if( j< 4)
				array[j][i] = ary[j][i];
				this->block = b;
			}}
			else if( tetrimino == TETRIMINO_T )  {
				Block b(0x99, 0x00, 0xff, 0x8c, textureSize);
				
				int ary[4][16] = {
					0,6,0,0,
					6,6,6,0,
					0,0,0,0,
					0,0,0,0,

					0,6,0,0,
					0,6,6,0,
					0,6,0,0,
					0,0,0,0,

					0,0,0,0,
					6,6,6,0,
					0,6,0,0,
					0,0,0,0,

					0,6,0,0,
					6,6,0,0,
					0,6,0,0,
					0,0,0,0
				};
				for(i=0, j=0; j < 4; i++) {
				if(i%16 == 0 && i != 0) {
					i=0;
					j++;
				}
				if( j< 4)
				array[j][i] = ary[j][i];
				this->block = b;
			}}
			else if( tetrimino == TETRIMINO_Z )  {
				Block b(0xff, 0x00, 0x00, 0x8c, textureSize);
				
				int ary[4][16] = {
					7,7,0,0,
					0,7,7,0,
					0,0,0,0,
					0,0,0,0,

					0,0,7,0,
					0,7,7,0,
					0,7,0,0,
					0,0,0,0,

					0,0,0,0,
					7,7,0,0,
					0,7,7,0,
					0,0,0,0,

					0,7,0,0,
					7,7,0,0,
					7,0,0,0,
					0,0,0,0
				};
				for(i=0, j=0; j < 4; i++) {
				if(i%16 == 0 && i != 0) {
					i=0;
					j++;
				}
				if( j< 4)
				array[j][i] = ary[j][i];
				this->block = b;
			}}



			this->rotation = 0;

		}

		Block getBlock() const;
		void getArray(int *arr) const;

		void rotateLeft();
		void rotateRight();	
};

#endif
