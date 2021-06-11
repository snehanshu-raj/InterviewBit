int Solution::solve(int w, vector<int> &v, vector<int> &wt) {
    
    int val = v.size();
    int dp[w + 1] = { 0 };
    
    int i, j;
    
    for(i = 0; i < val; i++)
    {
        for(j = 0; j <= w; j++)
        {
            if(wt[i] <= j)
                dp[j] = max(dp[j], v[i] + dp[j - wt[i]]);
        }
    }
    
    return dp[w];
}
