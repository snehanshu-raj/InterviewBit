/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// TreeNode* flatten(TreeNode* a)
// {
//     if(a == NULL)
//         return NULL;
    
//     TreeNode* l = flatten(a -> left);
//     TreeNode* r = flatten(a -> right);
    
//     a -> left = NULL;
    
//     if(l != NULL)
//     {
//         a -> right = l;
        
//         while(l -> right != NULL)
//         {
//             l = l -> right;
//         }
        
//         l -> right = r;
//     }
//     else
//     {
//         a -> right = r;
//     }
    
//     return a;
// }
    
TreeNode* Solution::flatten(TreeNode* a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // flatten(a);
    // return a;
    

    if(a == NULL)
        return NULL;
        
    TreeNode *node = a;
    while(node != NULL)
    {
        if(node -> left != NULL)
        {
            TreeNode *r = node -> left;
            while(r -> right != NULL)
                r = r -> right;
            r -> right = node -> right;
            node -> right = node->left;
            node -> left = NULL;
        }
        node = node -> right;
    }
    return a;
}
