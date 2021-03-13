/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* ans(vector<int> &in, vector<int> &po, int s, int e, int *ptr, unordered_map <int, int> m)
{
    if(s > e)
        return NULL;
    
    int cur = po[*ptr];
    TreeNode* node = new TreeNode(cur);
    (*ptr)--;
    
    if(s == e)
        return node;
    
    int i = m[cur];
    
    node -> right = ans(in, po, i + 1, e, ptr, m);
    node -> left = ans(in, po, s, i - 1, ptr, m);
    
    return node;
}

TreeNode* Solution::buildTree(vector<int> &in, vector<int> &po) {
    
    unordered_map <int, int> m;
    int i;
    
    for(i = 0; i < in.size(); i++)
        m[ in[i] ] = i;
    
    i = in.size() - 1;
    return ans(in, po, 0, in.size() - 1, &i, m);
}
