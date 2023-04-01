/*
700. Search in a Binary Search Tree  - LeetCode

You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with 
that node. If such a node does not exist, return null.
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

class BST{
    public:
    Node *root;
    BST(){
        root=NULL;
    }
    Node* insert(Node *r,int val);
    bool searchNode(Node *r,int val);
    Node* preOrderTraversal( Node* r);





};
int main(int argc, char const *argv[])
{
    BST t1;
    int val;

    t1.insert((t1.root),4);
    t1.insert((t1.root),2);
    t1.insert((t1.root),7);
    t1.insert((t1.root),1);
    t1.insert((t1.root),3);
    // t1.insert((t1.root),17);

    val=2;
    bool flag = false;
    // flag = t1.traversal(t1.root,k,flag);
    // cout<<flag<<endl;
    t1.searchNode(t1.root,val);
    return 0;
}

bool BST::searchNode(Node *r,int val){
    if(r==NULL) return false;

    // cout<<r->data<<endl;

    if(r->data==val) {
        preOrderTraversal(r);        
        return true;
}
    else if (val < r->data) return searchNode(r->left,val);
    else                    return searchNode(r->right,val);


}

Node* BST::preOrderTraversal( Node* r){
     if (r == NULL)
        return NULL;
   
    cout << " "<< r->data << ",";
    preOrderTraversal(r->left);
    preOrderTraversal(r->right);    
    return NULL;
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
        
        }
        else if(val<r->data)
        r->left = insert(r->left,val);
        else{
        r->right = insert(r->right,val);

        }
        
    return r;    
    }

}
