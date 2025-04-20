#pragma once
#include <iostream>
#include <vector>
#include "BaseClass.h"
#include "Thing.h"
#include "Another.h"

class Database
{
	another* derived1;
	Thing* derived2;
	std::vector<BaseClass*> objects;
	void Create(eType type) {
		BaseClass* obj = nullptr;
		switch (type)
		{
		case eType::CAT:
			obj = dynamic_cast<BaseClass*> (derived1);
			break;
		case eType::DOG:
			obj = dynamic_cast<BaseClass*> (derived2);
			break;
		}
		obj->Read(std::cout, std::cin);
		objects.push_back(obj);
	};
	void DisplayAll() {
		for (BaseClass* obj : objects) {
			obj->Write(std::cout);
		}
	};
	void Display(const std::string& name) {
		for (BaseClass* obj : objects)
		{
			if (obj->GetName() == name)
			{
				obj->Write(std::cout);
			}
		}
	};
	void Display(eType type) {
		for (BaseClass* obj : objects)
		{
			if (obj->Type == type)
			{
				obj->Write(std::cout);
			}
		}
	};
	void Destructor() {
		for (BaseClass* obj : objects)
		{
			delete obj;
		}
	};
	void main() {
		Database database;
		bool quit = false;
		while (!quit)
		{
			std::cout << "1 - Create\n2 - Display All\n3 - Display by Name\n4 - Display by Type\n5 - Quit\n";
			int choice;
			std::cin >> choice;
			switch (choice)
			{
			case 1: // Create object by type break; 
			case 2: // DisplayAll(); break; 
			case 3: // Ask for name, then call database.Display(name) break; 
			case 4:
			{
				std::cout << "Enter type (0 for TYPE1, 1 for TYPE2): ";
				int t;
				std::cin >> t;
				database.Display(static_cast<eType>(t)); break;
			}
			case 5:
				quit = true;
				break;
			}
		}
	};
};

