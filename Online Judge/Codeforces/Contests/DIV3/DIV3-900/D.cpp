#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<char> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> L(m), R(m);
    for (int i = 0; i < m; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> R[i];
    }
    vector<int> pos(n + 1, -1);
    for (int i = 0; i < m; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            pos[j] = i;
        }
    }
    vector<int> cnt(n + 2);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int i = pos[x];
        int lft = min(x, L[i] + R[i] - x);
        int rgt = max(x, L[i] + R[i] - x);
        cnt[lft]++;
        cnt[rgt + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < m; i++) {
        for (int l = L[i], r = R[i]; l < r; l++, r--) {
            if (cnt[l] & 1) {
                swap(a[l], a[r]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i];
    }
    cout << '\n';
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