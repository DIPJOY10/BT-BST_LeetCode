//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*,TreeNode*> m1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto [node,temp]=q.front();
            q.pop();
            if(node->left){
                m1[node->left]=node;
                q.push({node->left,0});
            }
            if(node->right){
                m1[node->right]=node;
                q.push({node->right,0});
            }
        }
        q.push({target,0});
        unordered_map<TreeNode*,int> visited;
        visited[target]=1;
        while(!q.empty()){
            auto [node,d]=q.front();
            q.pop();
            if(d==k){
                ans.push_back(node->val);
                continue;
            }
            if(node->left && visited.find(node->left)==visited.end()){
                q.push({node->left,d+1});
                visited[node->left]=1;
            }
            if(node->right && visited.find(node->right)==visited.end()){
                q.push({node->right,d+1});
                visited[node->right]=1;
            }
            if(m1.find(node)!=m1.end() && visited.find(m1[node])==visited.end()){
                q.push({m1[node],d+1});
                visited[m1[node]]=1;
            }
        }

        return ans;

    }
};
