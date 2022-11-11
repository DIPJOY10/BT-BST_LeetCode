//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        map<int,vector<pair<int,int>>>m1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int lev=0;
        while(!q.empty()){
            //at a current level
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto it=q.front();
                q.pop();
                m1[it.second].push_back({lev,it.first->val});
                if(it.first->left){
                    q.push({it.first->left,it.second-1});
                }
                if(it.first->right){
                    q.push({it.first->right,it.second+1});
                }
            }
            lev++;
        }
        for(auto&it:m1){
            sort(it.second.begin(),it.second.end());
            vector<int> v;
            for(auto&ele:it.second){
                v.push_back(ele.second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
