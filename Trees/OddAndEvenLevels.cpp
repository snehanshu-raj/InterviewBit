/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* a) {
    
    queue <TreeNode*> q;
    q.push(a);
    vector <int> sum(2, 0);
    int f = 1;
    
    while(!q.empty())
    {
        f = 1 - f;
        int c = q.size();
        
        while(c--)
        {
            TreeNode* node = q.front();
            q.pop();
            sum[f] += node -> val;
            
            if(node -> left)
                q.push(node -> left);
            if(node -> right)
                q.push(node -> right);
        }
    }
    
    return sum[0] - sum[1];
}
