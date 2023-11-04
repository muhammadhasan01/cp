#include <bits/stdc++.h>

using namespace std;

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
        if (s == e && s == pos) {
            t[v] = val;
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
};

struct Info {
    long long val;
    Info() : val(-LLONG_MAX) {}
    Info(long long v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(max(lhs.val, rhs.val));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = n;
    vector<Info> info(n + 2);
    for (int i = 0; i <= n + 1; i++) {
        info[i] = a[i];
    }
    SegmentTree<Info> sgt(info);
    long long m;
    cin >> m;
    vector<int> L(n + 2);
    {
        stack<int> st;
        for (int i = 0; i <= n + 1; i++) {
            while (!st.empty() && a[st.top()] < a[i]) {
                st.pop();
            }
            L[i] = st.empty() ? -1 : st.top();
            st.emplace(i);
        }    
    }
    vector<int> R(n + 2);
    {
        stack<int> st;
        for (int i = n + 1; i >= 0; i--) {
            while (!st.empty() && a[st.top()] < a[i]) {
                st.pop();
            }
            R[i] = st.empty() ? n : st.top();
            st.emplace(i);
        }
    }
    long long sum = 0;
    long long res = 0;
    vector<pair<long long, long long>> values;

    auto addVal = [&](long long len, long long val) {
        if (sum >= m) {
            return;
        }
        long long add = val * len;
        if (sum + add <= m) {
            sum += add;
            res += val * (len - 1);
            return;
        }
        long long dif = m - sum;
        long long take = (dif + len - 1) / len;
        long long cur = dif - (take - 1) * len;
        res += (take - 1) * (len - 1);
        res += max(0LL, cur - 1);
        sum = m;
    };

    for (int l = 0; l <= n; l++) {
        int r = R[l];
        if (r - l <= 1) {
            continue;
        }
        int maxi = sgt.rangeQuery(l + 1, r - 1).val;
        values.emplace_back(r - l - 1, a[l] - maxi);
    }
    for (int r = n; r >= 1; r--) {
        int l = L[r];
        if (r - l <= 1) {
            continue;
        }
        if (a[l] == a[r]) {
            continue;
        }
        int maxi = sgt.rangeQuery(l + 1, r - 1).val;
        values.emplace_back(r - l - 1, a[r] - maxi);
    }
    sort(values.rbegin(), values.rend());
    for (auto [len, val] : values) {
        addVal(len, val);
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}