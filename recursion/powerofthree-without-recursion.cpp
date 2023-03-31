#include <iostream>
#include <math.h>
using namespace std;

bool powerOfThree(int n){
    int raise=1,power;

    while(true){
        power = pow(3,raise);

        if(n==power) return true;

        else if(power>n) return false;

        raise++;

    }

    
}
int main()
{
    int n=27;
    cout<<powerOfThree(n)<<endl;

    return 0;
}
