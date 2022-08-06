#include <iostream>
using namespace std;
void minimax(int *p,int size){

int min = *p;
int max = *p;
    for(int i=0; i<size; i++){
        if (*p <min)
        min = *p;

        if (*p>max)
        max = *p;

        *p++;
    } 

cout <<"Min is "<<min<<endl;
cout <<"Max is "<<max<<endl;
}

int main()
{
    
    
return 0;
}