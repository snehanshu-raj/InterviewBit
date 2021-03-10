/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* a) {
    
    stack <ListNode*> s;
    ListNode* t = a;
    
    while(t != NULL)
    {
        s.push(t);
        t = t -> next;
    }
    
    while(a != NULL)
    {
        ListNode* temp = s.top();
        if(a -> val != temp -> val)
            return 0;
        a = a -> next;
        s.pop();
    }
    
    return 1;
}
