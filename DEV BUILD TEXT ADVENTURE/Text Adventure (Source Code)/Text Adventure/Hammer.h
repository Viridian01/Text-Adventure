#ifndef HAMMER_H
#define HAMMER_H
#include "Item.h"

class Hammer : public Item {
	public:
		Hammer();
		void use();
		void useItemOnObject(Object object);
};

#endif // !HAMMER_H