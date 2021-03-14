int dp[502][502]; // dp[i][j] tells whether the substring s[i...j] is palindrome or not
int ans[502][502];

int checker(string s, int start, int end)
{
    if(end == s.length())
    {
        if(!dp[start][end - 1])
            return INT_MAX;
        else
            return 0;
    }
    
    if(ans[start][end])
        return ans[start][end];
        
    if(dp[start][end])
    	return ans[start][end] = min(1 + checker(s, end + 1, end + 1), checker(s, start, end + 1));
    	
    else
        return ans[start][end] =  checker(s, start, end + 1);
}

int Solution::minCut(string s) {
    
    //pre-processing
    int n = s.length();
    
    if(n == 1)
        return 0;
        
    int i, j;
    memset(ans, 0, sizeof(ans));
    memset(dp, 0, sizeof(dp));
    
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i >= j)
                dp[i][j] = 1;
        }
    }
    
    for(i = n - 2; i >= 0; i--)
    {
        for(j = i + 1; j < n; j++)
        {
            if(s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    
    return checker(s, 0, 0);
}
