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

const int N = 1e5 + 5;

deque<int> divisors[N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    gp_hash_table<int, int, custom_hash> mp;
    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        ans += sum;
        long long cur = 0;
        if (i > 0) {
            gp_hash_table<int, int, custom_hash> ht;
            for (int x : divisors[a[i]]) {
                ht[x] = mp[x];
            }
            for (int x : divisors[a[i]]) {
                if (ht[x] == 0) {
                    continue;
                }
                for (int y : divisors[x]) {
                    if (x != y) {
                        ht[y] -= ht[x];
                    }
                }
                cur += 1LL * x * ht[x];
            }
            sum += cur;
        }
        for (int x : divisors[a[i]]) {
            mp[x]++;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_front(i);
        }
    } 
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}