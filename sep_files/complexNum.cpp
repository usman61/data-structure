// Implementation file
// complexNum.cpp
#include "complexNum.h"
#include <iostream>
using namespace std;

// A default constructor
complexNum::complexNum(int a,
					int b)
{
	real = a;
	imaginary = b;
}

// A function to set values
void complexNum::setNum(const int a,
						const int b)
{
	real = a;
	imaginary = b;
}

// A function to print the complex
// number in the form real +
// (imaginary)i, i->iota
void complexNum::print() const
{
	cout << real << " + " << imaginary << "i" << endl;
}

// An overloaded operator to
// compare two complex Number
// objects
bool complexNum::operator==(const complexNum& obj)
{
	if (this->real == obj.real && this->imaginary == obj.imaginary) {
		return true;
	}
	return false;
}
