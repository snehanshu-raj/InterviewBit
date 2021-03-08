int Solution::solve(vector<int> &a, int b, int c, int d) {
    
    int n = a.size();
    int left[n], right[n], i;
    
    left[0] = b * a[0];
    for(i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], a[i] * b);
    }
    
    right[n - 1] = d * a[n - 1];
    for(i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], a[i] * d);
    }
    
    int ans = INT_MIN;
    for(i = 0; i < n; i++)
    {
        ans = max(ans, left[i] + right[i] + a[i] * c);
    }
    
    return ans;
}
