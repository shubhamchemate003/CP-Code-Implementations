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
const int mod = 1e9 + 7, inf = 1e15;
const int D = 1e5 + 10;

vector<pii> adj[D];

signed main() {
	fastio
#ifndef ONLINE_JUDGE
	freopen("../input1.txt", "r", stdin);
	freopen("../output1.txt", "w", stdout);
#endif

	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].pb({v, wt});
		// adj[v].pb({u, wt});
	}

	int dist[n + 1];
	for (int i = 0; i <= n; i++)
		dist[i] = inf;

	priority_queue<pii> pq;
	pq.push({0, 1});
	dist[1] = 0;

	while (!pq.empty()) {
		int u = pq.top().s;
		int du = -pq.top().f;
		pq.pop();

		if (dist[u] < du)
			continue;

		for (auto p : adj[u]) {
			int v = p.f;
			int dv = p.s;
			if (dist[v] > dist[u] + dv) {
				dist[v] = dist[u] + dv;
				pq.push({ -dist[v], v});
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << ' ';
	cout << '\n';

	return 0;
}
