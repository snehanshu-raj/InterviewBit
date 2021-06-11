int Solution::braces(string a) {
    int f = 1;
    
    stack <char> s;
    
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] == ')')
        {
            f = 1;
            
            char t = s.top();
            s.pop();
            
            while(t != '(')
            {
                if(t == '/' || t == '*' || t == '+' || t == '-')
                    f = 0;
                
                t = s.top();
                s.pop();
            }
            
            if(f == 1)
                return 1;
        }
        else
            s.push(a[i]);
    }
return 0;
}
