#include<bits/stdc++.h>
using namespace std;

// int a[5];
// int tree[9];

// void build(int idx, int s, int e)
// {
//     if(s == e)
//         tree[idx] = a[s];
//     else
//     {
//         int m = (s + e) / 2;
//         int lc = 2 * idx + 1;
//         int rc = 2 * idx + 2;
//         build(lc, s, m);
//         build(rc, m + 1, e);
//         tree[idx] = min(tree[lc], tree[rc]);
//     }
// }

// int query(int idx, int s, int e, int l, int r)
// {
//     if(l > e || s > r) //non-overlap
//         return INT_MAX;
//     if(l <= s && e <= r) //complete overlap
//         return tree[idx];
    
//     int m = (s + e) / 2;
//     int lc = 2 * idx + 1;
//     int rc = 2 * idx + 2;
//     return min( query(lc, s, m, l, r), query(rc, m + 1, e, l, r) );
// }

void build(int a[], int tree[], int idx, int s, int e)
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

int query(int tree[], int idx, int s, int e, int l, int r)
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

void update(int tree[], int idx, int s, int e, int i, int x)
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

int main()
{
    // int i, n;
    // for(i = 0; i < 5; i++)
    //     cin >> a[i];
    
    // build(0, 0, 4);

    // for(i = 0; i < 5; i++)
    // {
    //     int l, r;
    //     cin >> l >> r;
    //     cout << query(0, 0, 4, l, r) << endl;
    // }
    // return 0;
    int a[] = { 18, 10, 1, 20, 25, 4, 9, 13, 15, 6, 21, 7 };
    int n = 12;
    int tree[24] = { 0 };

    build(a, tree, 0, 0, n - 1);
    
    for(int i = 0; i < 2*n; i++)
        cout << tree[i] << " ";
    
    cout << endl;
    int b[][3] = {
                    {1, 8, 12},
                    {0, 4, 7},
                    {1, 1, 3},
                    {1, 5, 11},
                    {1, 3, 9},
                    {1, 7, 12},
                    {1, 7, 10},
                    {0, 12, 20}
                };
    
    int i;
    vector <int> ans;
    for(i = 0; i < 8; i++)
    {
        if(b[i][0] == 1)
        {
            cout << b[i][1] << " " << b[i][2] << endl;
            cout << query(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1) << endl;
            ans.push_back(query(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1));
        }
        else
        {
            cout << "updated" << endl;
            update(tree, 0, 0, n - 1, b[i][1] - 1, b[i][2] - 1);
        }
    }

    for(i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
return 0;
}