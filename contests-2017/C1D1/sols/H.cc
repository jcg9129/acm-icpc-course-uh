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

	int V, E;
	cin >> V >> E;

	const int oo = 0x3f3f3f3f;

	vector<int> deg(V);
	vector<vector<int>> d(V, vector<int>(V, oo));

	for (int u = 0; u < V; ++u)
		d[u][u] = 0;

	int total_cost = 0;
	for (int i = 0; i < E; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		if (d[u][v] > w)
			d[u][v] = d[v][u] = w;
		++deg[u];
		++deg[v];
		total_cost += w;
	}

	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	vector<int> odd;
	for (int u = 0; u < V; ++u)
		if (deg[u] & 1) odd.emplace_back(u);

	int n = odd.size();
	vector<vector<int>> cost(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cost[i][j] = d[odd[i]][odd[j]];

	vector<int> dp(1 << n, -1);
	function<int(int)> rec = [&](int mask)
	{
		if (mask == 0) return 0;
		if (dp[mask] == -1)
		{
			dp[mask] = oo;
			for (int u = 0; u < n; ++u) if (mask >> u & 1)
				for (int v = u + 1; v < n; ++v) if (mask >> v & 1)
					dp[mask] = min(dp[mask], rec(mask ^ (1 << u) ^ (1 << v)) + cost[u][v]);
		}
		return dp[mask];
	};

	cout << total_cost + rec((1 << n) - 1) << endl;

	return 0;
}