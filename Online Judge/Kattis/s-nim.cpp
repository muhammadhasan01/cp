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

const int H = 1e4 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k;
    cin >> k;
    vector<int> s(k);
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }
    vector<int> dp(H);
    for (int i = 1; i < H; i++) {
        gp_hash_table<int, int, custom_hash> mp;
        for (int j = 0; j < k; j++) {
            int x = i - s[j];
            if (x >= 0) {
                mp[dp[x]]++;
            }
        }
        while (mp[dp[i]] > 0) {
            dp[i]++;
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int l;
        cin >> l;
        int XOR = 0;
        for (int i = 0; i < l; i++) {
            int h;
            cin >> h;
            XOR ^= dp[h];
        }
        cout << (XOR > 0 ? 'W' : 'L');
    }
    cout << '\n';
    
    return 0;
}