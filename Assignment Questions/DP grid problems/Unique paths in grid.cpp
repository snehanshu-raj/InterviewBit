int Solution::uniquePathsWithObstacles(vector<vector<int> > &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    
    int i, j;
    vector < vector <int> > mat(rows, vector <int> (cols, 0));
    
    if(a[0][0] == 0)
        mat[0][0] = 1;
        
    for(i = 1; i < cols; i++)
    {
        if(a[0][i] == 0)
            mat[0][i] = mat[0][i - 1];
    }
    
    for(j = 1; j < rows; j++)
    {
        if(a[j][0] == 0)
            mat[j][0] = mat[j - 1][0];
    }
    
    for(i = 1; i < rows; i++)
    {
        for(j = 1; j < cols; j++)
        {
            if(a[i][j] == 0)
            {
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
            }
        }
    }
    
    return mat[rows - 1][cols - 1];
}
