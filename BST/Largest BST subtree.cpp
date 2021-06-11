/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct info
{
    bool isBST;
    int size;
    int max;
    int min;
    int ans;
};

info checker(TreeNode* a)
{
    if(a == NULL)
        return {true, 0, INT_MIN, INT_MAX, 0};
    if(a -> left == NULL && a -> right == NULL)
        return {true, 1, a -> val, a -> val, 1};
    
    info l = checker(a -> left);
    info r = checker(a -> right);
    
    info obj;
    obj.size = l.size + r.size + 1;
    
    if(l.isBST && r.isBST && l.max < a -> val && r.min > a -> val)
    {
        obj.ans = obj.size;
        obj.min = min(l.min, a -> val);
        obj.max = max(r.max, a -> val);
        obj.isBST = true;
        return obj;
    }
    else
    {
        obj.isBST = false;
        obj.ans = max(l.ans, r.ans);
        return obj;
    }
}

int Solution::solve(TreeNode* a) {
    
    return checker(a).ans;
}
