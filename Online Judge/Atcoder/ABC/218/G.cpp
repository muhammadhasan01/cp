#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Compresser {
    vector<T> nums;
    
    Compresser() {}

    Compresser(vector<T>& v) {
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
 
    int getId(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }

    T getValue(int id) {
        return nums[id - 1];
    }
 
    int getLen() {
        return nums.size();
    }
};

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    Compresser comp(a);
    int len = comp.getLen();
    BIT<int> bit(len + 1);

    auto getPosVal = [&](int pos) -> int {
        int l = 1, r = len, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (bit.get(mid) >= pos) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        assert(at != -1);
        return comp.getValue(at);
    };

    int sz = 0;

    auto getMedian = [&]() -> int {
        if (sz & 1) {
            return getPosVal((sz + 1) / 2);
        }
        return (getPosVal(sz / 2) + getPosVal(sz / 2 + 1)) / 2;
    };

    vector<int> dp(n, -1);

    function<void(int, int)> dfs = [&](int u, int p) {
        bit.add(comp.getId(a[u]), 1);
        ++sz;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            };
            dfs(v, u);
            if (sz & 1) {
                dp[u] = (dp[u] == -1 ? dp[v] : max(dp[u], dp[v]));
            } else {
                dp[u] = (dp[u] == -1 ? dp[v] : min(dp[u], dp[v]));
            }
        }
        if (dp[u] == -1) {
            dp[u] = getMedian();
        }
        --sz;
        bit.add(comp.getId(a[u]), -1);
    };

    dfs(0, 0);

    cout << dp[0] << '\n';
     
    return 0;
}