#include <iostream>
using namespace std;
struct Person
{
	char name[32];
	int id;
};
void Square(int& p)
{
	p = p * p;
}
void Double(int* p) 
{
	*p = *p * 2;
}

int main()
{

	// ** REFERENCE **
	//
	// declare an int variable and set the value to some number (less than 10)
	int v1 = 4;
	// declare a int reference and set it to the int variable above
	int& v2 = v1;
	// output the int variable
	std::cout << v2 << std::endl;
	// set the int reference to some number
	v2 = 2;
	// output the int variable
	std::cout << v1 << std::endl;
	// what happened to the int variable when the reference was changed? (insert answer) the variable got replaced
	
	// output the address of the int variable
	std::cout << v1 << std::endl;
	// output the address of the int reference
	std::cout << v2 << std::endl;
	// are the addresses the same or different? (insert answer) yes
	// ** REFERENCE PARAMETER **
	//
	// create a function above main() called Square that takes in an int parameter
	// in the function, multiply the int parameter by itself and assign it back to the parameter(i = i * i)
	// call the Square function with the int variable created in the REFERENCE section
	Square(v1);
	// output the int variable to the console
	std::cout << v1 << std::endl;
	// !! notice how the variable has not changed, this is because we only passed the value to the function !!
	// change the Square function to take a int reference
	// !! notice how the calling variable has now changed, this is because we 'passed by reference' !!
	// !! when a function takes a reference parameter, any changes to the parameter changes the calling variable ""
	// ** POINTER VARIABLE **
	//
	// declare an int pointer, set it to nullptr (it points to nothing)
	int* p = &v1;
	// set the int pointer to the address of the int variable created in the REFERENCE section
	// output the value of the pointer
	std::cout << *p << std::endl;
	// what is this address that the pointer is pointing to? (insert answer) v1
	// output the value of the object the pointer is pointing to (dereference the pointer)
	
	std::cout << v1 << std::endl;
	// ** POINTER PARAMETER **
	//
	// create a function above main() called Double that takes in an int pointer parameter
	// in the function, multiply the int pointer parameter by 2 and assign it back to the parameter(i = i * 2)
	// !! make sure to dereference the pointer to set the value and not set the address !!
	// call the Double function with the pointer created in the POINTER VARIABLE section
	// output the dereference pointer
	Double(p);
	std::cout << *p << std::endl;
	// 
	// output the int variable created in the REFERENCE section
	std::cout << v1 << std::endl;
	
	// did the int variable's value change when using the pointer?yes
}
