//https://leetcode.com/problems/boundary-of-binary-tree/
//https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725

bool isLeaf(TreeNode<int>* root){
    return root->left==NULL && root->right==NULL;
}

void addLeftBoundary(TreeNode<int>* root,vector<int>& ans){
    //add left boundary except root and leaf
    TreeNode<int>* cur=root->left;
    while(cur){
        if(!isLeaf(cur))ans.push_back(cur->data);
        if(cur->left)
            cur=cur->left;
        else
            cur=cur->right;
    }
}

void addLeaves(TreeNode<int>* root,vector<int>& ans){
    //add all leaves
    if(!root){
        return;
    }
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left,ans);
    addLeaves(root->right,ans);
}

void addRightBoundary(TreeNode<int>* root,vector<int>& ans){
    //add right boundary except root and leaf
    TreeNode<int>* cur=root->right;
    stack<int> stk;
    while(cur){
        if(!isLeaf(cur))stk.push(cur->data);
        if(cur->right)
            cur=cur->right;
        else
            cur=cur->left;
    }
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    //add root when its not tackled by leaves
    if(!isLeaf(root))ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}
