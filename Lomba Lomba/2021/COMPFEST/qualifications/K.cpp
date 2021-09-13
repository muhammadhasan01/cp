// wrong answer
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
        p = make_pair(x, y);
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
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    precalc();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char cc;
            cin >> cc;
            v[i][j] = cc - 'a' + 1;
        }
    }
    vector<vector<dhash>> pre_r(n + 2, vector<dhash>(m + 2));
    vector<vector<dhash>> suf_r(n + 2, vector<dhash>(m + 2));
    vector<vector<dhash>> suf_c(n + 2, vector<dhash>(m + 2));
    vector<vector<dhash>> pre_c(n + 2, vector<dhash>(m + 2));
    for (int i = 1; i <= n; i++) {
        dhash pre = dhash(0, 0);
        for (int j = 1, k = 1; j <= m; j++, k++) {
            dhash cur = dhash((v[i][j] * pwr1[k]) % mod1, (v[i][j] * pwr2[k]) % mod2);
            pre = pre + cur;
            pre_r[i][j] = (pre ^ (i - 1)) + pre_r[i - 1][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        dhash suf = dhash(0, 0);
        for (int i = n, k = 1; i >= 1; i--, k++) {
            dhash cur = dhash((v[i][j] * pwr1[k]) % mod1, (v[i][j] * pwr2[k]) % mod2);
            suf = suf + cur;
            suf_c[i][j] = (suf ^ (j - 1)) + suf_c[i][j - 1];
        }
    }
    for (int i = n; i >= 1; i--) {
        dhash suf = dhash(0, 0);
        for (int j = m, k = 1; j >= 1; j--, k++) {
            dhash cur = dhash((v[i][j] * pwr1[k]) % mod1, (v[i][j] * pwr2[k]) % mod2);
            suf = suf + cur;
            suf_r[i][j] = (suf ^ (n - i)) + suf_r[i + 1][j];
        }
    }
    for (int j = m; j >= 1; j--) {
        dhash pre = dhash(0, 0);
        for (int i = 1, k = 1; i <= n; i++, k++) {
            dhash cur = dhash((v[i][j] * pwr1[k]) % mod1, (v[i][j] * pwr2[k]) % mod2);
            pre = pre + cur;
            pre_c[i][j] = (pre ^ (m - j)) + pre_c[i][j + 1];
        }
    }
    auto can = [&](int k) -> bool {
        set<pair<long long, long long>> st;
        for (int i = 1; i <= n; i++) {
            int ci = i + k - 1;
            if (ci > n) {
                continue;
            }
            for (int j = 1; j <= m; j++) {
                int cj = j + k - 1;
                if (cj > m) {
                    break;
                }
                // 0-rotation
                dhash rot0 = pre_r[ci][cj] - pre_r[i - 1][cj] - pre_r[ci][j - 1] + pre_r[i - 1][j - 1];
                rot0 = (rot0 * (j - 1)) * (i - 1);
                // 1-rotation
                dhash rot1 = suf_c[i][cj] - suf_c[ci + 1][cj] - suf_c[i][j - 1] + suf_c[ci + 1][j - 1];
                rot1 = (rot1 * (n - ci)) * (j - 1);
                // 2-rotation
                dhash rot2 = suf_r[i][j] - suf_r[ci + 1][j] - suf_r[i][cj + 1] + suf_r[ci + 1][cj + 1];
                rot2 = (rot2 * (m - cj)) * (n - ci);
                // 3-rotation
                dhash rot3 = pre_c[ci][j] - pre_c[i - 1][j] - pre_c[ci][cj + 1] + pre_c[i - 1][cj + 1];
                rot3 = (rot3 * (i - 1)) * (m - cj);
                vector<pair<long long, long long>> vv = {rot0.p, rot1.p, rot2.p, rot3.p};
                for (auto& x : vv) {
                    if (st.find(x) != st.end()) {
                        return true;
                    }
                }
                for (auto& x : vv) {
                    st.emplace(x);
                }
            }
        }
        return false;
    };
    int l = 1, r = min(n, m), ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans + 1 << '\n';

    return 0;
}