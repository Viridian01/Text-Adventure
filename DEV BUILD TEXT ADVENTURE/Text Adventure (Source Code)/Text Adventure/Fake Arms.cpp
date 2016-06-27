#include "Fake Arms.h"
#include "Sylladex.h"
#include "Player.h"

FakeArms::FakeArms() {
	name = "Fake Arms";
	description = "Arms made of foam. You could use these to come up with some really silly shenangins.";
	useMessage = "You hold the Fake Arms with your real arms.\nYou have a hard time comprehending how stupid you look right now.";
}

void FakeArms::use() {
	cout << useMessage << endl;
}
