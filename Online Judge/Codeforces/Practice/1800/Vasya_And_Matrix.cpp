#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int M = 35;
int n, m;
int a[N], b[N];
int ans[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        x ^= a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        x ^= b[i];
    }
    if (x != 0) {
        cout << "NO" << '\n';
        return 0;
    }
    ans[1][1] = a[1];
    for (int i = 2; i <= m; i++) {
        ans[1][1] ^= b[i];
    }
    for (int i = 2; i <= m; i++) {
        ans[1][i] = b[i];
    }
    for (int i = 2; i <= n; i++) {
        ans[i][1] = b[i];
    }
    cout << "YES" << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << (j == m ? '\n' : ' ');
        }
    }

    return 0;
}
