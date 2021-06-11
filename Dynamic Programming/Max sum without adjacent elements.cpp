int Solution::adjacent(vector<vector<int> > &a) {
    
    vector <int> modified;
    int i;
    
    for(i = 0; i < a[0].size(); i++)
    {
        modified.push_back( max( a[0][i], a[1][i] ) );
    }
    
    int dp[20001] = { 0 };
    dp[0] = modified[0];
    dp[1] = max( modified[1], modified[0] );
    
    for(i = 2; i < modified.size(); i++)
        dp[i] = max( modified[i] + dp[i - 2], dp[i - 1]);
    
    return dp[ modified.size() - 1 ];
}
