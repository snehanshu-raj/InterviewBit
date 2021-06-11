int Solution::solve(vector<int> &a, vector<int> &b) {
    
    vector < vector <int> > v;
    int i;
    
    for(i = 0; i < a.size(); i++)
    {
        vector <int> t;
        t.push_back(b[i]);
        t.push_back(a[i]);
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    int ans = 1;
    int refer = v[0][0];
    
    for(i = 1; i < a.size(); i++)
    {
        if(v[i][1] >= refer)
        {
            ans++;
            refer = v[i][0];
        }
    }
    return ans;
}
