/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* a) {
    
    stack <ListNode*> s;
    ListNode* cur = a;
    int c = 0;
    
    while(cur != NULL)
    {
        s.push(cur);
        c++;
        cur = cur -> next;
    }
    
    ListNode* p1 = a;
    ListNode* p2 = a;
    ListNode* ans = p1;
    
    int i = 0;
    
    while(i != c / 2)
    {
        p2 = p2 -> next;
        p1 -> next = s.top();
        p1 = s.top();
        s.pop();
        p1 -> next = p2;
        p1 = p2;
        i++;
    }
    p1 -> next = NULL;
    return ans;
}
