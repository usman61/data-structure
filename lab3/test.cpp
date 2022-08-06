#include <iostream>
using namespace std;

class ArrayList{
    private:
		int SIZE;
		int length;
		int pos;
		int * Array;
		int * curr;
	public:
    	ArrayList() {
			SIZE=10;
			Array= new int[SIZE];
			length=0;
			pos=0;
			curr= Array;
		}
		~ArrayList() {
			delete []Array;
			delete curr;
		}
};

int main(){
 int *arr = new int[5];

 for (int i=0; i<5; i++){
    if(arr[i]==0)cout<<"Empty";
    cout<<arr[i]<<"\t";
 }
cout<<endl;

    return 0;
}
