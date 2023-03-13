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
    node *n = new node(val);
    if(front == NULL){
        front = rear = n;
    }
    else{
        rear->next = n;
        rear = n;
    }
    length++;

}
int dequeue(){
    if(!front){
        cout<<"List Under Flow"<<endl;
        return 0;
    }
    else{
        node *temp = front;
        front = front->next;
        length--;
        int data = temp->data;
        delete temp;
        return data;
    }
}

void display() {
	node *curr=front;
	while (curr !=NULL) {
		cout<<curr->data<<"\t";
		curr=curr->next;
	}
    cout<<endl;
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
