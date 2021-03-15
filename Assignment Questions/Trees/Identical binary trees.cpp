/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int checker(TreeNode* a, TreeNode* b)
{
    if(a == NULL && b == NULL)
        return 1;
    if(a == NULL || b == NULL)
        return 0;
    if(a -> val != b -> val)
        return 0;
    return checker(a -> left, b -> left) && checker(a -> right, b -> right);
    
}

int Solution::isSameTree(TreeNode* a, TreeNode* b) {
    
    return checker(a, b);
}
