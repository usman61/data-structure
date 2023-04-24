#include <iostream>

using namespace std;
void max_heap(int *a, int m, int n){
   int j, t;
   t= a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] > a[j])
         j = j + 1;
      if (t > a[j])
         break;
      else if (t <= a[j]) {
         a[j/2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = t;
   return;
}
void build_maxheap(int *a, int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      max_heap(a,k,n);
   }
}
int main() {
   int n, i;
   cout<<"enter no of elements of array\n";
   int a[]={0,4,10,3,5,1};
   n=sizeof(a)/sizeof(int);
   cout<<n<<endl;
   build_maxheap(a, n);
   cout<<"Max Heap\n";
   for (i = 1; i < n; i++) {
      cout<<a[i]<<endl;
   }

}