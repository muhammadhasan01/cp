#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x > 0; x -= x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x <= n; x += x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

template<typename T>
struct compresser {
    vector<T> nums;
    
    compresser() { }

    compresser(vector<T>& v) {
        nums.assign(v.begin(), v.end());
        finish();
    }
 
    void add(T x) {
        nums.emplace_back(x);
    }
 
    void finish() {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    }
 
    int get_id(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }
 
    int get_len() {
        return nums.size();
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    compresser<int> cc;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cc.add(a[i]);
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        cc.add(b[i]);
    }
    cc.finish();
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = cc.get_id(a[i]);
    }
    for (int i = 0; i < m; i++) {
        b[i] = cc.get_id(b[i]);
    }
    vector<int> p(m);
    function<void(int, int, int, int)> solve = [&](int l, int r, int lp, int rp) {
        if (l > r) {
            return;
        }
        int mid = (l + r) / 2;
        int val = b[mid];
        int len = rp - lp + 1;
        vector<int> pre(len);
        for (int i = lp, j = 0; i <= rp; i++, j++) {
            if (j > 0) {
                pre[j] = pre[j - 1];
            }
            if (i - 1 >= 0 && a[i - 1] > val) {
                pre[j]++;
            }
        }
        vector<int> suf(len);
        for (int i = rp, j = len - 1; i >= lp; i--, j--) {
            if (j + 1 < len) {
                suf[j] = suf[j + 1];
            }
            if (i < n && a[i] < val) {
                suf[j]++;
            }
        }
        pair<int, int> best = make_pair(INF, -1);
        for (int i = lp, j = 0; i <= rp; i++, j++) {
            best = min(best, {pre[j] + suf[j], i});
        }
        auto [cost, pos] = best;
        p[mid] = pos;
        solve(l, mid - 1, lp, pos);
        solve(mid + 1, r, pos, rp);
    };
    solve(0, m - 1, 0, n);
    vector<vector<int>> place(n + 1);
    for (int i = 0; i < m; i++) {
        place[p[i]].emplace_back(b[i]);
    }
    int len = m + n;
    vector<int> c(len);
    for (int i = 0, j = 0; i <= n; i++) {
        for (int x : place[i]) {
            c[j++] = x;
        }
        if (i < n) {
            c[j++] = a[i];
        }
    }
    BIT<int> bit(len + 5);
    long long ans = 0;
    for (int i = 0; i < len; i++) {
        ans += bit.get(c[i] + 1);
        bit.add(c[i], 1);
    }
    cout << ans << '\n';
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