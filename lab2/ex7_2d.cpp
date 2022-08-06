#include <iostream>
using namespace std;

#define M 2
#define N 3
// Dynamic Memory Allocation in C++ for 2D Array
int main()
{
// dynamically create an array of pointers of size `M`
int** A = new int*[M];
// dynamically allocate memory of size `N` for each row
for (int i = 0; i < M; i++)
{
A[i] = new int[N];
}
// assign values to the allocated memory
for (int i = 0; i < M; i++)
{
    for (int j = 0; j < N; j++)
    {
        A[i][j] = rand() % 100;
    }
}

// print the 2D array
for (int i = 0; i < M; i++)
{
    for (int j = 0; j < N; j++)
    {
        cout << A[i][j] << " ";
    }
cout << endl;
}

// deallocate memory using the delete[] operator
for (int i = 0; i < M; i++)
{
delete[] A[i];
}

delete[] A;
return 0;
}