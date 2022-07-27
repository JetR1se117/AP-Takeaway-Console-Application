#include "Order.h"
#include "Item.h"
#include "ItemList.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

Order::Order() {
	items;
}

void Order::toString() {
    int TwoForOneCount= 0;
    total = 0;
    vector<float> saveVect = {};
    cout << "===== Checkout =====\n";   // the £ sign doesnt output because c++ likes to complain
    // the dynamic_cast checks the child(e.g. appetiser) is compatible with the parent(e.g. item). Using this I can differentiate the function used by the type of object passed to it.
    for (int i = 0; i < items.size(); i++) {
        Item* p = items[i];
        Appetiser* a1 = nullptr;
        if (a1 = dynamic_cast<Appetiser*>(p)) {
            a1->toString(a1, i);
            if (a1->Two() == 'y') {
                TwoForOneCount++;
                saveVect.push_back(a1->Price());
            }
            calculateTotal(a1->Price());
        }
    }
    for (int i = 0; i < items.size(); i++) {
        MainCourse* m1 = nullptr; Item* p = items[i];
        if (m1 = dynamic_cast<MainCourse*>(p)) {
            m1->toString(m1, i);
            calculateTotal(m1->Price());
        }
    }
    for (int i = 0; i < items.size(); i++) {
        Beverages* b1 = nullptr; Item* p = items[i];
        if (b1 = dynamic_cast<Beverages*>(p)) {
            b1->toString(b1, i);
            calculateTotal(b1->Price());
        }
    }
    cout << "-------------" << endl;
    float savings = 0;
    if (TwoForOneCount >= 2) {
        sort(saveVect.begin(),saveVect.end());
        int tfoMod = saveVect.size() / 2;
        for (int i = 0; i < tfoMod; i++) {
            savings = savings + saveVect[i];
        }
        //savings = savings / 2;
        calculateTotal(-savings);
        cout << "2-4-1 discount applied! Savings: \x9c" << savings<<endl;
    }
    cout << "Total: \x9c" << setprecision(2) << calculateTotal(0) << endl;
}

void Order::printReceipt() {
    cout <<endl;
    string fname = "receipt.txt";
    ofstream file("receipt.txt");
    for (int i = 0; i < items.size(); i++) {
        Item* p = items[i];
        Appetiser* a1 = nullptr;
        if (a1 = dynamic_cast<Appetiser*>(p)) {
            file << "(" << i + 1 << ") " << a1->Name() << ": \x9c" << setprecision(2) << fixed << a1->Price() << ", " << to_string(a1->Calories()) << " cal ";
            if (a1->Shar() == 'y') {
                file << "(shareable) ";
            }
            if (a1->Two() == 'y') {
                file << "(2-4-1)";
            }
            file << endl;
        }
    }
    for (int i = 0; i < items.size(); i++) {
        MainCourse* m1 = nullptr; Item* p = items[i];
        if (m1 = dynamic_cast<MainCourse*>(p)) {
            file << "(" << i + 1 << ") " << m1->Name() << ": \x9c" << setprecision(2) << fixed << m1->Price() << ", " << to_string(m1->Calories()) << " cal " << endl;
        }
    }
    for (int i = 0; i < items.size(); i++) {
        Beverages* b1 = nullptr; Item* p = items[i];
        if (b1 = dynamic_cast<Beverages*>(p)) {
            file << "(" << i + 1 << ") " << b1->Name() << ": \x9c" << setprecision(2) << fixed << b1->Price() << ", " << to_string(b1->Calories()) << " cal (" << setprecision(2) << to_string(b1->Volume()) << "ml";
            if (b1->IsAlcoholic()) {
                file << ", " << setprecision(1) << fixed << b1->Abv() << "% abv";
            }
            file << ")\n";
            // << to_string(b1->Abv()) << "% abv)\n";
        }
    }
    cout << endl;
    file << "-------------\nTotal: " << setprecision(2)<<calculateTotal(0) <<endl;
    file.close();
    cout << fname << " has been printed!"<<endl;
    items.clear();
}

float Order::calculateTotal(float price) {
    total = total + price;
    return total;
}

float Order::calculateTotal() {
    total = 0;
    int TwoForOneCount = 0;
    vector<float> saveVect = {};
    for (int i = 0; i < items.size(); i++) {
        Item* p = items[i];
        Appetiser* a1 = nullptr;
        if (a1 = dynamic_cast<Appetiser*>(p)) {
            if (a1->Two() == 'y') {
                TwoForOneCount++;
                saveVect.push_back(a1->Price());
            }
            calculateTotal(a1->Price());
        }
    }
    for (int i = 0; i < items.size(); i++) {
        MainCourse* m1 = nullptr; Item* p = items[i];
        if (m1 = dynamic_cast<MainCourse*>(p)) {
            calculateTotal(m1->Price());
        }
    }
    for (int i = 0; i < items.size(); i++) {
        Beverages* b1 = nullptr; Item* p = items[i];
        if (b1 = dynamic_cast<Beverages*>(p)) {
            calculateTotal(b1->Price());
        }
    }
    float savings = 0;
    if (TwoForOneCount >= 2) {
        sort(saveVect.begin(), saveVect.end());
        int tfoMod = saveVect.size() / 2;
        for (int i = 0; i < tfoMod; i++) {
            savings = savings + saveVect[i];}
        //savings = savings / 2;
        calculateTotal(-savings);
        cout << "Savings: \x9c" << savings << endl;
    }
    cout << "Total: \x9c" << setprecision(2)<<fixed << calculateTotal(0) << endl;
    return 0;
}

void Order::add(Item* choice) {
	items.push_back(choice);
    cout << choice->Name() << " added to order!\n";
    calculateTotal();
}

void Order::remove(int removeVal) {
    cout << items[removeVal]->Name() << " has been removed!\n";
    items.erase(items.begin() + removeVal);
    calculateTotal();
}

void Order::help() {
	cout << "\nType 'menu' for the menu\nType 'add' to add an item to the order\nType 'remove' to remove an item from the order\nType 'checkout' to get the bill\nType 'help' for this text\nType 'quit' or 'exit' to close the program\n\n";
}

int Order::getItemVectorSize() {
    return(items.size());
}