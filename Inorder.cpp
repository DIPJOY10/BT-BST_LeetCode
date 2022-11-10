//https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    void inorder(TreeNode* root,vector<int>& ans){
        if(!root)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

//iterative version
class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        stack<TreeNode*> stk;
        TreeNode* temp=root;
        while(temp!=NULL || !stk.empty()){
            if(temp){
                stk.push(temp);
                temp=temp->left;
            }else{
                //can't go any more left
                temp=stk.top();
                stk.pop();
                ans.push_back(temp->val);
                temp=temp->right;
            }
        }
        return ans;
    }
};
