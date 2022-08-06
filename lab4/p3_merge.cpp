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
    void merge(LinkedList a , LinkedList b);

};

int main()
{
    LinkedList l1,l2;
    l1.insertion(10,1);
    l1.insertion(4,2);
    l1.insertion(15,3);
    l1.printing();

    l2.insertion(2,1);
    l2.insertion(18,2);
    l2.insertion(87,3);

    l1.merge(l1,l2);
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


void LinkedList::merge(LinkedList a , LinkedList b)
{
      node *curr=a.head;

    while(curr->next!=NULL)
    {
        curr=curr->next;
    }

    curr->next=b.head;

    int l=a.length+b.length;


    for(int i=0; i<l; i++)
    {
        // sorting the merged list
        node *temp=a.head;
        node *temp1=temp->next;
        int v;
        while(temp->next!=NULL)
        {
            if(temp->info > temp1->info)
            {
                v = temp->info;
                temp->info=temp1->info;
                temp1->info=v;
            }

            temp=temp1;
            temp1=temp->next;
        }
    }

     node *temp2=a.head;

    while(temp2!=NULL)
    {
        cout<<temp2->info<<" ";
        temp2=temp2->next;
    }

    cout<<endl;
    
   
}