#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int K = 16;

int n, m;
int LCM = 1;
int a[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i <= K; i++) {
        LCM = (LCM / __gcd(LCM, i)) * i;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int ans;
            if ((i + j) % 2 == 0) {
                ans = LCM;
            } else {
                ans = LCM + (a[i][j] * a[i][j] * a[i][j] * a[i][j]);
            }
            cout << ans << " \n"[j == m];
        }
    }

    return 0;
}