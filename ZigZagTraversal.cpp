//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        int order=1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> curr;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                curr.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(!order){
                reverse(curr.begin(),curr.end());
            }
            ans.push_back(curr);
            order=1-order;
        }
        return ans;
    }
};
