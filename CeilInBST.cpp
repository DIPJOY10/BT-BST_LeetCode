//https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?leftPanelTab=0

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    BinaryTreeNode<int>* cur=node;
    int ans=-1;
    while(cur){
        if(cur->data<x){
            cur=cur->right;
        }else if(cur->data>x){
            ans=cur->data;
            cur=cur->left;
        }else{
            return x;
        }
    }
    return ans;
}
