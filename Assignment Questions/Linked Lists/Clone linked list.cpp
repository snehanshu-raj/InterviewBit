
/*
struct ListNode { 
    int val; 
    ListNode *next,*random; 
    ListNode(int x) { 
        val = x; 
        next = random = NULL; 
    } 
}; 
*/
ListNode* clonelist(ListNode *a) {

    // return a; best possible answer :p
    
    ListNode* cur = a;
    ListNode* t = a;
    
    while(cur)
    {
        cur = cur -> next;
        
        ListNode* n = new ListNode(t -> val);
        t -> next = n;
        t -> next -> next = cur;
        t = cur;
    }
    
    cur = a;
    t = a;
    
    while(cur)
    {
        if(cur -> next)
        {
            cur -> next -> random = cur -> random ? cur -> random -> next : cur -> random;
        }
        
        if(cur -> next)
            cur = cur -> next -> next;
        else
            cur = cur -> next;
    }
    
    cur = a;
    t = a -> next;
    ListNode* ans = t;
    
    while(cur && t)
    {
        cur -> next = cur -> next ? cur -> next -> next : cur -> next;
        
        t -> next = t -> next ? t -> next -> next : t -> next;
        
        cur = cur -> next;
        t = t -> next;
    }
    
    return ans;

}