#include "ItemList.h"
#include "Menu.h"
#include <string>
#include <fstream>
#include <vector>
#include <sstream> // std::stringstream
#include <iostream>
#include <iomanip>

using namespace std;

string Menu::toString() {

    //cout << "app Casting test: " << app->ID() << endl;
    bool aHead = false;
    bool bHead = false;
    bool mHead = false;
    for (int i = 0; i < items.size(); i++) {
        Item* p = items[i];
        Appetiser* a1 = nullptr;
        Beverages* b1 = nullptr;
        MainCourse* m1 = nullptr;
        if (a1 = dynamic_cast<Appetiser*>(p)) {
            if (!aHead)
            {
                cout << "----------------Appetisers----------------\n"; aHead = true;
            }
            a1->toString(a1, i);
        }
        if (b1 = dynamic_cast<Beverages*>(p)) {
            if (!bHead) {
                cout << "----------------Beverages----------------\n"; bHead = true;
            }
            b1->toString(b1, i);
            
            cout << "(" << i + 1 << ") " << b1->Name() << ": \x9c" << setprecision(2) << b1->Price() << ", " << to_string(b1->Calories()) << " cal (" << setprecision(2) << b1->Volume() << "ml";
            if (b1->IsAlcoholic()) {
                cout << ", " << setprecision(1) << b1->Abv() << "% abv";
            }
            cout << ")\n";
        }
        if (m1 = dynamic_cast<MainCourse*>(p)) {
            if (!mHead) {
                cout << "----------------MainCourse----------------\n"; mHead = true;
            }
            m1->toString(m1, i);
        }
    }
    return "\n";
};
int i;

Menu::Menu(string menuStr) {
    bool exit = false;
    i = 0;
    ifstream file;
    file.open(menuStr);
    if (file.is_open()) {
        while (!file.eof()) {
            string typeStr;
            getline(file, typeStr);
            const char* type = typeStr.c_str();
            std::string tempStr = " ";
            std::stringstream sbase(typeStr);
            switch (type[0]) {
            default:
                std::cout << endl;
                break;
            case 'a':
                appImport(sbase, typeStr);
                break;
            case 'm':
                mainImport(sbase, typeStr);
                break;
            case 'b':
                bevImport(sbase, typeStr);
                break;
            }
            i++;
        }
    }
}

int Menu::getItemVectorSize() {
    return(items.size());
}

Item* Menu::getItemChoice(int x) {
    return items[x];                // I put this here for access to itemlist but for the menu only.
}

void Menu::mainImport(stringstream& sbase, string line) {
    MainCourse *main;
    main = new MainCourse;
    vector<std::string> vars;
    while (sbase.good()) {
        std::string temp;
        temp = line;
        string substr;
        getline(sbase, substr, ',');
        vars.push_back(substr);
    }
    main->Name(vars[1]);
    main->Price(std::stod(vars[2]));
    main->Calories(std::stoi(vars[3]));
    items.push_back(main);
};
void Menu::bevImport(stringstream& sbase, string line) {
    Beverages* bev;
    bev = new Beverages; 
    vector<std::string> vars;
    while (sbase.good()) {
        std::string temp;
        temp = line;
        string substr;
        getline(sbase, substr, ',');
        vars.push_back(substr);
    }
    bev->Name(vars[1]);
    bev->Price(std::stod(vars[2]));
    bev->Calories(std::stoi(vars[3]));
    bev->Volume(std::stod(vars[6]));
    bev->Abv(std::stod(vars[7]));
    items.push_back(bev);
};
void Menu::appImport(stringstream& sbase, string line) {
    Appetiser* app;
    app = new Appetiser;
    vector<std::string> vars;
    while (sbase.good()) {
        std::string temp;
        temp = line;
        string substr;
        getline(sbase, substr, ',');
        vars.push_back(substr);
    }
    app->Name(vars[1]);
    app->Price(std::stod(vars[2]));
    app->Calories(std::stoi(vars[3]));
    app->Shar(vars[4][0]);
    app->Two(vars[5][0]);
    items.push_back(app);
    
};


