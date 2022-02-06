#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define int long long
const int D = 2e5 + 10;

int n, t[4 * D];

// source: cp-algo->https://cp-algorithms.com/data_structures/segment_tree.html
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) // leaf
        t[v] = a[tl];
    else { // internal nodes
        int tm = (tl + tr) / 2;
        build(a, 2 * v + 1, tl, tm);
        build(a, 2 * v + 2, tm + 1, tr);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;

    // we can take entire interval
    if (l == tl and r == tr)
        return t[v];

    int tm = (tl + tr) / 2;
    int ans = sum(2 * v + 1, tl, tm, l, min(r, tm));
    ans += sum(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);

    return ans;
}

void update(int v, int tl, int tr, int p, int x) {
    if (tl == tr) // leaf
        t[v] = x;
    else {
        int tm = (tl + tr) / 2;
        if (p <= tm) update(2 * v + 1, tl, tm, p, x);
        else update(2 * v + 2, tm + 1, tr, p, x);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }
}

signed main() {
    fastio
#ifndef ONLINE_JUDGE
    freopen("../input1.txt", "r", stdin);
    freopen("../output1.txt", "w", stdout);
#endif

    int n, q; cin >> n >> q;
    int a[n] = {0};
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // segment tree is 0-based
    build(a, 0, 0, n - 1);

    while (q--) {
        int qt, k, u; cin >> qt >> k >> u;
        if (qt == 1)
            update(0, 0, n - 1, k - 1, u);
        else {
            k--, u--;
            cout << sum(0, 0, n - 1, k, u) << '\n';
        }
    }

    return 0;
}