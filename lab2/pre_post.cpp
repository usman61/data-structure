#include<iostream>
using namespace std;
int main()
{
    int a = 5;
    int c;
    int* p1, * p2;
    p1 = &a;
    // p2 = &b;
    c = *p1;

    *p1++;
cout << "*(p1++) ="   << (p1) << endl;
cout << "*(p1++) ="   << *(p1++) << endl;
cout << "value of p1 "<< p1 << endl;
cout << "*(++p1) ="   <<*(++p1) << endl;
cout << "value of p1 "<< p1 << endl;
cout << "(*p1)++ ="   <<(*p1)++ << endl;
cout << "value of p1 "<< p1 << endl;
cout << "++(*p1) ="   <<++(*p1) << endl;
cout << "value of p1 "<< p1 << endl;
return 0;


}