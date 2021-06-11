int Solution::solve(vector<int> &a, int b) {
    
    int i = 0, j = a.size() - 1;
    long long ans = 0;
    
    // this
    
    // while(i <= j)
    // {
    //     if(1L * a[i] * a[j] < b)
    //     {
    //         ans += (1 + 2 * (j - i)) % 1000000007;
    //         i++;
    //     }
    //     else
    //         j--;
    // }
    
    //or this both gives right answer
    
    while(i < a.size() && j >= 0)
    {
        if(1L * a[i] * a[j] < b)
        {
            ans += (j + 1) % 1000000007;
            i++;
        }
        else
            j--;
    }
    
    return ans % 1000000007;
}