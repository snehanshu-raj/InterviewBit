int Solution::minPathSum(vector<vector<int> > &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    int i, j;
    
    vector < vector <int> > mat(rows, vector <int> (cols, 0));
    
    mat[0][0] = a[0][0];
    
    for(i = 1; i < rows; i++)
    {
        mat[i][0] = a[i][0] + mat[i - 1][0];
    }
    
    for(i = 1; i < cols; i++)
    {
        mat[0][i] = a[0][i] + mat[0][i - 1];
    }
    
    for(i = 1; i < rows; i++)
    {
        for(j = 1; j < cols; j++)
        {
            mat[i][j] = min(mat[i - 1][j], mat[i][j - 1]) + a[i][j];
        }
    }
    
    return mat[rows - 1][cols - 1];
}
