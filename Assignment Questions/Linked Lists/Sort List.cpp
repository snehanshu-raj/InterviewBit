/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* merge(ListNode* p, ListNode* q)
{
    if(p == NULL)
        return q;
    
    if(q == NULL)
        return p;
    
    ListNode* start = NULL;
    ListNode* cur = NULL;
    
    while(p && q)
    {
        if(p -> val < q -> val)
        {
            if(start == NULL)
            {
                start = p;
                cur = start;
                p = p -> next;
            }
            else
            {
                cur -> next = p;
                cur = p;
                p = p -> next;
            }
        }
        else
        {
            if(start == NULL)
            {
                start = q;
                cur = start;
                q = q -> next;
            }
            else
            {
                cur -> next = q;
                cur = q;
                q = q -> next;
            }
        }
    }
    
    if(p != NULL)
        cur -> next = p;
        
    if(q != NULL)
        cur -> next = q;
    
    return start;
}

ListNode* Solution::sortList(ListNode* a) {
    
    if(a == NULL || a -> next == NULL)
        return a;
    
    ListNode* start = a;
    ListNode* slow = a;
    ListNode* fast = a;
    ListNode* prev = a;
    
    while(fast != NULL && fast -> next != NULL) 
    {
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    prev -> next = NULL;
    
    return merge( sortList(start), sortList(slow) );
}
