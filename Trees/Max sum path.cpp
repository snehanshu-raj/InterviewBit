/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans;

int max_sum(TreeNode* a)
{
    if(a == NULL)
        return 0;
    
    int l = max_sum(a -> left);
    int r = max_sum(a -> right);
    
    int case1 = max( max(l, r) + a -> val, a -> val);
    
    int case2 = l + r + a -> val;
    
    int temp_max = max(case1, case2);
    
    ans = max(ans, temp_max);
    
    return case1;
}
int Solution::maxPathSum(TreeNode* a){
    
    ans = INT_MIN;
    max_sum(a);
    
    return ans;
}
