int Solution::LBSlength(const string s) {
    
    int n = s.length();
    int longest[n];
    
    
    int i, ans = 0;
    for(i = 0; i < n; i++)
        longest[i] = 0;
        
    if(n < 2)
        return 0;
    
    for(i = 1; i < n; i++)
    {
        if(s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            if((s[i - 1] == '[' && s[i] == ']') || (s[i - 1] == '{' && s[i] == '}') || (s[i - 1] == '(' && s[i] == ')'))
            {
                if(i - 2 >= 0)
                    longest[i] = longest[i - 2] + 2;
                else
                    longest[i] = 2;
                
                ans = max(ans, longest[i]);
            }
            else
            if((i - longest[i - 1] - 1 >= 0) && (
                (s[i] == '}' && s[i - longest[i - 1] - 1] == '{') || 
                (s[i] == ']' && s[i - longest[i - 1] - 1] == '[') || 
                (s[i] == ')' && s[i - longest[i - 1] - 1] == '(')
                ))
                {
                    longest[i] = longest[i - 1] + 2;
                    if(i - longest[i - 1] - 2 >= 0)
                    {
                        longest[i] += longest[i - longest[i - 1] - 2];
                    }
                    
                    ans = max(ans, longest[i]);
                }
        }
    }
 
    return ans;
}
