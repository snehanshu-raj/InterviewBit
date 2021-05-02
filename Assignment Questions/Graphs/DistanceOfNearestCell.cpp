vector<vector<int> > Solution::solve(vector<vector<int> > &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    int directions[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
    
    queue < pair <int, int> > q;
    vector < vector <int> > ans(rows, vector <int> (cols, INT_MAX));
    
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(a[i][j] == 1)
            {
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }
    
    while(!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        
        for(int k = 0; k < 4; k++)
        {
            int next_r = r + directions[k][0];
            int next_c = c + directions[k][1];
            
            if(next_r >= 0 && next_c >= 0 && next_r < rows && next_c < cols && ans[next_r][next_c] > ans[r][c] + 1)
            {
                q.push({next_r, next_c});
                ans[next_r][next_c] = ans[r][c] + 1;
            }
        }
    }
    
    return ans;
}
