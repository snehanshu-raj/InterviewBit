#include<bits/stdc++.h>
using namespace std;

int primes[10000000];

void build(vector<int> &a, vector<int> &tree, int idx, int s, int e)
{
    if(s == e)
    {
        cout << s  << " s" << endl;
        if(primes[ a[s] ] == 0)
        {
            cout << "prime " << a[s] << endl;
            tree[idx] = 1;
        }
        else
        {
            tree[idx] = 0;
        }
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

int query(vector<int> &tree, int idx, int s, int e, int l, int r)
{
    if(s > r || l > e)
        return 0;
    
    if(s >= l && e <= r)
        return tree[idx];

    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    return query(tree, lc, s, m, l, r) + query(tree, rc, m + 1, e, l, r);
}

void update(vector<int> &tree, int idx, int s, int e, int i, int x)
{
    if(i > e || s > i)
        return;
    
    if(s == e)
    {
        if(primes[x] == 0)
        {
            tree[idx] = 1;
            return;
        }
        else
        {
            tree[idx] = 0;
            return;
        }
    }
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    update(tree, lc, s, m, i, x);
    update(tree, rc, m + 1, e, i, x);
    
    tree[idx] = tree[lc] + tree[rc];
}

void initialize()
{
    int i, j;
    primes[0] = primes[1] = 1;
    cout << primes[2] << primes[3] << endl;
    for(i = 2; i * i <= 1000000; i++)
    {
        if(primes[i] == 0)
        {
            for(j = i * i; j <= 1000000; j += i)
            {
                primes[j] = 1;
            }
        }
    }
    cout << primes[2] << primes[3] << primes[5] << endl;
}

int main() 
{
    vector<int> a;    
    vector <int> ans;
    vector <int> tree;
    int i;

    initialize();

    for(i = 1; i <= 10; i++)
    {
        a.push_back(i);
        if(primes[i] == 0)
            cout << i << " prime" << endl;
        else    
            cout << i << " not prime" << endl;
    }

    int n = a.size();
    
    for(i = 0; i < 2*n; i++)
        tree.push_back(0);
    
    build(a, tree, 0, 0, n - 1);
    
    for(i = 0; i < tree.size(); i++)
        cout << tree[i] << " ";
    cout << endl;

    char b[] = { 'A', 'A', 'A'};
    int c[] = { 1, 5, 7};
    int d[] = { 4, 6, 9};

    for(i = 0; i < 3; i++)
    {
        if(b[i] == 'A')
        {
            ans.push_back( query(tree, 0, 0, n - 1, c[i] - 1, d[i] - 1) );
        }
        else
        {
            update(tree, 0, 0, n - 1, c[i] - 1, d[i]);
        }
    }

    for(i = 0; i < ans.size(); i++)
        cout << ans[i] <<  " ";
    return 0;
}
