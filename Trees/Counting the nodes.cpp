/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int count_using_dfs(TreeNode* a, int max_val)
{
    if(a == NULL)
        return 0;
    int count = 0;
    
    if(a -> val > max_val)
    {
        count = 1;
        max_val = a -> val;
    }
    
    count += count_using_dfs(a -> left, max_val);
    count += count_using_dfs(a -> right, max_val);
    
    return count;
}

int Solution::solve(TreeNode* a) {
    
    return count_using_dfs(a, 0);
}
