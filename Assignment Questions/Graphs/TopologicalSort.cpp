// void dfs(int node, vector < vector <int> > &graph, vector <int> &visited, stack <int> &s)
// {
//     visited[node] = 1;
    
//     for(int i = 0; i < graph[node].size(); i++)
//     {
//         if(!visited[ graph[node][i] ])
//             dfs(graph[node][i], graph, visited, s);
//     }
    
//     s.push(node);
// }

vector<int> Solution::solve(int a, vector<vector<int> > &b) {
    
    vector < vector <int> > graph(a + 1);
    int i;
    
    for(i = 0; i < b.size(); i++)
    {
        graph[ b[i][0] ].push_back( b[i][1] );
    }
    
    // for(i = 1; i <= a; i++)
    //     sort(graph[i].begin(), graph[i].end());
        
    // vector <int> visited(a + 1, 0);
    // vector <int> ans;
    // stack <int> s;
    
    // for(i = 1; i <= a; i++)
    // {
    //     if(!visited[i])
    //         dfs(i, graph, visited, s);
    // }
    
    // while(!s.empty())
    // {
    //     ans.push_back( s.top() );
    //     s.pop();
    // }
    
    // return ans;
    
    // dfs does not give topologically sorted array
    
    vector <int> degree(a + 1, 0);
    vector <int> visited(a + 1, 0);
    vector <int> ans;
    multiset <int> s;
    
    for(i = 1; i <= a; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            degree[ graph[i][j] ]++;
        }
    }
    
    for(i = 1; i <= a; i++)
    {
        if(degree[i] == 0)
            s.insert(i);
    }
    
    int c = 0;
    
    while(!s.empty())
    {
        int u = *s.begin();
        s.erase(s.begin());
        ans.push_back(u);
        
        for(i = 0; i < graph[u].size(); i++)
        {
            if(--degree[ graph[u][i] ] == 0)
                s.insert(graph[u][i]);
        }
        
        c++;
    }
    
    if(c != a)
    {
        vector <int> temp;
        return temp;
    }
    
    return ans;
}
