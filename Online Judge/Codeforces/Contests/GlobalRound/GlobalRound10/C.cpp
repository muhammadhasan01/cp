#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
int a[N];
pair<int, int> p[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i].first = a[i], p[i].second = i;
    }
    sort(p + 1, p + 1 + n);
    vector<bool> vis(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int id = p[i].second;
        if (id == 1) continue;
        if (a[id - 1] > a[id]) {
            ans += (1LL) * (a[id - 1] - a[id]);
        }
    }
    cout << ans << '\n';
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