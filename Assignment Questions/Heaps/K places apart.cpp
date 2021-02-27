vector<int> Solution::solve(vector<int> &a, int b) {
    
    priority_queue <int, vector <int>, greater <int> > min_heap;
    
    vector <int> ans;
    int i;
    
    for(i = 0; i <= b; i++)
        min_heap.push(a[i]);
    
    while(1)
    {
        int t = min_heap.top();
        ans.push_back(t);
        min_heap.pop();
        if(ans.size() == a.size())
            break;
            
        if(i < a.size())
        {
            min_heap.push(a[i]);
            i++;
        }
    }
    return ans;
}
