/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* a, ListNode* b) {
    
    ListNode* p = a;
    ListNode* q = b;
    ListNode* ans = NULL;
    ListNode* last = ans;
    
    while(p != NULL && q != NULL)
    {
        int n1 = p -> val;
        int n2 = q -> val;
        if(n1 < n2)
        {
            if(ans == NULL)
            {
                ans = p;
                last = p;
                p = p -> next;
            }
            else
            {
                last -> next = p;
                last = last -> next;
                p = p -> next;
            }
        }
        else
        {
            if(ans == NULL)
            {
                ans = q;
                last = q;
                q = q -> next;
            }
            else
            {
                last -> next = q;
                last = last -> next;
                q = q -> next;
            }
        }
    }
    if(p != NULL)
    {
        while(p != NULL)
        {
            last -> next = p;
            last = p;
            p = p -> next;
        }
    }
    if(q != NULL)
    {
        while(q != NULL)
        {
            last -> next = q;
            last = q;
            q = q -> next;
        }
    }
    last -> next = NULL;
    return ans;
}
