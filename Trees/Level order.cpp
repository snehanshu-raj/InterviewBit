/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* a) {
    
    vector < vector <int> > ans;
    vector <int> level0;
    
    queue <TreeNode*> q;
    q.push(a);
    
    level0.push_back(a -> val);
    ans.push_back(level0);
    
    while(!q.empty())
    {
        vector <int> levels;
        int size = q.size();
        
        int c = 0;
        
        while(c != size)
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(node -> left)
            {
                q.push(node -> left);
                levels.push_back(node -> left -> val);
            }
            
            if(node -> right)
            {
                q.push(node -> right);
                levels.push_back(node -> right -> val);
            }
            
            c++;
        }
        
        if(levels.size() > 0)
            ans.push_back(levels);
    }
    
    return ans;
}
