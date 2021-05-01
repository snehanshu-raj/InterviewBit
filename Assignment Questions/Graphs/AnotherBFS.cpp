int Solution::solve(int a, vector < vector <int> > &b, int c, int d) {
    
    vector < vector <int> > graph(2 * a + 1);
    
    int i;
    for(i = 0; i < b.size(); i++)
    {
        if(b[i][2] == 2)
        {
            graph[ b[i][0] ].push_back( a + b[i][0] );
            graph[ a + b[i][0] ].push_back( b[i][1] );
            graph[ b[i][1] ].push_back( a + b[i][1] );
            graph[ a + b[i][1] ].push_back( b[i][0] );
        }
        else
        {
            graph[ b[i][0] ].push_back( b[i][1] );
            graph[ b[i][1] ].push_back( b[i][0] );   
        }
    }
    
    vector <int> dist(2 * a + 1, INT_MAX);
    dist[c] = 0;
    queue <int> q;
    q.push(c);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for(i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if(dist[next] > dist[node] + 1)
            {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
    
    if(dist[d] == INT_MAX)
        return -1;
    else
        return dist[d];
}
