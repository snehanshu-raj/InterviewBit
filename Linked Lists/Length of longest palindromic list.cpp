/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int checker(ListNode* left, ListNode* right)
{
    int c = 0;
    while(left && right)
    {
        if(left -> val == right -> val)
            c++;
        else
            break;
        
        left = left -> next;
        right = right -> next;
    }
return c;
}

int Solution::solve(ListNode* a) {
    
    ListNode* cur = a;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    
    int ans = 0;
    
    while(cur)
    {
        next = cur -> next;
        cur -> next = prev;
        
        ans = max(ans, 2 * checker(prev, next) + 1);
        
        ans = max(ans, 2 * checker(cur, next));
        
        prev = cur;
        cur = next;
    }
    
    return ans;
}
