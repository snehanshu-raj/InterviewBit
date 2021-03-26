void all_subsequence(int sum, vector <int> &a, int i, int size, int b, int &ans)
{
    if(i == a.size())
    {
        if(sum <= 1000 && size == b)
            ans++;
        return;
    }
    
    all_subsequence(sum, a, i + 1, size, b, ans);
    
    sum += a[i];
    size++;
    
    all_subsequence(sum, a, i + 1, size, b, ans);
}

int Solution::solve(vector<int> &a, int b) {

    int ans = 0;
    all_subsequence(0, a, 0, 0, b, ans);
    
    return ans;
}
