// Modular Arithematic
int madd(int a, int b) {
	return (a + b) % mod;
}

int mmul(int a, int b) {
	return (a % mod * b % mod) % mod;
}

int msub(int a, int b) {
	return (((a - b) % mod) + mod) % mod;
}

int mdiv(int a, int b) {
	return mmul(a, binpow(b, mod - 2));
}

// binary exponentiation
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

// Deterministic primality test
bool ispm(int n) {
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return 0;
	return 1;
}

// Sieve of Eratosthenes -> primes in range
void sieve(int N) {
	vector<bool> ispm(N + 1, 1);
	ispm[0] = ispm[1] = 0;
	for (int i = 2; i * i <= N; i++)
		if (ispm[i])
			for (int j = i * i; j <= N; j += i)
				ispm[j] = 0;
}

// Prime Factorization -> O(sqrt(n))
vector<int> pmfact(int x) {
	vector<int> pmf;
	for (int i = 2; i * i <= x; i++)
		while (x % i == 0) {
			pmf.pb(i);
			x /= i;
		}
	if (x > 1) pmf.pb(x);
	return pmf;
}

// Prime Factorization -> O(log(n)) -> for multiple queries
const int D = 1000;
int primeFact[D + 1];
void initSIEVE() {
	primeFact[1] = 1;
	for (int i = 2; i <= D; i++) {
		if (!primeFact[i]) {
			primeFact[i] = i;
			for (int j = i * i; j <= D; j += i)
				if (!primeFact[j]) primeFact[j] = i;
		}
	}
}

void PrimeFactSIEVE(int n) {
	while (n > 1) {
		cout << primeFact[n] << " ";
		n /= primeFact[n];
	}
}

// Matrix Exponentiation
cont int D = 100;
void MulMat(int A[D][D], int B[D][D], int n) {
	int ans[D][D];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans[i][j] = 0;
			for (int k = 1; k <= n; k++)
				ans[i][j] += A[i][k] * B[k][j];
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			A[i][j] = ans[i][j];
}

void MatExpo(int A[D][D], int n, int m, int ans[D][D]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans[i][j] = (i == j ? 1 : 0);

	while (m > 0) {
		if (m & 1) MulMat(ans, A, n);
		m >>= 1;
		MulMat(A, A, n);
	}
}

// Euler's Tuotient Function
int phi(int n) {
	if (n == 1) return 1;
	int ans = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			ans /= i, ans *= (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans /= n, ans *= (n - 1);
	return ans;
}

// Euler's Tuotient Function for multiple queries
const int D = 1000;
int phi[D + 7];
void phiSIEVE() {
	for (int i = 1; i <= D; i++)
		phi[i] = i;

	for (int i = 2; i <= D; i++)
		if (phi[i] == i)
			for (int j = i; j <= D; j += i)
				phi[j] /= i, phi[j] *= (i - 1);
}

// Segmented Sieve -> Primes in range
void genPrimes(int L, int R) {
	int isRangePrime[R - L + 1] = {0};

	// prime contains primes tiint sqrt(R) -> use SIEVE();

	for (auto p : primes) {
		if (p * p <= R) {
			int i = (L / p) * p;
			if (i < L) i += p;
			for (; i <= R; i += p)
				if (i != p) isRangePrime[i - L] = 1;
		}
	}

	for (int i = 0; i < (R - L + 1); i++)
		if (!isRangePrime[i])
			cout << i + L << " ";
}

// Extended Euclidean Algorithm
int extendEuclid(int a, int b, int& x, int& y) {
	if (b == 0) {x = 1, y = 0; return a;}
	int x1, y1;
	int g = extendEuclid(b, a % b, x1, y1);
	x = y1, y = x1 - y1 * (a / b);
	return g;
}

// Linear Diophantine Equation
void LDA(int a, int b, int c, int& x, int& y) {
	x = 0, y = 0;
	if (a == 0 && b == 0) {
		if (c == 0) {cout << "INFINITE SOLUTIONS\n";}
		else cout << "NO SOLUTION\n";
		return;
	}

	int x0, y0;
	int g = extendEuclid(a, b, x0, y0);
	if (c % g != 0) {cout << "NO SOLUTION\n"; return;}
	else x = x0 * (c / g), y = y0 * (c / g);
}
