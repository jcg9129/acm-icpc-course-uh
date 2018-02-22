#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main()
{
#ifdef jcg
	assert(freopen("input.in", "r", stdin));
	// assert(freopen("output.out", "w", stdout));
#else
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> r(n), c(n);
	for (int i = 0; i < n; ++i)
		cin >> r[i] >> c[i];

	vector<vector<int>> dp(n, vector<int>(n));
	for (int l = 2; l <= n; ++l)
		for (int i = 0; i + l <= n; ++i)
		{
			int end = i + l - 1;
			dp[i][end] = numeric_limits<int>::max();
			for (int j = i; j < end; ++j)
				dp[i][end] = min(dp[i][end], dp[i][j] + dp[j + 1][end] + r[i] * c[j] * c[end]);
		}

	cout << dp[0][n - 1] << endl;

	return 0;
}