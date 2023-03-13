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
int frontNode(){
    if(!front){
        cout<<"List Under Flow"<<endl;
        return 0;
    }
    return front->data;
}


void display() {
	Node *curr=front;
	while (curr !=NULL) {
		cout<<curr->data<<"\t";
		curr=curr->next;
	}
    cout<<endl;
}

void duplicateNodes(Queue *q2){

    int data;

    while (data = this->dequeue()){

        for(int i=1; i<=data; i++){
            q2->enqueue(data);
        }

    }



}


};



int main(int argc, char const *argv[])
{
    Queue q1,q2;
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();
    q1.duplicateNodes(&q2);
    q2.display();

    
    return 0;
}
