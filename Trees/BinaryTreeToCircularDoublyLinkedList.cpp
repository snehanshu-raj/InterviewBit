/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

TreeNode* find_predecessor(TreeNode *a)
{
    TreeNode *t = a -> left;
    while(t -> right != NULL && t -> right != a)
    {
        t = t -> right;
    }
    
    return t;
}

void morris_inorder(TreeNode *a, vector <TreeNode *> &ans)
{
    TreeNode *cur = a;
    
    while(cur != NULL)
    {
        if(cur -> left == NULL)
        {
            ans.push_back(cur);
            cur = cur -> right;
        }
        else
        {
            TreeNode *pred = find_predecessor(cur);
            
            if(pred -> right == NULL)
            {
                pred -> right = cur;
                cur = cur -> left;
            }
            else
            {
                ans.push_back(cur);
                pred -> right = NULL;
                cur = cur -> right;
            }
        }
    }
}

void inorder(TreeNode *a, vector <TreeNode *> &ans)
{
    if(a)
    {
        inorder(a -> left, ans);
        ans.push_back(a);
        inorder(a -> right, ans);
    }
}

TreeNode* solve(TreeNode *a){
    
    vector <TreeNode *> ans;
    morris_inorder(a, ans);
    //inorder(a, ans);
    
    if(a == NULL)
        return a;
        
    if(ans.size() == 1)
    {
        ans[0] -> left = ans[0];
        ans[0] -> right = ans[0];
        return ans[0];
    }
    
    ans[0] -> left = ans[ans.size() - 1];
    ans[0] -> right = ans[1];
    ans[ans.size() - 1] -> right = ans[0];
    ans[ans.size() - 1] -> left = ans[ans.size() - 2];
    
    for(int i = 1; i < ans.size() - 1; i++)
    {
        ans[i] -> left = ans[i - 1];
        ans[i] -> right = ans[i + 1];
    }
    
    return ans[0];
}
