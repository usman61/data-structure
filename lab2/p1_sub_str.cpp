#include <iostream>
using namespace std;

struct Mode{
  int value,freq;
};

void findMode(int *arr,int n){
  Mode mode;
  mode.freq=0;
  mode.value=0;  
  int *start = arr;
  int elem,freq;

  for (int i=0; i<n; i++){

    cout<<*(arr+i)<<"\t";
    // add check for repeat element to reduce computation
    freq = 1;
    elem = *(arr+i);
    for (int j=i+1; j<n; j++){
      if (elem == *(arr+j)){
        freq++;
      }
    }

     if (freq > mode.freq){
      mode.freq = freq;
      mode.value = elem;
    }

  }

  cout<<"The Most Frequent element is "<<endl;
  cout<<"Value :"<<mode.value<<endl;
  cout<<"Freq  :"<<mode.freq<<endl;


}

bool isPrime(int no){

    if (no<=1)
    return false;

    for (int i=2; i<=no/2; i++){
        if (no%i==0)
          return false;
    }

    return true;
}



int main(){
    int n,i,j,primeCount=0,evenSum=0,max,secMax;
    cout<<"Enter the size of array"<<endl;
    // cin>>n;
    n=5;

    int *arr = new int[n];
     
    int set=5;
    for (i=0; i<n; i++){
        // arr[i] = rand() % 100;
        *(arr+i) = i+1;
    }
    arr[0] = 9;
    arr[1] = 9;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 9;
 
    for (i=0; i<n; i++){
        cout<<*(arr+i)<<"\t";
    }
    cout<<endl;

cout<<"1. display array in reverse order."<<endl;
    for (j=(n-1); j>=0; j--){
        cout<<*(arr+j)<<"\t";
    }    
cout<<"2. Count the elements of array that are prime numbers."<<endl;

   for (i=0; i<n; i++){
    if(isPrime( *(arr+i)) )
     primeCount++;
   }

   cout<<"Prime Numbers List "<<primeCount<<endl;

  cout<<" 3. Display the sum of even indexes."<<endl;

  for (i=0; i<n; i++){

    if (i%2==0)
        evenSum+=*(arr+i);
  }
  cout<<"Sum of Even Indexes "<<evenSum<<endl;

  cout<<"5. Displaying secondMax in array."<<endl<<endl;

  max= arr[0];
  secMax=*(arr+1);
  if (arr[0]>arr[1]){
    max = arr[0];
    secMax = arr[1];
  }
  else{
    max = arr[1];
    secMax = arr[0];
  }
  for (i=2; i<n; i++){
    if ( *(arr+i)>max){
     secMax = max;
      max = *(arr+i);
    }
    else if (*(arr+i)>secMax && *(arr+i)!=max){
        secMax = *(arr+i);
    }
    else if (secMax == max){
        secMax = *(arr+i);
    }
   
    

  }
  cout<<"Second Max "<<secMax<<endl;

  findMode(arr,n);


    return 0;
}
