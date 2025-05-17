#include <bits/stdc++.h>

using namespace std;

struct mint {
    const int MOD = 998244353;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int m = (1 << k);
    vector<mint> dp(m);
    vector<bool> isPalindrome(m);
    for (int i = 0; i < m; i++) {
        isPalindrome[i] = true;
        for (int l = 0, r = k - 1; l < r; l++, r--) {
            bool lft = (i & (1 << l));
            bool rgt = (i & (1 << r));
            if (lft != rgt) {
                isPalindrome[i] = false;
                break;
            }
        }
    }
    deque<int> pos;
    int mask = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] == '?') {
            pos.emplace_back(i);
        } else if (s[i] == 'A') {
            mask += (1 << i);
        }
    }
    {
        int len = (int) pos.size();
        for (int i = 0; i < (1 << len); i++) {
            int cur = mask;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    cur += (1 << pos[j]);
                }
            }
            if (isPalindrome[cur]) {
                continue;
            }
            dp[cur] += 1;
        }
    }

    for (int i = k, offset = 1; i < n; i++, offset++) {
        vector<mint> ndp(m);
        mask = (mask >> 1);
        if (s[i - k] == '?') {
            pos.pop_front();
        }
        if (s[i] == '?') {
            pos.emplace_back(i);
        } else if (s[i] == 'A') {
            mask += (1 << (k - 1));
        }
        int len = (int) pos.size();
        for (int x = 0; x < (1 << len); x++) {
            int ncur = mask;
            for (int j = 0; j < len; j++) {
                if (x & (1 << j)) {
                    ncur += (1 << (pos[j] - offset));
                }
            }
            if (isPalindrome[ncur]) {
                continue;
            }
            int cur = (ncur << 1) & (m - 1);
            ndp[ncur] += dp[cur];
            ndp[ncur] += dp[cur + 1];
        }
        dp.swap(ndp);
    }
    mint ans = 0;
    for (int i = 0; i < m; i++) {
        ans += dp[i];
    }
    cout << ans << '\n';
    
    return 0;
}