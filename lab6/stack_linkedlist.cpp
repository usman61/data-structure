#include <iostream>
using namespace std;

class node{
    public:
    int info;
    node *next;
    node(int val){
        info = val;
        next = NULL;
    }

};

// stack using Linked List
class Stack{
    int length;
    node *top;
    public:
    Stack(){
        top = NULL;
        length = 0;
    }

    int size() {
	return length;
}

bool isEmpty() {
	if (length==0)
		return true;
	else
		return false;
}

void push(int val){
        node *n = new node(val);
        if(top ==NULL)
            top = n;
        else{
            n->next = top;
            top = n;
        }            
        length++;   
    }

int pop(){
    if(isEmpty()){
    cout<<"List UnderFlow";
    return 0;
    }
    else{
        int data = top->info;
        node *temp = top;
        top = top->next;
        length--;
        delete temp;
        return data;
    }
    
}

void display() {
    cout<<"Displaying Stack"<<endl;
	node *curr=top;
	while (curr !=NULL) {
		cout<<curr->info<<"\t";
		curr=curr->next;
	}
    cout<<endl;
}
    
};

int main(int argc, char const *argv[])
{
    Stack s1,s2;
    s1.push(20);
    s1.push(40);
    s1.display();
    cout<<s1.pop()<<endl;
    s1.display();
    // cout<<s1.pop()<<endl;
    // cout<<s1.pop()<<endl;
    
    return 0;
}
