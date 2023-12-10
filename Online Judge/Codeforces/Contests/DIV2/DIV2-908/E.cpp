#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e17 + 5;

void solve() {
    int m;
    cin >> m;
    vector<int> n(m);
    vector<long long> L(m), R(m); 
    vector<vector<long long>> a(m);
    vector<vector<long long>> c(m);
    for (int i = 0; i < m; i++) {
        cin >> n[i] >> L[i] >> R[i];
        a[i].resize(n[i]);
        c[i].resize(n[i]);
        for (int j = 0; j < n[i]; j++) {
            cin >> a[i][j];
        }
        for (int j = 0; j < n[i]; j++) {
            cin >> c[i][j];
        }
    }
    long long mn = 0;
    long long mx = 0;
    long long sumDif = 0;
    vector<long long> C(m);
    map<long long, vector<int>> mp;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n[i]; j++) {
            mp[a[i][j]].emplace_back(i);
        }
        for (int j = 0; j < n[i]; j++) {
            C[i] += c[i][j];
        }
        mn = min(INF, mn + L[i]);
        mx = min(INF, mx + R[i]);
        sumDif = min(INF, sumDif + R[i] - L[i]);
    }
    for (long long l = mn; l <= mx; l++) {
        if (mp.find(l) == mp.end()) {
            cout << 0 << '\n';
            return;
        }
    }
    long long ans = LLONG_MAX;
    for (long long l = mn; l <= mx; l++) {
        vector<int>& idx = mp[l];
        long long len = l;
        long long cur = 0;
        long long sumd = 0;
        for (int i : idx) {
            int j = lower_bound(a[i].begin(), a[i].end(), l) - a[i].begin();
            long long other = C[i] - c[i][j];
            if (other < L[i]) {
                long long take = L[i] - other;
                cur += take;
            }
            sumd += R[i] - L[i];
        }
        len -= mn;
        if (len > 0) {
            len = max(0LL, len - (sumDif - sumd));
            for (int i : idx) {
                if (len == 0) {
                    break;
                }
                int j = lower_bound(a[i].begin(), a[i].end(), l) - a[i].begin();
                long long other = C[i] - c[i][j];
                if (other > L[i]) {
                    long long otake = other - L[i];
                    len = max(0LL, len - otake);
                }
            }
        }
        cur += len;
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}