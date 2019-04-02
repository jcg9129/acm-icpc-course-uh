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

	for (int n; cin >> n;)
	{
		using point = complex<double>;
		vector<point> ps;

		for (int i = 0; i < n; ++i)
		{
			double x, y;
			cin >> x >> y;
			ps.emplace_back(x, y);
		}

		vector<vector<double>> dp(n, vector<double>(n));
		for (int i = 1; i < n; ++i)
			dp[0][i] = dp[0][i - 1] + abs(ps[i] - ps[i - 1]);
		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
			{
				if (j == i + 1)
				{
					dp[i][j] = numeric_limits<double>::max();
					for (int k = 0; k < i; ++k)
						dp[i][j] = min(dp[i][j], dp[k][i] + abs(ps[j] - ps[k]));
				}
				else dp[i][j] = dp[i][j - 1] + abs(ps[j] - ps[j - 1]);
			}

		cout << fixed << setprecision(2) << dp[n - 2][n - 1] + abs(ps[n - 1] - ps[n - 2]) << endl;
	}

	return 0;
}