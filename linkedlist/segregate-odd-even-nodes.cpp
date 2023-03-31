/*
Odd Even Linked List
Given a doubly linked list, group all the nodes with odd indices together followed by the nodes with
even indices.
The first node is considered odd, and the second node is even, and so on.
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
    void isolateOddEven();
     
};


/*
this ftn would isolate odd even nodes e.g
input : 2<->3<->4 
output: 2<->2<->3<->3<->4<->4
*/
void DoublyLinkedList::isolateOddEven(){
    Node *odd=head;
    if(!length){
        cout<<"List is Empty"<<endl;
        return;
    }
    Node *even = head->next,*evenFirst=head->next;
    while(1){

        if(!odd || !even)
        break;

        if(even->next==NULL){
            odd->next = evenFirst;
            break;
        }

        odd->next = even->next;
        if(even->next!=NULL)
        even->next->prev = odd;
        odd = odd->next;


        if(odd->next==NULL){
            odd->next=evenFirst;
            even->next=NULL;
            break;
        }

        even->next = odd->next;
        if(odd->next!=NULL)
        odd->next->prev = even;
        even = even->next;
    }


}

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

int main()
{
    DoublyLinkedList l1,l2,l3;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.insert(4,4);
    l1.insert(5,5);
    l1.isolateOddEven();
    l1.display();
    
    return 0;
}
