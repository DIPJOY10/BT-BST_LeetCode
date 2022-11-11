//https://www.codingninjas.com/codestudio/problems/left-view-of-binary-tree_625707

void printLeftView(BinaryTreeNode<int> *root)
{
    if(!root){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            q.pop();
            if(i==0){
                cout<<it->data<<" ";
            }
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
        }
    }
    cout<<endl;
}
