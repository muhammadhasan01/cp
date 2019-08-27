#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n;
int ans[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int cnt = -1;
    for (int i = 1; i <= n; i+=2) {
        for (int j = 1; j <= n; j+=2) {
            ans[i][j] = ++cnt;
            ans[i][j + 1] = ++cnt;
            ans[i + 1][j] = ++cnt;
            ans[i + 1][j + 1] = ++cnt;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << (j == n ? '\n' : ' ');
        }
    }

    return 0;
}
