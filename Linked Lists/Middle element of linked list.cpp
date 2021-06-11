/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* a) {
    ListNode* p = a;
    ListNode* q = a;
    
    while(q -> next != NULL)
    {
        p = p -> next;
        q = q -> next;
        if( q -> next == NULL)
            break;
        else
            q = q -> next;
    }
    return p -> val;
}
