int Solution::maxProduct(const vector<int> &a) {
    
    int max_val = a[0];
    int min_val = a[0];
    int p = a[0];
    
    int i;
    for(i = 1; i < a.size(); i++)
    {
        if(a[i] < 0)
            swap(max_val, min_val);
        
        max_val = max( a[i], max_val * a[i] );
        min_val = min( a[i], min_val * a[i] );
    
        p = max(p, max_val);
    }

    return p;    
}
