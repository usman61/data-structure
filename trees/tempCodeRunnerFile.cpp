
    Node* truncate(Node *r,int s,int e){

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