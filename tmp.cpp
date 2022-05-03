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
    int n, m, q; cin >> n >> m >> q;
    string a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto printM = [&] () {
        for (int i = 0; i < n; i++)
            cout << a[i] << '\n';
        cout << '\n';
    };

    int x, y; cin >> x >> y; x--, y--;
    if (a[x][y] == '*') a[x][y] = '.';
    else a[x][y] = '*';
    q--;

    int ans = 0, lx = 0, ly = 0;
    // beautify
    int tot = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '*') tot++;

    int inp = 0;
    for (int j = 0, cur = 0; j < m; j++)
        for (int i = 0; i < n; cur++, i++)
            if (cur < tot) {
                if (a[i][j] == '*') inp++;
                else a[i][j] = '*';
            }
            else a[i][j] = '.';

    ans += tot - inp;
    lx = max(0ll, tot - 1) % n;
    ly = (tot + n - 1) / n - 1;

    // deb2(lx, ly);
    cout << ans << '\n';
    printM();

    while (q--) {
        cin >> x >> y; x--, y--;
        int cur = 0;
        if (a[x][y] == '.') {
            a[x][y] = '*';
            lx = (lx + 1) % n;
            ly = (ly + 1) % m;
            if (x == lx and y == ly)
                cur += 0;
            else {
                cur += 1;
                a[lx][ly] = '*';
                a[x][y] = '.';
            }
        }
        else {
            a[x][y] = '.';
            if (x == lx and y == ly)
                cur += 0;
            else {
                cur += 1;
                a[x][y] = '*';
                a[lx][ly] = '.';
            }
            lx = (lx - 1 + n) % n;
            ly = (ly - 1 + m) % m;
        }

        ans += cur;

        cout << cur << '\n';
        printM();

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