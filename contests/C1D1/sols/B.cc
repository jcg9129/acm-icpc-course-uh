#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;

struct segment_tree
{
	int N;
	vector<ll> data, lazy;

	segment_tree(int n) : N(n), data(4 * N), lazy(4 * N) {}

	void update(int bb, int ee, ll val) { update(1, 0, N, bb, ee, val); }

	ll query(int bb, int ee) { return query(1, 0, N, bb, ee); }

private:
	void apply(int p, int b, int e, ll val)
	{
		data[p] += (e - b) * val;
		lazy[p] += val;
	}

	void pushdown(int p, int b, int e)
	{
		if (!lazy[p]) return;
		apply(2 * p, b, (b + e) / 2, lazy[p]);
		apply(2 * p + 1, (b + e) / 2, e, lazy[p]);
		lazy[p] = 0;
	}

	void update(int p, int b, int e, int bb, int ee, ll val)
	{
		if (bb <= b && e <= ee) apply(p, b, e, val);
		else
		{
			int m = (b + e) / 2;
			pushdown(p, b, e);
			if (bb < m) update(2 * p, b, m, bb, ee, val);
			if (m < ee) update(2 * p + 1, m, e, bb, ee, val);
			data[p] = data[2 * p] + data[2 * p + 1];
		}
	}

	ll query(int p, int b, int e, int bb, int ee)
	{
		if (bb <= b && e <= ee) return data[p];
		ll ans = 0;
		int m = (b + e) / 2;
		pushdown(p, b, e);
		if (bb < m) ans += query(2 * p, b, m, bb, ee);
		if (m < ee) ans += query(2 * p + 1, m, e, bb, ee);
		return ans;
	}
};

int main()
{
#ifdef jcg
	assert(freopen("input.in", "r", stdin));
	// assert(freopen("output.out", "w", stdout));
#else
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	segment_tree tree(n);

	while (q--)
	{
		int type, s, t, x;
		cin >> type >> s >> t;

		if (type == 1) cout << tree.query(s - 1, t) << endl;
		else
		{
			cin >> x;
			tree.update(s - 1, t, x);
		}
	}

	return 0;
}