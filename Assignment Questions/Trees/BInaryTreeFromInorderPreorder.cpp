Node* construct(int in[], int pre[], unordered_map <int, int> map, int s, int e)
{
    static int itr = 0;

    if(s > e)
        return NULL;
    
    int data = pre[itr];
    itr++;

    Node* node = new Node(data);

    if(s == e)
        return node;
    
    int idx = map[data];

    node -> left = construct(in, pre, map, s, idx - 1);
    node -> right = construct(in, pre, map, idx + 1, e);

    return node;
}

Node* tree(int in[], int pre[], int n)
{
    unordered_map <int, int> map;
    for(i = 0; i < n; i++)
    {
        m[ in[i] ] = i;
    }

    return construct(in, pre, map, 0, n - 1);
}