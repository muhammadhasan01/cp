#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;

int n, m;
int a[M], ans[M], rig[M];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    reverse(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i++) {
        ans[i] = max(1, rig[i - 1] - a[i] + 1);
        if (ans[i] > n - a[i] + 1) dismiss();
        rig[i] = ans[i] + a[i];
    }
    int dif = n - rig[m] + 1;
    if (dif < 0) dismiss();
    int pre = 0;
    for (int i = 2; i <= m; i++) {
        ans[i] += pre;
        int cur = min(dif, rig[i - 1] - ans[i]);
        dif -= cur;
        pre += cur;
        ans[i] += cur;
        rig[i] = ans[i] + a[i];
    }
    if (dif > 0) dismiss();
    reverse(ans + 1, ans + 1 + m);
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << (i == m ? '\n' : ' ');
    }

    return 0;
}