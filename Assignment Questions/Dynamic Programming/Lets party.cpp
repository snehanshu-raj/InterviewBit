long long dp[1000001];

int ways(int n)
{
    if(n <= 2 || dp[n] != 0)
        return dp[n] % 10003;
    
    dp[n] = (ways(n - 1) + ways(n - 2) * (n - 1)) % 10003;
    return dp[n] % 10003;
}

int Solution::solve(int a) {
    
    // long long dp[1000001] = { 0 };
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    // for(int i = 3; i <= a; i++)
    //     dp[i] = (dp[i - 1] + dp[i - 2] * (i - 1)) % 10003;
    
    // return dp[a] % 10003;
    
    return ways(a) % 10003;
}
