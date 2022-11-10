//preorder, inorder and postorder in one pass

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> preorder, inorder, postorder;
        if(!root){
            return postorder;
        }
        stack<pair<TreeNode*, int>> stk;
        stk.push({root,1});
        while(!stk.empty()){
            auto it=stk.top();
            stk.pop();
            if(it.second==1){
                preorder.push_back(it.first->val);
                //if there is left keep pushing left
                stk.push({it.first,2});
                if(it.first->left){
                    stk.push({it.first->left,1});
                }
            }else if(it.second==2){
                inorder.push_back(it.first->val);
                stk.push({it.first,3});
                if(it.first->right){
                    stk.push({it.first->right,1});
                }
            }else{
                postorder.push_back(it.first->val);
            }
        }
        return postorder;
    }
};
