/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct compare {
    bool operator()(
        ListNode* b, ListNode* c)
    {
        return b -> val > c -> val;
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *t;
    
    priority_queue <ListNode*, vector <ListNode*>, compare > min_heap;
    int i;
    for(i = 0; i < a.size(); i++)
    {
        if(a[i] != NULL)
            min_heap.push(a[i]);
    }
    
    if(min_heap.empty())
        return NULL;
        
    ListNode* head = NULL;
    ListNode* last;
    
    while(!min_heap.empty())
    {
        ListNode* t = min_heap.top();
        min_heap.pop();
        
        if(head == NULL)
        {
            head = t;
            last = head;
        }
        else
        {
            last -> next = t;
            last = t;
        }
        
        if(t -> next != NULL)
            min_heap.push(t -> next);
    }
    return head;
}
