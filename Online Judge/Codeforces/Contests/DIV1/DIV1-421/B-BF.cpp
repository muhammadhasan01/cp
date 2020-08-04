#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int INF = 2e9;

int n;
int p[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int ans = INF, at = -1;
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 1, k = i; j <= n; j++, k++) {
            if (k > n) k = 1;
            res += abs(p[k] - j);
        }
        if (res < ans) {
            ans = res, at = n - i + 1;
            if (at == n) at = 0;
        }
        cerr << i << " => " << res << '\n';
    }
    cout << ans << " " << at << '\n';

    return 0;
}