#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;
const int p1 = 37;
const int mod1 = 1e9 + 7;
const int p2 = 31;
const int mod2 = 1e9 + 9;

long long pwr1[MAX + 7], pwr2[MAX + 7];
long long ipwr1[MAX + 7], ipwr2[MAX + 7];

long long modpow(long long x, long long y, long long m) {
    long long ret = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ret = (ret * x) % m;
        }
        y >>= 1;
        x = (x * x) % m;
    }
    return ret;
}

void precalc() {
    long long pw1 = 1, pw2 = 1;
    for (int i = 0; i < MAX; i++) {
        pwr1[i] = pw1;
        pwr2[i] = pw2;
        pw1 = (pw1 * p1) % mod1;
        pw2 = (pw2 * p2) % mod2;
        ipwr1[i] = modpow(pwr1[i], mod1 - 2, mod1);
        ipwr2[i] = modpow(pwr2[i], mod2 - 2, mod2);   
    }
}

long long norm(long long x, long long m) {
    return (x % m + m) % m;  
};

struct dhash {
    pair<long long, long long> p;
    dhash() {
        p = make_pair(0LL, 0LL);
    }

    dhash(long long x, long long y) {
        p = make_pair(norm(x, mod1), norm(y, mod2));
    }

    dhash(long long x) {
        *this = dhash(x, x);
    }

    dhash operator+(dhash y) {
        return dhash(norm(this->p.first + y.p.first, mod1), norm(this->p.second + y.p.second, mod2));
    }

    dhash operator+(long long x) {
        return *this + dhash(x);
    }

    dhash operator-(dhash y) {
        return dhash(norm(this->p.first - y.p.first, mod1), norm(this->p.second - y.p.second, mod2));
    }

    dhash operator-(long long x) {
        return *this - dhash(x);
    }

    dhash operator*(long long x) {
        auto cur = this->p;
        cur.first = (cur.first * x) % mod1;
        cur.second = (cur.second * x) % mod2;
        return dhash(cur.first, cur.second);
    }

    dhash operator^(int x) {
        auto cur = this->p;
        cur.first = (cur.first * pwr1[x]) % mod1;
        cur.second = (cur.second * pwr2[x]) % mod2;
        return dhash(cur.first, cur.second);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[v].emplace_back(u);
    }
    map<pair<long long, long long>, long long> mp;
    for (int u = 0; u < n; u++) {
        if (adj[u].empty()) {
            continue;
        }
        sort(adj[u].begin(), adj[u].end());
        dhash cur = 0;
        int len = adj[u].size();
        for (int i = 0; i < len; i++) {
            int x = adj[u][i];
            cur = (cur + (dhash(x) ^ i));
        }
        mp[cur.p] += a[u];
    }
    long long ans = 0;
    for (auto& [_, val] : mp) {
        ans = __gcd(ans, val);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    precalc();
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}