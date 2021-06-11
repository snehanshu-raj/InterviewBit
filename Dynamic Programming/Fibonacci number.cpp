#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll f[45];

ll fibo(ll n)
{
    if(n <= 1)
    {
        f[n] = n;
        return n;
    }
    
    if(f[n] != 0)
        return f[n];
    
    f[n] = fibo(n - 1) + fibo(n - 2);
    return f[n];
}

int main()
{
    ll n;
    cin >> n;
    
    cout << fibo(n);
return 0;
}