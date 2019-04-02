#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

// O(nW log W)
int slow_bounded_knapsack(int W, vector<int> v, vector<int> w, vector<int> m)
{
	const int n = v.size();
	vector<int> dp(W + 1);
	for (int i = 0; i < n; ++i)
	{
		int mi = min(m[i], W / w[i]);
		if (mi == 0 || w[i] > W) continue;
		auto update = [&](int wi, int vi)
		{
			for (int k = W; k >= wi; --k)
				dp[k] = max(dp[k], dp[k - wi] + vi);
		};
		for (int k = 1; k < mi; k *= 2)
		{
			update(w[i] * k, v[i] * k);
			mi -= k;
		}
		update(w[i] * mi, v[i] * mi);
	}
	return dp[W];
}

// O(nW)
int bounded_knapsack(int W, vector<int> v, vector<int> w, vector<int> m)
{
	const int n = v.size();
	vector<int> dp(W + 1);
	for (int i = 0; i < n; ++i)
	{
		int mi = min(m[i], W / w[i]);
		if (mi == 0 || w[i] > W) continue;
		vector<int> newdp = dp;
		for (int s = 0; s < w[i]; ++s)
		{
			deque<int> deq;
			auto cost = [&](int pos) { return dp[pos] - pos / w[i] * v[i]; };
			for (int wi = s; wi <= W; wi += w[i])
			{
				while (!deq.empty() && cost(deq.back()) < cost(wi))
					deq.pop_back();
				while (!deq.empty() && deq.front() < wi - mi * w[i])
					deq.pop_front();
				deq.emplace_back(wi);
				newdp[wi] = cost(deq.front()) + wi / w[i] * v[i];
			}
		}
		dp = newdp;
	}
	return dp[W];
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

	int N, W;
	cin >> N >> W;

	vector<int> v(N), w(N), m(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i] >> w[i] >> m[i];

	cout << slow_bounded_knapsack(W, v, w, m) << endl;

	return 0;
}