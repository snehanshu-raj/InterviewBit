int Solution::longestConsecutive(const vector<int> &a) {
    vector <int> b = a;
    
    int i, c = 0, ans = 0;
    unordered_set <int> s;
        
    for(i = 0; i < a.size(); i++)
    {
        s.insert(a[i]);
    }
    
    for(i = 0; i < a.size(); i++)
    {
        if(s.count(a[i] - 1) > 0)
            continue;
        else
        if(s.count(a[i] + 1) > 0)
        {
            int start = a[i];
            c = 0;
            while(s.count(start++) > 0)
            {
                c++;
            }
            ans = max(ans, c);
        }
    }
return ans > 0 ? ans : 1;
}
