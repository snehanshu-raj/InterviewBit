/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int checker(TreeNode* a)
{
    if(a == NULL)
        return 0;
        
    if(a -> left == NULL && a -> right == NULL)
        return a -> val;
        
    int l = checker(a -> left);
    int r = checker(a -> right);
    
    if(l != -1 && r != -1)
    {
        if(l + r == a -> val)
            return l + r + a -> val;
        return -1;
    } 
    
    return -1;
}

int Solution::solve(TreeNode* a) {
    
    if(a == NULL)
        return 1;
        
    if(checker(a) == -1)
        return 0;
    return 1;
}
