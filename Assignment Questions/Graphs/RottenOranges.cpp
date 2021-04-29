int Solution::solve(vector <vector <int> > &a) {
    
    int rows = a.size(), cols = a[0].size();
    
    queue <pair <int, int> > q; 
    
    int fresh = 0, count = 0;
    
    for(int i = 0; i < rows; i++) 
    {
        for(int j = 0; j < cols; j++) 
        {
            if(a[i][j] == 2)
                q.push({i, j});
            else if(a[i][j])
                fresh++;
        }
    }
    
    if(fresh == 0)
        return 0;
    
    while(!q.empty()) 
    {        
        int n = q.size();
        
        while(n--) 
        {
            auto [r, c] = q.front();
            q.pop();
            
            if(r > 0 and a[r - 1][c] == 1) 
            {
                a[r - 1][c] = 2;
                
                fresh--;
                
                q.push({r - 1, c});
            }
            if(r + 1 < rows and a[r + 1][c] == 1) 
            {
                a[r + 1][c] = 2;
                
                fresh--;
                
                q.push({r + 1, c});
            }
            if(c > 0 and a[r][c - 1] == 1) 
            {
                a[r][c - 1] = 2;
                
                fresh--;
                
                q.push({r, c - 1});
            }
            if(c + 1 < cols and a[r][c + 1] == 1) 
            {
                a[r][c + 1] = 2;
                
                fresh--;
                
                q.push({r, c + 1});
            }
        }
        
        count++;
    }
    
    return fresh > 0 ? -1 : count - 1;
}

