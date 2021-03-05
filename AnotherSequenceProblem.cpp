int Solution::solve(int a) {
    
    if(a <= 1)
        return 1;
    if(a == 2)
        return 2;
    
    return solve(a - 1) + solve(a - 2) + solve(a - 3) + a;

}
