/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* a, int b) {
    int c = 0;
    ListNode* cur = a;
    ListNode* prev = NULL;
    
    stack <ListNode*> s;
    
    while(cur != NULL)
    {
        c = 0;
        while(cur != NULL && c != b)
        {
            c++;
            s.push(cur);
            cur = cur -> next;
        }
        
        while(!s.empty())
        {
            if(prev == NULL)
            {
                prev = s.top();
                a = s.top();
                s.pop();
            }
            else
            {
                prev -> next = s.top();
                prev = prev -> next;
                s.pop();
            }
        }
    }
    prev -> next = NULL;
    return a;
}
