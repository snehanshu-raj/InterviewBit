vector <long long> powers(300005);
int mod = 998244353;

void cal()
{
    powers[0] = 1;
    for(int i = 1; i < 300006; i++)
    {
        powers[i] = ((2LL % mod) * (powers[i - 1] % mod)) % mod;
    }
}

bool dfs(int node, vector < vector <int> > &graph, vector <int> &visited, int &a, int &b)
{
    visited[node] = 1;
    a++;
    
    queue <int> q;
    q.push(node);
    
    while(!q.empty())
    {
        int from = q.front();
        q.pop();
        
        for(int i = 0; i < graph[from].size(); i++)
        {
            int next = graph[from][i];
            if(visited[next] == -1)
            {
                visited[next] = 1 - visited[from];
                if(visited[next] == 0)
                    b++;
                else
                    a++;
                q.push(next);
            }
            else
            if(visited[from] == visited[next])
                return false;
        }
    }
    return true;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    
    vector <int> visited(a + 1, -1);
    vector < vector <int> > graph(a + 1);
    int i;
    
    cal();
    
    for(i = 0; i < b.size(); i++)
    {
        graph[ b[i][0] ].push_back( b[i][1] );
        graph[ b[i][1] ].push_back( b[i][0] );
    }
    
    long long ans = 1;
    for(i = 1; i <= a; i++)
    {
        if(visited[i] == -1)
        {
            int a = 0;
            int b = 0;
            if(dfs(i, graph, visited, a, b) == false)
                return 0;
            
            long long temp = (powers[a] % mod + powers[b] % mod) % mod;
            ans = ((ans % mod) * (temp % mod))  % mod;
        }
    }
    
    return ans;
}
