int Solution::solve(vector <int> &a) {
    
    long long left = 0, right = 0, prev_right = -1;
    int i, mod = 1e9+7;
    map <int, int> refer;
    
    long long ans = 0;
    while(right < a.size())
    {
        if(refer[ a[right] ] == 0)
        {
            refer[ a[right] ] = 1;
            right++;
        }
        else
        {
            ans += ((right - left) * (right - left + 1) / 2);
        
            if(prev_right != -1)
                ans -= ((prev_right - left) * (prev_right - left + 1) / 2);   
            
            prev_right = right;
            
            while(refer[ a[right] ] == 1)
            {
                refer[ a[left++] ] = 0;
            }
        }
    }
    
    ans += ((right - left) * (right - left + 1) / 2);
        
    if(prev_right != -1)
        ans -= ((prev_right - left) * (prev_right - left + 1) / 2);   
        
    return ans % mod;
}
