#include "Item.h"
#include <string>
#include <iostream>
#include <iomanip>

string Item::toString(Item* p1, int i) {
	cout << "(" << i + 1 << ") " << p1->Name() << ": \x9c" << setprecision(2) << p1->Price() << ", " << to_string(p1->Calories()) << " cal " << endl;
	return "";
}
bool Beverages::IsAlcoholic() { 
	if (Abv() > 0)
		return true;
	else
		return false;
}
void Item::Calories(int x) {
	calories = x;
}
void Item::Name(string x) {
	name = x;
}
void Item::Price(double x) {
	price = x;
}
int Item::Calories() {
	return calories;
}
string Item::Name() {
	return name;
}
double Item::Price() {
	return price;
}
char Item::ID() {
	return id;
}
void Item::ID(char x) {
	id = x;
}

Appetiser::Appetiser() {
	shareable = false;
	twoForOne = false;
	calories = 0;
	name = "NAME";
	price = 25.20;
};
string Appetiser::toString(Appetiser* a1, int i) {
	cout << "(" << i + 1 << ") " << a1->Name() << ": \x9c" << setprecision(2) << fixed << a1->Price() << ", " << to_string(a1->Calories()) << " cal ";
	if (a1->Shar() == 'y') {
		cout << "(shareable) ";
	}
	if (a1->Two() == 'y') {
		cout << "(2-4-1)";
	}
	cout << endl;
	return "";

}
void Appetiser::Shar(char x) {
	shareable = x;
}
void Appetiser::Two(char x) {
	twoForOne = x;
}
char Appetiser::Shar() {
	return shareable;
}
char Appetiser::Two() {
	return twoForOne;
}

Beverages::Beverages() {
	abv = 0;
	volume = 0;
	calories = 0;
	name = "NAME";
	price = 0;
};
string Beverages::toString(Beverages* b1, int i) {
	cout << "(" << i + 1 << ") " << b1->Name() << ": \x9c" << setprecision(2) << b1->Price() << ", " << to_string(b1->Calories()) << " cal (" << setprecision(2) << b1->Volume() << "ml";
	if (b1->IsAlcoholic()) {
		cout << ", " << setprecision(1) << b1->Abv() << "% abv";
	}
	cout << ")";
	return "";
}
void Beverages::Abv(double x) {
	abv = x;
}
void Beverages::Volume(float x) {
	volume = x;
}
double Beverages::Abv() {
	return abv;
}
int Beverages::Volume() {
	return volume;
}

MainCourse::MainCourse() {
	calories = 0;
	name = "NAME";
	price = 0;
}