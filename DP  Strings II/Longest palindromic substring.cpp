string Solution::solve(string a) {
    
    int n = a.length();
    int dp[n + 1][n + 1];
    int i, j;
    
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i >= j)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    
    for(i = n - 2; i >= 0; i--)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    
    int len = INT_MIN;
    int s = 0;
    
    for(i = 0; i < n; i++)
    {
        for(j = i; j < n; j++)
        {
            if(dp[i][j])
            {
                int l = j - i + 1;
                if(l > len)
                {
                    s = i;
                    len = l;
                }
            }
        }
    }
    
    string ans = "";
    if(len == 1)
    {
        ans += a[0];
        return ans;
    }
        
    for(i = s; i < s + len; i++)
        ans += a[i];
    return ans;
}
