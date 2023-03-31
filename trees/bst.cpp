#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int v){
        data = v;
        left=right = NULL;
    }
};

class BST{
    public:
    Node *root;
    BST(){
        root=NULL;
    }
    Node* insert(Node *r,int val);
    void display(Node *r);
    bool searchNode(Node *r,int val);
    Node* findMin(Node *r);
    Node* findMax(Node *r);


};

int main(int argc, char const *argv[])
{
BST t1;

    t1.root = t1.insert((t1.root),5);
    t1.insert((t1.root),9);
    t1.insert((t1.root),2);
    t1.insert((t1.root),11);
    t1.display(t1.root);

    cout<<t1.searchNode(t1.root,9)<<endl;
    
    return 0;
}

bool BST::searchNode(Node *r,int val){
    if(r==NULL) return false;

    else if(r->data==val) return true;

    else if (val < r->data) return searchNode(r->left,val);
    else                    return searchNode(r->right,val);


}

Node* BST::findMin(Node *r){
    while(r->left!=NULL)
    r = r->left;
    return r;
 }
Node* BST::findMax(Node* r){
   
    while(r->right!=NULL){
        r= r->right;
    }
    return r;
   
}



Node* BST::insert(Node *r,int val){

    if(r==NULL){
        Node *temp = new Node(val);
        return temp;
    }
    else{
        
        if(r->data== val){
            cout<<"Already Exist"<<endl;
        
        }
        else if(val<r->data)
        r->left = insert(r->left,val);
        else{
        r->right = insert(r->right,val);

        }
        
    return r;    
    }

}

void BST::display(Node *temp){

    if(temp==NULL) return;

    display(temp->left);
    cout<<temp->data<<endl;
    display(temp->right);


}

