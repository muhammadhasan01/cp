#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, seed, vmax;
    cin >> n >> m >> seed >> vmax;
    auto rnd = [&]() -> int {
        int ret = seed;
        seed = (1LL * seed * 7 + 13) % M;
        return ret;
    };
    map<int, long long> mp;
    for (int i = 1; i <= n; i++) {
        mp[i] = rnd() % vmax + 1;
    }
    mp[n + 1] = 0LL;
    while (m--) {
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1;
        if (l > r) {
            swap(l, r);
        }
        auto get_iterator = [&](int pos) {
            auto it = --mp.upper_bound(pos);
            if (it->first != pos) {
                mp[pos] = it->second;
                it++;
            }
            return it;
        };
        auto itl = get_iterator(l);
        auto itr = get_iterator(r + 1);
        if (op == 1) {
            int x = rnd() % vmax + 1;
            while (itl != itr) {
                (--itr)->second += x;
            }
        } else if (op == 2) {
            int x = rnd() % vmax + 1;
            while (itl != itr) {
                mp.erase(itl++);
            }
            mp[l] = x;
        } else if (op == 3) {
            int x = rnd() % (r - l + 1) + 1;
            vector<pair<long long, int>> v;
            while (itr != itl) {
                int up = (itr--)->first;
                v.emplace_back(itr->second, up - itr->first);
            }
            sort(v.begin(), v.end());
            int cnt = 0;
            for (auto& [val, add] : v) {
                cnt += add;
                if (cnt >= x) {
                    cout << val << '\n';
                    break;
                }
            }
        } else if (op == 4) {
            auto modpow = [&](long long x, long long y, long long mod) -> long long {
                long long ret = 1;
                while (y > 0) {
                    if (y % 2 == 1) {
                        ret = (ret * x) % mod;
                    }
                    y = (y / 2);
                    x = (x * x) % mod;
                }
                return ret;
            };
            int x = rnd() % vmax + 1;
            int y = rnd() % vmax + 1;
            long long ans = 0;
            while (itl != itr) {
                int up = (itr--)->first;
                ans = (ans + (modpow(itr->second % y, x, y) * (up - itr->first)) % y) % y;
            }
            cout << ans << '\n';
        }
    }
    
    return 0;
}