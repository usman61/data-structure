#include <iostream>
#include <math.h>
using namespace std;


bool isPowerOfThree(int n){

    while (n%3==0)
    {
        n/=3;

    }
    
    if (n==1) return true;
    else return false;
    
}
int main(int argc, char const *argv[])
{

    int n=29;
    cout<<isPowerOfThree(n)<<endl;
    return 0;
}
