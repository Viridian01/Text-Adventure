#include "Area.h"

Area::Area() {
	name = "Default Area";
}

Area::Area(string areaName, string areaDescription) {
	name = areaName;
	description = areaDescription;
}

void Area::addArea(Area &areaToAdd) {
	accessibleAreas.push_back(areaToAdd);
}

void Area::removeArea(Area areaToRemove) {
	int pos;
	pos = checkAccessible(areaToRemove.name);
	cout << "REMOVED ACCESS TO: " << areaToRemove.name << endl;
	accessibleAreas.erase(accessibleAreas.begin() + pos);
}

void Area::showAccessible(Area area) {
	for (unsigned int i = 0; i < area.accessibleAreas.size(); i++) {
		cout << area.accessibleAreas[i].name << endl;
	}
}

void Area::checkArea(Area area) {
	cout << area.description << endl;
	showAreaItems(area);
	showUsableObjects(area);
}

void Area::showAreaItems(Area area) {
	cout << "Usable items in area are: " << endl;
	for (unsigned int i = 0; i < area.areaItems.size(); i++) {
		cout << area.areaItems[i].name << endl;
	}
}

int Area::checkAccessible(string areaToCheck) {
	if (accessibleAreas.size() == 0) {
		cout << "No accessible areas." << endl;
		return -1;
	}
	else {
		for (unsigned int i = 0; i < accessibleAreas.size(); i++) {
			if (accessibleAreas[i].name == areaToCheck) {
				return i;
			}
			else if (i == accessibleAreas.size() - 1) {
				cout << "You cannot access: " << areaToCheck << endl;
				return -1;
			}
		}
	}
}

void Area::place(Object objectToPlace) {
	areaObjects.push_back(objectToPlace);
}

void Area::assign(Item itemToAssign) {
	areaItems.push_back(itemToAssign);
}

void Area::showUsableObjects(Area area) {
	cout << "Usable objects in area are: " << endl;
	for (unsigned int i = 0; i < area.areaObjects.size(); i++) {
		cout << area.areaObjects[i].name << endl;
	}
}
