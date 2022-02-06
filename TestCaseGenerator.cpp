#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long

const string ALPHA = "abcdefghijklmnopwrstuvwxyz";
const int mod = 100;

signed main() {
    FAST;
#ifndef ONLINE_JUDGE
    freopen("../input1.txt", "r", stdin);
    freopen("../output2.txt", "w", stdout);
#endif

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // use rng()

    int tt = 9;
    int nn[tt] = {30, 35, 40, 50, 60, 72, 11, 9, 3};

    cout << tt << '\n';
    for (int test = 1; test <= tt; test++) {
        int n = nn[test - 1];
        cout << n << '\n';
        for (int i = 0; i < n; i++)
            cout << 1 + rng() % 50 << ' ';
        cout << '\n';
    }

    return 0;
}