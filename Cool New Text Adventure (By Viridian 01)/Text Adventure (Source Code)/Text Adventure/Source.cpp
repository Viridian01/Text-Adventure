#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <dos.h>
#include "Sylladex.h"
#include "Area.h"
#include "Player.h"
#include "Object.h"

using namespace std;

Sylladex sylladex;
Area area;
Player player;
Object object;

//Default Funcs

void help() {
	cout << "The commands you can use are:\n1: Help\n2: Check Area\n3: View Sylladex\n4: Pick Up\n5: Use Item\n6: Inspect\n7: Check Object\n8: Use Item With Object\n9: Drop\n10: Go To Area\n11: Stop\n(Items, Areas, and Objects are case-sensitive, while commands are used by typing in their corresponding number)" << endl;
}


//Items
Item Hammer("Hammer", "This hammer could be used to nail nails in place, or even smash something.", "Last time you checked, you need to use a hammer with something else to accomplish something useful.");
Item Cake("Cake", "The cake looks really tasty, but in reality it probably tastes like cardboard.", "You can't eat the entire cake, at least not in this form. Perhaps it would be more edible when cut in slices.");
Item fakeArms("Fake Arms", "Arms made of foam. You could use these to come up with some really silly shenangins.", "You hold the Fake Arms with your real arms.\nYou have a hard time comprehending how stupid you look right now.");

Item GameCopy("Game Beta Copy", "A small manilla packet that contains the hip new game that you have been waiting exactly 413 days for!", "You rip the manilla packet to shreds, trying to get the prize inside. \nThe manilla packet is gone now, only the game itself remains.\nCAPTCHALOGUED: Sburb");
Item Football("Football", "The ball is brown, with white stripes, like any old American Football.", "You put the ball down on the ground and nudge it with your foot. \nIt rolls a little bit.\nYou don't know if you were expecting more.");
Item Newspaper("Newspaper", "The black and white paper thing that gets thrown on your lawn. Who uses these things anyway?", "You tried to stay interested in the newspaper.\nIt didn't work.");
Item Sburb("Sburb", "The unwrapped Game Beta Copy. It's the hip new game that you have been waiting exactly 413 days for.", "You can't really play this without a computer of some sort, and yours was back in your bedroom.\nUpstairs.\nOut of the room you just jumped out of.");

//Areas
Area bedroom("Bedroom", "In this bedroom, there is a bed against the wall. On the adjacent wall, there is a window. \nThere are also a multitude of silly items thrown on the floor.");
Area lawn("Lawn", "You are in your house's lawn. The grass is pretty green today. You see the front door, and a mailbox. \n" 
	"The red arm-thingy is up.");

//Objects
Object Window("Window", "A glass window that looks into your lawn.");
Object Bed("Bed", "That's your bed! It looks pretty comfy, but you don't feel very tired now.");
Object PC("PC", "The piece of crap that is your computer. Yours is pretty outdated compared to your super-cool friend, but it works.\nYou're planning on playing this hip new game with your friends on this.");

Object Mailbox("Mailbox", "This metal mailbox has its red arm-thingy sticking up! That must mean there is something inside.");

//Item and Object Scripts

bool windowBroken = false;

void useItemOnObject(string itemToUse, string objectToUseItemOn) {
	if (player.currentArea.name == "Bedroom") {
		for (unsigned int i = 0; i < bedroom.areaObjects.size(); i++) {
			if (bedroom.areaObjects[i].name == objectToUseItemOn) {
				if (objectToUseItemOn == "Window") {
					int pos = sylladex.checkItem(itemToUse);
					if (pos > -1) {
						if (itemToUse == "Hammer") {
							cout << "You try to break the window with the hammer. It shatters easily, allowing you to jump into the front lawn.\nNOW ACCESSIBLE: Lawn" << endl;
							player.currentArea.addArea(lawn);
							windowBroken = true;
						}
						else if (itemToUse == "Cake") {
							cout << "You decide that the cake would be useless if thrown against a window.\nYou do as the author says, and keep the cake." << endl;
						}
						else if (itemToUse == "Fake Arms") {
							cout << "You forcefully poke the window with the Fake Arms. Nothing happened, how dissapointing!" << endl;
						}
					}
					else {
						cout << "It didn't work!" << endl;
					}
				}
				else if (objectToUseItemOn == "PC") {
					int pos = sylladex.checkItem(itemToUse);
					if (pos > -1) {
						if (itemToUse == "Hammer") {
							cout << "By hitting the PC with the Hammer, your hopes, your dreams, and your money, you make it faster." << endl;
						}
					}
				}
				else {
					cout << "It didn't work!" << endl;
				}
			}
		}
	}
	else if (player.currentArea.name == "Lawn") {
		
	}
	else {
		cout << "It didn't work!" << endl;
	}
}

