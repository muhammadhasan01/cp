#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i < n; i++) {
        if (a[0] >= a[i]) {
            continue;
        }
        long long take = (a[i] - a[0] + 1) / 2;
        a[0] += take;
    }
    cout << a[0] << '\n';
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