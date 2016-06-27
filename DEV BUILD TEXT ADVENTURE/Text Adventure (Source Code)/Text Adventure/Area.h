#ifndef AREA_H
#define AREA_H
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
#include "Object.h"

using namespace std;

class Area {
	public:
		Area();
		Area(string setName, string setDesc);
		
		string name;
		string description;

		void addAccessibleArea(string areaToAdd);
		void addArea(Area areaToAdd);
		void removeArea(Area areaToRemove);
		void showAccessible(Area area);
		void checkArea(Area area);
		void showAreaItems(Area area);
		int checkAccessible(string areaToCheck);
		void assign(Item itemToAssign);
		void place(Object objectToPlace);
		void showUsableObjects(Area area);
		int checkAreaObjects(string objectToCheck);

		vector<Area> accessibleAreas;
		vector<Item*> areaItems;
		vector<Object> areaObjects;
		vector<Area> allAreas;
};
extern Area area;

#endif
