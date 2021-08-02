struct node
{
    int data;
    struct node *left;
    struct node *right;
}

node* construct(int a[], int i, int n, Node* root)
{

    if(i < n)
    {
        Node *temp = new node(a[i]);
        root = temp;

        root -> left = construct(a, 2 * i + 1, n, root -> left);

        root -> right = construct(a, 2 * i + 2, n, root -> right);
    }

    return root;
    
}
