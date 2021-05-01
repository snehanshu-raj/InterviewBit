int Solution::minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    
    int i, j, k;
    i = j = k = 0;
    
    int a1 = abs(a[i] - b[j]);
    int b1 = abs(b[j] - c[k]);
    int c1 = abs(c[k] - a[i]);
    int temp = max(a1, b1);
    int ans = max(c1, temp);
    
    while(i < a.size() && j < b.size() && k < c.size())
    {
        int t = min(a[i], b[j]);
        t = min(t, c[k]);
        if(a[i] == t)
            i++;
        else
        if(b[j] == t)
            j++;
        else
        if(c[k] == t)
            k++;
        else
            break;
        
        a1 = abs(a[i] - b[j]);
        b1 = abs(b[j] - c[k]);
        c1 = abs(c[k] - a[i]);
        temp = max(a1, b1);
        int temp2 = max(c1, temp);
       
        ans = min(ans, temp2);
    }
    
    return ans;
}
