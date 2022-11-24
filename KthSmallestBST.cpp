//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

//O(n) t.c and O(1) s.c->morris traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            return -1;
        }
        TreeNode* cur=root;
        int rem=k;
        int ans=-1;
        while(cur){
            if(cur->left){
                TreeNode* temp=cur->left;
                while(temp->right!=NULL && temp->right!=cur){
                    temp=temp->right;
                }
                if(temp->right==cur){
                    if(rem==1){
                        ans=cur->val;
                    }
                    --rem;
                    temp->right=NULL;
                    cur=cur->right;
                }else{
                    temp->right=cur;
                    cur=cur->left;
                }
            }else{
                if(rem==1){
                    ans=cur->val;
                }
                --rem;
                cur=cur->right;
            }
        }
        return ans;
    }
};

