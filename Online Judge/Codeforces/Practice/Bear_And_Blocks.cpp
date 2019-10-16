#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int h[N], res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int mini = 0;
    for (int i = 1; i <= n; i++) {
        mini = min(mini, h[i] - i);
        res[i] = i + mini;
    }
    mini = n + 1;
    for (int i = n; i >= 1; i--) {
        mini = min(mini, h[i] + i);
        res[i] = min(res[i], mini - i);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, res[i]);
    }
    cout << ans << '\n';

    return 0;
}
