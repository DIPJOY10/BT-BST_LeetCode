//https://www.interviewbit.com/problems/path-to-given-node/

bool helper(TreeNode* A,int B,vector<int>& ans){
    if(!A){
        return false;
    }
    ans.push_back(A->val);
    if(A->val==B){
        return true;
    }
    if(helper(A->left,B,ans) || helper(A->right,B,ans){
        return true;
    }
    ans.pop_back();
    return false;
} 
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    helper(A,B,ans);
    return ans;
}
