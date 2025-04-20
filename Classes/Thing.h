#pragma once
#include <string>
#include "BaseClass.h"
#include <iostream>
class Thing : public BaseClass {
public:
void Read(std::ostream& ostream, std::istream& istream) override{
	BaseClass::Read(ostream, istream); // Call base class Read 
	ostream << "Enter age: ";
	istream >> BaseClass::age;
}
void Write(std::ostream& ostream) override {
	BaseClass::Write(ostream);
	ostream << "name: " << BaseClass::name;
};
	std::string hometown = " ";
};

