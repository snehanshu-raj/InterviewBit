vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
    
    vector <int> ans;
    int cur_left = 0;
    int cur_right = b.size() - 1;
    int ans_left, ans_right;
    int diff = INT_MAX;
    
    while(cur_left < a.size() && cur_right >= 0)
    {
        if( abs(a[cur_left] + b[cur_right] - c) < diff )
        {
            diff = abs(a[cur_left] + b[cur_right] - c);
            ans_left = cur_left;
            ans_right = cur_right;
        }
        else
        if( abs(a[cur_left] + b[cur_right] - c) == diff )
        {
            if(cur_left < ans_left)
            {
                ans_left = cur_left;
                ans_right = cur_right;
                diff = abs(a[cur_left] + b[cur_right] - c);
            }
            else
            if(cur_left == ans_left)
            {
                if(cur_right < ans_right)
                {
                    ans_right = cur_right;
                    ans_left = cur_left;
                    diff = abs(a[cur_left] + b[cur_right] - c);
                }
            }
        }
        
        if(a[cur_left] + b[cur_right] > c)
            cur_right--;
        else
            cur_left++;
    }
    
    ans.push_back(a[ans_left]);
    ans.push_back(b[ans_right]);
    return ans;
}
