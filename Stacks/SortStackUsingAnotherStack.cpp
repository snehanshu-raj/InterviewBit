vector<int> Solution::solve(vector <int> &a) {
    
    stack <int> s2;
    
    while(a.size() > 0)
    {
        int x = a[ a.size() - 1];
        a.pop_back();
        
        while(!s2.empty() && x < s2.top())
        {
            a.push_back(s2.top());
            s2.pop();
        }
        
        s2.push(x);
    }
    
    vector <int> ans;
    
    while(!s2.empty())
    {
        ans.push_back(s2.top());
        s2.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
