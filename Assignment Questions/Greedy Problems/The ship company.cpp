vector<int> Solution::solve(int a, int b, vector<int> &c) {
    
    int max_s = 0, min_s = 0;
    
    priority_queue <int> max_heap(c.begin(), c.end());
    
    sort(c.begin(), c.end());
    
    int pass = a;
    
    int i = 0;
    while(pass != 0)
    {
        if(c[i] > 0)
        {
            pass--;
            min_s += c[i];
            c[i]--;
        }
        else
            i++;
    }
    
    pass = a;
    
    while(pass != 0)
    {
        pass--;
        max_s += max_heap.top();
        int t = max_heap.top();
        max_heap.pop();
        max_heap.push(t - 1);
    }
    
    vector <int> ans;
    ans.push_back(max_s);
    ans.push_back(min_s);
    
    return ans;
}
