/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* a) {
    
    vector <int> ans;
    
    if(a == NULL)
        return ans;
        
    stack <TreeNode*> s;
    s.push(a);
    
    while(!s.empty())
    {
        TreeNode* t = s.top();
        s.pop();
        
        ans.push_back(t -> val);
        
        if(t -> right)
            s.push(t -> right);
        if(t -> left)
            s.push(t -> left);
    }
    
    return ans;
}
