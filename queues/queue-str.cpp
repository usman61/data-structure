#include <iostream>
using namespace std;
class node {
	public:
		node * next;
		int data;
		node(int val) {
			data= val;
			next=NULL;
		}
};

class Queue{
private:
    node *rear;
    node *front;
    int length;

public:
	Queue() {
        front= rear=NULL;
        length=0;
		}
    int size() {
	return length;
}

bool isEmpty() {
	if (length==0)
		return true;
	else
		false;
}
void enqueue(int val){
   

}
int dequeue(){
   
}

void display() {
	
}


};

int main(int argc, char const *argv[])
{
    Queue q1;
    q1.enqueue(34);
    q1.enqueue(87);
    q1.enqueue(65);
    q1.display();
    q1.dequeue();
    q1.display();
    
    
    return 0;
}
