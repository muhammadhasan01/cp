#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k;
pair<int, int> a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    int z = n;
    for (int i = 2; i <= n; i++) {
        if (a[i].second == a[i - 1].second + 1) {
            --z;
        }
    }
    cout << (z <= k ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}