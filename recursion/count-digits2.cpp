#include<iostream>
using namespace std;

int countDigits(int number){
    // int static cnt=0;

    if(number==0)
    return 0;
    else
    //cnt++;
    return 1+countDigits(number/10);
}

int main(int argc, char const *argv[])
{
    int digits=1;
    cout<<countDigits(digits)<<endl;
    
    return 0;
}
