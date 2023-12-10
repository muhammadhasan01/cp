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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    gp_hash_table<long long, int, custom_hash> ans;
    gp_hash_table<long long, int, custom_hash> S;
    unordered_map<long long, set<long long>, custom_hash> st;
    unordered_map<long long, vector<long long>, custom_hash> g;
    while (q--) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            long long x;
            cin >> x;
            S[x] = 1;
            for (long long k : g[x]) {
                st[k].erase(x);
            }
        } else if (tp == '-') {
            long long x;
            cin >> x;
            S[x] = 0;
            for (long long k : g[x]) {
                st[k].emplace(x);
            }
        } else if (tp == '?') {
            long long k;
            cin >> k;
            if (!st[k].empty()) {
                cout << *st[k].begin() << '\n';
                continue;
            }
            int cur = ans[k];
            if (cur == 0) {
                cur = 1;
            }
            while (S[k * cur] == 1) {
                g[k * cur].emplace_back(k);
                cur++;
            }
            cout << k * cur << '\n';
            ans[k] = cur;
        }
    }

    return 0;
}
