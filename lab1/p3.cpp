#include <iostream>
using namespace std;
bool is_exist(int elem,int *p,int size){
    for (int i=0; i<size; i++){
        if (elem == *p)
        return true;
        *p++;
    }

    return false;

}
int union_set(int *p1,int size1,int *p2,int size2,int *p3,int size3){
    int actual_size=0;

    int *p3_dup = p3;

cout<<"In Loop 1"<<endl;
    for (int i=0; i<size1; i++){
        cout<<*p1<<"\t"; 
         if(!is_exist(*p1,p3_dup,size3))
                {
                *p3 = *p1;
                *p3++;
                actual_size++;
                }
                *p1++;
    }
    cout<<endl<<"In Loop 2"<<endl;

     for (int i=0; i<size2; i++){
         cout<<*p2<<"\t";

         if(!is_exist(*p2,p3_dup,size3))
                {
                *p3 = *p2;
                *p3++;
                actual_size++;
                }
        *p2++;
    }
    cout<<endl;

   
    return actual_size;

}
int main()
{
    int size1= 6,size2 =5;
    int size3 = size1 + size2 ;
    int arr1[size1] = {2,5,7,10,1,4};
    int arr2[size2] = {9,2,3,4,7};
    int arr3[size3];



    int actual_size = union_set(arr1,size1,arr2,size2,arr3,size3);
    // cout<<size3<<endl;
    // cout<<actual_size<<endl;
    cout<<"Union of both the sets are:\n";
    for (int i =0; i<actual_size; i++){
        cout<<arr3[i]<<"\t";
    }
    cout<<"\n";


return 0;
}