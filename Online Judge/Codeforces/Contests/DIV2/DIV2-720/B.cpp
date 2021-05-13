#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int P = 1e9 + 7;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<tuple<int, int, int, int>> ans;
    for (int i = 1; i <= n; i += 2) {
        if (i + 1 > n) break;
        ans.emplace_back(i, i + 1, min(a[i], a[i + 1]), P);
    }
    cout << ans.size() << '\n';
    for (auto& [i, j, x, y] : ans) {
        cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
    }
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