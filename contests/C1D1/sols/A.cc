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

	int N, L;
	cin >> N >> L;
 
    vector<int> a(N), deq(N);
    int front = 0, back = -1;
 
    auto add = [&](int index)
    {
        while (front <= back && a[deq[back]] >= a[index])
            --back;
        deq[++back] = index;
    };
 
    auto remove = [&](int index)
    {
        while (front <= back && deq[front] <= index)
            ++front;
    };
 
    for (int i = 0; i < N; ++i)
    {
    	cin >> a[i];
        add(i);
        if (i >= L) remove(i - L);
        if (i >= L - 1) cout << a[deq[front]] << " \n"[i + 1 == N];
    }

	return 0;
}