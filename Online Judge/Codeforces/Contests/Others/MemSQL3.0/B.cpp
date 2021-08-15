#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int K = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ans = INF;
    for (int i = 1; i < K; i++) {
        int j = (n + i - 1) / i;
        ans = min(ans, 2 * (i + j));
    }
    cout << ans << '\n';

    return 0;
}