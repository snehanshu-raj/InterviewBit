int Solution::candy(vector<int> &a) {
    
    int n = a.size();
    vector <int> left(n), right(n);
    
    int i;
    
    left[0] = 1;
    for(i = 1; i < n; i++)
    {
        if(a[i] > a[i - 1])
            left[i] = left[i - 1] + 1;
        else
            left[i] = 1;
    }
    
    right[n - 1] = 1;
    for(i = n - 2; i >= 0; i--)
    {
        if(a[i] > a[i + 1])
            right[i] = right[i + 1] + 1;
        else
            right[i] = 1;
    }
    
    int ans = 0;
    for(i = 0; i < n; i++)
    {
        ans += max(left[i], right[i]);
    }
    return ans;
}
