/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int total_sum(TreeNode* a)
{
    if(a == NULL)
        return 0;
    
    int x = total_sum(a -> left);
    int y = total_sum(a -> right);
    
    return a -> val + x + y;
}

int ans = 0;

int checker(TreeNode* a, int sum)
{
    if(a == NULL)
        return 0;
        
    int x = checker(a -> left, sum);
    int y = checker(a -> right, sum);
    
    if(x == sum && a -> left)
        ans = 1;
    if(y == sum && a -> right)
        ans = 1;
        
    return x + y + a -> val;
}

int Solution::solve(TreeNode* a) {
    
    if(a == NULL)
        return 0;
      
    int sum =  total_sum(a);
    
    if(sum & 1)
        return 0;
        
    ans = 0;
    checker(a, sum / 2);
    return ans;
}
