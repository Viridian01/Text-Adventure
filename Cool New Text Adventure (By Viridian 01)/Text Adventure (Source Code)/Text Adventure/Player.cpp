#include "Player.h"

Player::Player() {

}

void Player::setArea(Area toArea) {
	currentArea = toArea;
	cout << "You go to the : " << toArea.name << endl;
}

void Player::checkObject(string object, Area area) {
	for (unsigned int i = 0; i < area.areaObjects.size(); i++) {
		if (area.areaObjects[i].name == object) {
			cout << "You check the: " << area.areaObjects[i].name << "." << endl;
			cout << area.areaObjects[i].description << endl;
		}
	}
}
