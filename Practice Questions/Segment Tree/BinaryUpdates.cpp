#include<bits/stdc++.h>
using namespace std;

void build(vector <int> &a, vector <int> &tree, int idx, int s, int e)
{
    if(s == e)
    {
        cout << tree.size() <<" :tree size" << endl;
        tree[idx] = a[s];
        cout << "s: " << s << " idx: " << idx << endl;
    }
    else
    {
        int m = (s + e) / 2;
        int lc = 2 * idx + 1;
        int rc = 2 * idx + 2;
        build(a, tree, lc, s, m);
        build(a, tree, rc, m + 1, e);
        
        tree[idx] = tree[lc] + tree[rc];
        cout << "idx :" << idx << " lc: " << lc << " rc: " << rc << " lc + rc: " << tree[lc] + tree[rc] << endl;
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
        cout << "updated " << s << " " << i << endl;
        return;
    }
    
    int m = (s + e) / 2;
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    
    update(tree, lc, s, m, i);
    update(tree, rc, m + 1, e, i);
    
    tree[idx] = tree[lc] + tree[rc];
}

int main()
{    
    vector <int> ans;
    vector <int> a;
    vector <int> tree;
    int i, n = 13;
    
    int b[][2] = {
                    {0, 7},
                    {1, 8},
                    {0, 5},
                    {0, 12},
                    {1, 1},
                    {1, 6},
                    {1, 11},
                    {1, 9},
                    {1, 3}
                };

    for(i = 0; i < n; i++)
        a.push_back(1);
    
    for(i = 0; i < 2*n; i++)
        tree.push_back(0);
    
    build(a, tree, 0, 0, n - 1);

    for(i = 0; i < 2*n; i++)
        cout << tree[i] << " ";
    cout << endl;

    cout << tree.size() << endl;
    cout << tree[27];
    cout << endl;

    for(i = 0; i < 9; i++)
    {
        if(b[i][0] == 0)
        {
            cout << b[i][1] - 1 << " : ";
            update(tree, 0, 0, n - 1, b[i][1] - 1);
        }
        else
            ans.push_back( query(tree, 0, 0, n - 1, b[i][1]) );
    }
    
    for(i = 0; i < 2*n; i++)
        cout << tree[i] << " ";
    cout << endl;

    for(i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;

    cout << tree.size();
    cout << tree[27] << endl;
return 0;
}
