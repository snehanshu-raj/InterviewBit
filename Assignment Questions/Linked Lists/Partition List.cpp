/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* a, int b) {
    
    ListNode* first = NULL;
    ListNode* second = NULL;
    ListNode* second_head = NULL;
    ListNode* first_head = NULL;
    
    while(a)
    {
        if(a -> val < b)
        {
            if(first_head == NULL)
            {
                first = a;
                first_head = a;
            }
            else
            {
                first -> next = a;
                first = a;
            }
        }
        else
        {
            if(second_head == NULL)
            {
                second = a;
                second_head = a;
            }
            else
            {
                second -> next = a;
                second = a;
            }
        }
        
        a = a -> next;
    }

    if(second != NULL)
        second -> next = NULL;
        
    if(first_head == NULL)
    {
        return second_head;
    }
    else
    {
        if(second_head != NULL)
            first -> next = second_head;
        else
            first -> next = NULL;
        return first_head;
    }
}
