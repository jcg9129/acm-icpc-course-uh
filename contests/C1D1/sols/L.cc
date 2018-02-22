#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int solve(const vector<vector<int>> &ps)
{
	const int n = ps.size();
	vector<int> mn(4), mx(4);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i)
		{
			vector<int> p = ps[i];
			rotate(p.begin(), next(p.begin()), p.end());
			for (int m = 0; m < 4; ++m)
			{
				int d = p[0];
				for (int bit : {0, 1})
					if (m >> bit & 1) d += p[bit + 1];
					else d -= p[bit + 1];
				ans = max({ans, d - mn[m], mx[m] - d});
			}
		}
		const vector<int> &p = ps[i];
		for (int m = 0; m < 4; ++m)
		{
			int d = p[0];
			for (int bit : {0, 1})
				if (m >> bit & 1) d += p[bit + 1];
				else d -= p[bit + 1];
			if (i == 0) mn[m] = mx[m] = d;
			else mn[m] = min(mn[m], d), mx[m] = max(mx[m], d);
		}
	}
	return ans;
}

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

	vector<vector<int>> ps;
	for (int i = 0; i < n; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		ps.push_back({x, y, z});
	}

	int a = solve(ps);
	reverse(ps.begin(), ps.end());
	int b = solve(ps);

	cout << max(a, b) << endl;

	return 0;
}