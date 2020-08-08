const int N = 2e5 + 5;

struct Segtree {
    vector<int> t;
    Segtree() {
        t.assign(4 * N, 0);
    }

    int combine(int x, int y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, int * a) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, int val) {
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

    int get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return 0;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        return combine(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
    }
};
