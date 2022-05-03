#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define deb(x) cout<<#x<<'='<<x<<'\n';
#define deb2(x,y) cout<<#x<<'='<<x<<", "<<#y<<'='<<y<<'\n';
#define int long long
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x).size()
const long double PI = acos(-1);
const int mod = 1e9 + 7, inf = 1e18;
const int D = 2e5 + 10;

void solve_test() {
    int n, m, q;
    cin >> n >> m >> q;

    string a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt[n + 5][m + 5];
    memset(cnt, 0, sizeof(cnt));

    int tot = 0;
    for (int i = 0; i < n; i++)
        tot += count(all(a[i]), '*');

    int bea = 0;
    for (int j = 0, cnt = tot; j < m; j++)
        for (int i = 0; i < n and cnt>0; i++, cnt--)
            bea += (a[i][j] == '*');

    auto getEqNum = [&](int x, int y) {
        return (y - 1) * n + x;
    };

    for (int qq = 1; qq <= q; qq++) {
        int x, y; cin >> x >> y;
        cnt[x][y]++;

        if (cnt[x][y] % 2 == 0 and cnt[x][y] > 0) {
            if (a[x - 1][y - 1] == '.') {
                if (getEqNum(x, y) <= tot) bea--;
                tot--;
            }
            else {
                tot++;
                if (getEqNum(x, y) <= tot) bea++;
            }
        }
        else {
            if (a[x - 1][y - 1] == '.') {
                tot++;
                if (getEqNum(x, y) <= tot) bea++;
            }
            else {
                if (getEqNum(x, y) <= tot) bea--;
                tot--;
            }
        }

        // cout << tot - bea << '\n';
        deb2(tot, bea);
    }
}

signed main() {
    fastio
#ifndef ONLINE_JUDGE
    freopen("../input1.txt", "r", stdin);
    freopen("../output1.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve_test();
    }
    return 0;
}