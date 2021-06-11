int Solution::numDistinct(string a, string b) {
    
    if(a == b)
        return 1;
        
    int l1 = a.length();
    int l2 = b.length();
    
    if(l2 > l1)
        return 0;
        
    int dp[l2 + 1][l1 + 1];
    int i, j;
    
    for(i = 0; i <= l2; i++)
    {
        for(j = 0; j <= l1; j++)
        {
            dp[i][j] = 0;
        }
    }
    
    for(i = 0; i <= l2; i++)
    {
        for(j = i; j <= l1; j++)
        {
            if(i == 0)
                dp[i][j] = 1;
            else
            if(b[i - 1] == a[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    
    return dp[l2][l1];
}
