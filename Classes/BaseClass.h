#pragma once
#include <string>
#include "eType.h"
class BaseClass
{
public:
	std::string name;
	int age = 0; 
	eType Type;

	std::string GetName() { return name; };
	eType GetType() { return Type; };
	virtual void Read(std::ostream& ostream, std::istream& istream) {};
	virtual void Write(std::ostream& ostream) {};
	
	
};

