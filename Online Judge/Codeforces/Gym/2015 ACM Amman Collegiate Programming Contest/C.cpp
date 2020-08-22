#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int tc;
int n;
char a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> good(n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == '*') {
            good[i] = good[i - 1] = good[i + 1] = 1;
        }
    }
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (good[i]) {
            res += (cnt + 2) / 3;
            cnt = 0;
            continue;
        }
        ++cnt;
    }
    res += (cnt + 2) / 3;
    cout << res << '\n';
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