int Solution::solve(vector<int> &a) {
    sort(a.begin(), a.end());
    
    int mini = INT_MAX;
    for(int i = 1; i < a.size(); i++)
    {
        mini = min(mini, a[i] - a[i - 1]);
    }
return mini;
}
