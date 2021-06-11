int Solution::solve(vector<int> &a, vector<int> &b) {
    
    vector < vector <int> > v;
    
    int i;
    for(i = 0; i < a.size(); i++)
    {
        vector <int> t;
        t.push_back(a[i]);
        t.push_back(b[i]);
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    priority_queue <int, vector <int>, greater <int> > min_heap;
    
    int time = 0;
    for(i = 0; i < a.size(); i++)
    {
        if(time < v[i][0])
        {
            min_heap.push(v[i][1]);
            time++;
        }
        else
        if(time == v[i][0])
        {
            if(min_heap.top() < v[i][1])
            {
                min_heap.pop();
                min_heap.push(v[i][1]);
            }
        }
    }
    
    int ans = 0;
    while(!min_heap.empty())
    {
        ans = (ans + min_heap.top()) % 1000000007;
        min_heap.pop();
    }
    return ans % 1000000007;
}
