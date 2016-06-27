#include "GameCopy.h"
#include "Sburb.h"

GameCopy::GameCopy() {
	name = "Game Beta Copy";
	description = "A small manilla packet that contains the hip new game that you have been waiting exactly 413 days for!";
	useMessage = "You rip the manilla packet to shreds, trying to get the prize inside. \nThe manilla packet is gone now, only the game itself remains.\nCAPTCHALOGUED: Sburb";
}

void GameCopy::use() {
	int pos = sylladex.checkItem(name);
	if (pos > -1) {
		Item* sburb = new Sburb();
		cout << useMessage << endl;
		sylladex.storage.erase(sylladex.storage.begin() + pos);
		sylladex.storage.push_back(sburb);
	}
}