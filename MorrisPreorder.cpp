//https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        //using morris traversal
        vector<int> ans;
        TreeNode* cur=root;
        while(cur){
            if(cur->left){
                //we have to perform preorder of left subtree now
                TreeNode* temp=cur->left;
                while(temp->right!=NULL && temp->right!=cur){
                    temp=temp->right;
                }
                if(temp->right!=cur){
                    ans.push_back(cur->val);
                    temp->right=cur;
                    cur=cur->left;
                }else{
                    //erase this pointer, we have already visited the left subtree
                    temp->right=NULL;
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
