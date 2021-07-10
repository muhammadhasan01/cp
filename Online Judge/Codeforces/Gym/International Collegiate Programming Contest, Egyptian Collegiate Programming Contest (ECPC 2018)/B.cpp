#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int mul = 0, cnt = 0, ans = INF;
    if (v[0] > 1) {
        ans = min(ans, n + 1);
    }
    for (int i = 0; i < n; i++) {
        if (i > 0 && v[i] == v[i - 1]) {
            mul++;
        }
        if (i + 1 < n && v[i] == v[i + 1]) {
            continue;
        }
        cnt++;
        int cur = mul + (v[i] - cnt) + (n - i - 1);
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("task.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}