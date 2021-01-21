vector<int> Solution::solve(vector<int> &a, int b) {

//     handles negetive number also but gives TLE

//     map <long long, long long> m;
//     vector <int> ans;
    
//     long long i, j, s = 0;
    
//     for(i = 0; i < a.size(); i++)
//     {
//         s += a[i];
        
//         if(s == b)
//         {
//             for(int j = 0; j <= i; j++)
//                 ans.push_back(a[j]);
//             return ans;
//         }
        
//         if(m.find(s - b) != m.end())
//         {
//             for(int j = m[ s - b ] + 1; j <= i; j++)
//                 ans.push_back(a[j]);
//             return ans;
//         }
        
//         m[s] = i;
//     }
// ans.push_back(-1);
// return ans;

    int start = 0, current;
    long long sum = 0;
    
    vector <int> ans;
    
    for(current = 0; current < a.size(); current++)
    {
        sum += a[current];
        
        if(sum == b)
        {
            for(int i = start; i <= current; i++)
            {
                ans.push_back(a[i]);
            }
            return ans;
        }
        if(sum > b)
        {
            while(sum > b)
            {
                sum -= a[start++];
            }
            
            if(sum == b)
            {
                for(int i = start; i <= current; i++)
                {
                    ans.push_back(a[i]);
                }
                return ans;
            }
        }
    }
    ans.push_back(-1);
return ans;
}
