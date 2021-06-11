int Solution::nchoc(int a, vector<int> &b) {
    
    priority_queue <long long> max_heap (b.begin(), b.end());
    
    int i;
    long long ans = 0;
    
    for(i = 0; i < a; i++)
    {
        long long t = max_heap.top();
        ans = (ans + t) % 1000000007;
        max_heap.pop();
        max_heap.push(t / 2);
    }
return ans % 1000000007;
}
