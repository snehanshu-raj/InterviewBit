/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// void inorder(TreeNode* a, vector <int> &v)
// {
//     if(a)
//     {
//         inorder(a -> left, v);
//         v.push_back(a -> val);
//         inorder(a -> right, v);
//     }
// }

int count(TreeNode* a, int b, int c)
{
    if(a == NULL)
        return 0;
    if(a -> val >= b && a -> val <= c)
        return 1 + count(a -> left, b, c) + count(a -> right, b, c);
    if(a -> val < b)
        return count(a -> right, b, c);
    if(a -> val > c)
        return count(a -> left, b, c);
    return 0;
}

int Solution::solve(TreeNode* a, int b, int c) {
    
    // correct solution
    
    // vector <int> v;
    // inorder(a, v);
    
    // int i;
    // int ans = 0;
    // for(i = 0; i < v.size(); i++)
    // {
    //     if(v[i] >= b && v[i] <= c)
    //         ans++;
    //     else
    //     if(v[i] > c)
    //         break;
    // }
    
    // return ans;
    
    //another aproach
    
    return count(a, b, c);
}
