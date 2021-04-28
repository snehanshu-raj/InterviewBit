int directions[][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1} };
int visited[105][105];
int tc = 0;

bool checker(int i, int j, int rows, int cols, vector < vector <int> > &a)
{
    return (i >= 0 && i < rows && j >= 0 && j < cols && (a[i][j] == 1) && visited[i][j] != tc);
}

void dfs(int i, int j, int rows, int cols, vector < vector <int> > &a)
{
    visited[i][j] = tc;
    int next_i; 
    int next_j;
    for(int n = 0; n < 8; n++)
    {
        next_i = i + directions[n][0];
        next_j = j + directions[n][1];
        if(checker(next_i, next_j, rows, cols, a))
            dfs(next_i, next_j, rows, cols, a);
    }
}

int Solution::solve(vector <vector <int> > &a) {
    
    int rows = a.size();
    int cols = a[0].size();
    tc++;
    
    int ans = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(a[i][j] == 1 && visited[i][j] != tc)
            {
                dfs(i, j, rows, cols, a);
                ans++;
            }
        }
    }
    
    return ans;
}
