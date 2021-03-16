/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode* a, vector <int> &v)
{
    if(a)
    {
        inorder(a -> left, v);
        v.push_back(a -> val);
        inorder(a -> right, v);
    }
}

int Solution::t2Sum(TreeNode* a, int b) {
    
    vector <int> v;
    inorder(a, v);
    
    int i= 0, j = v.size() - 1;
    
    while(i < j)
    {
        if(v[i] + v[j] == b)
            return 1;
        if(v[i] + v[j] > b)
            j--;
        else
            i++;
    }
    
    return 0;
}
