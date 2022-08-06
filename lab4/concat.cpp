#include <iostream>
using namespace std;

class node{
    public:
    node *next;
    char info;
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
    void concatenate2(LinkedList *l1,LinkedList *l2);

};

int main()
{
    LinkedList l1,l2;
    l1.insertion('a',1);
    l1.insertion('b',2);
    l1.insertion('c',3);
    l1.printing();

    l2.insertion('d',1);
    l2.insertion('e',2);
    l2.insertion('f',3);

    l1.concatenate2(&l1,&l2);
    l1.printing();

    return 0;
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
    // temp->info = 'Z';

    while(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
    cout<<endl;

}

void LinkedList::concatenate2(LinkedList *l1,LinkedList *l2){
    node *curr = l1->head;

    while(curr->next!=NULL)
    curr= curr->next;

    curr->next= l2->head;

    node *temp=l1->head;
    temp->info = 'Z';

    while(temp!=NULL)
    {
        cout<<temp->info<<"\t";
        temp=temp->next;
    }
    cout<<endl;

}