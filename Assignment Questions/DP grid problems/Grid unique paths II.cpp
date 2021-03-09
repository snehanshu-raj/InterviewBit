int Solution::solve(vector<vector<int> > &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    
    vector < vector <int> > mat(rows, vector <int> (cols, 0));
    
    int i, j;
    
    if(a[0][0] == 0)
        mat[0][0] = 1;
    
    for(i = 1; i < rows; i++)
    {
        if(a[i][0] == 0)
            mat[i][0] = mat[i - 1][0];
    }
    
    for(i = 1; i < cols; i++)
    {
        if(a[0][i] == 0)
            mat[0][i] = mat[0][i - 1];
    }
    
    for(i = 1; i < rows; i++)
    {
        for(j = 1; j < cols; j++)
        {
            if(a[i][j] == 0)
            {
                mat[i][j] = (mat[i - 1][j] + mat[i][j - 1]) % 1000000007;
            }
        }
    }
    
    return mat[rows - 1][cols - 1] % 1000000007;
}
