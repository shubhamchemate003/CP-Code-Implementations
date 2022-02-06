const int mod = 1e9 + 7;

const int D = 2020;
int fact[D], invf[D];

int binpow(int x, int n, int M = mod) {
    if (x == 0) return 0;
    x %= M;
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * x) % M;
        n >>= 1, x = (x * x) % M;
    }
    return ans % M;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < D; i++)
        fact[i] = fact[i - 1] * i % mod;
    for (int i = 0; i < D; i++)
        invf[i] = binpow(fact[i], mod - 2);
}

int nCr(int n, int r) {
    if (!fact[0]) {
        cout << "Precompute factorials Jaan!\n";
        exit(0);
    }
    return fact[n] * invf[r] % mod * invf[n - r] % mod;
}