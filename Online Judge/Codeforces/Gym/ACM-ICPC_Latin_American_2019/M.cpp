#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n, x;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int cur = 1;
        for (int j = i; j < n; j++) {
            if (a[j + 1] - a[j] <= x) {
                cur++;
            } else {
                break;
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}
