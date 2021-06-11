int Solution::minimumTotal(vector<vector<int> > &a) {

    int rows = a.size();
    int cols = rows;
    
    vector < vector <int> > mat(rows, vector <int> (cols, 0));
    
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < a[i].size(); j++)
        {
            mat[i][j] = a[i][j];
        }
    }
    
    for(i = rows - 2; i >= 0; i--)
    {
        for(j = 0; j <= i; j++)
        {
            mat[i][j] += min(mat[i + 1][j], mat[i + 1][j + 1]);
        }
    }
    
    return mat[0][0];
}
