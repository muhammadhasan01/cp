#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n;
int a[N];
int suf[N], pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (a[i] == 0);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + (a[i] == 1);
    }
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans = max(ans, pre[i - 1] + suf[i]);
    }
    cout << ans << '\n';

    return 0;
}