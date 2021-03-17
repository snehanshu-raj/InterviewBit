int Solution::solve(vector<int> &a, vector<int> &b, int w) {
    
    int val = a.size();
    int wt = b.size();
    
    int dp[val + 1][w + 1];
    
    int i, j;
    for(i = 0; i <= val; i++)
    {
        for(j = 0; j <= w; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else
            if(b[i - 1] <= j)
                dp[i][j] = max(a[i - 1] + dp[i - 1][j - b[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[val][w];
}
