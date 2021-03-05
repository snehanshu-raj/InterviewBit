vector<int> Solution::subUnsort(vector<int> &a) {
    
    vector <int> ans;
    
    if(is_sorted(a.begin(), a.end()))
    {
        ans.push_back(-1);
        return ans;
    }
    else
    {
        int i, j, start, end, n = a.size();
        for(i = 1; i < n; i++)
        {
            if(a[i] < a[i - 1])
            {
                start = i - 1;
                break;
            }
        }
        
        for(i = n - 2; i >= 0; i--)
        {
            if(a[i] > a[i + 1])
            {
                end = i + 1;
                break;
            }
        }
        
        sort(a.begin() + start, a.begin() + end + 1);
        
        for(i = 0; i < start; i++)
        {
            if(a[i] > a[start])
            {
                start = i;
                break;
            }
        }
        
        for(i = n - 1; i > end; i--)
        {
            if(a[i] < a[end])
            {
                end = i;
                break;
            }
        }
        
        ans.push_back(start);
        ans.push_back(end);
        
        return ans;
    }
}
