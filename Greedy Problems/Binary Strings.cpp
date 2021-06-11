int Solution::solve(string a, int b) {
    
    // int i, j, ans = 0;
    // for(i = 0; i <= a.length() - b; i++)
    // {
    //     if(a[i] == '0')
    //     {
    //         if(i + b <= a.length())
    //         {
    //             ans++;
    //             for(j = i; j < i + b; j++)
    //             {
    //                 if(a[j] == '0')
    //                     a[j] = '1';
    //                 else
    //                 {
    //                     a[j] = '0';
    //                 }
    //             }
    //         }
    //     }
    // }
    
    // for(i = 0; i < a.length(); i++)
    //     if(a[i] == '0')
    //         return -1;
        
    // return ans;
    
    //gives TLE
    
    int n = a.length();
    vector <int> refer(n);
    int x = 0;
    int ans = 0, i;
    
    for(i = 0; i <= n - b; i++)
    {
        x = x ^ refer[i];
        if((a[i] == '0' && x == 0) || (a[i] == '1' && x == 1))
        {
            ans++;
            if(i + b < n)
                refer[i + b] = 1;
            x = !x;
        }
    }
    
    while(i < n)
    {
        x = x ^ refer[i];
        int t = a[i] - '0';
        if(t ^ x == 0)
            return -1;
        i++;
    }
    return ans;
}
