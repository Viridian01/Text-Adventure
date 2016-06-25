#include "Sburb.h"
#include "Sylladex.h"

Sburb::Sburb(string itemName, string itemDescription, string itemUse) {
	name = itemName;
	description = itemDescription;
	use = itemUse;
}

void Sburb::useItem(Sylladex &sylladex, int pos) {
	sylladex.storage.erase(sylladex.storage.begin() + pos);
	//sylladex.pickUp;
}