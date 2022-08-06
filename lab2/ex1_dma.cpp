#include <iostream>
using namespace std;

int main(){

int* ptr = new int(25);
float* f_ptr = new float(75.25);
// Custom data type
struct cust
{
int p;
cust(int q){
  p = q;
}

};
cust* var = new cust(10);
cout<<*ptr<<endl;
cout<<*f_ptr<<endl;
cout<<var->p<<endl;

    return 0;
}
