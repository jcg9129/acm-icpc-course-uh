#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v;
    node *next;
    node() : next(NULL) {};
    node(int x) : v(x), next(NULL) {};
};

inline int merge(node *a, node *b)
{
    int ma, mb, r = 0, c;
    for (node *i = a, *k = b; i != NULL; i = i->next, k = k->next)
    {
        ma = 1 << 30, mb = 1 << 30, c = 0;
        for (node *j = i, *l = k; j != NULL; j = j->next, l = l->next)
        {
            ma = min(ma, j->v);
            mb = min(mb, l->v);
            r = max(r, ++c*(ma+mb));
        }
    }
    return r;
}

inline node *unite(node *a, node *b, node *c, node *d, int t)
{
    node *i, *j, *p;
    for (i=a, j=b; i!=NULL; i=i->next, j=j->next)
    {
        p = i;
        if (i->v==t)
            i->v += j->v;
    }

    for (i=c, j=d; i!=NULL; i=i->next, j=j->next)
        if (i->v==t)
            i->v += j->v;
    p->next = c;
    return a;
}

inline node *clone(node *a)
{
    node *r = new node(), *t = r;
    while (true)
    {
        t->v = a->v;
        if (a->next != NULL)
        {
            t->next = new node();
            t = t->next;
            a = a->next;
        }
        else break;
    };
    return r;
}

void garbage(node *u)
{
    if (u->next)
        garbage(u->next);
    delete(u);
}

struct st
{
    node *r0, *r1, *r2, *r3;
};

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m));

    for (auto &i : M)
        for (auto &j : i)
            cin >> j;

    int ans = 0;
    function<st(int, int, int, int)> solve = [&](int x1, int y1, int x2, int y2)
    {
        if (x1 == x2)
        {
            node *r0 = new node();
            node *t = r0;
            int c = 0;
            for (int i = y1; i <= y2; ++i)
            {
                t->v = !M[x1][i];
                if (t->v)
                    ++c;
                else
                    ans = max(ans, c), c = 0;
                if (i < y2)
                {
                    t->next = new node();
                    t = t->next;
                }
            }
            ans = max(ans, c);
            st r;
            r.r0=r0;
            c = 0;
            for (int i = y2; i >= y1 && !M[x1][i]; --i) ++c;
            r.r1=new node(c);
            r.r2=clone(r0);
            c = 0;
            for (int i = y1; i <= y2 && !M[x1][i]; ++i) ++c;
            r.r3=new node(c);
            return r;
        }

        if (y1 == y2)
        {
            node *r0 = new node();
            node *t = r0;
            int c = 0;
            for (int i = x1; i <= x2; ++i)
            {
                t->v = !M[i][y1];
                if (t->v)
                    ++c;
                else
                    ans = max(ans, c), c = 0;
                if (i < x2)
                {
                    t->next = new node();
                    t = t->next;
                }
            }
            ans = max(ans, c);
            st r;
            c = 0;
            for (int i = x1; i <= x2 && !M[i][y1]; ++i) ++c;
            r.r0=new node(c);
            r.r1=r0;
            c = 0;
            for (int i = x2; i >= x1 && !M[i][y1]; --i) ++c;
            r.r2=new node(c);
            r.r3=clone(r0);
            return r;
        }

        int mx = (x1+x2)>>1, my = (y1+y2)>>1;
        auto r1 = solve(x1, y1, mx, my);
        auto r2 = solve(x1, my+1, mx, y2);
        auto r3 = solve(mx+1, my+1, x2, y2);
        auto r4 = solve(mx+1, y1, x2, my);

        node *t = r1.r2;
        while (t->next != NULL) t=t->next;
        t->next = r2.r2;

        t = r4.r0;
        while (t->next != NULL) t=t->next;
        t->next = r3.r0;

        ans = max(ans, merge(r1.r2, r4.r0));
        ans = max(ans, merge(r1.r1, r2.r3));
        ans = max(ans, merge(r4.r1, r3.r3));

        st ret;
        ret.r0 = unite(r1.r0, r4.r0, r2.r0, r3.r0, mx-x1+1);
        ret.r1 = unite(r2.r1, r1.r1, r3.r1, r4.r1, y2-my);
        ret.r2 = unite(r4.r2, r1.r2, r3.r2, r2.r2, x2-mx);
        ret.r3 = unite(r1.r3, r2.r3, r4.r3, r3.r3, my-y1+1);
        garbage(r1.r2);
        garbage(r4.r0);
        garbage(r1.r1);
        garbage(r2.r3);
        garbage(r4.r1);
        garbage(r3.r3);
        return ret;
    };

    solve(0, 0, n-1, m-1);
    cout << ans << "\n";

    return 0;
}