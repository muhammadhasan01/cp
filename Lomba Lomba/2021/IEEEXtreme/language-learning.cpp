#include <bits/stdc++.h>

using namespace std;

struct mint {
    const int MOD = 1e9 + 7;
    int x;

    mint(int _x) : x((_x % MOD + MOD) % MOD) {}
    mint(long long _x) : x((_x % MOD + MOD) % MOD) {}

    mint() : x(0) {}

    mint &operator=(const mint &rhs) {
        x = rhs.x;
        return *this;
    }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = mint(1);
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    mint inv() const {
        return pow(MOD - 2);
    }

    mint &operator+=(const mint &rhs) {
        x += rhs.x;
        if (x >= MOD)
            x -= MOD;
        return *this;
    }

    mint &operator-=(const mint &rhs) {
        x -= rhs.x;
        if (x < 0)
            x += MOD;
        return *this;
    }

    mint &operator*=(const mint &rhs) {
        unsigned long long z = x;
        z *= rhs.x;
        x = (unsigned int)(z % MOD);
        return *this;
    }

    mint &operator/=(const mint &rhs) {
        return *this = *this * rhs.inv();
    }

    friend mint operator+(const mint &lhs, const mint &rhs) {
        return mint(lhs) += rhs;
    }

    friend mint operator-(const mint &lhs, const mint &rhs) {
        return mint(lhs) -= rhs;
    }

    friend mint operator*(const mint &lhs, const mint &rhs) {
        return mint(lhs) *= rhs;
    }

    friend mint operator/(const mint &lhs, const mint &rhs) {
        return mint(lhs) /= rhs;
    }

    friend ostream& operator<<(ostream &os, const mint &m) {
        return os << m.x;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    {
        map<string, int> mp;
        for (int i = 1, c = 1; i <= n; i++) {
            string s;
            cin >> s;
            if (mp.count(s) == 0) {
                mp[s] = c++;
            }
            a[i] = mp[s];
        }
    }
    vector<mint> pre(n + 2);
    vector<mint> dp(n + 2);
    vector<int> last(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int l = last[x] + 1;
        int r = i - k - 1;
        if (vis[x] == 0) {
            vis[x] = 1;
            dp[i] += 1;
        }
        if (l > r) {
            pre[i] = dp[i] + pre[i - 1];
            continue;
        }
        last[x] = r;
        dp[i] += (pre[r] - pre[l - 1]);
        pre[i] = dp[i] + pre[i - 1];
    }
    mint ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}