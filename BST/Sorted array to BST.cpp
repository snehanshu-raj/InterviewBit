/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* build(const vector<int> &a, int start, int end)
{
    if(start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(a[mid]);
    
    node -> left = build(a, start, mid - 1);
    node -> right = build(a, mid + 1, end);
    
    return node;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &a) {
    
    return build(a, 0, a.size() - 1);
}
