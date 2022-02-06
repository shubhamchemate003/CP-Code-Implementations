#include <bits/stdc++.h>
using namespace std;
#define int long long

// source: https://codeforces.com/blog/entry/18051 + Benq Github
template<class T> struct Seg {
    // ID=inf for min queries
    const T ID = 0; T cmb(T a, T b) { return a + b;}
    int n; vector<T> seg;
    void init(int n_) {
        for (n = 1; n < n_; n <<= 1);
        seg.assign(2 * n, ID);
    }
    void pull(int p) {
        seg[p] = cmb(seg[(p << 1)], seg[(p << 1) + 1]);
    }
    void upd(int p, T val) {
        seg[p += n] = val;
        for (p >>= 1; p; p >>= 1)
            pull(p);
    }
    T query(int l, int r) { // associtive op on [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ra = cmb(ra, seg[l++]);
            if (r & 1) rb = cmb(seg[--r], rb);
        }
        return cmb(ra, rb);
    }
};

Seg<int> st;

signed main() {
    // freopen("../input1.txt", "r", stdin);
    // freopen("../output1.txt", "w", stdout);

    int n, q; cin >> n >> q;
    st.init(n + 1); // array is 1 indexed
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        st.upd(i, a);
    }

    for (int i = 1; i <= q; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 1) st.upd(a, b);
        else cout << st.query(a, b) << '\n';
    }
    return 0;
}