int Solution::solve(vector<int> &a) {
    priority_queue <int, vector <int>, greater <int> > min_heap;
    
    int i, sum = 0;
    
    for(i = 0; i < a.size(); i++)
        min_heap.push(a[i]);
    
    while(1)
    {
        if(min_heap.size() == 1)
            break;
            
        int a, b;
        a = min_heap.top();
        min_heap.pop();
        b = min_heap.top();
        min_heap.pop();
        
        sum += a + b;
        
        min_heap.push(a + b);
    }
return sum;
}
