#include <iostream>
using namespace std;
int main () {
    int arr[5], *pp, i;
    pp=arr;
    cout<<"Enter Values into an array: "<<endl;
    for(i=0 ; i<=4 ; i++)
    {
    // cin>>arr[i];
    cin>>*pp;
    *pp++;
    }
    pp = arr;
    cout<<"Values from array Using Pointer notation: "<<endl;
    for(i=0 ; i<=4 ; i++)
    {
    cout<<*pp<<"\t";
    *pp++;
    }
    cout<<endl;

   cout<<"Values from array Using Array notation: "<<endl;
    for(int i=0 ; i<=4 ; i++)
    {
    cout<<arr[i]<<"\t";
    }
    cout<<endl;    
//    int *ptr = arr-1;
// while (*ptr!=NULL){
// cout<<*ptr++<<"\t";
// }
    return 0;
}