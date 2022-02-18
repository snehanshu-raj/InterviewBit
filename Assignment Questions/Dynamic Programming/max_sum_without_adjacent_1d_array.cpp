#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector <int> a(n);
	vector <int> dp(n, 0);
	
	int i;
	
	for(i = 0; i < n; i++)
		cin >> a[i];
	
	dp[0] = a[0];
	dp[1] = max(a[1], a[0]);
	
	for(i = 2; i < n; i++)
		dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
	
	cout << dp[n - 1] << endl;
return 0;
}