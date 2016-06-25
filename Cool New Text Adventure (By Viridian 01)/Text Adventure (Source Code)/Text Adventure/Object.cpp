#include "Object.h"

Object::Object() {
	name = "Default Object";
}

Object::Object(string objName, string objDescription) {
	name = objName;
	description = objDescription;
}
