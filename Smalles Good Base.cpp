string Solution::solve(string s) {
    
    unsigned long long num = stoull(s);
    for (int i = log2(num) + 1; i >= 2; i--) 
    {
        long long low = 2, high = pow(num, 1.0 / (i - 1)) + 1;
        while (low <= high) 
        {
            unsigned long long mid = (low + high) / 2, sum = 0;
            
            for (int j = 0; j < i; j++) 
            {
                sum = sum * mid + 1;
            }
            if (sum == num) 
                return to_string(mid);
            else 
            if (sum < num) 
                low = mid + 1;
            else 
                high = mid - 1;
        }
    }
    return to_string(num - 1);
}
