#include<bits/stdc++.h>
using namespace std;

int max_sum_top_down(vector < vector <int> > mat)
{
	int rows = mat.size();
	int cols = mat[0].size();
	
	int r, c;
	for(r = 1; r < rows; r++)
	{
		for(c = 0; c < cols; c++)
		{
			if(c > 0 and c < cols - 1)
				mat[r][c] += max(mat[r - 1][c], max(mat[r - 1][c - 1], mat[r - 1][c +  1]));
			else
			if(c > 0)
				mat[r][c] += max(mat[r - 1][c], mat[r - 1][c - 1]);
			else
				mat[r][c] += max(mat[r - 1][c], mat[r - 1][c + 1]);
		}
	}
	
	int ans = INT_MIN;
	for(c = 0; c < cols; c++)
	{
		ans = max(ans, mat[rows - 1][c]);
	}
	
	return ans;
}

int max_sum_left_right(vector < vector <int> > mat)
{
	int rows = mat.size();
	int cols = mat[0].size();
	
	int r, c;
	for(r = 0; r < rows; r++)
	{
		for(c = 1; c < cols; c++)
		{
			if(r > 0 and r < rows - 1)
				mat[r][c] += max(mat[r - 1][c - 1], max(mat[r][c - 1], mat[r + 1][c - 1]));
			else
			if(r > 0)
				mat[r][c] += max(mat[r][c - 1], mat[r - 1][c - 1]);
			else
				mat[r][c] += max(mat[r][c - 1], mat[r + 1][c - 1]);
		}
	}
	
	int ans = INT_MIN;
	for(r = 0; r < rows; r++)
	{
		ans = max(ans, mat[r][cols - 1]);
	}
	
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector < vector <int> > mat(n, vector <int> (n));
	
	int i, j;
	for (i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cin >> mat[i][j];
	}
	
	cout << max_sum_top_down(mat) << endl;
	cout << max_sum_left_right(mat) << endl;

	for (i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			cout << mat[i][j];
		cout << endl;
	}
return 0;
}