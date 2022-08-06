#include <iostream>
using namespace std;
int main () {

    char a;
    char *b;
    char **c;
    a = 'z';
    b = &a;
    c = &b;


    cout<<"a= "<<a<<endl;
    cout<<"&a= "<<(void *)&a<<endl;

    cout<<"b= "<<b<<endl;
    cout<<"c= "<<c<<endl;

    cout<<"*b= "<<*b<<endl;
    cout<<"*c= "<<*c<<endl;
    cout<<"**c= "<<**c<<endl;


return 0;
}