#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
int sz[N], idx[N], mx[N];
int res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int at = i - a[i] + 1;
        if (1 <= at && at <= n) {
            sz[at]++;
            idx[i] = sz[at];
        }
    }
    for (int i = n; i >= 1; i--) {
        int at = i - a[i] + 1;
        if (1 <= at && at <= n) {
            mx[at] = max(mx[at], idx[i] + res);
        }
        res = max({sz[i], mx[i], res});
    }
    cout << n - res << '\n';
    return 0;
}