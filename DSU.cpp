const int D = 1020;

struct dsu {
    int par[D], size[D];

    dsu() {
        fill(size, size + D, 0);
        iota(par, par + D, 0);
    }

    int get(int x) {
        if (par[x] != x)
            par[x] = get(par[x]);
        return par[x];
    }

    bool unify(int x, int y) {
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (size[x] < size[y])
            swap(x, y);
        size[x] += size[y];
        par[y] = x;
        return 1;
    }
};

// be careful while mentioning size of dsu
// ds(n+10) (not ds(D));
struct dsu {
    vector<int> e;
    dsu(int N) { e = vector<int>(N + 20, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unify(int x, int y) { // union by size
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};