template<int MAXN, typename T, T TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, 0);
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, vector<T>& a) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid, a);
            build(v << 1 | 1, mid + 1, e, a);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, T val) {
        if (s == e && s == pos) {
            t[v] += val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    T get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, r);
        T p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

// const int N = 1e5;
// const int INF = 2e9;
// Segtree<N, int, -INF> sgt;
