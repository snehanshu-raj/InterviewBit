TreeLinkNode* get_next_node(TreeLinkNode* node)
{
    while(node -> next != NULL)
    {
        node = node -> next;
        if(node ->left)
            return node -> left;
        if(node -> right)
            return node -> right;
    }
    
    return NULL;
}
 
void Solution::connect(TreeLinkNode* a) {
    
    if(a == NULL)
        return;
    
    a -> next = NULL;
    
    while(a != NULL)
    {
        TreeLinkNode* temp = a;
        while(temp != NULL)
        {
            if(temp -> left)
            {
                if(temp -> right)
                    temp -> left -> next = temp -> right;
                else
                    temp -> left -> next = get_next_node(temp);
            }
            if(temp -> right)
            {
                temp -> right -> next = get_next_node(temp);
            }
            temp = temp -> next;
        }
        
        if(a -> left)
            a = a -> left;
        else
        if(a -> right)
            a = a -> right;
        else
            a = get_next_node(a);
    }
}