void goToArea(string areaToGo, Area area) {
	int pos = area.checkAccessible(areaToGo);
	cout << pos << endl;
	if (pos > -1) {
		/*if (area == bedroom) {
			cout << "You're already in that area!" << endl;
		}*/
		player.setArea(area.accessibleAreas[pos]);
		if (areaToGo == "Lawn" && windowBroken) {
			cout << "You jump out the window, falling to the ground. It's quite the fall, but you didn't receive any injuries." << endl;
			area.removeArea(bedroom);
		}
	}
}

void useSpecialItem(string itemToUse) {
	int pos = sylladex.checkItem(itemToUse);
	if (pos > -1) {
		//if (sylladex.storage[pos].isSpecial) {
			if (sylladex.storage[pos].name == "Game Beta Copy") {
				/*for (int i = 0; i < sylladex.storage.size(); i++) {
					cout << sylladex.storage[i].name << endl;
				}*/
				sylladex.storage.erase(sylladex.storage.begin() + pos);
				sylladex.storage.push_back(Sburb);
			}
		//}
	}
}

int main() {

	//Item Assignments
	bedroom.assign(Hammer);
	bedroom.assign(fakeArms);
	bedroom.assign(Cake);

	lawn.assign(Football);
	lawn.assign(GameCopy);
	lawn.assign(Newspaper);

	//Object Assignments
	bedroom.place(Window);
	bedroom.place(Bed);
	bedroom.place(PC);

	lawn.place(Mailbox);

	//Area Accessiblity
	bedroom.addArea(bedroom);

	//Does something special?
	GameCopy.isSpecial = true;

	//Start
	player.currentArea = bedroom;
	help();

	bool inGame = true;
	string searchItem;
	string itemToDrop;
	string itemToUse;
	string objectToCheck;
	string objectToUseItemOn;
	string itemToInspect;
	string areaToGo;
	string input;
	while (inGame) {
		cout << "\n==> ";
		cin >> input;
		cout << "\n" << endl;
		cin.ignore(413, '\n');
		if (input == "1") { 
			help();
		}
		else if (input == "2") {
			cout << "You are in: " << player.currentArea.name << endl;
			area.checkArea(player.currentArea);
			cout << "Locations accessible from here are: " << endl;
			area.showAccessible(player.currentArea);
		}
		else if (input == "3") {
			sylladex.view();
		}

		else if (input == "4") {
			cout << "Pick up what?" << endl;
			getline(cin, searchItem);
			sylladex.pickUp(searchItem, player.currentArea);
		}
		else if (input == "5") {
			cout << "Use what item?" << endl;
			getline(cin, itemToUse);
			sylladex.useItem(itemToUse);
			useSpecialItem(itemToUse);
		}
		else if (input == "6") {
			cout << "Inspect which item in your sylladex?" << endl;
			getline(cin, itemToInspect);
			sylladex.inspect(itemToInspect);
		}
		else if (input == "7") {
			cout << "Check which object?" << endl;
			getline(cin, objectToCheck);
			player.checkObject(objectToCheck, player.currentArea);
		}
		else if (input == "8") {
			cout << "Use what item?" << endl;
			getline(cin, itemToUse);
			cout << "Use " << itemToUse << " on what?" << endl;
			getline(cin, objectToUseItemOn);
			useItemOnObject(itemToUse, objectToUseItemOn);
		}
		else if (input == "9") {
			cout << "Drop what?" << endl;
			getline(cin, itemToDrop);
			sylladex.dropItem(itemToDrop, player.currentArea);
		}
		else if (input == "10") {
			cout << "Go where?" << endl;
			getline(cin, areaToGo);
			goToArea(areaToGo, player.currentArea);
		}
		else if (input == "11") {
			inGame = false;
		}
		else if (input == "hue") {
			cout << "hue";
			while (true) {
				cout << " hue ";
				_sleep(2);
			}
		}
		else {
			cout << "Invalid command!" << endl;
		}
	}
}