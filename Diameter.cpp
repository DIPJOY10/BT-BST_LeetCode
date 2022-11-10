//https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
public:
    int helper(TreeNode* root,int& dia){
        if(!root){
            return 0;
        }
        int lh=helper(root->left,dia);
        int rh=helper(root->right,dia);
        dia=max(dia,lh+rh+1);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
       int dia=0;
       helper(root,dia); 
       return dia-1;
    }
};
