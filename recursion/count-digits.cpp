#include<iostream>
using namespace std;

int countDigits(int number,int count){
    // int static cnt=0;

    if(number==0)
    return count;
    else
    //cnt++;
    return countDigits(number/10,count+1);
}

int main(int argc, char const *argv[])
{
    int digits=0;
    cout<<countDigits(digits,0)<<endl;
    
    return 0;
}
