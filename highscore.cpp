#include "highscore.h"
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

/* Read the highscores from a text file */
void Highscore::readHighscore()
{
	string line;
	ifstream highscoreFile ("highscore.txt");
	int i=0;
	if(highscoreFile.is_open())
	{
		while(getline(highscoreFile, line) && i < MAX_HIGHSCORES ) { // get the name
			this->names[i] = line;	
			getline(highscoreFile, line); // get the highscore
			this->highscores[i] = atoi(line.c_str());
			i++;
		}

		highscoreFile.close();
	}

	/* Zero the rest of the scores */
	for(i=i; i < MAX_HIGHSCORES; i++) {
		this->names[i] = "";
		this->highscores[i] = 0;
	}
}

/* check if a score should be added to the highscore */
bool Highscore::newHighscore(int score) const
{
	return false;
}

/* add a new score to the highscore list */
void Highscore::writeNewHighscore(int score, string name)
{
}


