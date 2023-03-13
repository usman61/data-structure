#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class linkedlist
{

private:
    node *head;
    int length;
    node *curr;

public:
    linkedlist()
    {
        head = NULL;
        length = 0;
        curr = head;
    }
    
    bool check_empty(){
    	if (head==NULL)
    		return true;
    	else
    		return false;
	}

    void insert(int val, int pos){
        
        if (pos < 1 || pos > length + 1)
        {
            cout << "Out of Range" << endl;
            return;
        }
        else
        {
            node *n = new node(val);
            curr = head;
            if (pos == 1)
            {
                n->next = head;
                head = n;
            }
            else
            {
                for (int i = 1; i < pos - 1; i++)
                {
                    curr = curr->next;
                }
                n->next = curr->next;
                curr->next = n;
            }

            length++;
        }
    }


        

    


    void printlist(){

        curr=head;
        while (curr != NULL)
        {
            cout << curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

     node* Head()
    {
        return head;
    }
    void even_odd(){
    	node *temp =head;
    	node *temp1=head;
    	node *curr1=head;
    	curr1=curr1->next;
    	curr=head;
    	temp=temp->next;
    	temp1=temp1->next->next;
    	while(temp1->next!=NULL){
			curr->next=temp->next;
			temp->next=temp1->next;
			curr=temp1;
			temp=temp1->next;
			
			temp1=temp1->next->next;
			if(temp1->next==NULL){
				curr->next=temp->next;
				temp->next=NULL;
			}	
		}
		curr->next=curr1;
		curr=head;
        while (curr != NULL)
        {
            cout << curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
	}
    
    

       
    
    };
    int main(){
            linkedlist l1;
    l1.insert(2, 1);
    l1.insert(1, 2);
    l1.insert(3, 3);
    l1.insert(5, 4);
    l1.insert(6, 5);
    l1.insert(4, 6);
    // l1.insert(7, 7);


    
    l1.printlist();
    l1.even_odd();
    
    
    return 0;
}
