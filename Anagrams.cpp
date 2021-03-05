vector<vector<int> > Solution::anagrams(const vector<string> &a) {
    
    vector <string> b = a;
    unordered_map <string, vector <int> > m;
    
    vector < vector <int> > ans;
    
    int i;
    for(i = 0; i < a.size(); i++)
    {
        sort(b[i].begin(), b[i].end());
        m[ b[i] ].push_back(i + 1);
    }
    
    for(auto x : m)
    {
        ans.push_back(x.second);
    }
return ans;
}
