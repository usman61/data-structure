#include <iostream>
using namespace std;
int main () {
int *p;
int a;
p=&a;
    cout<<"Enter data value? ";
    cin>>*p;
    cout<<"Value of variable ="<<a<<endl;
    cout<<"Memory Address of variable= "<<p<<endl;

return 0;
}