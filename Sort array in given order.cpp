vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
    
    vector <int> ans;
    
    int i;
    
    map <int, int> m;
    for(i = 0; i < a.size(); i++)
    {
        m[ a[i] ]++;
    }
    
    for(i = 0; i < b.size(); i++)
    {
        if(m[ b[i] ] > 0)
        {
            while(m[ b[i] ] > 0)
            {
                m[ b[i] ]--;
                ans.push_back(b[i]);
            }
        }
    }
    
    for(auto x : m)
    {
        if(x.second > 0)
        {
            while(x.second > 0)
            {
                ans.push_back(x.first);
                x.second--;
            }
        }
    }
return ans;
}
