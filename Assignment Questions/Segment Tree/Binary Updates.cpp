void build(vector <int> &a, vector <int> &tree, int idx, int s, int e)
{
    if(s == e)
        tree[idx] = a[s];
    else
    {
        int m = (s + e) / 2;
        int lc = 2 * idx + 1;
        int rc = 2 * idx + 2;
        build(a, tree, lc, s, m);
        build(a, tree, rc, m + 1, e);
        
        tree[idx] = tree[lc] + tree[rc];
    }
}

int query(vector <int> &tree, int idx, int s, int e, int i)
{
    if(tree[idx] < i)
        return -1;
    
    if(s == e)
        return s + 1;
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    if(tree[lc] >= i)
        return query(tree, lc, s, m, i);
    else
        return query(tree, rc, m + 1, e, i - tree[lc]);
}

void update(vector <int> &tree, int idx, int s, int e, int i)
{
    if(s > i || e < i)
        return;
    
    if(s == e)
    {
        tree[idx] = 0;
        return;
    }
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    update(tree, lc, s, m, i);
    update(tree, rc, m + 1, e, i);
    
    tree[idx] = tree[lc] + tree[rc];
}

vector<int> Solution::solve(int n, vector<vector<int> > &b) {
    
    vector <int> ans;
    vector <int> a;
    vector <int> tree;
    int i;
    
    for(i = 0; i < n; i++)
        a.push_back(1);
    
    for(i = 0; i < 2*n; i++)
        tree.push_back(0);
    
    build(a, tree, 0, 0, n - 1);
    
    for(i = 0; i < b.size(); i++)
    {
        if(b[i][0] == 0)
            update(tree, 0, 0, n - 1, b[i][1] - 1);
        else
            ans.push_back( query(tree, 0, 0, n - 1, b[i][1]) );
    }
    return ans;
}
