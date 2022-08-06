#include <iostream>
using namespace std;

class node{
    public:
    node *next;
    int info;
    node(int val){
        info = val;
        next = NULL;

    }
};

class LinkedList{
    private:
    node *head;
    int length;

    public:
    LinkedList(){
        head = NULL;
        length = 0;
    }

    void insertion(int value,int pos);
    void printing();
    void concatenate(LinkedList l1,LinkedList l2);
    void deletion(int pos);

};

int main()
{
    LinkedList l1,l2;
    l2.insertion(90,1);
    l1.insertion(1,1);
    l1.insertion(2,2);
    l1.insertion(3,3);
    l1.insertion(4,4);
    l1.insertion(5,5);

    l1.insertion(90,2);
    l1.printing();

    l1.deletion(1);
    l1.printing();

    l1.concatenate(l1,l2);

    return 0;
}

void LinkedList::deletion(int pos){
    if(pos<1 || pos> length){
        cout<<"Invalid Position"<<endl;
    }
      node *temp = head;
    if(pos ==1){
        // removing head node
      
        head = head->next;
        delete temp;
        length--;
    }
    else{
        for(int i=1; i<(pos-1); i++){
            temp = temp->next;
        }
         node *del = temp->next;
         temp->next = temp->next->next;
         del->next = NULL;
         delete del;


    }

}
void LinkedList::insertion(int value,int pos){
    
    if (pos <1 || pos> length+1){
        cout<<"Invalid position."<<pos<<endl;
        return;
    }
    node *n = new node(value);

    if (pos == 1){
        // node would be inserted at the head
        n->next = head;
        head = n;
        length++;
    }
    else{

        node *curr = head;
        for (int i=1; i<(pos-1); i++){
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
        length++;
    }

}

void LinkedList::printing(){
    node *n = head;
    cout<<"----------------------------------------------------------------"<<endl;
    while(n!=NULL){
        cout<<n->info<<"\t";
        n = n->next;
    }
    
    cout<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
}

void LinkedList::concatenate(LinkedList l1,LinkedList l2){
    node *curr = l1.head;

    while(curr->next!=NULL)
    curr= curr->next;

    curr->next= l2.head;

    node *temp=l1.head;

    while(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
    cout<<endl;

}