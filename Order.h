#pragma once
#include "Item.h"
#include "ItemList.h"

class Order:public ItemList
{
	float total;
public:
	float calculateTotal(float price);
	float calculateTotal();
	void printReceipt();
	void toString();
	void add(Item* choice);
	void remove(int removeVal);
	int getItemVectorSize();
	void help();
	Order();
};