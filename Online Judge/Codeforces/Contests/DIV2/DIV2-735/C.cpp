#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e16;

void solve() {
    long long n, m;
    cin >> n >> m;
    if (n > m) {
        cout << 0 << '\n';
        return;
    }
    vector<int> bits;
    for (int i = 0; i <= 60; i++) {
        bool b = n & (1LL << i);
        if (b) {
            continue;
        }
        bits.emplace_back(i);
    }
    int len = bits.size();
    auto convert = [&](long long x) -> long long {
        int bit = __builtin_popcountll(x);
        if (bit > len) {
            return INF;
        }
        long long ret = 0;
        for (int i = 0; i < len; i++) {
            bool b = x & (1LL << i);
            if (!b) {
                continue;
            }
            ret += (1LL << bits[i]);
        }
        return (ret | n);
    };
    auto can = [&](long long x) -> bool {
        return convert(x) > m;
    };
    long long l = 0, r = INF, at = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            at = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << convert(at) - n << '\n';
}   

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}