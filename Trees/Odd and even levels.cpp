/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sum(TreeNode* a)
{
    if(a == NULL)
        return 0;
    return a -> val - sum(a -> left) - sum(a -> right);
}

int Solution::solve(TreeNode* a) {
    
    return sum(a);
}