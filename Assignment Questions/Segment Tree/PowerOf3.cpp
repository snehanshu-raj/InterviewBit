int power(int x, int y)
{
    if(y == 0)
        return 1;
    if(y % 2 == 0)
        return (power(x, y / 2) % 3) * (power(x, y / 2) % 3) % 3;
    return (x * (power(x, y / 2) % 3) * power(x, y / 2) % 3) % 3;
}

int inverse(int a, int m)
{
    return power(a, m - 2);
}

void build(vector <int> &a, vector <int> &tree, int idx, int s, int e)
{
    if(s == e)
    {
        tree[idx] = a[s];
    }
    else
    {
        int m = (s + e) / 2;
        int lc = 2 * idx + 1;
        int rc = 2 * idx + 2;
        
        build(a, tree, lc, s, m);
        build(a, tree, rc, m + 1, e);
        
        tree[idx] = (tree[lc] + tree[rc]) % 3;
    }
}

int query(vector <int> &tree, int idx, int s, int e, int l, int r)
{
    if(l > e || s > r)
        return 0;
    
    if(s >= l && e <= r)
        return tree[idx];
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    return (query(tree, lc, s, m, l, r) + query(tree, rc, m + 1, e, l, r)) % 3;
}

void update(vector <int> & tree, int idx, int s, int e, int i, int n)
{
    if(i > e || i < s)
        return;
    if(s == e)
    {
        tree[idx] = 1 * power(2, n - e - 1) % 3;
        return;
    }
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    update(tree, lc, s, m, i, n);
    update(tree, rc, m + 1, e, i, n);
    
    tree[idx] = (tree[lc] + tree[rc]) % 3;
}

vector<int> Solution::solve(string str, vector<vector<int> > &b) {
    
    vector <int> a;
    vector <int> ans;
    vector <int> tree;
    
    int n = str.length();
    int i;
    
    for(i = 0; i < n; i++)
    {
        if(str[i] == '1')
        {
            a.push_back( power(2, n - i - 1) % 3 );
        }
        else
        {
            a.push_back(0);
        }
    }
    
    for(i = 0; i < 4 * n; i++)
        tree.push_back(0);
        
    build(a, tree, 0, 0, n - 1);
    
    for(i = 0; i < b.size(); i++)
    {
        if(b[i][0] == 0)
        {
            int val = query(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1);
            val = (val * inverse( power(2, n - 1 - b[i][2] - 1), 3) ) % 3;
            //val = (val / power(2, n - 1 - b[i][2] - 1)) % 3;
            ans.push_back(val);
        }
        else
        {
            update(tree, 0, 0, n - 1, b[i][1] - 1, n);
            ans.push_back(-1);
        }
    }
    return ans;
}
