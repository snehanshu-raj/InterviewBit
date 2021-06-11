/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// method-1 using inorder traversal
// void inorder(TreeNode* a, vector <int> &v)
// {
//     if(a)
//     {
//         inorder(a -> left, v);
//         v.push_back(a -> val);
//         inorder(a -> right, v);
//     }
// }

// method-2 checking left-max and right-min for every node 'every time' O(N * H)
// int left_max(TreeNode* a)
// {
//     while(a -> right)
//         a = a -> right;
//     return a -> val;
// }

// int right_min(TreeNode* a)
// {
//     while(a -> left)
//         a = a -> left;
//     return a -> val;
// }

// int checker(TreeNode* a)
// {
//     if(a == NULL)
//         return 1;
    
//     if(a -> left)
//     {
//         if(a -> val <= left_max(a -> left))
//             return 0;
//     }
    
//     if(a -> right)
//     {
//         if(a -> val >= right_min(a -> right))
//             return 0;
//     }
    
//     return checker(a -> left) && checker(a -> right);
// }

// method-3 not checking every time O(H)
struct info
{
    int max;
    int min;
    int isBST;
};

info checker(TreeNode* a)
{
    if(a == NULL)
        return {INT_MIN, INT_MAX, 1};
    if(a -> left == NULL && a -> right == NULL)
        return {a -> val, a -> val, 1};
    
    info l = checker(a -> left);
    info r = checker(a -> right);
    
    info obj;
    
    if(l.isBST && r.isBST && a -> val > l.max && a -> val < r.min)
    {
        obj.min = min(a -> val, l.min);
        obj.max = max(a -> val, r.max);
        obj.isBST = 1;
        return obj;
    }
    else
    {
        obj.isBST = 0;
        return obj;
    }
}

int Solution::isValidBST(TreeNode* a) {
    
    // method 1
    // vector <int> v;
    // inorder(a, v);
    
    // for(int i = 0; i < v.size() - 1; i++)
    // {
    //     if(v[i] >= v[i + 1])
    //         return 0;
    // }
    
    // return 1;
    
    // method 2
    //return checker(a);
    
    //method 3
    return checker(a).isBST;
}
