void build(vector <int> &a, vector <int> &tree, int idx, int s, int e)
{
    if(s == e)
    {
        tree[idx] = __builtin_popcount(a[s]);
    }
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

int query(vector <int> &tree, int idx, int s, int e, int l, int r)
{
    if(s > r || l > e)
        return 0;
    
    if(s >= l && r >= e)
        return tree[idx];
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    return query(tree, lc, s, m, l, r) + query(tree, rc, m + 1, e, l, r);
}

void update(vector <int> &a, vector <int> &tree, int idx, int s, int e, int i)
{
    if(i > e || s > i)
        return;
    
    if(s == e)
    {
        tree[idx] = __builtin_popcount(a[i]);
        return;
    }
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    update(a, tree, lc, s, m, i);
    update(a, tree, rc, m + 1, e, i);
    
    tree[idx] = tree[lc] + tree[rc];
}

vector<int> Solution::solve(int n, vector<vector<int> > &b) {
    
    vector <int> a;
    vector <int> tree;
    vector <int> ans;
    
    int i;
    
    for(i = 0; i < n; i++)
        a.push_back(0);
        
    for(i = 0; i < 2*n; i++)
        tree.push_back(0);
        
    build(a, tree, 0, 0, n - 1);
    
    for(i = 0; i < b.size(); i++)
    {
        if(b[i][0] == 1)
        {
            a[ b[i][1] - 1 ] = a[ b[i][1] - 1 ] * 2 + 1;
            update(a, tree, 0, 0, n - 1, b[i][1] - 1);
        }
        else
        if(b[i][0] == 2)
        {
            a[ b[i][1] - 1 ] = a[ b[i][1] - 1 ] / 2;
            update(a, tree, 0, 0, n - 1, b[i][1] - 1);
        }
        else
        {
            ans.push_back( query(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1) );
        }
    }
    return ans;
}
