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

	int N, T;
	cin >> N >> T;

	vector<pair<int, int>> events;
	
	for (int i = 0; i < N; ++i)
	{
		int l, r;
		cin >> l >> r;
		events.emplace_back(l, +1);
		events.emplace_back(r, -1);
	}

	sort(events.begin(), events.end());

	int ans = 0, in = 0;
	for (auto e : events)
		ans = max(ans, in += e.second);

	cout << ans << endl;

	return 0;
}