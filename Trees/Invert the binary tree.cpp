/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void invert(TreeNode* a)
{
    if(a)
    {
        invert(a -> left);
        invert(a -> right);
        
        TreeNode* temp = a -> left;
        a -> left = a -> right;
        a -> right = temp;
    }
}

TreeNode* Solution::invertTree(TreeNode* a) {
    
    invert(a);
    return a;
}
