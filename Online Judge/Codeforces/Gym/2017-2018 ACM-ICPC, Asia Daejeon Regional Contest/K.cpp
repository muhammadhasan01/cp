#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << (a[i] != a[i + 1] ? 1 : n - i) << " \n"[i == n - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}