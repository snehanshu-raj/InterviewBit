/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* a) {
    
    if(a -> next == a)
    {
        a -> next = NULL;
        return a;
    }
    
    // uses O(n) space, gives correct answer:
    
    // set <ListNode*> s;
    // ListNode* t = a;
    
    // while(t)
    // {
    //     if(s.count(t -> next) > 0)
    //     {
    //         t -> next = NULL;
    //         return a;
    //     }
    //     s.insert(t);
    //     t = t -> next;
    // }
    
    ListNode* slow = a;
    ListNode* fast = a;
    
    while(1)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        
        if(slow == fast)
            break;
    }
    
    slow = a;
    
    if(slow == fast)
    {
        while(fast -> next != slow)
        {
            fast = fast -> next;
        }
        
        fast -> next = NULL;
    }
    else
    {
        while(slow -> next != fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        fast -> next = NULL;
    }
    
    return a;
}
