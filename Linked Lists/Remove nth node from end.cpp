/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* a, int b) { 
    ListNode* t = a;
    int c = 0;
    
    while(t != NULL)
    {
        t = t -> next;
        c++;
    }
    
    if(c == 1)
        return NULL;
        
    if(b >= c)
    {
        return a -> next;
    }
    
    t = a;
    int i;
    for(i = 0; i < c - b - 1; i++)
    {
        t = t -> next;
    }
    t -> next = t -> next -> next;
    return a;
}
