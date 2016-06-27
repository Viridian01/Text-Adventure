#include "Sburb.h"
#include "Sylladex.h"

Sburb::Sburb() {
	name = "Sburb";
	description = "The unwrapped Game Beta Copy. It's the hip new game that you have been waiting exactly 413 days for.";
	useMessage = "You can't really play this without a computer of some sort, and yours was back in your bedroom.\nUpstairs.\nOut of the room you just jumped out of.";
}

void Sburb::use() {
	cout << useMessage << endl;
}