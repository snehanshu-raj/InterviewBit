vector<int> Solution::solve(int a, vector<vector<int> > &b, int c) {

    vector < pair <int, int> > graph[a];
    int i;
    
    for(i = 0; i < b.size(); i++)
    {
        graph[ b[i][0] ].push_back( make_pair(b[i][1], b[i][2]) );
        graph[ b[i][1] ].push_back( make_pair(b[i][0], b[i][2]) );    
    }
    
    vector <int> dist(a, INT_MAX);
    dist[c] = 0;
    
    priority_queue < pair<int, int>, vector< pair<int, int> >, greater < pair <int, int> > > min_heap;
    min_heap.push({0, c});
    
    while(!min_heap.empty())
    {
        int from = min_heap.top().second;
        min_heap.pop();
        
        for(int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i].first;
            int cost = graph[from][i].second;
            
            if(dist[to] > dist[from] + cost)
            {
                dist[to] = dist[from] + cost;
                min_heap.push({dist[to], to});
            }
        }
    }
    
    for(i = 0; i < a; i++)
    {
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    }
    return dist;
}
