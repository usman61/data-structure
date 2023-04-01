/*
653. Two Sum IV - Input is a BST  - LeetCode

Given the root of a binary search tree and an integer k, return true if there exist two elements
in the BST such that their sum is equal to k, or false otherwise.
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
    bool traversal( Node* r,int k,bool &flag);





};
int main(int argc, char const *argv[])
{
    BST t1;
    int k;

    t1.insert((t1.root),2);
    t1.insert((t1.root),1);
    t1.insert((t1.root),3);
    // t1.insert((t1.root),2);
    // t1.insert((t1.root),4);
    // t1.insert((t1.root),17);

    k=4;
    bool flag = false;
    flag = t1.traversal(t1.root,k,flag);
    cout<<flag<<endl;
    return 0;
}

bool BST::searchNode(Node *r,int val){
    if(r==NULL) return false;

    // cout<<r->data<<endl;

    if(r->data==val) return true;

    else if (val < r->data) return searchNode(r->left,val);
    else                    return searchNode(r->right,val);


}


bool BST::traversal( Node* r,int k,bool &flag){

    if (r == NULL)
        return flag;

    if (flag)
    return true;   
    
    int res = k - r->data;
    if(res == r->data)
    ;
    else if(searchNode(root,res)){
        flag = true;
        return flag;

        }
        traversal(r->left,k,flag);        
        traversal(r->right,k,flag);
        return flag;
    
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
