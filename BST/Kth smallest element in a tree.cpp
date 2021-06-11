/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int n;

void inorder(TreeNode* a, vector <int> &v)
{
    if(a)
    {
        inorder(a -> left, v);
        v.push_back(a -> val);
        if(v.size() == n)
            return;
        inorder(a -> right, v);
    }
}

int Solution::kthsmallest(TreeNode* a, int b) {
    
    n = b;
    vector <int> v;
    inorder(a, v);
    
    return v[b - 1];
}
