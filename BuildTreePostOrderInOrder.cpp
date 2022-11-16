//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    TreeNode* build(int ps,int pe,int is,int ie,vector<int>& postorder,vector<int>& inorder,map<int,int>& m1){
        if(ps>pe)
            return NULL;
        int cur=postorder[pe];
        TreeNode* root=new TreeNode(cur);
        int idx=m1[cur],right_ele=ie-idx;
        root->left=build(ps,pe-right_ele-1,is,idx-1,postorder,inorder,m1);
        root->right=build(pe-right_ele,pe-1,idx+1,ie,postorder,inorder,m1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m1;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m1[inorder[i]]=i;
        }
        return build(0,n-1,0,n-1,postorder,inorder,m1);
    }
};
