#ifndef SYLLADEX_H
#define SYLLADEX_H


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <dos.h>
#include "Area.h"
using namespace std;

class Sylladex {
	public:
		Sylladex();
		int checkItem(string itemToCheck);
		void view();
		void inspect(string itemToInspect);
		void pickUp(string itemToPick, Area &area);
		void dropItem(string itemToDrop, Area &area);
		void useItem(string itemToUse);

		vector<Item> storage;

	private:
};

#endif