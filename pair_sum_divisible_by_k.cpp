int Solution::solve(vector<int> &a, int b) {
    // long long count[b] = { 0 };
    // long long ans = 0, i;
    
    // for(i = 0; i < a.size(); i++)
    // {
    //     long long r = a[i] % b;
    //     ans += (count[ (b - r) % b ] % 1000000007);
        
    //     count[r]++;
    // }
    
    long long count[b];
    long long ans = 0, i;
    
    for(i = 0; i < b; i++)
        count[i] = 0;
        
    for(i = 0; i < a.size(); i++)
    {
        count[ a[i] % b ]++;
    }
    
    ans += count[0] * (count[0] - 1) / 2;
    
    for(i = 1; i <= b / 2 && i != b - i; i++)
        ans += count[i] * count[b - i];
        
    if(b % 2 == 0)
        ans += count[b / 2] * (count[b / 2] - 1) / 2;
        
return ans % 1000000007;
}
