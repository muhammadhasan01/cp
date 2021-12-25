#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    long long x;
    cin >> x;
    string s;
    cin >> s;
    if (x == 1) {
        for (char cc : s) {
            if (cc == '*') {
                continue;
            }
            cout << cc;
        }
        cout << '\n';
        return;
    }
    vector<pair<char, int>> v;
    char curc = s[0];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == curc) {
            ++cnt;
        } else {
            v.emplace_back(curc, cnt);
            curc = s[i];
            cnt = 1;
        }
    }
    v.emplace_back(curc, cnt);
    int m = v.size();
    long long cur = 1;
    long long add = 1;
    vector<long long> store(m);
    for (int i = m - 1; i >= 0; i--) {
        auto [cc, len] = v[i];
        store[i] = add;
        if (cc == 'a') {
            continue;
        }
        for (int j = 1; j <= len; j++) {
            for (int it = 1; it <= k; it++) {
                cur += add;
                if (cur >= x) {
                    long long rem = add - (cur - x) - 1;
                    string ans = "";
                    for (int p = 0; p < i; p++) {
                        auto [ccp, lenp] = v[p];
                        if (ccp == 'a') {
                            for (int rep = 0; rep < lenp; rep++) {
                                ans += ccp;
                            }
                        }
                    }
                    for (int rep = 0; rep < (j - 1) * k + it; rep++) {
                        ans += 'b';
                    }
                    for (int p = i + 1; p < m; p++) {
                        auto [ccp, lenp] = v[p];
                        if (ccp == 'a') {
                            for (int rep = 0; rep < lenp; rep++) {
                                ans += ccp;
                            }
                        } else {
                            for (int rep = 0; rep < lenp * k; rep++) {
                                if (rem >= store[p]) {
                                    rem -= store[p];
                                    ans += 'b';
                                }
                            }
                        }
                    }
                    cout << ans << '\n';
                    return;
                }
            }
        }
        add = cur;
    }
    assert(false);
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