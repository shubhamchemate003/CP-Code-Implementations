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
const int D = 1e5 + 10;

vector<int> adj[D];
int val[D];
int ans;

int dfs(int u, int p) {
    int lcm = 1;
    for (int v : adj[u])
        if (v != p and sz(adj[v]) != 1) {
            int l1 = dfs(v, u);
            lcm = (l1 * lcm) / __gcd(l1, lcm);
        }

    int cnt = 0, sum = 0, mn = inf;
    for (int v : adj[u])
        if (v != p)
            mn = min(mn, val[v]), cnt++, sum += val[v];

    assert(lcm != 0);

    int fval = mn / lcm * lcm;
    val[u] = fval * cnt;
    ans += sum - val[u];

    // cout << u << ' ' << lcm << ' ' << cnt << ' ' << fval << '\n';

    return lcm * cnt;
}

// notes
signed main() {
    fastio

    freopen("../input1.txt", "r", stdin);
    freopen("../output1.txt", "w", stdout);

    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 0; i < n - 1; i++) {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    dfs(1, -1);

    cout << ans << '\n';

    return 0;
}