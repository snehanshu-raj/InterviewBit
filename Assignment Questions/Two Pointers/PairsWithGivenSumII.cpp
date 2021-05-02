int Solution::solve(vector<int> &a, int b) {
    
    map <long, long> m;
    
    long long ans = 0;
    
    long long i;
    for(i = 0; i < a.size(); i++)
    {
        m[ a[i] ]++;
    }
    
    for(auto x : m)
    {
        long long n = x.first;
        
        if(n * 2 == b)
        {
            if(x.second > 1)
                ans = (ans + (x.second * (x.second - 1) / 2));
        }
        else
        if(m.find(b - n) != m.end())
        {
            ans = (ans + (m[b - n] * m[n]));
            m[n] = 0;
            m[b - n] = 0;
        }
    }
    
    return ans % 1000000007;
}
