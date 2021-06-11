int Solution::solve(vector<int> &a, int b) {
    
    int ans = 0, i;
    
    priority_queue <int, vector <int>, greater <int> > min_heap(a.begin(), a.end());

    while(1)
    {
        int t = min_heap.top();
        min_heap.pop();
        if(t > b)
            return ans;
        int eaten = t / 2;
        ans += eaten;
        if(min_heap.empty())
            return ans;
        int t1 = min_heap.top();
        min_heap.pop();
        min_heap.push(t1 + (t - eaten));
    }
    return ans;
}
