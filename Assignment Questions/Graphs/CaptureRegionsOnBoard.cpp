void Solution::solve(vector<vector<char> > &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    
    if(rows == 1 || cols == 1)
        return;
        
    vector < vector <int> > refer(rows, vector <int> (cols, 1));
    
    int i, j;
    queue < pair <int, int> > q;
    
    //check for first and last coloumns
    for(i = 0; i < rows; i++)
    {
        if(a[i][0] == 'O')
        {
            refer[i][0] = 0;
            q.push({i, 0});
        }
        if(a[i][cols - 1] == 'O')
        {
            refer[i][cols - 1] = 0;
            q.push({i, cols - 1});
        }
    }
    
    //check for first and last rows
    for(j = 0; j < cols; j++)
    {
        if(a[0][j] == 'O')
        {
            refer[0][j] = 0;
            q.push({0, j});
        }
        if(a[rows - 1][j] == 'O')
        {
            refer[rows - 1][j] = 0;
            q.push({rows - 1, j});
        }
    }
    
    while(!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        
        if(r > 1 && refer[r - 1][c] == 1 && a[r - 1][c] == 'O')
        {
            refer[r - 1][c] = 0;
            q.push({r - 1, c});
        }
        if(r + 1 < rows - 1 && refer[r + 1][c] == 1 && a[r + 1][c] == 'O')
        {
            refer[r + 1][c] = 0;
            q.push({r + 1, c});
        }
        
        if(c > 1 && refer[r][c - 1] == 1 && a[r][c - 1] == 'O')
        {
            refer[r][c - 1] = 0;
            q.push({r, c - 1});
        }
        if(c + 1 < cols - 1 && refer[r][c + 1] == 1 && a[r][c + 1] == 'O')
        {
            refer[r][c + 1] = 0;
            q.push({r, c + 1});
        }
    }
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(refer[i][j] == 1 && a[i][j] == 'O')
                a[i][j] = 'X';
        }
    }
}
