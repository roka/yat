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
bool Highscore::isNewHighscore(int score) const
{
	for(int i=0; i < MAX_HIGHSCORES; i++) {
		if(this->highscores[i] < score)
			return true;
	}
	return false;
}

/* add a new score to the highscore list */
void Highscore::writeNewHighscore(int score, string name)
{
	int index;
	/* Find the index for the new highscore */
	for(index=0; index < MAX_HIGHSCORES; index++)
	{
		if(score > this->highscores[index])
			break;
	}

	/* exit function if this is not a valid highscore */
	if(index == 10)
		return;
	
	/* Move down all highscores after index */
	for(int i=(MAX_HIGHSCORES-2); i >= index; i--) {
		this->names[i+1] = this->names[i];
		this->highscores[i+1] = this->highscores[i];
	}

	/* Add the new highscore */
	this->names[index] = name;
	this->highscores[index] = score;

	/* Write the highscores to disk */
	ofstream highscoreFile("highscore.txt");
	if(highscoreFile.is_open())
	{
		for(int i = 0; i < MAX_HIGHSCORES; i++) {
			highscoreFile << this->names[i] << endl;
			highscoreFile << this->highscores[i] << endl;
		}
		highscoreFile.close();
	}
}


