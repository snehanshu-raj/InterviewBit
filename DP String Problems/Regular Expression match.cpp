int Solution::isMatch(const string a, const string b) {
    
    int l1 = a.length();
    int l2 = b.length();
    
    int i, j;
    
    int c = 0;
    for(i = 0; i < l2; i++)
    {
        if(b[i] == '*')
            c++;
    }
    
    if(l2 - c > l1)
        return 0;
    
    int dp[l1 + 1];
    for(i = 0; i <= l1; i++)
        dp[i] = 0;
        
    dp[0] = 1;
    
    for(i = 0; i < l2; i++)
    {
        if(b[i] == '*')
        {
            for(j = 1; j <= l1; j++)
            {
                dp[j] = dp[j - 1] || dp[j];
            }
        }
        else
        {
            for(j = l1 - 1; j >= 0; j--)
            {
                dp[j + 1] = dp[j] & (a[j] == b[i] || b[i] == '?');
            }
        }
        
        dp[0] = dp[0] & (b[i] == '*');
    }
    
    if(dp[l1] > 0)
        return 1;
    return 0;
    // int l1 = a.length();
    // int l2 = b.length();
    
    // if(l1 == 0 && l2 == 0)
    //     return 1;
    // if(l1 == 0 || l2 == 0)
    //     return 0;
        
    // int i, j;
    // vector < vector <int> > dp(l1 + 1, vector <int> (l2 + 1, 0));
    
    // dp[0][0] = 1;
    
    // for(i = 0; i < l2; i++)
    // {
    //     if(b[i] == '*')
    //         dp[0][i + 1] = 1;
    //     else
    //         break;
    // }
        
    // for(i = 0; i < l1; i++)
    // {
    //     for(j = 0; j < l2; j++)
    //     {
    //         if(b[j] != '*')
    //             dp[i + 1][j + 1] = dp[i][j] && (a[i] == b[j] || b[j] == '?');
    //         else
    //             dp[i + 1][j + 1] = dp[i + 1][j] || dp[i][j + 1];
    //     }
    // }
    
    // if(dp[l1][l2] > 0)
    //     return 1;
    // return 0;
}
