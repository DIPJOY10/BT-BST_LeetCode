//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        if(root->right){
            flatten(root->right);
        }
        if(root->left){
            flatten(root->left);
            TreeNode* cur=root->left;
            while(cur->right!=NULL){
                cur=cur->right;
            }
            cur->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
    }
};
