#include <iostream>
using namespace  std;

class node
{

public:
    int info;
    node *next;
    node(int val){
        info = val;
        next = NULL;
    }

};

class CircularList
{
private:
    node *head;
    int length;
public:
    CircularList(){
        head = NULL;
        length = 0;
    }
    void insertAtBegin(int val){
        node *n = new node(val);

        if (!head){
            head = n;
            n->next = head;

        }
        else{
            node * curr = head;
            while (curr->next!=head)
            curr = curr->next;
            n->next = head;
            head = n;
            curr->next = head;


        }
        length++;

    }
    void deleteAtEnd(){
        node * curr = head,*temp;
        
        while(curr->next !=head){
            temp = curr;
            curr = curr->next;
        }
        temp->next = curr->next;
        delete curr;
        

        
    }
    void display(){
       node * curr = head;
        while(curr->next!=head){
            cout<<curr->info<<"\t";
            curr = curr->next;
        }
        cout<<endl;
    }

};


int main(int argc, char const *argv[])
{
    CircularList l1;
    l1.insertAtBegin(3);
    l1.insertAtBegin(6);
    l1.insertAtBegin(9);
    l1.insertAtBegin(12);
    l1.insertAtBegin(15);
    l1.display();

    l1.deleteAtEnd();
    l1.deleteAtEnd();
    l1.display();



    return 0;
}
