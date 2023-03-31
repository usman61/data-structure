#include <iostream>
#include <math.h>
using namespace std;

int multiplyTwoNumbers(int a,int b){

    if (b==0 || a==0) return 0;

    else if(b==1) return a;

    else return a+multiplyTwoNumbers(a,b-1);


}
int main(int argc, char const *argv[])
{

    int a=0,b=4;
    cout<<multiplyTwoNumbers(a,b)<<endl;
    return 0;
}
