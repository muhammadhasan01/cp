#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e9;

template<class Info, class Merge = plus<Info>>
struct SegmentTree {
    const int n;
    const Merge merge;
    vector<Info> t;
    SegmentTree(int len) : n(len), merge(Merge()), t(4 << __lg(len)) {}
    SegmentTree(vector<Info> init) : SegmentTree(init.size()) {
        function<void(int, int, int)> build = [&](int v, int s, int e) {
            if (s == e) {
                t[v] = init[s];
                return;
            }
            int mid = (s + e) >> 1;
            build(v << 1, s, mid);
            build(v << 1 | 1, mid + 1, e);
            pull(v);
        };
        build(1, 0, n - 1);
    }

    void pull(int v) {
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }

    void modify(int v, int s, int e, int pos, const Info &val) {
        if (s == e) {
            if (s != pos) {
                return;
            }
            t[v] = merge(t[v], val);
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            modify(v << 1, s, mid, pos, val);
        } else {
            modify(v << 1 | 1, mid + 1, e, pos, val);
        }
        pull(v);
    }

    void modify(int p, const Info &v) {
        modify(1, 0, n - 1, p, v);
    }

    Info rangeQuery(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r) {
            return Info();
        }
        if (l <= s && e <= r) {
            return t[v];
        }
        int mid = (s + e) >> 1;
        return merge(rangeQuery(v << 1, s, mid, l, r), rangeQuery(v << 1 | 1, mid + 1, e, l, r));
    }

    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n - 1, l, r);
    }

    int getPosition(int v, int s, int e, int k) {
        if (k <= 0) {
            return INF; 
        }
        if (s == e) {
            return t[v].val >= k ? s : INF;
        }
        int mid = (s + e) >> 1;
        if (t[v << 1].val >= k) {
            return getPosition(v, s, mid, k);
        } 
        return getPosition(v, mid + 1, e, k - t[v << 1].val);
    }

    int getPosition(int k) {
        return getPosition(1, 0, n - 1, k);
    }
};

struct Info {
    int val;
    Info() : val(0) {}
    Info(int v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(lhs.val + rhs.val);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].emplace_back(i);
    }
    vector<vector<tuple<int, int, int>>> queries(n + 1);
    for (int i = 0; i < q; i++) {
        int v, l, k;
        cin >> v >> l >> k;
        queries[v].emplace_back(i, l, k);
    }
    
    SegmentTree<Info> segtree(n + 1);
    vector<int> ans(q);
    vector<int> freq(n + 1);
    vector<int> cnt(n + 1);
    vector<set<int>> st(n + 1);
    freq[0] = n;
    for (int u = 1; u <= n; u++) {
        st[0].emplace(u);
    }
    segtree.modify(0, Info(n));

    function<void(int)> dfs = [&](int u) {
        segtree.modify(freq[cnt[a[u]]], Info(-1));
        st[freq[cnt[a[u]]]].erase(u);
        ++cnt[a[u]];
        debug() << "IN " imie(u) imie(cnt) imie(freq) imie(st);
        segtree.modify(freq[cnt[a[u]]], Info(1));
        for (int v : adj[u]) {
            dfs(v);
        }
        for (auto [i, l, k] : queries[u]) {
            int lft = segtree.rangeQuery(0, l - 1).val;
            int pos = segtree.getPosition(lft + k);
            debug() << imie(u) imie(i) imie(l) imie(k);
            debug() << imie(lft) imie(pos);
            auto it = st.lower_bound({pos, -1});
            if (it == st.end()) {
                ans[i] = -1;
            } else {
                ans[i] = it->second;
            }
        }
        segtree.modify(freq[cnt[a[u]]], Info(-1));
        st.erase({freq[cnt[a[u]]]--, u});
        --cnt[a[u]];
        st.emplace(++freq[cnt[a[u]]], u);
        segtree.modify(freq[cnt[a[u]]], Info(1));
        debug() << "OUT " imie(u) imie(cnt) imie(freq) imie(st);
    };

    dfs(1);

    for (int i = 0; i < q; i++) {
        cout << ans[i] << " \n"[i == q - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}