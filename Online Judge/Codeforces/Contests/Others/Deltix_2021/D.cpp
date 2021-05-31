#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    vector<long long> a(n);
    vector<vector<int>> bits(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cc;
            cin >> cc;
            if (cc == '1') {
                bits[i].emplace_back(j);
                a[i] |= (1LL << j);
            }
        }
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    shuffle(ord.begin(), ord.end(), rng32);
    string ans(m, '0');
    int best = 0;
    for (int it = 0; it < min(150, n); it++) {
        int chosen = ord[it];
        int len = bits[chosen].size();
        vector<int> cnt(1 << len);
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < len; j++) {
                if (a[i] & (1LL << bits[chosen][j])) {
                    cur |= (1 << j);
                }
            }
            cnt[cur]++;
        }
        for (int bit = 0; bit < len; bit++) {
            for (int mask = 0; mask < (1 << len); mask++) {
                if (mask & (1 << bit)) {
                    cnt[mask ^ (1 << bit)] += cnt[mask];
                }
            }
        }
        for (int mask = 0; mask < (1 << len); mask++) {
            if (2 * cnt[mask] < n) continue;
            if (__builtin_popcount(mask) < best) continue;
            best = __builtin_popcount(mask);
            string res(m, '0');
            for (int i = 0; i < len; i++) {
                if (mask & (1 << i)) {
                    res[bits[chosen][i]] = '1';
                }
            }
            ans = res;
        }
    }
    cout << ans << '\n';

    return 0;
}