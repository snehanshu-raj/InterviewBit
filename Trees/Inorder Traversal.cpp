/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode* node, vector <int> &ans)
{
    if(node != NULL)
    {
        inorder(node -> left, ans);
        ans.push_back(node -> val);
        inorder(node -> right, ans);
    }
}

vector<int> Solution::inorderTraversal(TreeNode* a) {
    
    vector <int> ans;
    inorder(a, ans);
    
    return ans;
}
