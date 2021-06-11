/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// void inorder(TreeNode* a, vector <int> &ar)
// {
//     if(a)
//     {
//         inorder(a -> left, ar);
//         ar.push_back(a -> val);
//         inorder(a -> right, ar);
//     }
// }

int sum(TreeNode* a, TreeNode* b)
{
    stack <TreeNode*> s1, s2;
    int ans = 0;
    
    while(1)
    {
        if(a)
        {
            s1.push(a);
            a = a -> left;
        }
        
        else
        if(b)
        {
            s2.push(b);
            b = b -> left;
        }
        
        else
        if(!s1.empty() && !s2.empty())
        {
            a = s1.top();
            b = s2.top();
            
            if(a -> val == b -> val)
            {
                ans = (ans + (a -> val)) % 1000000007;
                s1.pop();
                s2.pop();
                a = a -> right;
                b = b -> right;
            }
            
            else
            if(a -> val < b -> val)
            {
                a = a -> right;
                s1.pop();
                b = NULL;
            }
            
            else
            if(b -> val < a -> val)
            {
                b = b -> right;
                s2.pop();
                a = NULL;
            }
        }
        
        else
            break;
    }
    return ans;
}

int Solution::solve(TreeNode* a, TreeNode* b) {
    
    // TLE
    
    // vector <int> ar, br;
    // inorder(a, ar);
    // inorder(b, br);
    // int ans = 0;
    // unordered_set <int> s(ar.begin(), ar.end());
    
    // for(int i = 0; i < br.size(); i++)
    // {
    //     if(s.count(br[i]) > 0)
    //         ans = (ans + br[i]) % 1000000009;
    // }
    
    // return ans % 1000000009;
    
    return sum(a, b) % 1000000007;
}
