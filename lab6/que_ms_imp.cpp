#include <iostream>
using namespace std;

/*
Implentation of Queue Using Linked List
Methods:
1. Dequeue: Removal of an element from the queue
2. Enqueue: Addition of an element to the queue
3. Front: Get the front element from the queue i.e. arr[front] if queue is not empty.
4. Display: Print all element of the queue. If the queue is non-empty, traverse and print all the elements from index front to rear.
5. isEmpty: returns true if queue is empty
6. is Full: returns true if queue is full 

*/

class Node{
	public:
	int data;
	Node *next;
};
Node *front=new Node();
Node *rear=new Node();
int qSize=5;
int currentSize=0;


/*
this method would check whether the Queue is empty or not.
*/
bool isEmpty(Node* front){
	if (front==NULL) return true;
	return false;
	
}
/*
this method would check whether the Queue is full or not.
*/
bool isFull(){
	if (currentSize==qSize) return true;
	return false;
	
}

/*
this method would just create a new node by setting
its value to the passed argument 
*/
Node* createNode(int value){
	Node *new_node=new Node();
	new_node->data=value;
	new_node->next=NULL;
	return new_node;	
}
/*
 this method will insert an element to the queue 
 from rear(tail) side 
 */
void enqueue(){
	
	int value;
	if (isFull()){
		cout<<"Queue is Full or Overflow"<<endl;
		return ;
	}
	cout<<"Enter the value you want to insert"<<endl;
	cin>>value;
	Node* newNode=createNode(value);
	if (rear==NULL){
		// if rear is empty this would occur while
		// inserting first value in queue
		rear=newNode;
		front=rear;

	}
	else{
//		cout<<"second case"<<endl;
		rear->next=newNode;
		rear=newNode;
	}
	currentSize+=1; //incrementing queue size by 1

}
/*
 this method will remove an element in the queue 
 from front(head) side  
 */
void dequeue(){
	if (isEmpty(front)){
		cout<<"Queue is already empty or Underflow"<<endl;
		return;
	} 
	else{
		Node* temp=new Node();
		temp=front;
		front=front->next;
		delete temp;
	}
		currentSize-=1; //decrementing queue size by 1
		
}
/*
 this method will print the whole queue 
 from front to rear
 */
void display(Node* start){
	cout<<"<------------------->"<<endl;
	while (start!=NULL){
		cout<<start->data<<endl;
		start=start->next;
	}
		cout<<"<------------------->"<<endl;
}
/*
 this method will print the last inserted
 element in the queue 
 from front side
 */
void frontElement(Node* front){
	if (isEmpty(front)){
		cout<<"Queue is already empty or Underflow"<<endl;
		return;
	} 
	
	cout<<front->data<<endl;
	
}

int main(){
	int option;
	rear=front=NULL;
	
   do{
   cout<<"1) Enqueue element to queue"<<endl;
   cout<<"2) Dequeue element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Display the front elements of queue"<<endl;
   cout<<"5) Check Whether the queue is full or not"<<endl;
   cout<<"6) Check Whether the queue is empty or not"<<endl;
   cout<<"7) Exit"<<endl;
   cin>>option;
   switch (option){
   	case 1:
   		enqueue();
   		break;
   	case 2:
   		dequeue();
   		break;
   	case 3:
   		display(front);
   		break;
   	case 4:
   		frontElement(front);
   		break;
   	case 5:
   		if(isFull()) cout<<"Queue is Full or Overflow"<<endl;
   		else  cout<<"Queue has Space"<<endl;
   		break;
   	case 6:
   		if(isEmpty(front)) cout<<"Queue is Empty or Underflow"<<endl;
   		else  cout<<"Queue isn't Empty"<<endl;
   		break;
   }	
   	
   }while(option!=7);
	

	return 0;
}
