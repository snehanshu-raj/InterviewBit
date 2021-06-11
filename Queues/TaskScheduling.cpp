int Solution::solve(vector<int> &a, vector<int> &b) {
    
    int ans = 0;
    deque <int> q;
    
    int i;
    for(i = 0; i < a.size(); i++)
    {
        q.push_back(a[i]);
    }
    
    for(i = 0; i < b.size(); i++)
    {
        int cur = b[i];
        if(q.front() == cur)
        {
            ans++;
            q.pop_front();
        }
        else
        {
            while(1)
            {
                q.push_back(q.front());
                ans++;
                q.pop_front();
                
                if(q.front() == cur)
                {
                    ans++;
                    q.pop_front();
                    break;
                }
            }
        }
    }
    
    return ans;
}
