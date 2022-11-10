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

//2 stacks-> preorder (root,l,r)->reverse(root,r,l)
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

//1 stack and curr pointer
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                assert(!stk.empty());
                TreeNode* justRight=stk.top()->right;
                if(justRight){
                    temp=justRight;
                }else{
                    justRight=stk.top();
                    stk.pop();
                    ans.push_back(justRight->val);
                    while(!stk.empty() && justRight==stk.top()->right){
                        justRight=stk.top();
                        stk.pop();
                        ans.push_back(justRight->val);
                    }
                }
            }
        }
        return ans;
    }
};
