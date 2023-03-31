/*
this script contains all the basic operations (insert,delete,display etc) on doubly linked list
*/

#include <iostream>
using namespace std;
    
class Node{
    public:
    int info;   
    Node *next,*prev;
    Node(int val){
        info=val;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLinkedList{
    int length;
    Node *head;
    public:
    DoublyLinkedList(){
        head=NULL;
        length=0;
    }

    void insert(int val,int pos);
    void display();
    void remove(int pos);
     
};

void DoublyLinkedList::display(){
    Node *curr = head;
    if(!length){
        cout<<"List is Empty"<<endl;
        return;
    }
    cout<<"---------------------------------"<<endl;
    while (curr!=NULL){
        cout<<curr->info<<"\t";
        curr = curr->next;
    }
    cout<<endl;
    cout<<"---------------------------------"<<endl;

}
void DoublyLinkedList::insert(int val,int pos){
    if (pos <1 || pos> length+1){
        cout<<"Invalid position."<<pos<<endl;
        return;
    }
    Node *n = new Node(val);

    if(pos==1){
        if(!head)
            head = n;
        else{
            n->next=head;
            head->prev=n;
            head=n;
        }
       
    }
    else{

        Node *curr = head;
        for (int i=1; i<(pos-1); i++)
        curr = curr->next;

        n->next=curr->next;
        n->prev=curr;
        
        if(curr->next!=NULL)
            curr->next->prev=n;
        curr->next=n;    

    }
    length++;



}
void DoublyLinkedList::remove(int pos){

     if(pos<1 || pos> length){
        cout<<"Invalid Position"<<endl;
        return;
    }

    Node *curr = head;
    if (pos==1){
        curr = head;
        head = head->next;
        head->prev = NULL;
        delete curr;

    }
    else{
        Node *temp = NULL;
        for (int i=0; i<(pos-1); i++){
            temp = curr;
            curr = curr->next;
        }

        temp->next = curr->next;
        if(curr->next!=NULL)
        curr->next->prev = temp;

        delete curr;
    }

    length--;

}


int main()
{
    DoublyLinkedList l1,l2,l3;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(4,4);
    l1.insert(5,5);
    l1.display();
    l1.remove(2);
    l1.display();
    
    return 0;
}
