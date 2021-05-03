int directions[][2] = { {1, 0}, { -1, 0}, {0, 1}, {0, -1} };

bool checker(int r, int c, int rows, int cols, vector <string> &a, vector < vector <int> > &visited)
{
    return (r >= 0 && c >= 0 && r < rows && c < cols && a[r][c] == 'X' && visited[r][c] != 1);    
}

void dfs(int r, int c, vector <string> &a, vector < vector <int> > &visited)
{
    visited[r][c] = 1;
    for(int k = 0; k < 4; k++)
    {
        int next_r = r + directions[k][0];
        int next_c = c + directions[k][1];
        
        if(checker(next_r, next_c, a.size(), a[0].size(), a, visited))
            dfs(next_r, next_c, a, visited);
    }
}

int Solution::black(vector<string> &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    
    vector < vector <int> > visited(rows, vector <int> (cols, 0));
    int i, j;
    int ans = 0;
    
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            if(a[i][j] == 'X' && visited[i][j] == 0)
            {
                dfs(i, j, a, visited);
                ans++;
            }
        }
    }
    
    return ans;
}
