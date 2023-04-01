/*
this script contains basic implementation and operations on binary search tree
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
    void inOrderTraversal(Node *r);
    bool searchNode(Node *r,int val);
    Node* findMin(Node *r);
    Node* findMax(Node *r);
    int countLeafNodes(Node *r);
    int findHeight(Node *r);
    void merge( Node* r1, Node* r2);    
    void findFloorCeil(Node *r,int key,Node *&floor,Node *&ceil);
     

};
int main(int argc, char const *argv[])
{
    BST t1,t2;

    Node obj;
  

    t1.insert((t1.root),5);
    t1.insert((t1.root),9);
    t1.insert((t1.root),12);

    t2.insert((t2.root),1);
    t2.insert((t2.root),15);
    t2.insert((t2.root),10);
 
    cout<<"-----------------------"<<endl;
    t1.inOrderTraversal(t1.root);
    cout<<"-----------------------"<<endl;

    cout<<"-----------------------"<<endl;
    t2.inOrderTraversal(t2.root);
    cout<<"-----------------------"<<endl;

    t1.merge(t1.root,t2.root);

    cout<<"-----------------------"<<endl;
    t2.inOrderTraversal(t2.root);
    cout<<"-----------------------"<<endl;


    // cout<<t1.searchNode(t1.root,9)<<endl;
    // cout<<t1.countLeafNodes(t1.root)<<endl;
    // cout<<t1.findHeight(t1.root)<<endl;
    Node *floor=NULL,*ceil=NULL;
    int key=5;
    t2.findFloorCeil(t2.root,key,ceil,floor);
    cout<<"Ceil-------> "<<( ceil  ? ceil->data: -1)<<endl;
    cout<<"Floor-------> "<<(floor ? floor->data: -1)<<endl;
    return 0;
}

void BST::findFloorCeil(Node *r,int key,Node *&ceil,Node *&floor){
    
    if(r ==NULL) return;
    else{

        if(r->data==key){
            floor =ceil =  r;

            return;
        }
        else if (key<r->data){
            ceil = r;
            findFloorCeil(r->left,key,ceil,floor);
        }
        else{
            floor = r;
            findFloorCeil(r->right,key,ceil,floor);
        }

        

    }


}
void BST::merge( Node *r1, Node *r2){
    // this->merge

     if (r1 == NULL)
        return;
    /* first recur on left child */
   
    merge(r1->left, r2);
    insert(r2, r1->data);
    /* now recur on right child */
    merge(r1->right, r2);
   
}

int BST::findHeight(Node *r){
    int   l_height=0;
    int   r_height=0;
    if (r == NULL)
        return -1;
    else
    {
    l_height = findHeight(r->left);
    r_height = findHeight(r->right);
        if (l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);
    }
}

int BST::countLeafNodes(Node *r){
    static int count=0;

    if(r==NULL)
    return 0;

    if(r->left==NULL && r->right==NULL)
    count++;

    countLeafNodes(r->left);
    countLeafNodes(r->right);
    return count;

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


void BST::inOrderTraversal(Node *temp){

    if(temp==NULL) return;

    inOrderTraversal(temp->left);
    cout<<temp->data<<endl;
    inOrderTraversal(temp->right);


}

