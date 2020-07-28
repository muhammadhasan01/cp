#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n;
int a[N][3];
int ans[N][N];

void solve() {
    cin >> n;
    for (int j = 1; j <= 2; j++) {
        for (int i = 1; i <= n; i++) {
            char x;
            cin >> x;
            a[i][j] = (x == 'Y');
        }
    }
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++) {
        ans[i][i] = 1;
        if (i < n) {
            ans[i][i + 1] = (a[i][2] && a[i + 1][1]);
            ans[i + 1][i] = (a[i + 1][2] && a[i][1]);
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!ans[i][k] || !ans[k][j]) continue;
                ans[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (ans[i][j] ? 'Y' : 'N');
        }
        cout << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("A_input.txt","r",stdin);
    freopen("A_output.txt","w",stdout);

    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cout << "Case #" << tt << ": \n";
        solve();
    }

    return 0;
}