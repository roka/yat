#include <iostream>
#include <SFML/Graphics.hpp>
#include "graphics.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768 

#define NUM_ROWS 22
#define NUM_COLS 10
#define TEXTURE_SIZE 24

using namespace sf;
using namespace std;

/* Draw the borders of the "well" */
void drawBorders(RenderWindow &window)
{
	float x = (WINDOW_WIDTH/2) - ((NUM_COLS/2) * TEXTURE_SIZE);
	float y = 100;

	cout << "x=" << x << " y=" << y << endl;

	RectangleShape side(Vector2f(TEXTURE_SIZE, TEXTURE_SIZE*(NUM_ROWS))); // Rectangle covering the sides
	RectangleShape bottom(Vector2f(TEXTURE_SIZE*(NUM_COLS+5), TEXTURE_SIZE)); // Rectangle cover the bottom
	side.setFillColor(Color(100, 250, 50));
	bottom.setFillColor(Color(100, 250, 50));

	side.setPosition(x, y);
	window.draw(side);
	side.setPosition(x + ((NUM_COLS+4)*TEXTURE_SIZE), y);
	window.draw(side);
	bottom.setPosition(x, y+(NUM_ROWS*TEXTURE_SIZE));
	window.draw(bottom);
}

/* Draw the grid inside of the well */
void drawGrid(RenderWindow &window)
{
	float x = (WINDOW_WIDTH/2) - ((NUM_COLS/2) * TEXTURE_SIZE) + TEXTURE_SIZE;
	float y = 100;
	float tmpx = x;
	float tmpy = y;

	RectangleShape square(Vector2f(TEXTURE_SIZE, TEXTURE_SIZE));
	square.setFillColor(Color(0, 0, 0));
	square.setOutlineThickness(2);
	square.setOutlineColor(Color(250, 150, 100));

	for(int i=0; i < (NUM_ROWS*NUM_COLS); i++) {
		if(i % 10 == 0 && i != 0 ) {
			tmpy+=TEXTURE_SIZE;
			tmpx=x;
		}

		square.setPosition(tmpx, tmpy);
		window.draw(square);
		tmpx+=32;
	}
}

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Tetris");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    text.setPosition(200,200);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        //window.draw(sprite);
        // Draw the string
       // window.draw(text);
	drawBorders(window);
	drawGrid(window);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
