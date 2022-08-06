using namespace std;
#include <string>
#include <iostream>
using namespace std;
int* abc(int &a)
{
    int *p;
    p=&a;
    *p = (*p + *p) * *p - *p * *p;
    // *p = *p+5;
return p;
}
int main()
{
    int x=3;
    int *p;
    p=abc(x);
    cout<<"Value of p is changed by the function returned.: "<<*p<<endl;
return 0;
}