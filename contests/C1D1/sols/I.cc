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

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		
		vector<pair<int, int>> xs(n);

		for (auto &x : xs)
			cin >> x.first;
		for (auto &x : xs)
			cin >> x.second;

		sort(xs.begin(), xs.end());

		vector<int> ends;
		for (auto p : xs)
			if (ends.empty() || ends.back() <= p.second)
				ends.emplace_back(p.second);
			else *upper_bound(ends.begin(), ends.end(), p.second) = p.second;

		cout << ends.size() << endl;
	}

	return 0;
}