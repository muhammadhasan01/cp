#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int tc;
char s[N];
int pre[N];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= k; i++) {
        s[i] = 'S';
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = (s[i] == 'S' ? i : pre[i - 1]);
    }
    int last = k;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        char x;
        cin >> x;
        if (x == 'A') {
            last = n;
        } else {
            int x; cin >> x;
            if (s[x] == 'S' && x <= pre[last]) ++ans;
            last = max(last, x);
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}