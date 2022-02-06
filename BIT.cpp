#include <bits/stdc++.h>
using namespace std;
#define int long long
const int D = 2e5 + 10;

// source: USACO-guide
int n, q;
int bit[D], a[D];

void upd(int i, int v) {
    for (; i <= n; i += i & (-i))
        bit[i] += v;
}

int query(int i) {
    int sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += bit[i];
    return sum;
}

signed main() {
    // freopen("../input1.txt", "r", stdin);
    // freopen("../output1.txt", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(i, a[i]);
    }

    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            upd(x, -a[x]);
            a[x] = y;
            upd(x, a[x]);
        }
        else cout << query(y) - query(x - 1) << '\n';
    }

    return 0;
}