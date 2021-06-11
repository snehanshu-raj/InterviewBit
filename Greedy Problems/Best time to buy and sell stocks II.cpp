int Solution::maxProfit(const vector<int> &a) {
    
    int ans = 0;
    
    if(a.size() == 0 || a.size() == 1)
        return 0;
    
    for(int i = 0; i < a.size() - 1; i++)
    {
        int d = a[i + 1] - a[i];
        if(d > 0)
            ans += d;
    }
    
    return ans;
}
