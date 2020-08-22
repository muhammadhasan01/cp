#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e7;

int n;
int a[N];
int pre[N], suf[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[0] = -INF;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if (a[i] == 0) pre[i] = i;
    }
    suf[n + 1] = INF;
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if (a[i] == 0) suf[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int res = min(i - pre[i], suf[i] - i);
        cout << res << (i == n ? '\n' : ' ');
    }

    return 0;
}