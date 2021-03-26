/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void sum_path(TreeNode* a, vector <vector <int> > &ans, int sum, vector <int> &v)
{
    // if(sum == 0 && a -> left == NULL && a -> right == NULL)
    // {
    //     ans.push_back(v);
    // }
    
    // if(a -> left != NULL){
    //     v.push_back((a -> left) -> val);
    //     sum_path(a -> left, ans, sum - (a -> left) -> val, v);
    //     v.pop_back();
    // }
    
    // if(a -> right != NULL){
    //     v.push_back((a -> right) -> val);
    //     sum_path(a -> right, ans, sum - ( a -> right) -> val, v);
    //     v.pop_back();
    // }
    
    if(a == NULL)
        return;
    
    sum = sum - (a -> val);
    
    v.push_back(a -> val);
    
    if(sum == 0 && a -> left == NULL && a -> right == NULL)
        ans.push_back(v);
    
    if(a -> left)
        sum_path(a -> left, ans, sum, v);
    
    if(a -> right)
        sum_path(a -> right, ans, sum, v);
    
    v.pop_back();
}

vector<vector<int> > Solution::pathSum(TreeNode* a, int b) {
    
    vector < vector <int> > ans;
    vector <int> v;
    
    if(a == NULL){
        return ans;
    }
    
    sum_path(a, ans, b, v);
    
    return ans;
}
