vector<int> Solution::solve(int a, vector<int> &b) {
    
    int i;
    vector <int> ans;
    
    priority_queue <int, vector <int>, greater <int> > min_heap(b.begin(), b.begin() + a);
    
    for(i = 1; i <= a - 1; i++)
        ans.push_back(-1);
    
    ans.push_back(min_heap.top());
    for(i = a; i < b.size(); i++)
    {
        if(b[i] > min_heap.top())
        {
            min_heap.pop();
            min_heap.push(b[i]);
            ans.push_back(min_heap.top());
        }
        else
            ans.push_back(min_heap.top());
    }
    return ans;
}
