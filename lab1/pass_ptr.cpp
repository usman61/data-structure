#include <string>
#include <iostream>
using namespace std;
void abc(int *a)
{
 *a=*a * *a - *a;
 int b=30;
}
int main()
{
    int x=5;
    int *p;
    p=&x;
    abc(p); // calling function
    cout<<"Value of p is changed by the function passed as parameter.: "<<*p<<endl;
    return 0;
}