#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int b, w;
const double eps = 1e-13;
double dp[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> b;
    for (int i = 1; i <= b; i++) {
        dp[i][0] = 0.0;
    }
    for (int j = 1; j <= w; j++) {
        dp[0][j] = 1.0;
    }
    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j] = j * (1.0) / (i + j);
            double cb = i * (1.0) / (i + j);
            cb *= (i - 1) * (1.0) / (i + j - 1);
            if (cb > eps && i >= 2) {
                double pb = 0, pw = 0;
                if (i >= 3) pb = ((i - 2) * (1.0) / (i + j - 2)) * dp[i - 3][j];
                pw = (j * (1.0) / (i + j - 2)) * dp[i - 2][j - 1];
                dp[i][j] += cb * (pb + pw);
            }
        }
    }
    cout << fixed << setprecision(13) << dp[b][w] << '\n';

    return 0;
}
