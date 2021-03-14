/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(vector<int> &a) {
    
    TreeNode* root = new TreeNode(a[0]);
    queue <TreeNode*> q;
    q.push(root);
    
    int i, c = 0;
    for(i = 0; c * 2 + 1 < a.size() ; i++)
    {
        if(a[i] > 0)
        {
            TreeNode* t = q.front();
            q.pop();
            
            int lc = 2 * c + 1;
            int rc = 2 * c + 2;
            
            if(lc >= a.size())
                break;
                
            if(a[lc] > 0)
            {
                TreeNode* l = new TreeNode(a[lc]);
                t -> left = l;
                q.push(l);
            }
            
            if(rc >= a.size())
                break;
                
            if(a[rc] > 0)
            {
                TreeNode* r = new TreeNode(a[rc]);
                t -> right = r;
                q.push(r);
            }
            c++;
        }
    }
    
    return root;
}
