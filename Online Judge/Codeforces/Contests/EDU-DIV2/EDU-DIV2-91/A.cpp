#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<pair<int, int>> pre(n + 2);
    pre[1] = make_pair(p[1], 1);
    for (int i = 2; i <= n; i++) {
        pre[i] = min(pre[i - 1], make_pair(p[i], i));
    }
    vector<pair<int, int>> suf(n + 2);
    suf[n] = make_pair(p[n], n);
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = min(suf[i + 1], make_pair(p[i], i));
    }
    for (int i = 2; i <= n - 1; i++) {
        if (p[i] > pre[i - 1].first && p[i] > suf[i + 1].first) {
            cout << "YES" << '\n';
            cout << pre[i - 1].second << ' ' << i << ' ' << suf[i + 1].second << '\n';
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