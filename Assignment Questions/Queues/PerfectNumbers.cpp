string Solution::solve(int a) {

    string s[100005];
    s[1] = "1";
    s[2] = "2";
    
    queue <string> q;
    q.push(s[1]);
    q.push(s[2]);
    
    int i = 3;
    while(i <= a + 2)
    {
        string ts = q.front();
        q.pop();
        
        s[i++] = ts + "1";
        q.push(ts + "1");
        s[i++] = ts + "2";
        q.push(ts + "2");
    }
    
    string s1 = s[a];
    string s2 = s1;
    reverse(s1.begin(), s1.end());
    
    return s2 + s1;
}
