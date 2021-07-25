#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mini = INF, maxi = -INF;
        for (int j = i; j < n; j++) {
            mini = min(mini, a[j]);
            maxi = max(maxi, a[j]);
            if (maxi - mini == k) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}