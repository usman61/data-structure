#include <iostream>
using namespace std;
int main () {

    int a;
    int *b;
    int **c;
    a = 45;
    b = &a;
    c = &b;


    cout<<"a= "<<a<<endl;
    cout<<"&a= "<<&a<<endl;

    cout<<"b= "<<b<<endl;
    cout<<"c= "<<c<<endl;

    cout<<"*b= "<<*b<<endl;
    cout<<"*c= "<<*c<<endl;
    cout<<"**c= "<<**c<<endl;


return 0;
}