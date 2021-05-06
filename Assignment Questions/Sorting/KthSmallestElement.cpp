int Solution::kthsmallest(const vector<int> &a, int k) {
    
    vector <int> b = a;
    // sort(b.begin(), b.end());
    
    // return b[k - 1];
    
    int n = a.size(), i;
    
    for(i = 0; i < k; i++)
    {
        int p = i;
        
        for(int j = i + 1; j < n; j++)
        {
            if(b[j] < b[i])
                swap(b[j], b[i]);
        }
    }
    return b[k - 1];
}
