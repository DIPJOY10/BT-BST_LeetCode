//https://www.codingninjas.com/codestudio/problems/bottom-view-of-binary-tree_893110

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    map<int,int> m1;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        int coordinate=node.second;
        m1[coordinate]=node.first->data;
        if(node.first->left){
            q.push({node.first->left,coordinate-1});
        }
        if(node.first->right){
            q.push({node.first->right,coordinate+1});
        }
    }
    for(auto&it:m1){
        ans.push_back(it.second);
    }
    return ans;
}
