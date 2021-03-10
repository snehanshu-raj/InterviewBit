/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* temp_head = NULL;

void reverse(ListNode* q, ListNode* p, ListNode* trail)
{
    if(p != trail)
    {
        reverse(p, p -> next, trail);
        p -> next = q;
    }
    else
    {
        temp_head = q;
    }
}

ListNode* Solution::reverseBetween(ListNode* a, int b, int c) {
    
    if(a -> next == NULL)
        return a;
        
    int cnt = 1;
    
    ListNode* lead = a;
    ListNode* trail_1 = a;
    ListNode* trail_2 = a;
    ListNode* p = NULL;
    ListNode* q = NULL;
    
    while( cnt != b )//lead -> val != b)
    {
        trail_1 = lead;
        lead = lead -> next;
        cnt++;
    }
    
    p = lead;
    ListNode* tp = p;
    
    while(cnt != c )//lead -> val != c)
    {
        lead = lead -> next;
        trail_2 = lead;
        cnt++;
    }
    
    trail_2 = lead -> next;
    
    reverse(q, p, trail_2);
    
    trail_1 -> next = temp_head;
    
    p -> next = trail_2;
    
    if(tp == a)
        return temp_head;
    return a;
}
