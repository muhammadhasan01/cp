#include <bits/stdc++.h>

using namespace std;

int tc;
int n;
long long k;

void solve() {
    cin >> n >> k;
    vector<long long> v(n);
    for (auto& e : v) cin >> e;
    if (k % 2 == 1) k = 1;
    else k = 2;
    for (int it = 0; it < k; it++) {
        long long maks = *max_element(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            v[i] = maks - v[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}