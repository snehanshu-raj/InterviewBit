class Solution {
public:    
    int height(TreeNode* root, int &ans)
    {
        if(root == NULL)
            return 0;
        
        int lh = height(root -> left, ans);
        int rh = height(root -> right, ans);
        
        ans = max(ans, 1 + lh + rh);
        
        if(lh > rh)
            return 1 + lh;
        return 1 + rh;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = INT_MIN;
        height(root, ans);
        
        return ans - 1;
    }
};