int Solution::maxArea(vector<int> &a) {
    
    if(a.size() == 1)
        return 0;
    
    int i = 0, j = a.size() - 1;
    
    int ans = 0;
    
    while(i < j)
    {
        ans = max(ans, min(a[i], a[j]) * (j - i));
        
        if(a[i] < a[j])
            i++;
        else
            j--;
    }
    
    return ans;
}
