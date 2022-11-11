//https://www.interviewbit.com/problems/path-to-given-node/

void helper(TreeNode* A,int B,vector<int>& ans,bool& found){
    if(!A){
        return;
    }
    if(!found){
        ans.push_back(A->val);
        if(B==A->val){
            found=true;
        }   
    }
    helper(A->left,B,ans,found);
    helper(A->right,B,ans,found);
    if(!found){
        ans.pop_back();
    }
} 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    bool found=false;
    helper(A,B,ans,found);
    return ans;
}
