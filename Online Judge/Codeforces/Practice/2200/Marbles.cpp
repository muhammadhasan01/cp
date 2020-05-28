#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int K = 20;
const long long INF = 1e18;

int n;
int a[N];
long long pre[K][K];
long long cost[K];
long long dp[(1 << K)];
vector<int> v[K];

long long F(long long x) {
    return x * (x + 1) / 2;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        st.emplace(a[i]);
    }
    int ord = 0;
    vector<int> mp(K + 1);
    for (auto& e : st) {
        mp[e] = ord++;
    }
    assert(ord <= K);
    for (int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
        v[a[i]].emplace_back(i);
    }
    for (int i = 0; i < ord; i++) {
        for (auto& e : v[i]) {
            cost[i] += (1LL) * e;
        }
        int len = v[i].size();
        cost[i] -= F(len);
        assert(cost[i] >= 0);
        for (int j = 0; j < ord; j++) {
            if (i == j) continue;
            for (auto& e : v[j]) {
                int pos = lower_bound(v[i].begin(), v[i].end(), e) - v[i].begin();
                int sz = len - pos;
                pre[i][j] += (1LL) * sz;
            }
        }
    }
    for (int mask = 1; mask < (1 << ord); mask++) {
        vector<int> bit;
        for (int i = 0; i < ord; i++) {
            if (mask & (1 << i)) {
                bit.emplace_back(i);
            }
        }
        int len = bit.size();
        long long res = INF;
        for (int i = 0; i < len; i++) {
            long long cur = cost[bit[i]];
            for (int j = 0; j < len; j++) {
                cur -= pre[bit[i]][bit[j]];
            }
            int bmask = (mask ^ (1 << bit[i]));
            cur = cur + dp[bmask];
            res = min(res, cur);
        }
        dp[mask] = res;
    }
    cout << dp[(1 << ord) - 1] << '\n';

    return 0;
}