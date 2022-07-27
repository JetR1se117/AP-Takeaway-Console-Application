#pragma once
#include <string>

using namespace std;

class Item
{
protected:
	char id;
	int calories;
	std::string name;
	double price;
public:
	string toString(Item* p1, int i);
	virtual void Calories(int x);
	virtual void Name(string x);
	virtual void Price(double x);
	virtual int Calories();
	virtual string Name();
	virtual double Price();
	virtual void ID(char x);
	virtual char ID();
};


class MainCourse:public Item{
public:
	MainCourse();
};


class Beverages:public Item{
private:
	double abv;
	float volume;
public:
	Beverages();
	bool IsAlcoholic();
	string toString(Beverages* b1, int i);
	void Abv(double x);
	void Volume(float x);
	double Abv();
	int Volume();
};



class Appetiser:public Item {
private:
	char shareable;
	char twoForOne;
public:
	Appetiser();
	string toString(Appetiser* a1, int i);
	virtual void Shar(char x);
	virtual void Two(char x);
	virtual char Shar();
	virtual char Two();
};
