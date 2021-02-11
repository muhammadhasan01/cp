#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int N = 1e5 + 5;
const int K = 30;

int n, k;
char s[N];
int pre[N][K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> (s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][int(s[i] - 'A')]++;
    }
    int ans = INF;
    for (int i = 1; i <= n - k + 1; i++) {
        int res = k, cur = -INF;
        for (int j = 0; j < K; j++) {
            cur = max(cur, pre[i + k - 1][j] - pre[i - 1][j]);
        }
        ans = min(ans, res - cur);
    }
    cout << ans << '\n';

    return 0;
}