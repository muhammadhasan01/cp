#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pos;
    for (int i = 1; i + 1 < n; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            pos.emplace_back(i);
        }
    }
    int ans = 0;
    int m = (int) pos.size();
    vector<bool> done(m);
    for (int i = 0; i + 1 < m; i++) {
        if (done[i]) {
            continue;
        }
        if (pos[i + 1] - pos[i] == 2) {
            int j = pos[i];
            a[j + 1] = max(a[j], a[j + 2]);
            ++ans;
            done[i] = true;
            done[i + 1] = true;
        }
    }
    for (int i = 0; i < m; i++) {
        if (done[i]) {
            continue;
        }
        int j = pos[i];
        a[j] = max(a[j - 1], a[j + 1]);
        ++ans;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
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