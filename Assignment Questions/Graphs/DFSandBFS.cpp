void dfs(graph, visited, node)
{
    if(!visited[node])
    {
        cout << node;
        visited[node] = 1;

        for(int i = 0; i < graph[node].size(); i++)
        {
            int next = graph[node][i];
            if(!visited[next])
            {
                dfs(graph, visited, next);
            }
        }
    }
}

void bfs(graph, visited, node)
{
    queue <int> q;
    q.push(node);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        visited[cur] = 1;
        cout << cur;

        for(i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if(!visited(next))
            {
                q.push(next);
            }
        }
    }
}

int main()
{
    vector < vector <int> > graph;

    int i;
    vector <int> visited(n, 0);

    // dfs
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];
            if(!visited[next])
            {
                dfs(graph, visited, next);
            }
        }
    }

    //bfs
    bfs(graph, visited, node);
}