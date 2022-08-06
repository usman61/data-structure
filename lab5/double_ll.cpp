#include <iostream>
using namespace std;

class node{
    public:
    int info;
    node *next,*prev;
    node(int val){
        info = val;
        next = NULL;
        prev = NULL;
    }

};
class DoubleLList{
    node *head;

    public:
    int length;
    DoubleLList(){
        length = 0;
        head = NULL;
    }
    void insert(int val,int pos);
    void remove(int pos);
    void display();
    void removeDup();
    void frontBackSplit(DoubleLList &l1,DoubleLList &l2);

};
int main(int argc, char const *argv[])
{
    DoubleLList l1,l2,l3;
    l1.insert(1,1);
    // l1.insert(2,2);
    // l1.insert(3,3);
    // l1.insert(1,4);
    // l1.insert(6,5);
    // l1.insert(7,6);
    // l1.insert(7,7);
    l1.display();
    
    l1.frontBackSplit(l2,l3);
    // l1.removeDup();
    // l1.display();
    cout<<"Displaying L2 List"<<endl;
    l2.display();

    cout<<"Displaying L3 List"<<endl;
    l3.display();

    cout<<l3.length<<endl;

    return 0;
}

void DoubleLList::insert(int val,int pos){
    node *n = new node(val);

    if (pos <1 || pos> length+1){
        cout<<"Invalid position."<<pos<<endl;
        return;
    }

    if(pos == 1){

        if (!head){           // mean null
        head = n;
        // n->next = head;
        // n->prev = head;
        }
        else{
        n->next = head;
        n->prev = head->prev;
        head->prev = n;
        head = n;
    }
  
    

    }
      else{
        node *curr = head;
        for (int i=1; i<(pos-1); i++)
        curr = curr->next;

        n->next = curr->next;
        n->prev = curr;

        if(curr->next !=NULL) // check for the last node
        curr->next->prev = n;
        curr->next = n;        

    }
    length++;
}
void DoubleLList::display(){
    node * curr = head;
    if(!length){
        cout<<"List is Empty"<<endl;
    }

    while (curr!=NULL){
        cout<<curr->info<<"\t";
        curr = curr->next;
    }
    cout<<endl;
}

void DoubleLList::remove(int pos){

     if(pos<1 || pos> length){
        cout<<"Invalid Position"<<endl;
        return;
    }

    node *curr = head;
    if (pos==1){
        curr = head;
        head = head->next;
        head->prev = NULL;
        delete curr;

    }
    else{
        node *temp = NULL;
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

void DoubleLList::removeDup(){
    node *curr = head;
    node *first,*sec;
    while(curr!=NULL){
        // cout<<"In Main WHile"<<endl;
        first = curr;
        sec = first->next;
        while(sec!=NULL){
                    // cout<<"In Sec WHile"<<endl;
            if(first->info == sec->info){
                // cout<<"Value Matches"<<sec->info<<endl;
                node * temp = sec;
                sec->prev->next = sec->next;
                if(sec->next!=NULL)
                sec->next->prev = sec->prev;
                sec = sec->next;
                delete temp;
                continue;
            }
            sec= sec->next;
        }

        curr = curr->next;
    }
}

  void DoubleLList::frontBackSplit(DoubleLList &l2,DoubleLList &l3){
    
    node *curr = head;
    int splitSize;

    l2.head = head;

    if(length%2==0){
        splitSize = length/2;
    }
    else{
        splitSize = (length/2)+1;
    }



    for (int i=1; i<splitSize; i++)
        curr = curr->next;

    l3.head = curr->next;
    // l3.head->prev = NULL;

    curr->next = NULL;
    curr->prev = NULL;

  }