#include "Hammer.h"
#include "Player.h"


Hammer::Hammer() {
	name = "Hammer";
	description = "This hammer could be used to nail nails in place, or even smash something.";
	useMessage = "Last time you checked, you need to use a hammer with something else to accomplish something useful.";
}

void Hammer::use() {
	cout << useMessage << endl;
}

void Hammer::useItemOnObject(Object object) {
	if (object.name == "Window") {
		cout << "You try to break the window with the hammer. It shatters easily, allowing you to jump into the front lawn.\nNOW ACCESSIBLE: Lawn" << endl;
		player.currentArea.addAccessibleArea("Lawn");
	}
}
