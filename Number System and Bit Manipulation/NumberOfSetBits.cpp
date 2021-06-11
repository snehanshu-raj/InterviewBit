int Solution::numSetBits(int a) {
    
    // gives correct answer
    //return __builtin_popcount(a);
    
    int ans = 0;
    
    while(a)
    {
        ans += (a & 1);
        a >>= 1;
    }
    
    return ans;
}
