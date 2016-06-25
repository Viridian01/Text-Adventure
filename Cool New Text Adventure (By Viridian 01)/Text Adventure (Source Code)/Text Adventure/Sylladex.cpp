#include "Sylladex.h"
#include "Area.h"
#include "Player.h"
#include "Item.h"

Sylladex::Sylladex() {

}

void Sylladex::inspect(string itemToInspect) {
	int pos = checkItem(itemToInspect);
	if (pos > -1) {
		cout << "You inspect: " << itemToInspect << endl;
		cout << storage[pos].description << endl;
	}
}

void Sylladex::pickUp(string itemToPick, Area &area) {
	for (unsigned int i = 0; i < area.areaItems.size(); i++) {
		if (area.areaItems[i].name == itemToPick) {
			storage.push_back(area.areaItems[i]);
			area.areaItems.erase(area.areaItems.begin() + i);
			cout << "You picked up " << itemToPick << " and captchalogued it." << endl;
		}
	}
}

int Sylladex::checkItem(string itemToCheck) {
	if (storage.size() == 0) {
		cout << "You don't have: " << itemToCheck << endl;
		return -1;
	}
	else {
		for (unsigned int i = 0; i < storage.size(); i++) {
			if (storage[i].name == itemToCheck) {
				return i;
			}
			else if (i == storage.size() - 1) {
				cout << "You don't have: " << itemToCheck << endl;
				return -1;
			}
		}
	}
}

void Sylladex::view() {
	if (storage.size() == 0) {
		cout << "Your Sylladex is empty, ya dingus!" << endl;
	}
	else if (storage.size() > 0) {
		cout << "Sylladex: " << endl;
		for (unsigned int i = 0; i < storage.size(); i++) {
			cout << storage[i].name << endl;
		}
	}
}

void Sylladex::dropItem(string itemToDrop, Area &area) {
	int pos = checkItem(itemToDrop);
	if (pos > -1) {
		area.areaItems.push_back(storage[pos]);
		storage.erase(storage.begin() + pos);
		cout << "You dropped " << itemToDrop << " in " << area.name << "." << endl;
	}
}

void Sylladex::useItem(string itemToUse) {
	int pos = checkItem(itemToUse);
	if (pos > -1) {
		cout << "You use: " << itemToUse << endl;
		cout << storage[pos].use << endl;
	}
}