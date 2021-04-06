#define ll long long

int Solution::sqrt(int a) {
    
    // TLE 
    // int j;
    // for(int i = 1; i * i <= a; i++)
    // {
    //     j = i;
    //     if(i * i == a)
    //         return i;
    // }
    // return j;
    
    // use binary search
    
    if(a <= 1)
        return a;
    
    ll int s, e, m, t;
    s = 1, e = a;
    
    while(s <= e)
    {
        m = (s + e) / 2;
        
        ll int p = m * m;
        
        if(p == a)
            return m;
        
        if(p < a)
        {
            s = m + 1;
            t = m;
        }
        else
            e = m - 1;
    }
    
    return t;
}
