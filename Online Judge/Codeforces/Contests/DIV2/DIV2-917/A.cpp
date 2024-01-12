#include <bits/stdc++.h>

using namespace std;

const int K = 3;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> cnt(K);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            cnt[2]++;
        } else if (a[i] == 0) {
            cnt[1]++;
        } else if (a[i] < 0) {
            cnt[0]++;
        }
    }
    if (cnt[1] > 0) {
        cout << 0 << '\n';
        return;
    }
    if (cnt[0] & 1) {
        cout << 0 << '\n';
        return;
    }
    cout << 1 << '\n';
    cout << 1 << ' ' << 0 << '\n';
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