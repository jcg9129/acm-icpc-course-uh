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

	int H, W;
	cin >> H >> W;

	vector<int> a(W), l(W), r(W);
	int area = 0;

	for (int row = 0; row < H; ++row)
	{
		for (int i = 0; i < W; ++i)
		{
			int v;
			cin >> v;

			if (v == 0) ++a[i];
			else a[i] = 0;
		}

		for (int i = 0; i < W; ++i)
			for (l[i] = i - 1; l[i] >= 0 && a[i] <= a[l[i]]; l[i] = l[l[i]]);
		for (int i = W - 1; i >= 0; --i)
			for (r[i] = i + 1; r[i] < W && a[i] <= a[r[i]]; r[i] = r[r[i]]);

		for (int i = 0; i < W; ++i)
			area = max(area, a[i] * (r[i] - l[i] - 1));
	}

	cout << area << endl;

	return 0;
}