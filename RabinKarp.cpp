// one pair of p, m

int RabinKarp(string S, string T) {

    int p = 31, mod = 1e9 + 7;
    int n = S.size(), m = T.size();

    if (n < m) {
        cout << "Length of S is less than T\n";
        return 0;
    }

    int p_pow[n + 7] = {1};
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % mod;

    int t_h = 0;
    for (int i = 0; i < m; i++)
        t_h = (t_h + (T[i] - 'a' + 1) * p_pow[i]) % mod;

    int pref[n + 7] = {0};
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (S[i] - 'a' + 1) * p_pow[i];
        pref[i + 1] %= mod;
    }

    int ans = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        int cur_h = (pref[i + m] - pref[i] + mod) % mod;
        if ((t_h * p_pow[i]) % mod == cur_h)
            ans++;
    }

    return ans;
}