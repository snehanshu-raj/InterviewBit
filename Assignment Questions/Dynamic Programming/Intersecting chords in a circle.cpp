int Solution::chordCnt(int n) {
    
    long long dp[n + 1] = { 0 };
    int i, k;
    
    if(n == 1 || n == 0)
        return 1;
    if(n == 2)
        return 2;
        
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(i = 3; i <= n; i++)
    {
        for(k = 0; k < i; k++)
        {
            dp[i] = (dp[i] + dp[k] * dp[i - k - 1]) % 1000000007;
        }
    }
    
    return dp[n] % 1000000007;
}
     