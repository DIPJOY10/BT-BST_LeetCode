//https://leetcode.com/problems/count-complete-tree-nodes/description/

class Solution {
public:
    int height(TreeNode* root){
        if(!root)
            return 0;
        return 1+height(root->left);
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh=height(root->left), rh=height(root->right);
        int ans=0;
        if(lh==rh)
            ans=(1<<lh)+countNodes(root->right);
        else
            ans=(1<<rh)+countNodes(root->left);
        return ans;
    }
};
