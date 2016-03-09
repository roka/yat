#ifndef __GRAPHICS_H__
#define __GRAPHICS_H_

#include <SFML/Graphics.hpp>

#include "defines.h"
#include "block.h"
#include "tetriminos.h"
#include "playingField.h"

using namespace sf;
using namespace std;

class Graphics : public RenderWindow {
	private:
		int windowWidth;
		int windowHeight;
		float wellX; // Starting X pos of the "tetris well"
		float wellY; // String Y pos of the "tetris well"
		float textureSize; // The default size for all blocks

		/* Blocks for all in-game tetriminos */
		Block *bTetrimino[7];

		Font font;

	public:
		Graphics(int windowWidth, int windowHeight) {
			this->windowWidth = windowWidth;
			this->windowHeight = windowHeight;
			this->textureSize = 24;

			this->wellX = (this->windowWidth/2) - ((NUM_COLS/2) * this->textureSize);
			this->wellY = 100;

			// Create main window
			create(VideoMode(this->windowWidth, this->windowHeight), "Tetris");

			// Initalize all blocks
			this->bTetrimino[0] = new Block(0x00, 0xff, 0xff, 0xff, this->textureSize); 
			this->bTetrimino[1] = new Block(0x00, 0x00, 0xff, 0xff, this->textureSize);
			this->bTetrimino[2] = new Block(0xff, 0xaa, 0x00, 0xff, this->textureSize);
			this->bTetrimino[3] = new Block(0xff, 0xff, 0x00, 0xff, this->textureSize);
			this->bTetrimino[4] = new Block(0x00, 0xff, 0x00, 0xff, this->textureSize);
			this->bTetrimino[5] = new Block(0x99, 0x00, 0xff, 0xff, this->textureSize);
			this->bTetrimino[6] = new Block(0xff, 0x00, 0x00, 0xff, this->textureSize);

			/* Load Font */
			font.loadFromFile("arial.ttf");
		}

		float getTextureSize() const; // Get the texture size

		void drawBorders(); // draw the borders of the tetris well
		void drawGrid(); // draw the grids inside of the tetris well
		void drawWell(PlayingField p); // draws the well
		bool drawBlock(RectangleShape b, int x, int y); // draw block to cord
		bool drawTetrimino(Tetrimino t, int x, int y); // draw a tetrimino to cord
		void drawGhost(Tetrimino t, int x, int y, PlayingField p); // draw a ghost tetrimino
		void drawScore(int score); // print the score to the screen
		void printGameOver(); // print game over to the screen
		void showHighscores(int *highscores, string *names); // shows the highscores
		string enterName();
};

#endif
