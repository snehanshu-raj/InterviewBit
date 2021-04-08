bool check(vector <int> &c, int a, long long max_time)
{
    long long sum_time = 0;
    if(a < 0)
        return false;
    
    int i;
    for(i = 0; i < c.size(); i++)
    {
        if(c[i] > max_time)
            return false;
        if(sum_time + c[i] > max_time)
        {
            a--;
            sum_time =c[i];
            if(a == 0)
                return false;
        }
        else
            sum_time += c[i];
    }
return true;
}

int Solution::paint(int a, int b, vector <int> &c) {
    
    long long min_time = *max_element(c.begin(), c.end());
    long long max_time = 0;
    
    long long i;
    for(i = 0; i < c.size(); i++)
        max_time += c[i];
    
    long long minimum = max_time;
    
    while(min_time <= max_time)
    {
        long long mid_time = (min_time + max_time) / 2;
        
        if(check(c, a, mid_time))
        {
            max_time = mid_time - 1;
            minimum = mid_time;
        }
        else
            min_time = mid_time + 1;
    }
    return (minimum * b) % 10000003;
}
