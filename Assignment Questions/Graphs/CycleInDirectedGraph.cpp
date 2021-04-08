bool is_cyclic(int node, vector < vector <int> > &mat, vector <int> &visited, vector <int> &recursion_stack)
{
    recursion_stack[node] = 1;
    visited[node] = 1;
    
    for(int i = 0; i < mat[node].size(); i++)
    {
        int next_node = mat[node][i];
        
        if(recursion_stack[ next_node ] == 1)
            return true;
        if(is_cyclic(next_node, mat, visited, recursion_stack) == true)
            return true;
    }
    
    recursion_stack[node] = 0;
    return false;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    
    vector < vector <int> > mat(a + 1);
    vector <int> visited(a + 1, 0);
    vector <int> recursion_stack(a + 1, 0);
    
    int i, j;
    for(i = 0; i < b.size(); i++)
    {
        mat[ b[i][0] ].push_back(b[i][1]);
    }
    
    for(i = 0; i < a; i++)
    {
        if(visited[i] == 0)
            if(is_cyclic(i, mat, visited, recursion_stack) == true)
                return true;
    }
    
    return false;
}
