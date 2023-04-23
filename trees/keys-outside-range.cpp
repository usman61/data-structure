/*
Remove nodes from a BST that have keys outside a valid range
*/
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int v=0){
        data = v;
        left=right = NULL;
    }
};

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};


// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout<< p->str;
}

void printTree(Node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout<<root->data << endl;

    if(prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

class BST{
    public:
    Node *root;
    BST(){
        root=NULL;
    }
    Node* insert(Node *r,int val);
    
    Node* truncate(Node *&r,int s,int e){

    if(r==NULL) return NULL; 

    r->left  =  truncate(r->left,s,e);
    r->right =  truncate(r->right,s,e);
    // logic
    Node *curr = r;
    if(r->data<s){
        r = r->right;
        delete curr;
    }
    else if(r->data>e){
        r = r->left;
        delete curr;
    }
    return r;
    }
 


};
int main()
{
    BST t1,t2;

    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
    for (int key: keys) {
        t1.insert(t1.root, key);
    }


    printTree(t1.root, NULL, false);
    cout<<"--------------------------------"<<endl;

    t1.truncate(t1.root,9,12);

    printTree(t1.root, NULL, false);
    cout<<"--------------------------------"<<endl;



    return 0;
}

Node* BST::insert(Node *r,int val){

    if(r==NULL){
        Node *temp = new Node(val);

        if(r==root){
            root = r = temp;
        }
        return temp;
    }
    else{
        
        if(r->data== val){
            cout<<"Already Exist"<<endl;
            return r;
        
        }
        else if(val<r->data)
        r->left = insert(r->left,val);
        else{
        r->right = insert(r->right,val);

        }
        
    return r;    
    }

}
