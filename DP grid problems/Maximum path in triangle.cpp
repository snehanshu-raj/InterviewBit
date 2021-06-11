int Solution::solve(vector<vector<int> > &a) {
    
    int rows = a.size();
    int cols = rows;
    
    int i, j;
    for(i = rows - 2; i >= 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
        }
    }
    
    return a[0][0];
}
