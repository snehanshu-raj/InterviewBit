int Solution::minDistance(string a, string b) {
    
    int l1 = a.length();
    int l2 = b.length();
    
    int dp[l1 + 1][l2 + 1];
    int i, j;
    
    for(i = 0; i <= l1; i++)
    {
        for(j = 0; j <= l2; j++)
        {
            if(i == 0)
                dp[i][j] = j;
            else
            if(j == 0)
                dp[i][j] = i;
            
            else
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min( min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }
    
    return dp[l1][l2];
}
