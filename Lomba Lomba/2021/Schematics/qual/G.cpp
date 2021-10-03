#include <bits/stdc++.h>

using namespace std;

const int MAX = 4e5 + 5;
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

    dhash operator/(int x) {
        auto cur = this->p;
        cur.first = (cur.first * ipwr1[x]) % mod1;
        cur.second = (cur.second * ipwr2[x]) % mod2;
        return dhash(cur.first, cur.second);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    precalc();
    auto solve = [&](string s, string t) -> int {
        int n = s.length();
        int m = t.length();
        vector<dhash> sp(n + 1);
        for (int i = 1; i <= n; i++) {
            int num = s[i - 1];
            sp[i] = sp[i - 1] + (dhash(num) ^ i);
        }
        vector<dhash> st(m + 1);
        for (int i = 1; i <= m; i++) {
            int num = t[i - 1];
            st[i] = st[i - 1] + (dhash(num) ^ i);
        }
        int ret = n + m;
        for (int i = 1; i <= min(n, m); i++) {
            dhash pre = st[i];
            dhash suf = (sp[n] - sp[n - i]) / (n - i);
            if (pre.p == suf.p) {
                int cur = n + m - i;
                ret = min(ret, cur);
            }
        }
        if (n > m) {
            for (int i = 1; i <= n; i++) {
                int j = i + m - 1;
                if (j > n) {
                    break;
                }
                dhash cur = (sp[j] - sp[i - 1]) / (i - 1);
                if (cur.p == st[m].p) {
                    ret = min(ret, n);
                    break;
                }
            }
        }
        return ret;
    };

    string s, t;
    cin >> s >> t;
    cout << min(solve(s, t), solve(t, s)) << '\n';

    return 0;
}