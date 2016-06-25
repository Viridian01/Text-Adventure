#ifndef SBURB_H
#define SBURB_H

#include "Item.h"
#include "Sylladex.h"

class Sburb : public Item
{
private:

public:
	Sburb(string itemName, string itemDescription, string itemUse);
	virtual void useItem(Sylladex &sylladex, int pos);
};

#endif
