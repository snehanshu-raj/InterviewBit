int helper(string a, string b)
{
    string ab = a.append(b);
    string ba = b.append(a);
    
    return ab.compare(ba) > 0 ? 1 : 0;
}

string Solution::largestNumber(const vector<int> &a) {
    
    vector <string> b;
    
    int i, n = a.size();
    
    for(i = 0; i < n; i++)
        b.push_back(to_string(a[i]));
    
    sort(b.begin(), b.end(), helper);
    
    string ans = "";
    
    for(i = 0; i < n; i++)
        ans += b[i];
    
    int f = 0;
    for(i = 0; i < ans.length(); i++)
    {
        if(ans[i] != '0')
        {
            f = 1;
            break;
        }
    }
    if(f)
        return ans;
    return "0";
}
