/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int find_len(TreeNode* a, int node)
{
    if(a -> val == node)
        return 0;
    if(node > a -> val)
        return 1 + find_len(a -> right, node);
    return 1 + find_len(a -> left, node);
}

int checker(TreeNode* a, int b, int c)
{
    if(b > a -> val && c > a -> val)
        return checker(a -> right, b, c);
        
    if(b < a -> val && c < a -> val)
        return checker(a -> left, b, c);
    
    return find_len(a, b) + find_len(a, c);
}

int Solution::solve(TreeNode* a, int b, int c) {
    
    return checker(a, b, c);
}
