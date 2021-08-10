#include <bits/stdc++.h>

using namespace std;

const int N = 6e3 + 5;
const int K = 4;
const int L = 2;

int n;
int cnt[L][L];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cnt[(x % 4) / 2][(y % 4) / 2]++;
    }
    auto choose = [&](int n, int k) -> long long {
        if (n < k) {
            return 0LL;
        }
        if (k == 2) {
            return 1LL * n * (n - 1) / 2;
        }
        return 1LL * n * (n - 1) * (n - 2) / 6;
    };
    auto cnt_bound = [&](int x1, int y1, int x2, int y2) -> int {
        if (x1 == x2 && y1 == y2) {
            return 0;
        }
        return 2;
    };
    long long ans = 0;
    for (int s1 = 0; s1 < K; s1++) {
        for (int s2 = s1; s2 < K; s2++) {
            for (int s3 = s2; s3 < K; s3++) {
                int x1 = s1 / 2, y1 = s1 % 2;
                int x2 = s2 / 2, y2 = s2 % 2;
                int x3 = s3 / 2, y3 = s3 % 2;
                int b1 = cnt_bound(x1, y1, x2, y2);
                int b2 = cnt_bound(x2, y2, x3, y3);
                int b3 = cnt_bound(x3, y3, x1, y1);
                int B = (b1 + b2 + b3) % K;
                if (B != 0) {
                    continue;
                }
                if (s1 == s2 && s2 == s3) {
                    ans += choose(cnt[x1][y1], 3);
                } else if (s1 == s2) {
                    ans += choose(cnt[x1][y1], 2) * cnt[x3][y3];
                } else if (s2 == s3) {
                    ans += choose(cnt[x2][y2], 2) * cnt[x1][y1];
                } else {
                    ans += 1LL * cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3];
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}