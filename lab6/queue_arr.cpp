#include<iostream>
using namespace std;
class Queue{
	private:
	int *arr;
	int size;
	int rear, front; // Index
	int length;
	public:
		
	Queue(int val){
		this->size= val;
		arr= new int[size];
		rear= -1, front=-1,length=0 ;
	}
	~Queue(){
		delete []arr;
	}
	void enqueue(int val){
		if(rear== size-1){
			cout<<"Stack OverFlow"<<endl;
			return;
		}
		if (front == - 1)
      		front = 0;
      		
		arr[++rear] =val;
		length++;
	}
    void dequeue()
	{
		if (front == - 1) {
      		cout<<"Queue Underflow ";
      		return ;
   		} 
		else {
	      cout<<"Element deleted from queue is : "<< arr[front] <<endl;
	      front++;
   		}
	}

	void display(){
		if (front == - 1)
   			cout<<"Queue is empty"<<endl;
   		else 
		   {
		      cout<<"Queue elements are : ";
		      for (int i = front; i <= rear; i++)
		      cout<<arr[i]<<" ";
		        cout<<endl;
   			}
	}
};

int main (){
	Queue q1(5);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.enqueue(4);
	q1.enqueue(5);
	
	q1.display();
	q1.dequeue();
	q1.dequeue();
	q1.display();
	return 0;
}
