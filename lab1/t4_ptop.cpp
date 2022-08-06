#include <iostream>
using namespace std;
int main ()
{
    int a;
    int *b;
    int **c;
    int ***d;
    a = 7;
    b = &a;
    c = &b;
    d = &c;
    cout<<"The Address of the Vairiable a is: "<<b<<endl;
    cout<<"The Address of the Vairiable b is: "<<c<<endl;
    cout<<"The Address of the Vairiable d is: "<<d<<endl;

    cout<<"The value of the Vairiable a is: "<<*b<<endl;
    cout<<"The value of the Vairiable a is: "<<**c<<endl;
    cout<<"The value of the Vairiable a is: "<<***d<<endl;
return 0;
}