#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "[[{()}]]";
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
        {
            cout << endl << i - longest[i - 1] - 1 << " i - longest[i - 1] - 1 " << s[i] << " s[i] " << s[i - longest[i - 1] - 1] << " s[i - longest[i - 1] - 1] ";
            if((i - longest[i - 1] - 1 >= 0) && (
                (s[i] == '}' && s[i - longest[i - 1] - 1] == '{') || 
                (s[i] == ']' && s[i - longest[i - 1] - 1] == '[') || 
                (s[i] == ')' && s[i - longest[i - 1] - 1] == '(')
                ))
                {
                    cout << "here";
                    longest[i] = longest[i - 1] + 2;
                    if(i - longest[i - 1] - 2 >= 0)
                    {
                        longest[i] += longest[i - longest[i - 1] - 2];
                    }
                    
                    ans = max(ans, longest[i]);
                }
        }
        }
    }
    cout << endl << ans;
return 0;
}