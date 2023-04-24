#include <iostream>

using namespace std;
bool isMaxHeap(int *a,int n){
    bool heap=true;
    for (int i=1; i<=n/2; i++){
        if(a[i]<a[2*i] || a[i]<a[2*i+1]){
            heap = false;
            break;
        }
    }

      return heap;
}

int main() {
   int n, i;
//    int a[]={0,90,15,10,7,12,2};
   int a[]={0,9,15,10,7,12,2};
   n=sizeof(a)/sizeof(int);
   cout<<n<<endl;
   cout<<isMaxHeap(a, n)<<endl;

   

}