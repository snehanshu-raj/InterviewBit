int Solution::solve(int a, int b, vector<int> &c) {
    stack <int> s;
    
    int i;
    s.push(b);
    for(i = 0; i < a; i++)
    {
        if(c[i] > 0)
            s.push(c[i]);
        else
            s.pop();
    }
    return s.top();
}
