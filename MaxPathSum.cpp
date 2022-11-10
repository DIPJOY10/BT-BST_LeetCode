//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

class Solution {
public:
    int ans=-1e9;
    int helper(TreeNode* root){
        if(!root){
            return 0;
        }
        int lpath=0,rpath=0;
        if(root->left){
            lpath=helper(root->left);
        }
        if(root->right){
            rpath=helper(root->right);
        }
        int curr=root->val+max({0,lpath,rpath});
        ans=max({ans,root->val,lpath+root->val,rpath+root->val,lpath+rpath+root->val});
        return curr;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};
