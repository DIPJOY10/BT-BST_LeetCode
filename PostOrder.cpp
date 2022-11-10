//https://leetcode.com/problems/binary-tree-postorder-traversal/

class Solution {
public:
    void postorder(TreeNode* root,vector<int>& ans){
        if(!root)
        return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

//iterative
class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            auto it=st1.top();
            st1.pop();
            st2.push(it);
            if(it->left){
                st1.push(it->left);
            }
            if(it->right){
                st1.push(it->right);
            }
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};
