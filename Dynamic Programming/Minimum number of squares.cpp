int Solution::countMinSquares(int n) {
    
    int dp[n + 1] = { 0 };
    
    int i, x;
    for(i = 1; i <= n; i++)
    {
        dp[i] = i;
        for(x = 1; x * x <= i; x++)
        {
            dp[i] = min(dp[i], dp[i - x*x] + 1);
        }
    }
    return dp[n];
}
