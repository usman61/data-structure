/*
530. Minimum Absolute Difference in BST  - LeetCode

Given the root of a Binary Search Tree (BST), return the minimum absolute 
difference between the values of any two different nodes in the tree.

Note: This question is the same as 783: 
https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    void getDifference(Node *curr,Node *r,int &diff);
    void traverseNodes(Node * curr,Node *r,int &diff);

};
int main(int argc, char const *argv[])
{
    BST t1;
    int diff  = 0;

    t1.insert((t1.root),1);
    t1.insert((t1.root),0);
    t1.insert((t1.root),48);
    t1.insert((t1.root),12);
    t1.insert((t1.root),49);
   
    t1.traverseNodes(t1.root,t1.root,diff);
    cout<<diff<<endl;
    return 0;
}
/*
this would traverse the whole tree for each node.
*/
void BST::traverseNodes(Node * curr,Node *r,int &diff){

    if(root==NULL)
    return;

    getDifference(curr,r,diff);
    if(diff==1) return;

    traverseNodes(curr->left,r,diff);
    traverseNodes(curr->right,r,diff);

    
}
/*
this would calculate the difference between nodes
*/
void BST::getDifference(Node *curr,Node *r,int &diff){

  
    if(r==NULL){
      return;
    } 
    
    else if (curr->data == r->data) ;   // ignoring the case when curr and r pointing to the same node
  

    else if( abs(curr->data-r->data) <diff || diff==0){   
        diff = abs(curr->data-r->data);
       
    }
    
    getDifference(curr,r->left,diff);
    getDifference(curr,r->right,diff);
    

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
