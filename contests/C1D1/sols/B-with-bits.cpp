#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fenwick{
  vector<ll> f;
  int n;
  
  fenwick(ll n) : f(n), n(n) {}
  
  ll query(ll p)
  {
    ll s = 0;
    for(; p > 0; p -= (p & -p))
      s += f[p];
    return s;
  }
  
  void update(ll p, ll v)
  {
    for(; p < n; p += (p & -p))
      f[p] += v;
  }
};

int main()
{
  int n, q;
  cin >> n >> q;
  
  fenwick fw1(n+1);
  fenwick fw2(n+1);
  
  ll op, l, r, v;
  while(q--)
  {
    cin >> op;
    if(op)
    {
      cin >> l >> r;
      l--;
      if(l) l = fw1.query(l)*l - fw2.query(l);
      r = fw1.query(r)*r - fw2.query(r);
      cout << r - l << endl;
    }
    else
    {
      cin >> l >> r >> v;
      fw1.update(l,v);
      fw1.update(r+1,-v);
      fw2.update(l, v*(l-1));
      fw2.update(r+1, -v*r);
    }
  }
}