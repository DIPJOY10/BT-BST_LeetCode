//https://leetcode.com/problems/maximum-width-of-binary-tree/description/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root){
            return ans;
        }
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz=q.size();
            int mn,mx;
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                if(i==0){
                    mn=it.second;
                }
                if(i==sz-1){
                    mx=it.second;
                    ans=max(ans,mx-mn+1);
                }
                int curr_val=it.second-mn;
                if(it.first->left){
                    q.push({it.first->left,(long long)curr_val*2});
                }
                if(it.first->right){
                    q.push({it.first->right,(long long)curr_val*2+1});
                }
            }
        }
        return ans;
    }
};
