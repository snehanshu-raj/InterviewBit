int steps[37];

int ways(int n)
{
    if(n <= 2 || steps[n] != 0)
        return steps[n];
    
    steps[n] = ways(n - 1) + ways(n - 2);
    return steps[n];
}

int Solution::climbStairs(int n) {
    steps[0] = 1;
    steps[1] = 1;
    steps[2] = 2;
    return ways(n);

}
