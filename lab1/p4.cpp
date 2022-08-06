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

void find_small_val(int arr[],int size){
    int i =1;
    while(1){

        if (!is_exist(i,arr,size)){
            cout<<"The smallest +ve int "<<i<<endl;
            break;
        }
        i++;

    }
}
int main(){


  int arr[] = {1,2,3};
  int size=sizeof(arr)/sizeof(int);
  find_small_val(arr,3);
 
  return 0;
}
