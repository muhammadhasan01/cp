#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int t[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = 0;
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

void update(int v, int s, int e, int pos, int val) {
    if (s == e && e == pos) {
        t[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        update(v << 1, s, mid, pos, val);
    } else {
        update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) {
        return 0;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, r);
    int p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return max(p1, p2);
}

void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> a(n);
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int x : {a[i] - k, a[i], a[i] + k}) {
            nums.emplace_back(x);
        }
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    int len = nums.size();
    build(1, 1, len);
    auto get_id = [&](int x) -> int {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    };
    vector<multiset<int>> ms(len + 5);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int j = i - l - 1;
        if (j >= 0) {
            int cur = get_id(a[j]);
            ms[cur].erase(ms[cur].find(dp[j]));
            int val = 0;
            if (!ms[cur].empty()) {
                val = *ms[cur].rbegin();
            }
            update(1, 1, len, cur, val);
        }
        int l = get_id(a[i] - k);
        int r = get_id(a[i] + k);
        int cur = get_id(a[i]);
        dp[i] = 1 + get(1, 1, len, l, r);
        ms[cur].emplace(dp[i]);
        auto it = *ms[cur].rbegin();
        update(1, 1, len, cur, it);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    for (int T = 1; T <= tt; T++) {
        cout << "Case #" << T << ": ";
        solve();
    }

    return 0;
}