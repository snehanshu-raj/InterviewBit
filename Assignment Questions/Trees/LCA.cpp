/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// time O(3n) space O(3h)

bool path(TreeNode* a, vector <int> &arr, int k)
{
    if(a == NULL)
        return false;
    
    arr.push_back(a -> val);
    
    if(a -> val == k)
        return true;
    
    bool lc = path(a -> left, arr, k);
    bool rc = path(a -> right, arr, k);
    
    if(lc || rc)
        return true;
    else
    {
        arr.pop_back();
        return false;
    }
}

int Solution::lca(TreeNode* a, int b, int c) {
    
    vector <int> path1, path2;
    bool l = path(a, path1, b);
    bool r = path(a, path2, c);

    int i;
        
    if(path1.size() == 0 || path2.size() == 0)
        return -1;
        
    for(i = 0; i < path1.size() && i < path2.size(); i++)
    {
        if(path1[i] != path2[i])
            return path1[i - 1];
    }
    
    return path1[i - 1];
}
