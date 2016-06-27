#include "Cake.h"

Cake::Cake() {
	name = "Cake";
	description = "The cake looks really tasty, but in reality it probably tastes like cardboard.";
	useMessage = "You can't eat the entire cake, at least not in this form. Perhaps it would be more edible when cut in slices.";
}

void Cake::use() {
	cout << useMessage << endl;
}
