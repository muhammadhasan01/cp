#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 2;

int g[N][K];

void DP(int i, string& ans) {
    for (int j = K - 1; j >= 0; j--) {
        if (g[i][j] == -1) {
            continue;
        }
        int temp = g[i][j];
        g[i][j] = -1;
        DP(temp, ans);
        ans += (char) (j + '0');
    }
}

void solve() {
    int n;
    cin >> n;
    int m = n / 2;
    for (int i = 0; i < n; i++) {
        g[i][0] = (i * 2) % m;
        g[i][1] = (i * 2 + 1) % m;
    }
    string ans;
    DP(0, ans);
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
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