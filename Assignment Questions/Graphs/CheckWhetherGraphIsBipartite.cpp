// bool is_bipartite(int node, vector <int> &col_arr, int col, vector < vector <int> > mat)
// {
//     col_arr[node] = col;
//     for(int i = 0; i < mat[node].size(); i++)
//     {
//         int next_node = mat[node][i];
        
//         if(col_arr[next_node] == -1)
//         {
//             if(is_bipartite(next_node, col_arr, 1 - col, mat) == false)
//                 return false;
//         }
//         if(col_arr[next_node] == col_arr[node])
//             return false;
//     }
    
//     return true;
// }

int Solution::solve(int a, vector<vector<int> > &b) {
    
    vector <int> col_arr(a, -1);
    vector < vector <int> > mat(a);
    
    
    int i;
    for(i = 0; i < b.size(); i++)
    {
        mat[ b[i][0] ].push_back( b[i][1] );
        mat[ b[i][1] ].push_back( b[i][0] );
    }
    
    // for(i = 0; i < a; i++)
    // {
    //     if(col_arr[i] == -1)
    //         if(is_bipartite(i, col_arr, 0, mat) == false)
    //             return false;
    // }
    
    // return true;
    
    //using bfs
    
    queue <int> q;
    
    for(i = 0; i < a; i++)
    {
        if(col_arr[i] != -1)
            continue;
        
        q.push(i);
        col_arr[i] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int j = 0; j < mat[node].size(); j++)
            {
                int next_node = mat[node][j];
                
                if(col_arr[next_node] == -1)
                {
                    col_arr[next_node] = col_arr[node] ^ 1;
                    q.push(next_node);
                }
                else
                if(col_arr[next_node] == col_arr[node])
                    return false;
            }
        }
    }
    return true;
}
