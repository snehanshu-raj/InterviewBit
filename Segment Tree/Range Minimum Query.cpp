void build(vector<int> &a, vector<int> &tree, int idx, int s, int e)
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
        tree[idx] = min(tree[lc], tree[rc]);
    }
}

int query(vector<int> &tree, int idx, int s, int e, int l, int r)
{
    if(s > r || l > e)
        return INT_MAX;
    
    if(l <= s && r >= e)
        return tree[idx];
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    return min( query(tree, lc, s, m, l, r), query(tree, rc, m + 1, e, l, r) );
}

void update(vector<int> &tree, int idx, int s, int e, int i, int x)
{
    if(s > i || i > e)
        return;
        
    if(s == e)
    {
        tree[idx] = x;
        return;
    }
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    update(tree, lc, s, m, i, x);
    update(tree, rc, m + 1, e, i, x);
    
    tree[idx] = min(tree[lc], tree[rc]);
}

vector<int> Solution::solve(vector<int> &a, vector<vector<int> > &b) {
    int n = a.size();
    
    vector <int> tree;
    
    for(int i = 0; i < 2*n; i++)
        tree.push_back(0);
    
    build(a, tree, 0, 0, n - 1);
    
    vector <int> ans;
    
    for(int i = 0; i < b.size(); i++)
    {
        if(b[i][0] == 0)
        {
            update(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2]);
        }
        else
        {
            ans.push_back( query(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1) );
        }
    }
    return ans;
}
