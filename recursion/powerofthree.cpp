#include <iostream>
#include <math.h>
using namespace std;

bool powerOfThree(int n,int raise){

    int power = pow(4,raise);

    if(power == n) return true;

    else if (power>n) return false;

    else
    return powerOfThree(n,raise+1);



}
int main(int argc, char const *argv[])
{

    int n=64;
    cout<<powerOfThree(n,1)<<endl;
    return 0;
}
