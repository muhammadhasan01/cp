#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n + 5);
    while (q--) {
        int x;
        cin >> x;
        pre[1]++;
        pre[x + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (pre[i] >= a[i]) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}