#ifndef __HIGHSCORE__H__
#define __HIGHSCORE__H__

#include "defines.h"
#include <string>

using namespace std;

class Highscore{
	private:
		string names[10];
		int highscores[10];
	public:
	       Highscore() {}	
	       ~Highscore() {}

	       void readHighscore();
	       bool isNewHighscore(int score) const;
	       void writeNewHighscore(int score, string name);

};
#endif
