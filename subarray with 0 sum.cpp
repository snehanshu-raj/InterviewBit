int Solution::solve(vector<int> &a) {
    unordered_set <long long> s;
    
    long long i, sum = 0;
    for(i = 0; i < a.size(); i++)
    {
        sum += a[i];
        
        if(sum == 0)
            return 1;
        
        if(s.count(sum) > 0)
            return 1;
            
        s.insert(sum);
    }
return 0;
}
