#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = { 2, 5, 1, 3, 10, 11, 15, 16, 17, 12, 13};
    unordered_set <int> s;

    int i, ans = 0;
    for(i = 0; i < 11; i++)
        s.insert(a[i]);
    
    int c = 0;

    for(i = 0; i < 11; i++)
    {
        if(s.count(a[i] - 1) > 0)
            continue;
        else
        {
            c = 0;
            int start = a[i];
            while(s.count(start++) > 0)
            {
                c++;
            }
            ans = max(ans, c);
        }
    }
    cout << ans;
return 0;
}