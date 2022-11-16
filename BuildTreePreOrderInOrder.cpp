//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m1;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            m1[inorder[i]]=i;
        }
        return build(preorder,inorder,m1,0,n-1,0,n-1);
    }
    
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,map<int,int>& m1,int is,int ie,int ps,int pe){
        if(ps>pe)return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int currpos=m1[preorder[ps]];
        int leftele=currpos-is;
        root->left=build(preorder,inorder,m1,is,currpos-1,ps+1,ps+leftele);
        root->right=build(preorder,inorder,m1,currpos+1,ie,ps+leftele+1,pe);
        return root;
    }
};
