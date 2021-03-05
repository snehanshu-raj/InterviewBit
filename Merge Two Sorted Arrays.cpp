vector<int> Solution::solve(const vector<int> &a, const vector<int> &b) {
    
    int i = 0, j = 0;
    vector <int> c;
    
    while(i < a.size() && j < b.size())
    {
        if(a[i] < b[j])
        {
            c.push_back(a[i]);
            i++;
        }
        else
        {
            c.push_back(b[j]);
            j++;
        }
    }
    
    for( ; i < a.size(); i++)
        c.push_back(a[i]);
    
    for( ; j < b.size(); j++)
        c.push_back(b[j]);
        
    return c;
}
