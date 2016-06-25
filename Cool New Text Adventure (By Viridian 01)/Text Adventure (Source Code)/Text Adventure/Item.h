#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Item {
	public:
		Item();
		Item(string itemName, string itemDescription, string itemUse);
		string description;
		string name;
		string use;
		string objectToUseOn;

		bool isSpecial = false;

		void setSpecial(bool special);
		//void virtual useItem();

		//void setUseObjectOn

};

#endif
