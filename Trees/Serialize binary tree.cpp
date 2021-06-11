/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* a) {
    
    vector <int> ans;
    queue <TreeNode*> q;
    
    q.push(a);
    ans.push_back(a -> val);
    
    int level;
    
    while(!q.empty())
    {
        level = q.size();
        
        while(level--)
        {
            TreeNode* t = q.front();
            q.pop();
            
            if(t -> left)
            {
                q.push(t -> left);
                ans.push_back(t -> left -> val);
            }
            else
            {
                ans.push_back(-1);
            }
            
            if(t -> right)
            {
                q.push(t -> right);
                ans.push_back(t -> right -> val);
            }
            else
            {
                ans.push_back(-1);
            }
        }
    }
    
    return ans;
}
