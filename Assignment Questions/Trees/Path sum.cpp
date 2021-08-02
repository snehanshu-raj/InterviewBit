/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* a, int b) {
   
    if(a == NULL)
        return 0;
    
    if(a -> left == NULL && a -> right == NULL)
        return a -> val == b;
    
    return hasPathSum(a -> left, b - a -> val) || hasPathSum(a -> right, b - a -> val);
}