#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <vector>
#include "Object.h"

using namespace std;

class Item {
	public:
		Item();
		string description;
		string name;
		string useDescription;
		string objectToUseOn;
		string useMessage;

		virtual void use();
		virtual void useItemOnObject(Object object);
};

#endif
