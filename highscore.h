#ifndef __HIGHSCORE__H__
#define __HIGHSCORE__H__

#define MAX_HIGHSCORES 10

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
	       bool newHighscore(int score) const;
	       void writeNewHighscore(int score, string name);

};
#endif
