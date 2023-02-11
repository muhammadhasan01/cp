#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());
    vector<int> suf(n + 1, INT_MAX);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = min(suf[i + 1], v[i].second);
    }
    long long damage = 0;
    for (int i = 0; i < n; i++) {
        damage += k;
        for (int j = i; j < n; j++) {
            if (damage < v[j].first) {
                if (k == 0) {
                    cout << "NO" << '\n';
                    return;
                }
                k = max(0, k - suf[j]);
                i = j - 1;
                break;
            }
        }
    }
    cout << "YES" << '\n';
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