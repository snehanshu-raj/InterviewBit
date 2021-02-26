int Solution::solve(vector<int> &a, int b) {
    
    priority_queue <int, vector <int>, greater <int> > min_heap(a.begin(), a.end());
    
    int i, sum = 0, c = b;
    
    while(1)
    {
        int t = min_heap.top();
        min_heap.pop();
        if(t > 0)
        {
            if(c % 2 == 0)
                min_heap.push(t);
            else
                min_heap.push(t * (-1));
            break;
        }
        else
        {
            c--;
            min_heap.push(t * (-1));
            if(c == 0)
                break;
        }
    }
    
    while(!min_heap.empty())
    {
        sum += min_heap.top();
        min_heap.pop();
    }
return sum;
}
