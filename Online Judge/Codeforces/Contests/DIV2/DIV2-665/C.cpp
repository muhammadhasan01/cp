#include <bits/stdc++.h>

using namespace std;

const int N = 1e5  + 5;

int tc;
int n;
int a[N];
pair<int, int> p[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = make_pair(a[i], i);
    }
    sort(p + 1, p + 1 + n);
    int mini = p[1].first;
    for (int i = 1; i <= n; i++) {
        if (p[i].first % mini == 0) continue;
        if (a[i] == p[i].first) continue;
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
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