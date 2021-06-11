Input :      
           6                               
         /   \                          
        3     5                      
      /   \     \
     2    5      4             
        /  \                        
       7    4  

Output: 13997

Explanation :
There are 4 leaves, hence 4 root to leaf paths:
Path                      Number
6->3->2                   632
6->3->5->7                6357
6->3->5->4                6354
6->5>4                    654   
Answer = 632 + 6357 + 6354 + 654 = 13997

int helper(Node *root, int sum)
{
    if(root == NULL)
        return 0;
   
    sum = sum * 10 + root -> data;
    
    if(root -> left == NULL and root -> right == NULL)
        return sum;
    
    return helper(root -> left, sum) + helper(root -> right, sum);
}

long long treePathsSum(Node *root)
{
    return helper(root, 0);
}