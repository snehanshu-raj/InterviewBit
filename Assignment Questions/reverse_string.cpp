string Solution::solve(string a) {
    vector <string> s;
    int i = 0, c = 0;
    
    string temp = "";
    for(i = 0; i < a.length(); i++)
    {
        if(isspace(a[i]))
        {
            if(c == 0)
            {
                c = 1;
                if(temp != "")
                    s.push_back(temp);
                temp = "";
            }
        }
        else
        {
            c = 0;
            temp += a[i];
        }
    }
    
    if(temp != "")
        s.push_back(temp);
    
    reverse(s.begin(), s.end());
    string ans = "";
    
    for(i = 0; i < s.size() - 1; i++)
    {
        ans += s[i];
        ans += " ";
    }
    ans += s[ s.size() - 1 ];
return ans;
}
