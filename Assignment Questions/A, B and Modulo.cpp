int Solution::solve(int a, int b) {
    int maxi = max(a, b);
    int mini = min(a, b);
    
    for(int i = maxi; i >= 0; i -= mini)
    {
        if((a % i) == (b % i))
            return i;
    }
}
