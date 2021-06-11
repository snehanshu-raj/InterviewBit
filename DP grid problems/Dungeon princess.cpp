int Solution::calculateMinimumHP(vector<vector<int> > &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    int i, j;
    
    vector < vector <int> > mat(rows, vector <int>(cols));
    
    mat[rows - 1][cols - 1] = max(1, 1 - a[rows - 1][cols - 1]);
    
    for(i = rows - 2; i >= 0; i--)
    {
        mat[i][cols - 1] = max(mat[i + 1][cols - 1] - a[i][cols - 1], 1);
    }
    
    for(j = cols - 2; j >= 0; j--)
    {
        mat[rows - 1][j] = max(mat[rows - 1][j + 1] - a[rows - 1][j], 1);
    }
    
    for(i = rows - 2; i >= 0; i--)
    {
        for(j = cols - 2; j >= 0; j--)
        {
            int health = min(mat[i + 1][j], mat[i][j + 1]); 
            mat[i][j] = max(health - a[i][j], 1);
        }
    }
    
    return mat[0][0];
}
