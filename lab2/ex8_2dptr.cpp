#include <iostream>
using namespace std;
#define M 2
#define N 3
 
// Dynamically allocate memory for 2D Array in C++
int main()
{
    // dynamically allocate memory of size M * N
    int* A = new int[M * N];
 
    // assign values to the allocated memory
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            *(A + i * N + j) = rand() % 100;
        }
    }
 
    // print the 2D array
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << *(A + i * N + j) << " ";       // or (A + i*N)[j]
        }
        cout << endl;
    }

    cout<<endl;
     
    // print as 1D array
    for (int j = 0; j < (N*M); j++)
        {
            cout << *(A + j) << " ";
        }
        cout << endl;
 
    // deallocate memory
    delete[] A;
 
    return 0;
}
