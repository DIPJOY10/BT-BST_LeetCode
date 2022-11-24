//https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457

//iterative
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans=0;
    TreeNode<int>* cur=root;
    while(cur){
        if(cur->val>X){
            cur=cur->left;
        }else if(cur->val<X){
            ans=cur->val;
            cur=cur->right;
        }else{
            return X;
        }
    }
    return ans;
}

//recursive
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    if(root->val==X)
        return X;
    if(root->val>X){
        return floorInBST(root->left,X);
    }
    if(root->right==NULL){
        return root->val;
    }
    TreeNode<int>* cur=root->right;
    while(cur->left)
        cur=cur->left;
    if(cur->val>X){
        return root->val;
    }
    return floorInBST(root->right,X);
}
