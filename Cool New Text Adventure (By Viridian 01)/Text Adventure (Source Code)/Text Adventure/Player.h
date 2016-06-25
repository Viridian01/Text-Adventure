#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include "Area.h"
#include "Object.h"

using namespace std;

class Player {
	public:
		Player();
		void setArea(Area toArea);
		void checkObject(string object, Area area);
		Area currentArea;
};
#endif

