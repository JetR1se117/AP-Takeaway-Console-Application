/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for "Takeaway" assignment
Autumn 2020

Written by James Brown

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "Terminal.h"

#include <iostream>
#include <vector>
#include <cstring>
#include <string>


using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file // done
	Menu menu = Menu("menu.csv");

	// Create an order object // done
	Order order = Order();
	while (userCommand != "exit" && userCommand != "quit")
	{
		std::cout << ":>>";
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());
		
		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		int vSize = parameters.size();
		if (vSize > 0) {						//checks that the user inputted something
			string command = parameters[0];

			if (command.compare("menu") == 0) {
				std::cout << menu.toString();
			}
			else if (command.compare("add") == 0)
			{
				if (!parameters[1].empty()) {
					Item* choice = 0; // you need to instantiate this using the menu object! //done
					for (int i = 1; i < vSize; i++) {
						try {
							if (menu.getItemVectorSize() >= stoi(parameters[i]) && 0 < stoi(parameters[i])) {
								choice = menu.getItemChoice(stoi(parameters[i]) - 1);
								order.add(choice);
							}
							else {
								cout << "item " << parameters[i] << " does not exist";
							}
						}
						catch (...) {
							
							cout << parameters[i] << " does not exist";
						}
					}
					std::cout << endl;
					//while () {}
				}
				// You may also wish to implement the ability to add multiple items at once! //done
			}
			else if (command.compare("remove") == 0)
			{
				if (order.getItemVectorSize() > 0) {

					if (!parameters[1].empty()) {
						int lowestInt = order.getItemVectorSize(); // gets the length of the item vector
						int count = 0;
						for (int i = 1; i < vSize; i++) {
							try
							{
								if (stoi(parameters[i]) > order.getItemVectorSize() || stoi(parameters[i]) < 0) {
									cout << "Item " << parameters[i] << " does not exist!\n";
								}
								else {
									if (stoi(parameters[i]) > lowestInt)
										count--;
									order.remove(stoi(parameters[i]) - 1 + count);
									if (stoi(parameters[i]))
										lowestInt = stoi(parameters[i]);
								}
							}
							catch (...) {
								cout << parameters[i] << " doesnt exist";
							}
						}
						std::cout << endl;
					}
				}
				else {
					cout << "You can't remove from an empty list\n";
				}
				
			}
			else if (command.compare("checkout") == 0)
			{
				order.toString();
				std::cout << "Do you want to place your order?\nType 'y' to confirm, or 'n' to go back and modify it.\n";
				bool exit = false;
				string input;
				while (!exit) {
					getline(cin, input);
					if (input == "y") {
						exit = true;
						order.printReceipt();
					}
					if (input == "n") {
						exit = true;
					}
				}
				
			}
			else if (command.compare("help") == 0)
			{
				order.help();
			}
			parameters.clear();
		}
		else {
			std::cout << "\nPlease enter a command. Type 'help' for a list of commands.\n "; // if no input, output this message
		}
	}

	std::cout << "Press any key to quit...";
	std::getchar();
}

/*
  for (int i = 1; i < vSize; i++) {
	choice = menu.getItemChoice(stoi(parameters[i]) - 1);
	order.add(choice);
  else {
	cout << "item " << parameters[i] << " does not exist";
  }
*/