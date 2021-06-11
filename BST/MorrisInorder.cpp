Node* find_predecessor(Node *a)
{
    Node *t = a;
    while(a -> right != NULL || a -> right != t)
    {
        a = a -> right;
    }
    return a;
}

void morris_inorder(Node *a)
{
    Node *cur = a;
    while(cur != NULL)
    {
        if(cur -> left == NULL)
        {
            print(cur -> data);
            cur = cur -> right;
        }
        else
        {
            Node *pred = find_predecessor(cur -> left);

            if(pred -> right == NULL)
            {
                pred -> right = cur;
                cur = cur -> left;
            }
            else
            {
                pred -> right = NULL;
                print(cur -> data);
                cur = cur -> right;
            }
        }
    }
}