#include "Item.h"
#include "Sylladex.h"

Item::Item() {
	name = "Default Item Name";
	description = "Default Description";
	useMessage = "Default Use Message";
}

void Item::use() {
	cout << "Default Item Used!" << endl;
}

void Item::useItemOnObject(Object object) {
	cout << "Used the " << name << " on " << object.name << endl;
}