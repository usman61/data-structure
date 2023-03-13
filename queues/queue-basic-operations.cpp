#include <iostream>

using namespace std;

class Node {
	public:
		Node * next;
		int data;
		Node(int val) {
			data= val;
			next=NULL;
		}
};

class Queue{

private:
    Node *rear;
    Node *front;
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
    Node *n = new Node(val);
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
        Node *temp = front;
        front = front->next;
        length--;
        int data = temp->data;
        delete temp;
        return data;
    }
}

void display() {
	Node *curr=front;
	while (curr !=NULL) {
		cout<<curr->data<<"\t";
		curr=curr->next;
	}
    cout<<endl;
}


};
