template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int t_n) : n(t_n), bit(t_n + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};