/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* a) {
    ListNode* p = a;
    
    if(p -> next == NULL)
        return a;
        
    while(1)
    {
        if(p -> next -> val == p -> val)
        {
            ListNode* t = p;
            while(t -> next != NULL && t -> next -> val == p -> val)
            {
                t = t -> next;
            }
            p -> next = t -> next;
            p = p -> next;
            if(p == NULL)
                break;
        }
        else
            p = p -> next;
        if(p == NULL || p -> next == NULL)
            break;
    }
    return a;
}
