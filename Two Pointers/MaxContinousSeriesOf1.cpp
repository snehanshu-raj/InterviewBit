vector<int> Solution::maxone(vector<int> &a, int b) {
    
    int count = 0, i, j;
    int left = 0, right = 0;
    int max_len = -1;
    
    while(right < a.size())
    {
        if(count <= b)
        {
            if(a[right] == 0)
                count++;
            right++;
        }
        
        if(count > b)
        {
            if(a[left] == 0)
                count--;
            left++;
        }
        
        if(right - left + 1 > max_len)
        {
            max_len = right - left + 1;
            i = left;
            j = right;
        }
    }
    
    vector <int> ans;
    for(int k = i; k < j; k++)
        ans.push_back(k);
    return ans;
}
