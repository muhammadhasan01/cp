#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> pref, rem;
    for (int i = 0; i < n; i++) {
        if (pref.empty()) {
            pref.emplace_back(a[i]);
            continue;
        }
        if (pref.back() == a[i]) {
            rem.emplace_back(a[i]);
            continue;
        }
        pref.emplace_back(a[i]);
    }
    for (int x : rem) {
        pref.emplace_back(x);
    }
    for (int i = 0; i < n; i++) {
        cout << pref[i] << " \n"[i == n - 1];
    }
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