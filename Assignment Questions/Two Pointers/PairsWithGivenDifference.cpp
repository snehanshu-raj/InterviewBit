int Solution::solve(vector<int> &a, int b) {
    
    map <int, int> m;
    int i;
    
    for(i = 0; i < a.size(); i++)
    {
        m [ a[i] ]++;
    }
    
    int ans = 0;
    
    for(auto x : m)
    {
        int n = x.first;
        
        if(n - n == b)
        {
            if(x.second > 1)
                ans += 1;
        }
        else
        if(m.find(n + b) != m.end() && b != 0)
        {
            ans++;
        }
    }
    
    return ans;
}
