//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

class Solution {
public:
    TreeNode* ans=NULL;
    int findLCA(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root)
            return 0;
        int leftval=findLCA(root->left,p,q);
        int rightval=findLCA(root->right,p,q);
        int mid=(root==p || root==q);
        if(leftval+rightval+mid>=2){
            ans=root;
        }
        return (leftval+rightval+mid>0);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findLCA(root,p,q);
        return ans;
    }
};

//similar approach, within same function
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root=p || root==q){
            return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(!left){
            return right;
        }
        if(!right){
            return left;
        }
        return root;
    }
};
