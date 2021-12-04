#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x < n; x = x | (x + 1))
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x >= 0; x = (x & (x + 1)) - 1)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

const long long INF = 4e18;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    k = n - k + 1;
    BIT<int> cnt_e(N);
    BIT<long long> sum_e(N);
    BIT<int> cnt_p(N);
    vector<vector<int>> values(N);
    for (int i = 0; i < n; i++) {
        int p, e;
        cin >> p >> e;
        values[p].emplace_back(e);
        cnt_e.add(e, 1);
        sum_e.add(e, e);
        cnt_p.add(p, 1);
    }
    int curlen = 0;
    long long ans = INF;
    for (int m = 0; m <= n; m++) {
        int rank = cnt_p.get(m - 2);
        vector<int> curval(values[m].begin(), values[m].end());
        if (m > 0) {
            curval.insert(curval.begin(), values[m - 1].begin(), values[m - 1].end());
        }
        int take = max(0, k - rank);
        int len = curval.size();
        if (take > len) {
            continue;
        }
        long long res = 0;
        sort(curval.begin(), curval.end());
        for (int i = 0; i < take; i++) {
            res += curval[i];
            cnt_e.add(curval[i], -1);
            sum_e.add(curval[i], -curval[i]);
        }
        int otake = max(0, m - take);
        int l = 0, r = N - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (cnt_e.get(mid) >= otake) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at == -1) {
            continue;
        }
        res += sum_e.get(at);
        res -= 1LL * (cnt_e.get(at) - otake) * at;
        ans = min(ans, res);
        for (int i = 0; i < take; i++) {
            cnt_e.add(curval[i], 1);
            sum_e.add(curval[i], curval[i]);
        }
    }
    if (ans == INF) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}