int Solution::solve(vector<int> &a) {
    
    sort(a.begin(), a.end());
    
    for(int i = 1; i < a.size(); i++)
    {
        if(a[i] - a[i - 1] > 1)
            return 0;
    }
return 1;
}
