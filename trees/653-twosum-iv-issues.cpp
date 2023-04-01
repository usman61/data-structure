/*
653. Two Sum IV - Input is a BST  - LeetCode

Given the root of a binary search tree and an integer k, return true if there exist two elements
in the BST such that their sum is equal to k, or false otherwise.

Note: locally it works but on leet code it gives run time error due to memory issues
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
    bool preOrderTraversal(Node *temp,Node *root,int k);
    bool twoSumK(Node *r,Node *root,int k);

};
int main(int argc, char const *argv[])
{
    BST t1;
    int k;

    t1.insert((t1.root),5);
    t1.insert((t1.root),3);
    t1.insert((t1.root),6);
    t1.insert((t1.root),2);
    t1.insert((t1.root),4);
    t1.insert((t1.root),7);

    k=28;

    cout<<t1.twoSumK(t1.root,t1.root,k)<<endl;
    return 0;
}

bool BST::twoSumK(Node *r,Node *root,int k){
 static bool flag = false;
 if(r==NULL) return flag;

 flag = preOrderTraversal(r,root,k);
 cout<<flag<<" In two sum K function"<<endl;
 if(flag)
 return true;
 else{
    twoSumK(r->left,root,k);
    twoSumK(r->right,root,k);
 }

 return flag;

}

bool BST::preOrderTraversal(Node *temp,Node *root,int k){

     static bool flag=false;

    if(root==NULL){
        //return false;
        if (flag){
            return true;
        }
        else
        return false;

    } 
    

    // cout<<"Temp data--->"<<temp->data<<" Val--->"<<root->data<<endl;

    else if (temp->data == root->data){
    //   cout<<"Temp data--->"<<temp->data<<" Val--->"<<val<<endl;
    // cout<<"done"<<endl;
        ;
    }

    else if(temp->data+root->data==k){
        cout<<"Temp data--->"<<temp->data<<" Val--->"<<root->data<<endl;
        flag = true;
    }
    
    flag = preOrderTraversal(temp,root->left,k);
    flag = preOrderTraversal(temp,root->right,k);
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
