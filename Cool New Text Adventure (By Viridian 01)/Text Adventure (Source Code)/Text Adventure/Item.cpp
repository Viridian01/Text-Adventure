#include "Item.h"

Item::Item(string itemName, string itemDescription, string itemUse) {
	name = itemName;
	description = itemDescription;
	use = itemUse;
}

Item::Item() {
	name = "Default Item Name";
	description = "Default Description";
	use = "Default Use Message";
}

/*void Item::useItem() {
	cout << "Default Item Used!" << endl;
}*/

void Item::setSpecial(bool special) {
	isSpecial = special;
}