//https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution {
public:
    void preorder(TreeNode* root,vector<int>& ans){
        if(!root)
        return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

//iterative version using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        //iterative
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            auto it=stk.top();
            stk.pop();
            ans.push_back(it->val);
            if(it->right)
            stk.push(it->right);
            if(it->left)
            stk.push(it->left);
        }
        return ans;
    }
};
