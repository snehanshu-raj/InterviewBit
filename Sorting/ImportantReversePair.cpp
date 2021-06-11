vector <int> temp(100001);

void merge(vector <int> &a, int s, int m, int e)
{
    int l = s;
    int r = m + 1;
    
    int k = s;
    
    while(l <= m && r <= e)
    {
        if(a[l] <= a[r])
            temp[k++] = a[l++];
        else
            temp[k++] = a[r++];
    }
    
    while(l <= m)
    {
        temp[k++] = a[l++];
    }
    
    while(r <= e)
    {
        temp[k++] = a[r++];
    }
    
    for(int i = s; i <= e; i++)
    {
        a[i] = temp[i];
    }
}

int mergesort(vector <int> &a, int s, int e)
{
    if(s < e)
    {
        int m = (s + e) / 2;
        int c = mergesort(a, s, m) + mergesort(a, m + 1, e);
        
        int j = m + 1;
        for(int i = s; i <= m; i++)
        {
            while(j <= e && a[i] > 2LL * a[j])
                j++;
            c += j - m - 1;
        }
        
        merge(a, s, m, e);
        
        return c;
    }
    else
        return 0;
}

int Solution::solve(vector<int> &a) {
    
    int ans = mergesort(a, 0, a.size() - 1);
    return ans;
}
