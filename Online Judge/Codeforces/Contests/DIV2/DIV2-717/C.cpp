#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
const int M = 2e5 + 5;
const int INF = 2e9;

int n;
int a[N];
bool dp[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a + 1, a + 1 + n, 0);
    if (sum % 2 == 1) {
        cout << 0 << '\n';
        return 0;
    }
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        for (int val = M - 1; val >= a[i]; val--) {
            if (dp[val - a[i]]) {
                dp[val] = true;
            }
        }
    }
    if (!dp[sum / 2]) {
        cout << 0 << '\n';
        return 0;
    }

    auto F = [&](int x) -> int {
        int ret = 0;
        while (x % 2 == 0) {
            x /= 2;
            ret++;
        }
        return ret;
    };

    tuple<int, int, int> res = make_tuple(INF, INF, INF);
    for (int i = 1; i <= n; i++) {
        auto cur = make_tuple(F(a[i]), a[i], i);
        res = min(res, cur);
    }
    cout << 1 << '\n';
    cout << get<2>(res) << '\n';

    return 0;
}