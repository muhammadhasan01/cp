#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int n;
int a[N];
int pre[N], suf[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            pre[i] = pre[i - 1] + 1;
            cur++;
        } else {
            pre[i] = 1;
            ans = max(ans, cur);
            cur = 1;
        }
    }
    ans = max(ans, cur);
    a[n + 1] = 2e9;
    for (int i = n; i >= 1; i--) {
        if (a[i] < a[i + 1]) {
            suf[i] = suf[i + 1] + 1;
        } else {
            suf[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] < a[i + 1]) {
            ans = max(ans, pre[i - 1] + suf[i + 1]);
        }
    }
    cout << ans << '\n';

    return 0;
}
