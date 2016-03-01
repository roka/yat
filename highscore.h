#ifndef __HIGHSCORE__H__
#define __HIGHSCORE__H__

#include "defines.h"
#include <string>

using namespace std;

class Highscore{
	private:
		string *names;
		int *highscores;
	public:
	       Highscore() {
		       this->names = new string[MAX_HIGHSCORES];
		       this->highscores = new int[MAX_HIGHSCORES];

	       }	
	       ~Highscore() {
		       delete[] this->names;
		       delete[] this->highscores;
	       }

	       void readHighscore();
	       bool isNewHighscore(int score) const;
	       void writeNewHighscore(int score, string name);

	       string *getNames() const { return this->names; }
	       int *getHighscores() const { return this->highscores; }

};
#endif
