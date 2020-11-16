const int N = 2e5 + 5;

typedef int t_data;

const t_data TERM = 0;

struct SegtreeLazy {
    vector<t_data> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }

    t_data combine(const t_data& x, const t_data& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, t_data * a) {
        lazy[v] = 0;
        if (s == e) {
            t[v] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        t[v << 1] += lazy[v];
        t[v << 1 | 1] += lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, t_data val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] += val;
            lazy[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    t_data get(int v, int s, int e, int l, int r) {
        if (l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        t_data p1 = get(v << 1, s, mid, l, min(r, mid));
        t_data p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
};
