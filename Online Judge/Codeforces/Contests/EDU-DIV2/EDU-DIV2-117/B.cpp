#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for (int i = 0, j = n; i < n; i++) {
        if (i == 0) {
            p[i] = a;
        } else if (i == n / 2) {
            p[i] = b;
        } else {
            while (j == a || j == b) {
                j--;
            }
            p[i] = j--;
        }
    }
    int mini = n + 1;
    for (int i = 0; i < n / 2; i++) {
        mini = min(mini, p[i]);
    }
    int maxi = -1;
    for (int i = n / 2; i < n; i++) {
        maxi = max(maxi, p[i]);
    }
    if (mini != a || maxi != b) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
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