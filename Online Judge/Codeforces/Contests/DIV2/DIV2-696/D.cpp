#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n + 5);
    for (int i = 1; i <= n; i++) {
        b[i] = a[i] - b[i - 1];
    }
    vector<long long> suf(n + 5, INF);
    for (int i = n; i >= 1; i--) {
        suf[i] = min(suf[i + 2], b[i]);
    }
    int last_pos = 1;
    for (int i = 1; i <= n; i++) {
        if (b[i] < 0) {
            break;
        }
        last_pos = i;
    }
    if (last_pos == n && b[n] == 0) {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 1; i < n; i++) {
        if (i - 1 <= last_pos) {
            long long bi = a[i + 1] - b[i - 1];
            if (bi < 0) {
                continue;
            }
            long long bj = a[i] - bi;
            if (bj < 0) {
                continue;
            }
            long long add = a[i + 1] * 2 - a[i] * 2;
            if (i + 2 <= n) {
                if (suf[i + 2] + add < 0) {
                    continue;
                }
            }
            if (i + 3 <= n) {
                if (suf[i + 3] - add < 0) {
                    continue;
                }
            }
            if (abs(n - i) % 2 != 0) {
                add = -add;
            }
            if (b[n] + add != 0) {
                continue;
            }
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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