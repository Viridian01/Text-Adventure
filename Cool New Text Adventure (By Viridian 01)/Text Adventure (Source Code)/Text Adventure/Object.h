#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Object {
	public:
		Object();
		Object(string objName, string objDescription);

		string name;
		string description;
};
#endif