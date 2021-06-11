int sets[2];

void dfs(int cur_node, int prev_node, int s, vector < vector <int> > &graph)
{
    sets[s]++;
    
    for(int i = 0; i < graph[cur_node].size(); i++)
    {
        int v = graph[cur_node][i];
        if(v != prev_node)
            dfs(v, cur_node, 1 - s, graph);
    }
}

int Solution::solve(int a, vector<vector<int> > &b) {
    
    sets[0] = sets[1] = 0;
    
    int i;
   
    vector < vector <int> > graph(a + 1);
    
    for(i = 0; i < b.size(); i++)
    {
        graph[ b[i][0] ].push_back( b[i][1] );
        graph[ b[i][1] ].push_back( b[i][0] );
    }
    
    dfs(1, 0, 0, graph);
    
    return ((1L * sets[0] * sets[1]) - (a - 1)) % 1000000007;
}
