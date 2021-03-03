int Solution::solve(int A) {
    int ans=0;
    while (A>0)
    {
        ans += (A%5);
        A /= 5;
    }
    return ans;
}

int Solution::solve(int a) {
    
    int i, ans = 0;
    vector <long long> coins;
    
    for(i = 0; ; i++)
    {
        if(pow(5, i) == a)
            return 1;
        else
        if(pow(5, i) < a)
            coins.push_back(pow(5, i));
        else
            break;
    }
    
    for(i = coins.size() - 1; i >= 0; i--)
    {
        if(a == 0)
            return ans;
        
        ans += a / coins[i];
        a = a % coins[i];
    }
    
    return ans;
}
