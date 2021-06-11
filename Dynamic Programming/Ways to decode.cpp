int Solution::numDecodings(string s) {
    
    long long len = s.size();
    
    if(len == 0)
        return 0;
    if(s[0] == '0')
        return 0;
    if(len == 1)
        return 1;
    
    int refer[100001];
    long long dp[100001] = { 0 };
    long long i;
    
    for(i = 0; i < len; i++)
    {
        refer[i] = (int)s[i] - '0';
    }
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(i = 2; i <= len; i++)
    {
        dp[i] = 0;
        
        if(refer[i - 1] > 0)
            dp[i] = dp[i - 1];
        if(refer[i - 1] == 0 && refer[i - 2] > 2)
            return 0;
        if((refer[i - 2] < 2 && refer[i - 2] > 0) || ( refer[i - 2] == 2 && refer[i - 1] < 7))
            dp[i] = (dp[i] + dp[i - 2]) % 1000000007;
    }
   
    return dp[len] % 1000000007;
}
