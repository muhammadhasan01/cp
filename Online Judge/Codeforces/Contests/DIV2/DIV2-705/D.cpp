#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 1e9 + 7;

int n, q;
vector<pair<int, int>> fprime[N];
int last[N];
unordered_map<int, int> mp[N];
multiset<int> ms[N];
int last_big[N];

long long binpow(long long x, int y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % M;
        y >>= 1;
        x = (x * x) % M;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (last[i] > 0) continue;
        for (int j = i; j < N; j += i) {
            last[j] = i;
        }
    }
    for (int i = 2; i < N; i++) {
        int x = i;
        while (x > 1) {
            int p = last[x], cur = 0;
            while (x % p == 0) {
                ++cur;
                x /= p;
            }
            fprime[i].emplace_back(p, cur);
        }
    }

    cin >> n >> q;
    long long gcd = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        gcd = __gcd(gcd, (long long) x);
        for (auto& e : fprime[x]) {
            int u, v;
            tie(u, v) = e;
            ms[u].emplace(v);
            mp[i][u] = v;
        }
    }
    for (int i = 1; i < N; i++) {
        if (last[i] != i) continue;
        int len = ms[i].size();
        if (len < n) continue;
        last_big[i] = *ms[i].begin();
    }
    while (q--) {
        int i, x;
        cin >> i >> x;
        for (auto& e : fprime[x]) {
            int u, v;
            tie(u, v) = e;
            if (mp[i].count(u) > 0) {
                ms[u].erase(ms[u].find(mp[i][u]));
            }
            mp[i][u] += v;
            ms[u].emplace(mp[i][u]);
            if ((int) ms[u].size() < n) continue;
            int cur = *ms[u].begin();
            if (cur > last_big[u]) {
                gcd = (gcd * binpow(u, cur - last_big[u])) % M;
                last_big[u] = cur;
            }
        }
        cout << gcd << '\n';
    }

    return 0;
}