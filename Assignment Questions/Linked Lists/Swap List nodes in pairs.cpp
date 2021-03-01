/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* a) {
    ListNode* ans = NULL;
    ListNode* last = NULL;
    stack <ListNode*> s;
    ListNode* t = a;
    
    while(t != NULL)
    {
        int c = 0;
        while(c != 2 && t != NULL)
        {
            s.push(t);
            c++;
            t = t -> next;
        }
        
        while(!s.empty())
        {
            if(ans == NULL)
            {
                ans = s.top();
                last = ans;
                s.pop();
            }
            else
            {
                last -> next = s.top();
                last = last -> next;
                s.pop();
            }
        }
    }
    last -> next = NULL;
    return ans;
}
