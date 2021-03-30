int Solution::solve(int a, vector<vector<int> > &b) {
    
    vector < vector <int> > mat(a + 1);
    int i, j, u, v;
    
    queue <int> q;
    int visited[a + 1] = { 0 };
    
    for(i = 0; i < b.size(); i++)
    {
        mat[ b[i][0] ].push_back( b[i][1] );
    }
    
    q.push(1);
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        visited[u] = 1;
        
        for(i = 0; i < mat[u].size(); i++)
        {
            visited[ mat[u][i] ] = 1;
            if( mat[u][i] == a)
                return 1;
            q.push( mat[u][i] );
        }
    }
    
    return 0;
}
