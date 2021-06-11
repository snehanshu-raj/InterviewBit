/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* a) {
    
    // using deque data structure
    
    // vector < vector <int> > ans;
    // deque <TreeNode*> list;
    
    // list.push_back(a);
    // int f = 1; //left to right first
    
    // while(!list.empty())
    // {
    //     int level = list.size();
    //     vector <int> v;
        
    //     while(level--)
    //     {
    //         if(f)
    //         {
    //             TreeNode* t = list.front();
    //             list.pop_front();
                
    //             v.push_back(t -> val);
                
    //             if(t -> left)
    //                 list.push_back(t -> left);
    //             if(t -> right)
    //                 list.push_back(t -> right);
    //         }
    //         else
    //         {
    //             TreeNode* t = list.back();
    //             list.pop_back();
                
    //             v.push_back(t -> val);
                
    //             if(t -> right)
    //                 list.push_front(t -> right);
    //             if(t -> left)
    //                 list.push_front(t -> left);
    //         }
    //     }
        
    //     f = !f;
    //     if(v.size() > 0)
    //         ans.push_back(v);
    // }
    
    // return ans;
    
    //using stack data structure
    
    vector < vector <int> > ans;
    stack <TreeNode*> now;
    stack <TreeNode*> later;
    
    now.push(a);
    int f = 1;
    vector <int> v;
    
    while(!now.empty())
    {
        if(f)
        {
            TreeNode* t = now.top();
            now.pop();
            
            v.push_back(t -> val);
            
            if(t -> left)
                later.push(t -> left);
            if(t -> right)
                later.push(t -> right);
        }
        else
        {
            TreeNode* t = now.top();
            now.pop();
            
            v.push_back(t -> val);
            
            if(t -> right)
                later.push(t -> right);
            if(t -> left)
                later.push(t -> left);
        }
        
        if(now.empty())
        {
            f = !f;
            swap(now, later);
            if(v.size() > 0)
                ans.push_back(v);
            v.clear();
        }
    }
    
    return ans;
}
