// C++ program to illustrate dynamic allocation
// and deallocation of memory using new and delete
#include <iostream>
using namespace std;
int main()
{
// Pointer initialization to null
int* p = NULL;
// Request memory for the variable
// using new operator
p = new (nothrow) int;
if (!p)
cout << "allocation of memory failed\n";
else
{
// Store value at allocated address
*p = 29;
cout << "Value of p: " << *p << endl;
}
// Request block of memory
// using new operator
float* r = new float(75.25);
cout << "Value of r: " << *r << endl;
// Request block of memory of size n
int n = 5;
int* arr = new int[n];
if (!arr)
    cout << "allocation of memory failed\n";
else
{
    
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;

    cout << "Value store in block of memory using index: ";
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";




}

// freed the allocated memory
delete p;
delete r;
// freed the block of allocated memory
delete[] arr;

return 0;
}