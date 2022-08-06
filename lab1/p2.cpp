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
int common(int *p1,int size1,int *p2,int size2,int *p3,int size3){
    int actual_size=0;

    int *p3_dup = p3;
    for (int i=0; i<size1; i++){
        int *p2_dup = p2;

        for (int j=0; j<size2; j++){
           

            if (*p1 == *p2_dup){
                if(!is_exist(*p1,p3_dup,size3))
                {
                *p3 = *p1;
                *p3++;
                actual_size++;
                }
            }


            p2_dup++;

        }

        p1++;
    }

    return actual_size;

}
int main()
{
    int size1= 6,size2 =5;
    int size3 = size1 > size2 ? size1: size2;
    int arr1[size1] = {2,5,7,10,1,4};
    int arr2[size2] = {1,2,4,90,7};
    int arr3[size3];

    int actual_size = common(arr1,size1,arr2,size2,arr3,size3);
    cout<<size3<<endl;
    cout<<"Common Elements in both the sets are:\n";
    for (int i =0; i<actual_size; i++){
        cout<<arr3[i]<<"\t";
    }
    cout<<"\n";


return 0;
}