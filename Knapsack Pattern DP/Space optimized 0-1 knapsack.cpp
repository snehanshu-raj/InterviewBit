int Solution::solve(vector<int> &a, vector<int> &b, int w) {
    int val = a.size();
    int wt = b.size();
    
    int dp[w + 1] = { 0 };
    
    int i, j;
    
    for(i = 0; i < val; i++)
    {
        for(j = w; j >= b[i]; j--)
        {
            dp[j] = max(dp[j], a[i] + dp[j - b[i]]);
        }
    }
    
    return dp[w];
}
