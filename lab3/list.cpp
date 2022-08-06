#include <iostream>
using namespace std;

class ArrayList{
    private:
		int capacity;
		int size;
		int * Array;
		int * curr;
	public:
    	ArrayList() {
			capacity=10;
			Array= new int[capacity];
			size=0;
			curr= Array;
		}
		~ArrayList() {
			delete []Array;
			delete curr;
		}
		void displayList() {
			if(size>0) {
				for(int x=0; x<size; x++)
					cout<<*(Array+x)<<"\t";

					cout<<endl;
			} 
			else cout<<"Array is Empty"<<endl;
		}
		void pushBack(int x){
			if (!isFull()){
				*(Array+size) = x;
				size++;

			}
			else{
				cout<<"List is full"<<endl;
			}
		}
		void insertAt(int value,int loc){
			if(!isFull()){
				if(loc<=size && loc>=0){
					for (int i=size; i>loc; i--){
						*(Array+i) = *(Array+i-1);
					}
					*(Array+loc) = value;
					size++;

			}

			}
			else{
				cout<<"List is already full"<<endl;
			}
			

		}

		void remove(int n){
			if(!isEmpty()){

				for (int i=0; i<size; i++){
					if (*(Array+i)==n){
						for (int j=i; j<(size-1); j++){
							*(Array+j) = *(Array+j+1);
						}
						size--;
						break;
					}

				}

			}
			else{
				cout<<"List is already Empty (Operation Failed)"<<endl;
			}

		}

		void removeAt(int loc){
			if(!isEmpty()){
				if(loc>=0 && loc<size){
					for (int i=loc; i<(size-1); i++){
						*(Array+i) = *(Array+i+1);

					}
					size-=1;


				}

		

			}
			else{
				cout<<"List is already Empty (Operation Failed)"<<endl;
			}



		}

		void reverseList(){
			int *left,*right,temp;
			left = Array;
			right = Array+size-1;
			int midIndex = size/2;
			for(int i=0; i<midIndex; i++){
				temp = *left;
				*left = *right;
				*right= temp;

				left++;
				right--;
			}

		}
		void sortList() {
			int *p1,*ab;
			int *p2,*temp,asd;
			temp = &asd;
			//sorting - ASCENDING ORDER

			for(int step=0; step<size; step++) {
				cout<<"Before Loop"<<endl;
				// cout<<*ab<<"\t";
				for(int j=0; j<size-step-1; j++) {
					p1 = Array + j;
					p2 = Array+j+1;
					
					if( (*p1) > (*p2) ) {
				    //    cout<<*p1<<"\t";
						*temp  =*p1;
						*p1=*p2;
						*p2=*temp;
					}
				}
				cout<<endl;
			
			}

		}
		// void sortArray2() {
		// 	int *p1;
		// 	int *p2, temp;
		// 	//sorting - ASCENDING ORDER
		// 	for(int i=0; i<size; i++) {
		// 		p1 = Array+i; 
		// 		for(int j=i+1; j<size; j++) {
		// 			p2 = Array+j;
		// 			if(*p1>*p2) {
		// 				temp  =*p1;
		// 				*p1=*p2;
		// 				*p2=temp;
		// 			}
		// 		}
			
		// 	}

		// }
		

		bool isFull() {
			if (size==capacity)
				return true;
			else return false;
		}
		bool isEmpty() {
			if (size==0)
				return true;
			else return false;
		}
		void head() {
			curr= Array;
		}
		void tail() {
			curr= Array+size-1;
		}

		void back() {
			curr= curr-1;
		}
		void next() {
			curr= curr+1;
		}
		int listSize() {
			return size;
		}


		void emptylist() {
			for (int i=0; i<capacity; i++) {
				*(Array+i)=0;
			}
		}
};

int main(){

	ArrayList *list1= new ArrayList();
	list1->emptylist();
	list1->pushBack(1);
	list1->pushBack(2);
	list1->pushBack(3);
	list1->pushBack(5);
	// list1->displayList();

	list1->insertAt(4,3);
	list1->displayList();

	list1->insertAt(9,0);
	// list1->displayList();

	list1->pushBack(12);
	list1->displayList();

	list1->remove(2);
	list1->displayList();
	cout<<"size of List "<<list1->listSize()<<endl;
	list1->removeAt(0);
	list1->displayList();
    
	list1->reverseList();
	list1->displayList();

	cout<<"Sorted List"<<endl;
	// list1->sortArray2();
	// list1->sortList();
	list1->displayList();

    


 
    return 0;
}
