//add any non negative value to any node.
//make the BT satisfy the children sum property-> value at any node=sum of values of left and right child

class Solution{
 public:
  void ChildrenSumConversion(TreeNode* root){
    if(!root){
      return;
    }
    int lval=(root->left)?root->left->val:0;
    int rval=(root->right)?root->right->val:0;
    if(root->val<=lval+rval){
      root->val=lval+rval;
    }else{
      if(root->left) root->left->data=root->data;
      if(root->right) root->right->data=root->data;
    }
    ChildrenSumConversion(root->left);
    ChildrenSumConversion(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;
  }
}
