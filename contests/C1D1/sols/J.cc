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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> g(n);
	vector<int> indeg(n);

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[--b].emplace_back(--a);
		++indeg[a];
	}

	priority_queue<int> pq;;
	for (int u = 0; u < n; ++u)
		if (!indeg[u]) pq.emplace(u);

	vector<int> ord;
	while (!pq.empty())
	{
		int u = pq.top(); pq.pop();
		for (int v : g[u])
			if (!--indeg[v]) pq.emplace(v);
		ord.emplace_back(u);
	}
	assert(ord.size() == n);

	reverse(ord.begin(), ord.end());
	for (int i = 0; i < n; ++i)
		cout << ord[i] + 1 << " \n"[i + 1 == n];

	return 0;
}