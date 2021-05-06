int n;
int mod = 1000000007;
vector <int> b(100000);

int merge_(vector <int> &a, int l, int m, int r)
{
    int i, j ,ans = 0, k = l;
    i = l, j = m + 1;
    
    while(i <= m && j <= r)
    {
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
        {
            ans = ans + (m + 1 - i);
            b[k++] = a[j++];
        }
    }
    
    for( ; i <= m; i++)
        b[k++] = a[i];
    
    for( ; j <= r; j++)
        b[k++] = a[j];
    
    for(i = l; i <= r; i++)
        a[i] = b[i];
        
    ans %= mod;
    return ans;
}

long long merge_sort_(vector <int> &a, int l, int r)
{
    int ans = 0;
    if(l < r)
    {
        int m = (l + r) / 2;
        ans += merge_sort_(a, l, m);
        ans += merge_sort_(a, m + 1, r);
        ans += merge_(a, l, m, r);
    }
    
    return ans % mod;
}

int Solution::solve(vector <int> &a) 
{
    // int c = 0;
    // int i, j;
    
    // for(i = 0; i < a.size(); i++)
    // {
    //     for(j = i + 1; j < a.size(); j++)
    //     {
    //         if(a[j] < a[i])
    //             c++;
    //     }
    // }
    // return c;
    
    // HERE YOU GET TLE O(n ^ 2)
    
    //using merge sort
        
    n = a.size();
    int ans = merge_sort_(a, 0, a.size() - 1);
    return ans;
}
