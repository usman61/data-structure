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

		void remove(){
			if(!isEmpty()){
                *(Array+size-1) = 0;
                size--;
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
				// cout<<"Before Loop"<<endl;
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
            size=0;
		}
};

int main(){

	ArrayList *list1= new ArrayList();
    int option,element,loc;
	do{
cout<<"----------------------------------------------------------------------"<<endl;
cout<<"----------------------------------------------------------------------"<<endl;
   cout<<"1) Push Back Element in List"<<endl;
   cout<<"2) Push Element at Specific Location"<<endl;
   cout<<"3) Display Elements of List"<<endl;
   cout<<"4) Sort the List"<<endl;
   cout<<"5) Reverse the List"<<endl;
   cout<<"6) Remove Last Element of List"<<endl;
   cout<<"7) Remove Element of Specific Index in List"<<endl;
   cout<<"8) Empty the List"<<endl;
   cout<<"9) Current List Size"<<endl;
   cout<<"10) Exit the Program"<<endl;
   cin>>option;
cout<<"----------------------------------------------------------------------"<<endl;
cout<<"----------------------------------------------------------------------"<<endl;
    switch (option){
   	case 1:
        cout<<"Enter the Integer"<<endl;
        cin>>element;
   		list1->pushBack(element);
   		break;
   	case 2:
   		cout<<"Enter the Integer"<<endl;
        cin>>element;
        cout<<"Enter the Location (Index)"<<endl;
        cin>>loc;
   		list1->insertAt(element,loc);
   		break;
   	case 3:
   		list1->displayList();
   		break;
   	case 4:
   		list1->sortList();
        list1->displayList();
   		break;
   	case 5:
   		list1->reverseList();
        list1->displayList();
        break;
   	case 6:
   		list1->remove();
        break;
    case 7:
        cout<<"Enter the Location (Index)"<<endl;
        cin>>loc;
   		list1->removeAt(loc);
        break;

    case 8:
        list1->emptylist();
        break;

     case 9:
        cout<<list1->listSize()<<endl;
        break;

    // default:
    //  cout<<"Invalid Number"<<endl;
   }	
   	
   }while(option<10);
    


 
    return 0;
}
