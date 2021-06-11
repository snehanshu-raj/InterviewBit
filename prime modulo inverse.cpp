#define ll long long

int power(int a, ll b, ll m)
{
    if(b == 0)
        return 1;
    ll p = power(a, b / 2, m) % m;
    p = (p * p) % m;
    
    if(b % 2 == 0)
        return p;
    return (a * p) % m;
}

void gcd(int a, int b, int *x, int *y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return;
    }
    int x1, y1;
    gcd(b % a, a, &x1, &y1);
    
    *x = y1 - (b / a) * x1;
    *y = x1;
}

int Solution::solve(int a, int b) {
    // int x, y;
    // gcd(a, b, &x, &y);
    
    // return (x % b + b) % b;
    
    return power(a, b - 2, b);
}


// for(int i = 1; i < a; i++)
    // {
    //     if( (a * i) % b == 1)
    //         return i;
    // }
