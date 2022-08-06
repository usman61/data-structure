#include <iostream>
using namespace std;
void minimax(int *p,int size){
int min = *p;
int max = *p;

   for (int i=0; i<size; i++){
       cout<<*p++<<"\t";
   }
   cout<<endl;
}
int main()
{
    int arr_size=5;
    int arr[arr_size];
    int *p=arr;
    cout<<"Enter element in array\n";

    for(int i=0; i<arr_size; i++){
        cin>>*p;
        *p++;
    }
    minimax(arr,arr_size);
    
    
return 0;
}