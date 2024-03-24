#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


const long long MX = 1e18 + 100;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<pair<long long, int>> v;
    long long curSz = 0;
    for (int i = 0; i < n; i++) {
        int b;
        long long x;
        cin >> b >> x;
        if (curSz >= MX) {
            continue;
        }
        if (b == 1) {
            curSz = curSz + 1;
            v.emplace_back(curSz, x);
        } else if (b == 2) {
            if (curSz >= MX / (x + 1)) {
                curSz = MX;
            } else {
                curSz = curSz * (x + 1);
            }
            v.emplace_back(curSz, -1);
        }
    }
    unordered_map<long long, int, custom_hash> memo;

    function<int(long long)> answer = [&](long long k) {
        if (memo[k] > 0) {
            return memo[k];
        }
        int l = 0, r = (int) v.size() - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (v[mid].first >= k) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (v[at].second != -1) {
            return memo[k] = v[at].second;
        }
        long long curlen = v[at - 1].first;
        long long len = (k % curlen == 0 ? curlen : k % curlen);
        return memo[k] = answer(len);
    };

    for (int i = 0; i < q; i++) {
        long long k;
        cin >> k;
        cout << answer(k) << " \n"[i == q - 1];
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