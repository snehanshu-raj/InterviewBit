/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// void builder(TreeNode* a, map <int, vector <int> > &m, int dist)
// {
//     if(a == NULL)
//         return;
    
//     m[dist].push_back(a -> val);
    
//     builder(a -> left, m, dist - 1);
//     builder(a -> right, m, dist + 1);
// }

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* a) {
    
    vector < vector <int> > ans;
    map <int, vector <int> > m;
    
    // builder(a, m, 0);
    
    // for(auto it : m)
    // {
    //     ans.push_back(it.second);
    // }
    
    // return ans;
    
    if(a == NULL)
        return ans;
    
    queue < pair <TreeNode*, int> > q;
    int dist = 0;
    
    q.push( make_pair(a, dist) );
    
    while(!q.empty())
    {
        pair <TreeNode*, int> p = q.front();
        q.pop();
        
        int d = p.second;
        m[d].push_back(p.first -> val);
        
        if(p.first -> left)
            q.push( make_pair(p.first -> left, d - 1) );
        if(p.first -> right)
            q.push( make_pair(p.first -> right, d + 1) );
    }
    
    for(auto it : m)
        ans.push_back(it.second);
    
    return ans;
}
