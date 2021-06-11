vector<int> Solution::solve(vector<int> &a) {
    
    vector <int> ans;
    int i;
    
    // for(i = 0; i < a.size(); i++)
    // {
    //     priority_queue <int> max_heap(a.begin(), a.begin() + i + 1);
    //     if(max_heap.size() < 3)
    //         ans.push_back(-1);
    //     else
    //     {
    //         int m1 = max_heap.top();
    //         max_heap.pop();
    //         int m2 = max_heap.top();
    //         max_heap.pop();
    //         int m3 = max_heap.top();
    //         max_heap.pop();
    //         ans.push_back(m1 * m2 * m3);
    //     }
    // }
    
    priority_queue <int, vector <int>, greater <int> > min_heap(a.begin(), a.begin() + 3);
    
    ans.push_back(-1);
    ans.push_back(-1);
    int p = a[0] * a[1] * a[2];
    ans.push_back(p);
    for(i = 3; i < a.size(); i++)
    {
        if(min_heap.top() < a[i])
        {
            p = p / min_heap.top();
            min_heap.pop();
            min_heap.push(a[i]);
            p = p * a[i];
            ans.push_back(p);
        }
        else
            ans.push_back(p);
    }
return ans;
}
