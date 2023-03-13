#include <iostream>

using namespace std;

class Node {
	public:
		Node *next;
		int empId,salary;
        string name;
		Node(int id,int sal,string n) {
			this->empId  = id;
            this->salary = sal;
            this->name = n; 
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
void enqueue(int id,int salary,string name){
    Node *n = new Node(id,salary,name);
    if(front == NULL){
        front = rear = n;
    }
    else{
        rear->next = n;
        rear = n;
    }
    length++;

}
// Node* dequeue(){
//     if(!front){
//         cout<<"List Under Flow"<<endl;
//         return NULL;
//     }
//     else{
//         Node *temp = front;
//         front = front->next;
//         length--;
//         // int data = temp->data;
//         delete temp;
//         return temp;
//     }
// }
Node* frontNode(){
    if(!front){
        cout<<"List Under Flow"<<endl;
        return NULL;
    }
    return front;
}


void display() {
	Node *curr=front;
    int i=1;
    cout<<"Employee Record Details:"<<endl;
    while(curr !=NULL) {
		cout<<i<<"\tEmp ID:"<<curr->empId<<"\t";
        cout<<"Name:"<<curr->name<<"\t";
        cout<<"Salary:"<<curr->salary<<"\t";
		curr=curr->next;
	    i++;
    cout<<endl;
    }
    cout<<endl;
}


};



int main(int argc, char const *argv[])
{
    Queue q1,q2;
    q1.enqueue(6049,50000,"Ali");
    q1.enqueue(5438,40000,"Hamza");
    q1.enqueue(8743,60000,"Zain");
    q1.enqueue(4529,70000,"Noman");
    q1.display();


    
    return 0;
}
