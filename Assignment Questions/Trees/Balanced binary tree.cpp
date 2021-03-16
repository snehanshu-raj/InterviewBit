/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* a)
{
    if(a != NULL)
    {
        int x = height(a -> left);
        int y = height(a -> right);
        
        if(x > y)
            return x + 1;
        else
            return y + 1;
    }
    else
        return 0;
}

int is_balanced(TreeNode* a)
{
    if(a == NULL)
        return 1;
    int lh = height(a -> left);
    int rh = height(a -> right);
    
    if( abs(lh - rh) <= 1 && is_balanced(a -> left) && is_balanced(a -> right) )
        return 1;
    else
        return 0;
}

int Solution::isBalanced(TreeNode* a) {
    
    return is_balanced(a);
}
