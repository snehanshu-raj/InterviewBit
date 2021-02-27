vector<int> Solution::solve(vector<int> &a) {
    
    priority_queue <int> max_heap;
    priority_queue <int, vector <int>, greater <int> > min_heap;
    vector <int> ans;
    
    int i;
    int m = a[0];
    max_heap.push(m);
    ans.push_back(m);
    
    for(i = 1; i < a.size(); i++)
    {
        int t = a[i];
        
        if(max_heap.size() > min_heap.size())
        {
            if(t < m)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(t);
            }
            else
                min_heap.push(t);
            
            m = max_heap.size() > min_heap.size() ? min_heap.top() : max_heap.top();
        }
        else
        if(max_heap.size() == min_heap.size())
        {
            if(t < m)
            {
                max_heap.push(t);
                m = max_heap.top();
            }
            else
            {
                min_heap.push(t);
                m = min_heap.top();
            }
        }
        else
        {
            if(t > m)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(t);
            }
            else
                max_heap.push(t);
                
            m = max_heap.size() > min_heap.size() ? min_heap.top() : max_heap.top();
        }
        ans.push_back(m);
    }
    return ans;
}
