//https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //using morris traversal
        vector<int> ans;
        TreeNode* cur=root;
        while(cur){
            if(cur->left){
                //we have to perform inorder of left subtree first
                TreeNode* temp=cur->left;
                while(temp->right!=NULL && temp->right!=cur){
                    temp=temp->right;
                }
                if(temp->right!=cur){
                    temp->right=cur;
                    cur=cur->left;
                }else{
                    //erase this pointer, we have already visited the left subtree
                    temp->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }else{
                ans.push_back(cur->val);
                cur=cur->right;
            }
        }
        return ans;
    }
};
