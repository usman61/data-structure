// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:


    bool findTarget(TreeNode* root, int k) {
        bool flag=false;
    return inOrderTraversal(root,root,k,flag);
    }

     bool inOrderTraversal( TreeNode* r,TreeNode* root,int k,bool &flag){

     if (r == NULL)
        return flag;

     if (flag)
     return true;   
    
    int res = k - r->val;
    if (res == r->val)
    ;
    else if(searchNode(root,res)){
        flag = true;
        return flag;

    }
    /* first recur on left child */
    inOrderTraversal(r->left,root,k,flag);
    /* then print the data of node */
    
    /* now recur on right child */
    inOrderTraversal(r->right,root,k,flag);
    return flag;
   
}
bool searchNode(TreeNode *r,int val){
    if(r==NULL) return false;

    else if(r->val==val) return true;

    else if (val < r->val) return searchNode(r->left,val);
    else                    return searchNode(r->right,val);


}


};