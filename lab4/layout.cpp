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
    void deletion(int pos);

};

int main()
{
    LinkedList l1;
    l1.insertion(1,1);
    l1.insertion(2,2);
    l1.insertion(3,3);
    l1.insertion(4,4);
    l1.insertion(5,5);

    l1.insertion(90,2);
    l1.printing();

    l1.deletion(1);
    l1.printing();

    return 0;
}

void LinkedList::deletion(int pos){
   // delete a node

}
void LinkedList::insertion(int value,int pos){
    // insert a node at pos
}

void LinkedList::printing(){
   // print the linked list 
}

