//https://www.codingninjas.com/codestudio/problems/time-to-burn-tree_630563

//if all node values<=~1e6

void dfs(BinaryTreeNode<int>* root,vector<vector<int>>& adj){
    if(!root)
        return;
    if(root->left){
        adj[root->data].push_back(root->left->data);
        adj[root->left->data].push_back(root->data);
        dfs(root->left,adj);
    }
    if(root->right){
        adj[root->data].push_back(root->right->data);
        adj[root->right->data].push_back(root->data);
        dfs(root->right,adj);
    }
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    int ans=0;
    vector<vector<int>>adj(1000005);
    dfs(root,adj);
    queue<pair<int,int>> q;
    q.push({start,0});
    vector<int> vis(1000005,0);
    vis[start]=1;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        ans=max(ans,it.second);
        for(auto&u:adj[it.first]){
            if(vis[u])
                continue;
            vis[u]=1;
            q.push({u,it.second+1});
        }
    }
    return ans;
}

//if node values can be upto 1e9
BinaryTreeNode<int>* target;
void dfs(BinaryTreeNode<int>*root, map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>& parent,int start){
    if(!root)
        return;
    if(root->data==start){
        target=root;
    }
    if(root->left){
        parent[root->left]=root;
        dfs(root->left,parent,start);
    }
    if(root->right){
        parent[root->right]=root;
        dfs(root->right,parent,start);
    }
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
    int ans=0;
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>parent;
    dfs(root,parent,start);
    map<BinaryTreeNode<int>*,int> visited;
    queue<pair<BinaryTreeNode<int>*,int>>q;
    if(target)
    q.push({target,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        ans=max(ans,it.second);
        if(it.first->left && 
           visited.find(it.first->left)==visited.end()){
            q.push({it.first->left,it.second+1});
            visited[it.first->left]=1;
        }
        if(it.first->right && 
           visited.find(it.first->right)==visited.end()){
            q.push({it.first->right,it.second+1});
            visited[it.first->right]=1;
        }
        if(parent.find(it.first)!=parent.end() 
           &&   visited.find(parent[it.first])==visited.end()){
            q.push({parent[it.first],it.second+1});
            visited[parent[it.first]]=1;
        }
    }
    return ans;
}
