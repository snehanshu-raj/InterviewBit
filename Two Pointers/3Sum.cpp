int Solution::threeSumClosest(vector<int> &a, int b) {
    int i = 0, ans;
    
    sort(a.begin(), a.end());
    int diff = INT_MAX;
    
    while(i < a.size() - 2)
    {
        int left = i + 1, right = a.size() - 1;
        
        while(left < right)
        {
            int temp_sum = a[i] + a[left] + a[right];
            int temp_diff = abs(temp_sum - b);
            
            if(temp_diff == 0)
                return temp_sum;
               
            if(temp_diff < diff)
            {
                diff = temp_diff;
                ans = temp_sum;
            }
            if(temp_sum > b)
                right--;
            else
                left++;
        }
        i++;
    }
return ans;
}
