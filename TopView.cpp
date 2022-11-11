//https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree_799401

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(!root){
        return ans;
    }
    map<int,int> m1;
    queue<pair<TreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(m1.find(it.second)==m1.end()){
            m1[it.second]=it.first->val;
        }
        if(it.first->left){
            q.push({it.first->left,it.second-1});
        }
        if(it.first->right){
            q.push({it.first->right,it.second+1});
        }
    }
    for(auto&it:m1){
        ans.push_back(it.second);
    }
    return ans;
}
