#pragma once
#include <string>
#include "BaseClass.h"
#include <iostream>
class another : public BaseClass{
public:
	std::string ownerName = " ";
void Write(std::ostream& ostream) override{
	BaseClass::Write(ostream);
	ostream << "name: " << BaseClass::name;
};
void Read(std::ostream& ostream, std::istream& istream) override{
	BaseClass::Read(ostream, istream); // Call base class Read 
	ostream << "Enter age: ";
	istream >> BaseClass::age;
}
};
