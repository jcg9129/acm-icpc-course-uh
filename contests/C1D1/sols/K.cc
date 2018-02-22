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

	vector<int> p(n);
	for (int i = 1; i < n; ++i)
		cin >> p[i], --p[i];

	vector<int> size(n, 1);
	for (int i = n - 1; i >= 1; --i)
		size[p[i]] += size[i];

	vector<int> count(n + 1);
	for (int i = 0; i < n; ++i)
		++count[size[i]];

	for (int i = 1; i <= n; ++i)
		for (int j = i + i; j <= n; j += i)
			count[i] += count[j];

	for (int i = n; i >= 1; --i)
		if (n % i == 0 && count[i] == n / i)
			cout << n / i << " \n"[i == 1];

	return 0;
}