#include <iostream>
using namespace std;
#define N 10
 
// Dynamically allocate memory for 1D Array in C++
int main()
{
    // dynamically allocate memory of size `N`
    int* A = new int[N];
 
    // assign values to the allocated memory
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
    }
 
    // print the 1D array
    for (int i = 0; i < N; i++)
    {
        // cout << A[i] << " ";   // or *(A + i)
        cout<<*(A+i)<<" ";
    }

     cout<<endl; 
    // deallocate memory
    delete[] A;
 
    return 0;
}
