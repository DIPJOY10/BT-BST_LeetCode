//https://leetcode.com/problems/balanced-binary-tree/description/

class Solution {
public:
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh=helper(root->left);
        int rh=helper(root->right);
        if(abs(lh-rh)>1 || lh==-1 || rh==-1){
            return -1;
        }
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        return helper(root)!=-1;
    }
};
