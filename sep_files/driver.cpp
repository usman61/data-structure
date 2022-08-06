// Driver file to illustrate
// the implementation of
// complexNum.cpp file
#include "complexNum.h"
#include <iostream>
using namespace std;

// Driver code
int main()
{
	// Defines a complex number
	// object (obj1 = 4 + 5i)
	complexNum obj1(4, 34);
	complexNum obj2;

	// Defines a complex number
	// object (obj2 = 3 + 4i)
	obj2.setNum(3, 4);

	// Prints the complex number
	obj1.print();
	obj2.print();

	// Checks, if two complex
	// number objects are equal or
	// not
	if (obj1 == obj2) {
		cout << "Both the numbers are equal" << endl;
	}
	else {
		cout << "Numbers are not equal" << endl;
	}
	return 0;
}
