/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* find_predecessor(TreeNode* a)
{
    TreeNode* t = a -> left; 
    while(t -> right != NULL && t -> right != a)
    {
        t = t -> right;
    }
    
    return t;
}

vector<int> Solution::recoverTree(TreeNode* a) {
    
    TreeNode *node1, *node2, *first, *second, *cur, *pred;
    node1 = node2 = NULL;
    first = second = NULL;
    cur = a;
    
    while(cur != NULL)
    {
        if(cur -> left == NULL)
        {
            if(node1 == NULL)
                node1 = cur;
            else
            if(node2 == NULL)
                node2 = cur;
            else
            {
                node1 = node2;
                node2 = cur;
            }
            
            cur = cur -> right;
        }
        else
        {
            pred = find_predecessor(cur);
            
            if(pred -> right == NULL)
            {
                pred -> right = cur;
                cur = cur -> left;
                continue;
            }
            else
            {
                pred -> right = NULL;
                if(node2 == NULL)
                    node2 = cur;
                else
                {
                    node1 = node2;
                    node2 = cur;
                }
                
                cur = cur -> right;
            }
        }
        
        if(node1 && node2 && node1 -> val > node2 -> val)
        {
            if(first == NULL)
                first = node1;
            second = node2;
        }
    }
    
    vector <int> ans;
    ans.push_back(min(first -> val, second -> val));
    ans.push_back(max(first -> val, second -> val));
    
    return ans;
}
