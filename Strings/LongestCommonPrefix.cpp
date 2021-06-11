string Solution::longestCommonPrefix(vector<string> &a) {
    string ans = "";
    int i, c = 0;
    
    for(i = 0; i < a[0].size(); i++)
    {
        int f = 0;
        for(int j = 1; j < a.size(); j++)
        {
            if(a[j][i] == a[0][i])  
                c++;
        }
        if(c == a.size() - 1)
        {
            ans += a[0][i];
            f = 1;
            c = 0;
        }
        if(f == 0)
            return ans;
    }
return ans;
}
