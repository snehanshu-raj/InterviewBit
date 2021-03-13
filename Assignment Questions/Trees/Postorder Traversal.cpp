/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* a) {
    
    vector <int> ans;
    
    if(a == NULL)
        return ans;
    
    stack <TreeNode*> s1;
    stack <TreeNode*> s2;
    
    s1.push(a);
    
    while(!s1.empty())
    {
        TreeNode* t = s1.top();
        s1.pop();
        
        s2.push(t);
        
        if(t -> left)
            s1.push(t -> left);
        if(t -> right)
            s1.push(t -> right);
    }
    
    while(!s2.empty())
    {
        TreeNode* t = s2.top();
        s2.pop();
        
        ans.push_back(t -> val);
    }
    
    return ans;
}
