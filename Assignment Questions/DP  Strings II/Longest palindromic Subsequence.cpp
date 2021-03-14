int Solution::solve(string a) {
    
    int n = a.length();
    int dp[n][n];
    int i, j;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }
    
    //state dp[i][j] -> length of longest palindromic subsequence in the range [i, j]
    
    for(i = n - 2; i >= 0; i--)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    
    return dp[0][n - 1];
}
